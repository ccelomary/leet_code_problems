#include <iostream>
#include <vector>
#include <string>

bool    IsMatchR(const std::string & s, const std::string & pattern, int s_index, int p_index, std::vector<std::vector<int> > &memo)
{
  if (s.length() <= s_index && pattern.length() <= p_index)
      return (true);
  if (pattern.length() <= p_index)
      return (false);
  if (s.length() > s_index && memo[s_index][p_index] != 2)
      return (memo[p_index][s_index]);
  if (p_index + 1 < pattern.length() && pattern[p_index + 1] == '*')
  {
    memo[s_index][p_index] = (IsMatchR(s, pattern, s_index, p_index + 2, memo) ||
            (s_index < s.length() && (pattern[p_index] == s[s_index] ||
        pattern[p_index] == '.') && IsMatchR(s, pattern, s_index + 1, p_index, memo)));
    return (memo[s_index][p_index]);
  }
  if (s.length() > s_index && (s[s_index] == pattern[p_index] || pattern[p_index] == '.'))
  {
      memo[s_index][p_index] = IsMatchR(s, pattern, s_index + 1,  p_index + 1, memo);
      return (memo[s_index][p_index]);
  }
  if (s.length() > s_index)
    memo[s_index][p_index] = 0;
  return (false);
}

int     main(void)
{
  std::string s = "ab";
  std::string p = "a*b";
  std::vector<std::vector<int>  >   memo(s.length());
  for (int iter= 0; iter <s.length(); iter++)
  {
    std::vector<int>    t(p.length() + 1, 2);
    memo[iter] = t;
  }
  std::cout << IsMatchR(s, p, 0, 0, memo) << std::endl << std::endl;
  for (int i = 0; i < s.length(); i++)
  {
    for (int j = 0; j < p.length(); j++)
    {
      std::cout << memo[i][j] << " " ;
    }
    std::cout << "\n";
  }
	return (0);
}
