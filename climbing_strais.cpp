#include <iostream>
#include <vector>

int climbStairs(int n)
{
    int     a;
    int     b;
    int     tmp;
    if (n == 1 || n == 2)
        return (n);
    a = 1;
    b = 2;
    for (int i = 2; i < n; i++)
    {
        tmp = b;
        b = a + b;
        a = tmp;
    }
    return (b);
}

int         main(void)
{
    int n = 6;
    std::vector<int>    memo(n, -1);
    for (int l : memo)
    {
        std::cout << l << " ";
    }
    std::cout << "\n";
    std::cout << climbStairs(n) << std::endl;
    for (int l : memo)
    {
        std::cout << l << " ";
    }
    std::cout << "\n";
    return (0);
}