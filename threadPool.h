#include<iostream>
#include<vector>
#include<queue>
#include<mutex>
#include<thread>
#include<functional>
using namespace std;
class threadPool
{
public:
    threadPool(int workSize):_stop(false)
    {
        for(int i = 0; i < workSize; i++)
        {
            works.emplace_back(
            [this]{
                function<void ()> task;
                while(true)
                {
                    {
			std::unique_lock<std::mutex> mlock(this->_mk);
                    	_cond.wait(mlock);
                    	if(!tasks.empty())
                    	{
                        	function<void ()> task = this->tasks.front();
                        	tasks.pop();
                    	}
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
    void addTask(function<void ()> task)
    {
        std::unique_lock<std::mutex> mlock(_mk);
        
        tasks.emplace(task);
        _cond.notify_one();
    }
private:
    queue<function<void ()>> tasks;
    vector<std::thread> works;
    std::mutex _mk;
    std::condition_variable _cond;
    bool _stop;
};
