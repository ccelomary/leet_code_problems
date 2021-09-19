#include <iostream>

uint32_t reverseBits(uint32_t n)
{
    uint32_t b = 0;
    for (int i = 31; i >= 0; i--)
    {
        b |= ((bool)(n & (1<<i))) << (31 - i);
    }
    return (b);
}


int     main(void)
{
    std::cout << reverseBits(43261596) << std::endl;
    return (0);
}