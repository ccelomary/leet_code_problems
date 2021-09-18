#include <iostream>

int hammingWeight(uint32_t n)
{
    int total = 0;
    for (int i = 0; i < 32;total+= static_cast<bool>(n & (1<<i)), i++);
    return (total);       
}


int         main(void)
{
    std::cout << hammingWeight(00000000000000000000000000001011) << std::endl;
    return (0);
}