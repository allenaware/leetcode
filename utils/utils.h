#include<vector>

template<typename T>
std::vector<T> buildVec(T param )
{
    std::vector<T> v;
    v.push_back(param);
    return v;
}