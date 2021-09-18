#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<std::string> letterCasePermutation(std::string s)
{
    std::vector<std::string>        vect_s;
    std::vector<std::string>        nested;
    if (!s.length())
        return {""};
    nested = letterCasePermutation(s.substr(1, std::string::npos));
    for (std::string str: nested)
    {
        if (isalpha(s[0]))
        {
            vect_s.push_back((char)toupper(s[0]) + str);
            vect_s.push_back((char)tolower(s[0]) + str);
        }
        else
            vect_s.push_back(s[0] + str);
    }
    return (vect_s);
}

int         main(void)
{
    std::vector<std::string>    vect = letterCasePermutation("a4b");
    for (std::string s: vect)
        std::cout << s << "\n";
    return (0);
}