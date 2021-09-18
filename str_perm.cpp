#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <stack>

bool checkInclusion(std::string s1, std::string s2) {
	int       mp[127], cmp[127];
	size_t     pa, pb;
	size_t     iter;
	memset(mp, 0, 127 * sizeof(int));
	memset(cmp,0, 127 * sizeof(int));
	for (char c: s1)
		mp[c]++;
	pa = 0;
	pb = 0;
	while (pb < s2.length())
	{
		if (pb - pa == s1.length())
		{
			if (!memcmp(mp, cmp, sizeof(int) * 127))
				return (true);
			else
			{
				cmp[s2[pa]]--;
				pa++;
			}
		}
		cmp[s2[pb]]++;
		pb++;
    }
	if (pb - pa == s1.length() && !memcmp(mp, cmp, sizeof(int) * 127))
		return (true);
	return (false);
}

using namespace std;
class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        map<pair<int, int>, bool>       visited;
        stack<pair<int, int> > positions;
        pair<int, int>      position;
        positions.push(make_pair(sc, sr));
        while (!positions.empty())
        {
            position = positions.top();
            positions.pop();
            visited.insert(make_pair(position, true));
            image[position.second][position.first] = newColor;
            if (check_left(position.first, position.second, visited) &&
            image[position.second][position.first - 1] != 0)
            {

                positions.push(make_pair(position.first - 1, position.second));
            }
            if (check_right(position.first, position.second, image[0].size(), visited) &&
               image[position.second][position.first + 1] != 0)
            {
                positions.push(make_pair(position.first + 1, position.second));
            }
            if (check_top(position.first, position.second, visited) &&
               image[position.second - 1][position.first] != 0)
                positions.push(make_pair(position.first, position.second - 1));
            if (check_bottom(position.first, position.second, image.size(), visited) &&
               image[position.second + 1][position.first] != 0)
            {
                std::cout << position.first << " " << position.second << "bottom\n";
                positions.push(make_pair(position.first, position.second + 1));
            }
        }
        return image;
    }
private:
    bool        check_left(int x, int y, const map<pair<int, int>, bool> & visited)
    {
        return (x - 1 >= 0 && visited.find(make_pair(x - 1, y)) == visited.end());
    }
    bool        check_right(int x, int y, int n, const map<pair<int, int>,  bool> & visited)
    {
        return (x + 1 < n && visited.find(make_pair(x + 1, y)) == visited.end());
    }
    bool        check_top(int x, int y, const map<pair<int, int>, bool>  & visited)
    {
        return (y - 1 >= 0 && visited.find(make_pair(x, y - 1)) == visited.end());
    }
    bool        check_bottom(int x, int y, int m, const map<pair<int, int>, bool> & visited)
    {
        return (y + 1 < m && visited.find(make_pair(x, y + 1)) == visited.end());
    }
};

int     main(void)
{
    return (0);
}