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
