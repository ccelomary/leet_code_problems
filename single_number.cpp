#include <iostream>
#include <map>
#include <vector>
#include <utility>

int singleNumber(std::vector<int>& nums)
{
    int a = 0;
    for (int num: nums)
        a = a ^ num;
    return (a);
}

int         add(int a, int b)
{
    return (a + b);
}   

int         funcn(int a, int b, int (*func)(int, int))
{
    return func(a, b);
}

int         main(void)
{
    std::vector<int> nums = {1, 2, 2, 1, 4};
    std::cout << singleNumber(nums) << std::endl;
    return (0);
}