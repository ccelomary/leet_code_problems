#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>

#define MAX(A, B) (((A.second - A.first) > (B.second - B.first)) ? A : B)

std::string longestPalindrome(std::string s)
{
    int             _max;
    std::pair<int, int>     positions;
    int             y, x;
    int             length_s;
    int             *table;
    std::string     subs;

    length_s = s.length();
    table = new int[length_s * length_s];
    _max = 0;
    memset(table, 0, sizeof(int) * (length_s * length_s));
    subs = "";
    for (x = 0; x < length_s; x++)
        table[x * length_s + x] = 1;
    for (y = length_s - 1; y >= 0; y--)
    {
        for (x = length_s - 1; x > y; x--)
        {
            if (s[x] == s[y])
            {
                if (x - 1 == y)
                    table[y * length_s + x] = 1;
                else if (x >= 2 && y <= length_s - 2)
                    table[y * length_s + x] = table[(y + 1) * length_s + x - 1];
            }
            if (x - y > _max && table[y * length_s + x])
            {
                _max = x - y;
                positions.first = y;
                positions.second = x;
            }
        }
    }
    for (y = 0; y < length_s; y++)
    {
        for (x = 0; x < length_s; x++)
            std::cout << table[y * length_s + x] << " ";
        std::cout << "\n";
    }
    delete table;
    while (positions.first <= positions.second)
    {
        subs += s[positions.first];
        positions.first++;
    }
    return (subs);
}

int     main(void)
{
    std::cout << longestPalindrome("abcd") << "\n";
    return (0);
}
