#include <iostream>
#include <vector>

std::vector<int>                rise_index(const std::vector<int> &vect, int index)
{
    std::vector<int>         rised;
    for (int y = 0; y < vect.size(); y++)
    {
        if (y == index)
            continue;
        rised.push_back(vect[y]);
    }
    return (rised);
}

std::vector<std::vector<int> > permute(std::vector<int>& nums)
{
    int         y;
    std::vector<std::vector<int> >     collection;
    std::vector<std::vector<int> >     nested;
    std::vector<int>                    r;
    if (nums.size() == 0)
        return {{}};
    for (y = 0; y <  nums.size(); y++)
    {
        r = rise_index(nums, y);
        nested = permute(r);
        for (std::vector<int> numbers: nested)
        {
            numbers.push_back(nums[y]);
            collection.push_back(numbers);
        }
    }
    return (collection);
}

int         main(void)
{
    std::vector<int> v = {1, 2, 3};
    std::vector<std::vector<int> > vect = permute(v);
   for (int y = 0; y < vect.size(); y++)
    {
        for (int x = 0; x < vect[y].size(); x++)
        {
            std::cout <<  vect[y][x] << " ";
        }
        std::cout << "\n";
    }
    return (0);
}