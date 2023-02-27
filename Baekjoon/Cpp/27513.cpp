#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, vector<pii>> answer;

    answer.first = n * m;
    if (n % 2 == 1 && m % 2 == 1) {
        answer.first--;
    }
    
    int x = 1, y = 1;
    answer.second.push_back({ x,y });
    for (int i = 0; i < m - 1; i++) {
        answer.second.push_back({ x,++y });
    }
    x++;

    auto f1 = [&]() {
        for (int i = 0; i < n - 1; i++) {
            answer.second.push_back({ x++,y });
        }
        x--;
        y--;
    };

    auto f2 = [&]() {
        f1();

        for (int i = 0; i < n - 1; i++) {
            answer.second.push_back({ x--,y });
        }
        x++;
        y--;
    };

    auto f3 = [&]() {
        answer.second.push_back({ --x,y });
        answer.second.push_back({ x,++y });
        answer.second.push_back({ --x,y });
        answer.second.push_back({ x,--y });
    };

    if (m % 2 == 0) {
        for (int i = 0; i < m; i += 2) {
            f2();
        }
    }
    else {
        for (int i = 0; i < m - 3; i +=2) {
            f2();
        }
        f1();

        if (n % 2 == 0) {
            answer.second.push_back({ x,y-- });
            answer.second.push_back({ x,y });

            for (int i = 0; i < n - 2; i += 2) {
                f3();
            }
        }
        else {
            answer.second.push_back({ x,y });
            answer.second.push_back({ --x,y });
            answer.second.push_back({ x,--y });

            for (int i = 0; i < n - 3; i += 2) {
                f3();
            }
        }
    }

    cout << answer.first << '\n';
    for (auto& i: answer.second) {
        cout << i.first << ' ' << i.second << '\n';
    }
}