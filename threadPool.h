#include<iostream>
#include<vector>
#include<queue>
#include<mutex>
#include<thread>
#include<functional>
#include <future>
using namespace std;
class threadPool
{
public:
    threadPool(int workSize):_stop(false)
    {
        for(int i = 0; i < workSize; i++)
        {
            works.emplace_back(
            [this,i]{
                function<void ()> task;
                while(true)
                {
                    {
			std::unique_lock<std::mutex> mlock(this->_mk);
                    	_cond.wait(mlock,[this]{return _stop || !tasks.empty();});
                    	if(!tasks.empty())
                    	{
                            task = std::move(this->tasks.front());
                            tasks.pop();
                    	}
			else
			    continue;
		    }
                    task();
                    if(tasks.empty()&&_stop) return;
                }
            });
        }
    }
    ~threadPool()
    {
        std::unique_lock<std::mutex>(_mk);
        _stop = true;
        for(auto &work:works){work.join();}
        _cond.notify_all();
    }
    template<class F,class ...Args>
    void addTask(F&& f,Args&& ...args)
    {
	//using RetType = decltype(f(args...));
	//auto task = std::make_shared<std::packaged_task<RetType()>> 
	//	(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
	{
       	    std::unique_lock<std::mutex> mlock(_mk);        
       	    //tasks.emplace([task](){(*task)();});
	    tasks.emplace([=](){f(args...);});
	}
        _cond.notify_one();
    }
    template<class F,class ...Args>
    auto addTaskRe(F&& f,Args&& ...args) ->std::future<decltype(f(args...))>
    {
	using RetType = decltype(f(args...));
	auto task = std::make_shared<std::packaged_task<RetType()>> 
		(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

	std::future<RetType> future = task->get_guture();
        {
       	    std::unique_lock<std::mutex> mlock(_mk);        
       	    tasks.emplace([task](){(*task)();});
	    //tasks.emplace([=](){f(args...);});
	}
        _cond.notify_one();
	return future;
    }
private:
    queue<function<void()>> tasks;
    vector<std::thread> works;
    std::mutex _mk;
    std::condition_variable _cond;
    bool _stop;
};
