#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;

    int tmp = 0;
    function<void(long long, long long, int)> dfs = [&](long long b, long long length, int lv) {
        if (b > length) {
            return;
        }

        long long e;
        if (lv != n) {
            e = b + 5;
            for (long long i = b; i < e; i++) {
                if (i == b + 2) {
                    continue;
                }

                dfs(i * 5, length, lv + 1);
            }
        }
        else {
            if (b <= length && length < b + 5) {
                e = length;

                for (long long i = b; i < e; i++) {
                    if (i == b + 2) {
                        continue;
                    }

                    tmp++;
                }
            }
            else {
                tmp += 4;
            }
        }
    };

    dfs(0, r, 1);

    answer = tmp;
    tmp = 0;

    dfs(0, l - 1, 1);

    answer -= tmp;

    return answer;
}

int main() {
    int n;
    long long l, r;
    cin >> n >> l >> r;

    int answer = solution(n, l, r);

    cout << answer;
}