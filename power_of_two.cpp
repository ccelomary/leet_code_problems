#include <iostream>

bool isPowerOfTwo(int n)
{
    bool found = false;
    for (int i = 0; i < 32; i++)
    {
        std::cout << (n & (1<< i));
        if ((bool)(n & (1 << i)) == 1)
        {
            if (found)
            {
                return (false);
            }
            found = true;      
        }
    }
    std::cout << "\n";
    return (true);
}

int         main(void)
{
    std::cout << isPowerOfTwo(-4) << std::endl;
    return (0);
}