#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int DP(std::vector<int> &need, std::vector<int> &value, int N, int M) {

    std::vector<int> p(M + 1, 0);
    std::vector<int> q(M + 1, 0);
    for (int i = 0; i < N; ++i) {//下标问题需要特别注意
        for (int j = 0; j <= M; ++j) {
            if (i % 2 == 1) {
                if (j < need[i]) {
                    q[j] = p[j];
                } else {
                    q[j] = std::max(p[j], p[j - need[i]] + value[i]);
                }
            } else {
                if (j < need[i]) {
                    p[j] = q[j];
                } else {
                    p[j] = std::max(q[j], q[j - need[i]] + value[i]);
                }
            }
        }
    }

    return std::max(q[M], p[M]);

}

int DP2(std::vector<int> &need, std::vector<int> &value, int N, int M) {
    std::vector<int> f(M + 1, 0);
    for (int i = 0; i < N; ++i) {//N件商品
        for (int j = M; j >= 0; --j) {
            if (j >= need[i]) {
                f[j] = std::max(f[j - need[i]] + value[i], f[j]);
                //曾经错误的方式，因为下面的方式我没有办法保证每一次f[j]都比f[j-need[i]]+value[i]小
                //f[j] = f[j - need[i]] + value[i];
            }
//            else {
//                f[j] = f[j];
//            }
        }
    }
//    for (auto i = f.begin(); i != f.end(); ++i) {
//        std::cout << *i << " ";
//    }
//    std::cout << std::endl;
    return f[M];
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int count, money;
    iss >> count;
    iss >> money;

    std::vector<int> need;
    std::vector<int> value;

    for (int i = 0; i < count; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int n, v;
        iss >> n;
        iss >> v;
        need.push_back(n);
        value.push_back(v);
    }

    int res1, res2;
//    res1 = DP(need, value, count, money);
    res2 = DP2(need, value, count, money);

//    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}