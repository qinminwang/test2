#include<iostream>
bool isOrder(vector<int>& in,vector<int>& out)
{
    if(in.size()!=out.size())
        return false;
    stack<int> temp;
    int index_in = 0;int index_out = 0;
    while(true)
    {
        if(index_out == out.size()-1&&index_in == in.size()-1)
            return true;
        if(!temp.empty()&&temp.top() == out[index_out])
        {
            if(index_out == out.size()-1)
                return false
            index_out++;
            temp.pop();
        }
        else
        {
            if(in[index_in] == in.size() - 1)
                return false;
            temp.push(in[index_in]);
            index_in++;
        }
    }
}
