#include<iostream>
class singleten
{
public:
    static singleten  getInstance()
    {
	static singleten instance;
	return instance;
    }
private:
    singleten():test_a(0),test_b(0){}
    singleten(const singleten&);
    const singleten& operator=(const singleten&);

    int test_a;
    float test_b;	
};

class singleton
{
public:
    struct data{int data;};
    data* getInstance()
    {
	if(!_data)
{
	_mk.lock();
	if(!_data)
	{
	    _data = new data();
	}
	_mk.unlock();
}
	return _data;
    }
private:
    sigleton(){}
    std::mutex _mk;
    static data * _data;
}
singleton _data = nullptr;
