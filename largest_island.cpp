#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int length_island(vector<vector<int> > &grid, int posx, int posy, int iceland_id)
    {
        int length;
        map<pair<int, int>, bool> visited;
        stack<pair<int, int> > to_visit;
        to_visit.push(pair<int, int>(posx, posy));
        pair<int, int> current_position;
        length = 0;
        while (!to_visit.empty())
        {
            current_position = to_visit.top();
            to_visit.pop();
            if (visited.find(current_position) != visited.end())
                continue;
            grid[current_position.second][current_position.first] = iceland_id;
            visited.insert(pair<pair<int, int>, bool>(current_position, true));
            if (check_top(current_position.second) && visited.find(pair<int, int>(current_position.first, current_position.second - 1)) == visited.end() && grid[current_position.second - 1][current_position.first])
            {
                to_visit.push(pair<int, int>(current_position.first, current_position.second - 1));
            }
            if (check_bottom(current_position.second, grid.size()) && visited.find(pair<int, int>(current_position.first, current_position.second + 1)) == visited.end() && grid[current_position.second + 1][current_position.first])
            {
                to_visit.push(pair<int, int>(current_position.first, current_position.second  + 1));
            }
            if (check_left(current_position.first) && visited.find(pair<int, int>(current_position.first - 1, current_position.second)) == visited.end() && grid[current_position.second][current_position.first - 1 ])
            {
                to_visit.push(pair<int, int>(current_position.first  - 1, current_position.second));
            }
            if (check_right(current_position.first, grid.size()) && visited.find(pair<int, int>(current_position.first + 1, current_position.second)) == visited.end() && grid[current_position.second][current_position.first + 1])
            {
                to_visit.push(pair<int, int>(current_position.first + 1, current_position.second));
            }
            length++;
        }
        return (length);
                              
    }
    int largestIsland(vector<vector<int>>& grid)
    {
        size_t n = grid.size();
        size_t  x, y;
        int max_island, current_iceland;
        int iceland_id = 2;
        map<int, int> islands_length;
        int             arr[4];
        int current_land_length;
        for (y = 0; y < n; y++)
        {
            for (x = 0; x < n; x++)
            {
                if (grid[y][x] == 1)
                {
                    current_land_length = length_island(grid, x, y, iceland_id);
                    islands_length.insert(pair<int, int>(iceland_id, current_land_length));
                    iceland_id++;
                }
            }
        }
        max_island = 0;
        for (y = 0; y < n; y++)
        {
            for (x = 0; x < n; x++)
            {
                if (!grid[y][x])
                {
                    current_iceland = 0;
                    init_array4(arr);
                    if (check_left(x) && !check_for_id(arr, grid[y][x - 1]))
                    {
                        insert_id(arr, grid[y][x - 1]);
                        current_iceland += islands_length[grid[y][x - 1]];
                    }
                    if (check_right(x, n) && !check_for_id(arr, grid[y][x + 1]))
                    {
                        insert_id(arr, grid[y][x + 1]);
                       current_iceland += islands_length[grid[y][x + 1]];
                    }
                    if (check_top(y) && !check_for_id(arr, grid[y - 1][x]))
                    {
                        current_iceland += islands_length[grid[y - 1][x]];
                        insert_id(arr, grid[y - 1][x]);
                    }
                    if (check_bottom(y, n) && !check_for_id(arr, grid[y + 1][x]))
                    {
                         insert_id(arr, grid[y + 1][x]);
                         current_iceland += islands_length[grid[y + 1][x]];
                    }
                    current_iceland += 1;
                    if (current_iceland > max_island)
                        max_island = current_iceland;
                }
            }
        }
        return ((max_island) ? max_island : n * n);
    }
private:
    bool check_top(int pos_y)
    {
        return (pos_y - 1 >= 0);
    }
    bool    check_bottom(int pos_y, int size_n)
    {
        return (pos_y + 1 < size_n);
    }
    bool    check_left(int pos_x)
    {
        return (pos_x - 1 >= 0);
    }
    bool    check_right(int pos_x, int size_n)
    {
        return (pos_x + 1 < size_n);
    }
    void init_array4(int *arr)
    {
        for (int i = 0; i <  4; i++)
            arr[i] = -1;
    }
    bool    check_for_id(int *arr, int island_id)
    {
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == island_id)
                return (true);
        }
        return (false);
    }
    void    insert_id(int *arr, int island_id)
    {
        static int i = 0;
        arr[i] = island_id;
        i = (i + 1) % 4;
    }
};


int     main(void)
{
    vector<vector<int> > vect;
    vect.push_back(vector<int>{1, 0, 1});
    vect.push_back(vector<int>{0, 0, 0});
    vect.push_back(vector<int>{0, 1, 1});
    Solution s;
    cout << s.largestIsland(vect) << std::endl;
    return (0);
}