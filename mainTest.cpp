#include<iostream>
#include <unistd.h>
#include<stdio.h>
#include<my_thread.h>
#include"singleton.h"
#include"smartPtr.h"
#include"threadPool.h"

using namespace std;
my_thread th1;
void hello_thread(int i)
{
    while(!th1.getStop())
    {
        th1.wait();
        cout<<"hello"<<i<<endl;
    }
    cout<<"thread return"<<endl;
}

template<class T>
struct funct
{
    void operator() (T *a)
    {
    	cout<<"------"<<endl;
    }
};
void TestSharedPtr()
{
    funct<int> func;
    smart_ptr<ListNode<int>> sp1(new ListNode<int> (10));
    smart_ptr<ListNode<int>> sp2(new ListNode<int> (20));
    sp1->_next = sp2;
    sp2->_prev = sp1;
}
int main()
{
    TestSharedPtr();
    int para = 5;
    thread t1(hello_thread,para);
     
    for(int i= 0; i < 11; i++)
    {
	th1.signal();
	sleep(1);
	if(i >= 9)
	    th1.setStop(true);
    }
    t1.join();
//    sleep(2);
    cout<<"test process"<<endl;
    return 0;
}
