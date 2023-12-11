#include <iostream>
#include <vector>
#include <cassert>

int numberOfSeq(std::vector<std::vector<int>> &rhs)
{
    int res = 0;
    int l = rhs.size();
    int w = rhs[0].size();
    std::vector<std::vector<int>> dp(l, std::vector(w, 0));

    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (rhs[i][j] != 1)
            {
                continue;
            }
            dp[i][j] = 1;
            if ((i - 1) >= 0 && (j - 1) >= 0)
            {
                auto min = std::min(std::min(dp[i - 1][j], dp[i][j - 1]),
                                    dp[i - 1][j - 1]);
                if (min > 0)
                {
                    dp[i][j] += min;
                }
            }
            res += dp[i][j];
        }
    }
    return res;
}

int numberOfSeq2(std::vector<std::vector<int>> &rhs)
{
    if (rhs.empty())
    {
        return 0;
    }
    int w = rhs.size();
    int l = rhs[0].size();
    int res = 0;
    std::vector<std::vector<int>> dp(2, std::vector<int>(l, 0));

    for (int x = 0; x < w; ++x)
    {
        for (int y = 0; y < l; ++y)
        {
            if (x == 0)
            {
                if (rhs[x][y] == 1)
                {
                    dp[0][y] = 1;
                }
                res += dp[0][y];
                continue;
            }
            if (rhs[x][y] != 1)
            {
                dp[1][y] = 0;
            }
            else
            {
                dp[1][y] = 1;
                if ((y - 1) >= 0)
                {
                    int min = std::min(dp[0][y - 1],
                                       std::min(dp[0][y], dp[1][y - 1]));
                    if (min > 0)
                    {
                        dp[1][y] += min;
                    }
                }
            }
            res += dp[1][y];
            // UPDATE dp[1]
            dp[0] = dp[1];
        }
    }
    return res;
}

/**
 *   1 0 1 0 1
 *   0 1 1 0 0
 *   0 1 1 1 1
 *   1 0 0 1 1
 */
int main()
{
    std::vector<std::vector<int>> s{
        {1, 0, 1, 0, 1}, {0, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {1, 0, 0, 1, 1}};
    int res = numberOfSeq2(s);
    std::cout << "res = " << res << std::endl;
    return 0;
}
