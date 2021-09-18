#include <iostream>
#include <vector>
#include <stack>
#include <utility>

int minimumTotal(std::vector<std::vector<int>>& triangle)
{
    if (triangle.size() == 1)
        return triangle[0][0];
    int y = triangle.size() - 2;
    int x;
    while (y >= 0)
    {
        for (x = 0; x < triangle[y].size(); x++)
        {
            triangle[y][x] += std::min(triangle[y + 1][x], triangle[y + 1][x + 1]);
        }
        y--;
    }
    return triangle[0][0];
}

int         main(void)
{
    std::vector<std::vector<int> > vect = {{2},{3,4},{6,5,7},{4,1,8,3}};
    std::cout << minimumTotal(vect) << std::endl;
    return (0);
}