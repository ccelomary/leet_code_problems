#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <limits>
#include <utility>

std::vector<std::vector<int> > updateMatrix(std::vector<std::vector<int> >& mat)
{
    std::queue<std::pair<int, int> >    pr;
    int                                 y, x;
    std::pair<int, int>                 position;
    for (y = 0; y < mat.size(); y++)
    {
        for (x = 0; x < mat[y].size(); x++)
        {
            if (mat[y][x] == 0)
                pr.push(std::make_pair(x, y));
            else
                mat[y][x] = -1;
        }
    }
    while (!pr.empty())
    {
        position = pr.front();
        pr.pop();
        y = position.second;
        x = position.first;
        if (x - 1 >= 0 && mat[y][x - 1] == -1)
        {
            pr.push(std::make_pair(x - 1, y));
            mat[y][x - 1] = mat[y][x] + 1;
        }
        if (x + 1 < mat[y].size() && mat[y][x + 1] == -1)
        {
            pr.push(std::make_pair(x + 1, y));
            mat[y][x + 1] = mat[y][x] + 1;
        }
        if (y - 1 >= 0 && mat[y - 1][x] == -1)
        {
            pr.push(std::make_pair(x, y - 1));
            mat[y - 1][x] = mat[y][x] + 1;
        }
        if (y + 1 < mat.size() && mat[y + 1][x] == -1)
        {
            pr.push(std::make_pair(x, y + 1));
            mat[y + 1][x] = mat[y][x] + 1;
        }
    }
    return (mat);
}

int     main(void)
{
    std::vector<std::vector<int> > mat = {{0, 0, 0}, {1, 1, 1}, {1, 1, 1}};
    std::vector<std::vector<int> > matrix;
    matrix = updateMatrix(mat);
    for (int i = 0; i  < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    return (0);
}

/*
{
{1,0,1,1,0,0,1,0,0,1},
{0,1,1,0,1,0,1,0,1,1},
{0,0,1,0,1,0,0,1,0,0},
{1,0,1,0,1,1,1,1,1,1},
{0,1,0,1,1,0,0,0,0,1},
{0,0,1,0,1,1,1,0,1,0},
{0,1,0,1,0,1,0,0,1,1},
{1,0,0,0,1,1,1,1,0,1},
{1,1,1,1,1,1,1,0,1,0},
{1,1,1,1,0,1,0,0,1,1}};
[
[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,1,1,1,0,1],
[1,1,1,1,1,1,1,0,1,0],
[1,1,1,1,0,1,0,0,1,1]]

[
[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,2,1,1,0,1],
[2,1,1,1,1,2,1,0,1,0],
[3,3,2,1,0,1,0,0,1,1]]

[
[1,0,1,1,0,0,1,0,0,1],
[0,1,1,0,1,0,1,0,1,1],
[0,0,1,0,1,0,0,1,0,0],
[1,0,1,0,1,1,1,1,1,1],
[0,1,0,1,1,0,0,0,0,1],
[0,0,1,0,1,1,1,0,1,0],
[0,1,0,1,0,1,0,0,1,1],
[1,0,0,0,1,2,1,1,0,1],
[2,1,1,1,1,2,1,0,1,0],
[3,2,2,1,0,1,0,0,1,1]]






*/