#include<iostream>
#include<vector>
using namespace std;
//best binary search template bule and red region
bool isBule(int a, int target)
{
    return a<target;
}
int binarySearch(const vector<int>& v,int target)
{
    //初始化， 蓝色和红色都为空
    int l=-1, r = v.size();
    //循环结束条件 蓝色和红色相遇
    while(l+1!=r)
    {
        int m = (l+r)/2;
        //判断是否为蓝色区域,调整红蓝边界
        if(isBule(v[m],target))
        {
            l= m;
        }else
        {
            r=m;
        }
    }
    //对结果做处理， 返回红色或者蓝色边界，或者l+1,r-1
    return l;

}

int main()
{

    vector<int> v {3,5,8,9,11,11,11,12,12,13,14,15};
    int res = binarySearch(v,11);
    cout<<res<<endl;
}
