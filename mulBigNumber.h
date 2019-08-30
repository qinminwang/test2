#include"head.h"
void mulBigNumber(std::string &a,std::string &b,std::string &c)
{
    int len_a = a.size();
    int len_b = b.size();

    vector<int> result(len_a+len_b-1);
    for(int index_a = 0;index_a<len_a;index_a++)
        for(int index_b = 0; index_b<len_b;index_b++)
        {
            result[index_a+index_b] += (a[index_a] - '0')*(b[index_b]-'0');
        }
    for(int index = result.size() - 1; index > 0; index --)
    {
        result[index - 1] += result[index]/10;
        result[index] = result[index]%10;
    }
    char result0 = result[0]/10;
    result[0] = result[0]%10;
    c = "";
    if(result0>'0')
        c.push_back(result0);
    for(int index = 0; index < result.size(); index ++)
    {
        c.push_back(result[index] + '0');
    }
}

