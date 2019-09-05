#include<iostream>
#include<vector>
std::vector<std::vector<int>> results;
void huisu(std::vector<int> input,int sum,std::vector<int> result)
{
   if(sum == 0 && result.size()>0)
   {
        results.push_back(result);
        return;
   }
   if(sum < 0 || input.size() == 0)
      return;
   int num = input[input.size()-1];
   input.pop_back();
   huisu(input,sum,result);
   sum -= num;
   result.push_back(num);
   huisu(input,sum,result);
   input.push_back(num);
}
void output(std::vector<std::vector<int>> print)
{
    for(auto its = print.cbegin();its<print.cend();its++)
    {
        for(auto it = its->cbegin();it < its->cend(); it ++)
            std::cout<<*it<<"\t";
        std::cout<<std::endl;
    }
}
void test_vector(std::vector<int > &input)//传值是深拷贝，内容一起拷贝
{
    input.emplace_back(1);
}
int main()
{
    std::vector<int> input{1,2,3,5,6,7};
//    std::vector<int> result;
//    huisu(input,10,result);
//    output(results);
    test_vector(input);
    return 0;

}
