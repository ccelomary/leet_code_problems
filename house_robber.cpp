#include <iostream>
#include <string>
#include <vector>

int rob(std::vector<int>& nums, int iter, std::vector<int>  & memo)
{
    if (iter >= nums.size())
        return (0);
    if (memo[iter] != -1)
    {
        return (memo[iter]);
    }
    memo[iter] = std::max(rob(nums, iter + 1, memo), nums[iter] + rob(nums, iter + 2, memo));
    return (memo[iter]);        
}

int rob(std::vector<int>    &nums)
{
    if (nums.size() == 1)
    {
        return (nums[0]);
    }
    int a, b;
    int     max_;
    b = nums.size() - 2;
    while (b >= 0)
    {
        if (b + 2 < nums.size())
            nums[b] = nums[b] + nums[b + 2];
        nums[b] = std::max(nums[b], nums[b + 1]);
        b--;
    }
    return (nums[0]);
}

int         main(void)
{
    std::vector<int>        vect = {2,7,9,3,1};
    std::vector<int>        memo(vect.size(), -1);
    std::cout << rob(vect, 0, memo) << std::endl;
    std::cout << rob(vect) << std::endl;
    for (int i = 0; i < memo.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < memo.size(); i++)
    {
        std::cout << memo[i] << " ";
    }
    std::cout << "\n";
    return (0);
}