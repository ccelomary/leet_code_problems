#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
std::vector<std::vector<int> > subsets_depth(const std::vector<int> &nums, size_t depth, size_t index)
{
    if (!depth)
        return std::vector<std::vector<int> > {{}};
    std::vector<std::vector<int> > nested_result;
    std::vector<std::vector<int> > result;
    size_t iter, it;
    size_t real_size = nums.size() - depth + 1;
    for (iter = index; iter < real_size; iter++)
    {
        nested_result = subsets_depth(nums, depth - 1, iter + 1);
        for (it = 0; it < nested_result.size(); it++)
        {
            nested_result[it].push_back(nums[iter]);
            std::sort(nested_result[it].begin(), nested_result[it].end());
            result.push_back(nested_result[it]);
        }
    }
    return (result);
}
std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums)
{
    size_t  iter, t;
    size_t length;
    bool printed;
    length = nums.size();
    std::set<std::vector<int> > sets;
    std::vector<std::vector<int> > subsets;
    std::vector<std::vector<int> > nested_subset;
    for (t = 1; t <= length; t++)
    {
        nested_subset = subsets_depth(nums, t, 0);
        for (iter  = 0; iter < nested_subset.size(); iter++)
            sets.insert(nested_subset[iter]);
    }
    for (std::set<std::vector<int> >::iterator iter = sets.begin(); iter != sets.end(); iter++)
        subsets.push_back(*iter);
    subsets.push_back({});
    return (subsets);
}

int     main(void)
{
    std::vector<int> arr{2, 1, 2};
    std::vector<std::vector<int> > v = subsetsWithDup(arr);
    for (std::vector<std::vector<int> >::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        for (std::vector<int>::iterator it = iter->begin(); it != iter->end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    return (0);
}