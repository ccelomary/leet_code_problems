#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int> > combine(int n, int k)
{
    std::vector<std::vector<int> >  collection;
    std::vector<std::vector<int> >  nested;
    if (k == 0)
        return {{}};
    while (n > 0)
    {
        nested = combine(n - 1, k - 1);
        for (std::vector<int> numbers: nested)
        {
            numbers.push_back(n);
            collection.push_back(numbers);
        }
        n--;
    }
    return (collection);
}
int     main(void)
{ 
    std::vector<std::vector<int> > comb = combine(4, 2);
    for (int i = 0; i < comb.size(); i++)
    {
        for (int j = 0; j < comb[i].size(); j++)
            std::cout << comb[i][j] << " ";
        std::cout << "\n";
    }
    return (0);
}