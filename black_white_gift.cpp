#include <iostream>
#include <vector>

long taumBday(int b, int w, int bc, int wc, int z) {
    long best_price_w;
    long best_price_b;

    if (bc + z < wc)
    {
        best_price_w = bc + z;
        best_price_b = bc;
    }
    else if (wc + z < bc)
    {
        best_price_b = wc + z;
        best_price_w = wc;
    }
    else
    {
        best_price_b = bc;
        best_price_w = wc;
    }
    return (b * best_price_b + w * best_price_w);
}



int     climbstrais(int n)
{
    if (n == 1 || n == 2)
        return (n);
    int a = 1;
    int b = 2;
    int tmp;
    for (int i = 2; i < n; i++)
    {
        tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

/*


                5
            4      3
        3     2   2   1
                 1  0 -1 0
            -1 0
*/

int     main(void)
{
    int     n = 8;
    std::cout << climbstrais(n) << std::endl;
    return (0);
}