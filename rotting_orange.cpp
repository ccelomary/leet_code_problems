#include <iostream>
#include <string>
#include <vector>
#include <queue>

// Rotting
int orangesRotting(std::vector<std::vector<int>>& grid)
{
    std::queue<std::pair<int, int>>     q, h;
    int                                 y, x;
    int                                 timer;
    std::pair<int, int>                 position;

    timer = -1;
    for (y = 0; y < grid.size(); y++)
    {
        for (x = 0; x < grid[y].size(); x++)
        {
            if (grid[y][x] == 2)
                q.push(std::make_pair(x, y));
        }
    }
    while (!q.empty())
    {
        timer++;
        while (!q.empty())
        {
            position = q.front();
            q.pop();
            x = position.first;
            y = position.second;
            if (x - 1 >= 0 && grid[y][x - 1] == 1)
            {
                h.push(std::make_pair(x - 1, y));
                grid[y][x - 1] = 2;
            }
            if (x + 1 < grid[y].size() && grid[y][x + 1] == 1)
            {
                h.push(std::make_pair(x + 1, y));
                grid[y][x + 1] = 2;
            }
            if (y - 1 >= 0 && grid[y - 1][x] == 1)
            {
                h.push(std::make_pair(x, y - 1));
                grid[y - 1][x] = 2;
            }
            if (y + 1 < grid.size() && grid[y + 1][x] == 1)
            {
                h.push(std::make_pair(x, y + 1));
                grid[y + 1][x] = 2;
            }
        }
        while (!h.empty())
        {
            q.push(h.front());
            h.pop();
        }
    }
    for (y = 0; y < grid.size(); y++)
    {
        for (x = 0; x < grid[y].size(); x++)
        {
            if (grid[y][x] == 1)
                return (-1);
        }
    }
    return (timer);
}

int     main(void)
{
    std::vector<std::vector<int> > v = {{2,1,1},{1,1,0},{0,1,1}};
    std::cout << orangesRotting(v) << std::endl;
    return (0);
}