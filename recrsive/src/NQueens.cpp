#include <iostream>
#include <vector>
#include <string>

/**
 * \brief 将 n 个皇后摆放再 N * N 的棋盘中， 互相不可攻击，有多少种不同的摆放方式，方式是怎样？
 *  每一个皇后的上下左右斜线不相交
 */

class Solution {
public:
    static std::vector<std::vector<std::string>> solveNQueue(int n) {
        // 最终的结果
        std::vector<std::vector<std::string>> res;
        // 标记影响
        std::vector<std::vector<int>> mark;
        // 存储某一次摆放的结果
        std::vector<std::string> location;
        mark.reserve(n);
        for (int i = 0; i < n; ++i) {
            mark.emplace_back();
            mark[i].reserve(n);
            for (int j = 0; j < n; ++j) {
                mark[i].push_back(0);
            }
            location.emplace_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, res, mark);
        return res;
    }

private:
    static void generate(int k, int n,
                         std::vector<std::string>& location,
                         std::vector<std::vector<std::string>>& result,
                         std::vector<std::vector<int>>& mark) {
        if (k == n) {
            result.push_back(location);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (mark[k][i] == 0) {
                const std::vector<std::vector<int>> tmp_mark = mark;
                location[k][i] = 'Q';
                putOneQueue(k, i, mark);
                generate(k + 1, n, location, result, mark);
                mark = tmp_mark;
                location[k][i] = '.';
            }
        }
    }

    /**
     * \brief 放入一个还皇后对后续皇后的影响，会对后续可放入性产生影响
     * \param x
     * \param y
     * \param mark
     *
     *               X 坐标的八个方向的变化
     *
     *              (-1,-1) (-1, 0) (-1,1)
     *              (0, -1)    X    (0, 1)
     *              (1, -1) (1,  0) (1, 1)
     */
    static void putOneQueue(int x, int y, std::vector<std::vector<int>>& mark) {
        constexpr const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        constexpr const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for (int i = 0; i < mark.size(); ++i) {
            for (int j = 0; j < 8; ++j) {
                const int new_x = x + i * dx[j];
                const int new_y = y + i * dy[j];
                // 检查新位置是否在棋盘内
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};


int main() {
    // 8 皇后有 92 种放置方法
    const auto res = Solution::solveNQueue(8);
    std::cout << "put way = " << res.size() << std::endl;
    for (const auto& form: res) {
        for (const auto& line: form) {
            std::cout << line << std::endl;
        }
        std::cout << "===========================" << std::endl;
    }
    return 0;
}
