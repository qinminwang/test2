#include<iostream>
#include <unistd.h>
#include<stdio.h>
#include<my_thread.h>
#include"singleton.h"
#include"smartPtr.h"
#include"threadPool.h"
#include"mulBigNumber.h"

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
void testmulBigNum()
{
    std::string a = "999";
    std::string b = "999";
    std::string c = "";
    mulBigNumber(a,b,c);
    std::cout<<c<<endl;
}
void TestSharedPtr()
{
    funct<int> func;
    smart_ptr<ListNode<int>> sp1(new ListNode<int> (10));
    smart_ptr<ListNode<int>> sp2(new ListNode<int> (20));
    sp1->_next = sp2;
    sp2->_prev = sp1;
}
void taskwork(int a)
{
    cout<<"that is"<<a<<endl;
}
void TestpoolThread()
{
   threadPool thp(5);
   for(int i = 0;i<10;i++)
   {
	auto funccc = [i](int a){cout<<"this is"<<a<<endl;};
        thp.addTask([i](){cout<<"this is"<<i<<endl;});
	auto *a = taskwork;
        thp.addTask(funccc,22);
	thp.addTask(&taskwork,11);
   }
}
int main()
{
      testmulBigNum();
//    TestpoolThread();
//    TestSharedPtr();
//    int para = 5;
//    thread t1(hello_thread,para);
     
//    for(int i= 0; i < 11; i++)
//    {
//	th1.signal();
//	sleep(1);
//	if(i >= 9)
//	    th1.setStop(true);
//    }
//   t1.join();
//    sleep(2);
//    cout<<"test process"<<endl;
    return 0;
}
