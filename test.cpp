#include <iostream>
#include <tuple>
#include  <string>

int     main(void)
{
    std::string     s = "mohamed";
    std::cout << s.substr(1, std::string::npos) << "\n";
    return (0);
}