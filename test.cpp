#include<memory>
#include<iostream>
using namespace std;
int main()
{
    std::cout<<"hello test"<<endl;
    allocator<int> poopmem[100];
    return 0;
}
