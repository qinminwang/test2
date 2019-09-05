#include<memory>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
#include<stack>
#include<deque>
using namespace std;
static void fprint(int a)
{
    cout<<a<<endl;
}
int main()
{
    string str(6,'c');
    str.push_back('s');
    cout<<str.size()<<endl;
    deque<int> test_queue;
    test_queue.push_back(2);
    test_queue.push_back(1);
    test_queue.push_front(3);
    cout<<test_queue.size()<<endl;
//    for(auto &c:)    {cout<<c<<endl;} //queue 没有迭代器，不能遍历
//    for_each(test_queue.front(),test_queue.back(),[](int &a){cout<<a<<endl;});
	
    list<int> test_list(7,7);
    test_list.push_back(6);
    test_list.push_front(10);
    for(int & c:test_list) {cout<<c<<"\t";}

    cout<<"end list"<<endl;
    stack<int, list<int>> temp_stack(test_list);
 
    while(!temp_stack.empty())
    {
	cout<<temp_stack.top()<<"\t";
	temp_stack.pop();
    }
    cout<<"end stack"<<endl;

queue<int, list<int>> temp_queue(test_list);
 
    while(!temp_queue.empty())
    {
	cout<<temp_queue.front()<<"\t";
	temp_queue.pop();
    }
    cout<<"end queue"<<endl;

deque<int> temp_deque(2,4);
 temp_deque.push_back(1);
temp_deque.push_front(5);
/*
    while(!temp_deque.empty())
    {
	cout<<temp_deque.back()<<"\t";

	temp_deque.pop_back();
    }
*/
for(int &c:temp_deque)
{
    cout<<c<<"\t";
}
cout<<temp_deque[1]<<endl;
    cout<<"end deque"<<endl;


    vector<int> test(3,9);
    test.push_back(7);
    test.front() = 2;
    test.back() = 6;
//    cout<<test.pop_back()<<endl;
    for(auto& iter:test)
    {
        cout<<iter<<endl;
    }

    std::cout<<test[2]<<endl;
    cout<<test.front()<<endl;
    std::cout<<"hello test"<<endl;
    allocator<int> poopmem[100];
    return 0;
}
