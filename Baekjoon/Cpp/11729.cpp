#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<char, char>> v;

int move(char from, char to) {
    v.push_back({ from,to });
    return 1;
}

int hanoi(int n, char a, char b, char c) {
    int answer = 0;
    if (n == 1) answer += move(a, b);
    else {
        answer += hanoi(n - 1, a, c, b);
        answer += move(a, b);
        answer += hanoi(n - 1, c, b, a);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << hanoi(n, '1', '3', '2') << '\n';
    for (auto i: v) {
        cout << i.first << ' ' << i.second << '\n';
    }
}