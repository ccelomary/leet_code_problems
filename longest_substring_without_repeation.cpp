#include <iostream>
#include <string>
#include <cstring>

int lengthOfLongestSubstring(std::string s) {
	int max_ = 0;
    int  pos_a;
    int  pos_b;

	int faced_char_position[127];
	memset(faced_char_position, -1, 127 * sizeof(int));
	pos_a = 0;
    pos_b = 0;
    while (pos_b < s.length())
    {
        if (faced_char_position[s[pos_b]] >= pos_a && pos_b)
        {
            max_ = std::max(max_, pos_b - pos_a);
            pos_a = faced_char_position[s[pos_b]] + 1;
        }
        faced_char_position[s[pos_b]] = pos_b;
        pos_b++;
    }
    max_ = std::max(max_, pos_b - pos_a);
	return (max_);
}

int     main(void)
{
    std::cout <<  lengthOfLongestSubstring("1232"
) << std::endl;
	return (0);
}
