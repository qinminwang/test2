#include<mutex>
#include<thread>
#include<condition_variable>
class noCopy
{
public:
    noCopy(const noCopy&)=delete;
    const noCopy& operator=(const noCopy&)=delete;
    noCopy(){}
};
class my_thread:public noCopy
{
public:
    my_thread():_flag(true),_stop(false){}
    void wait()
    {
	std::unique_lock<std::mutex> m(mk);
	_flag = true;
	while(_flag)
	{
	    _cond.wait(m);
	}
    }
    void signal()
    {
	std::unique_lock<std::mutex> m(mk);
	_flag = false;
	_cond.notify_one();
    }
    void setStop(bool tem){_stop = tem;}
    bool getStop(){return _stop;}
private:
    bool _stop;
    bool _flag = true;
    std::mutex mk;
    std::condition_variable _cond;
};
