#include <iostream>
#include <string>
void set_array_to_zero(int *arr)
{
	for (int i = 0; i < 127; i++)
		arr[i] = 0;
}

int lengthOfLongestSubstring(std::string s) {
	size_t max_ = 0;
	size_t current;
	size_t nit;
	int faced_char[127];
	for (size_t it = 0; it < s.length(); it++)
	{
		current = 0;
		set_array_to_zero(faced_char);
		for (nit = it; nit < s.length(); nit++)
		{
             std::cout << faced_char[(int)s[nit]] << std::endl;
			if (faced_char[(int)s[nit]])
			    break;
			faced_char[(int)s[nit]] = 1;
            std::cout << (int)s[nit] << std::endl;
			current++;
		}
		if (max_ < current)
			max_ = current;
	}
	return (max_);
}

int     main(void)
{
    std::cout  << lengthOfLongestSubstring("abcabcbb") << std::endl;
    return (0);
}