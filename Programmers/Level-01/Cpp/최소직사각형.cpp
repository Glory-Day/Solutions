#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> size) {
    // 가로, 세로가 주어지면 큰 쪽을 a로 작은 쪽을 b로 바꿔 a, b의 최대값을 구한다.
    int a = -1, b = -1;
    for (auto i: size) {
        if (i[0] < i[1]) {
            swap(i[0], i[1]);
        }

        a = max(a, i[0]);
        b = max(b, i[1]);
    }

    return a * b;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> size;
    for (int i = 0; i < n; i++) {
        vector<int> input(2);
        cin >> input[0] >> input[1];
        size.push_back(input);
    }

    cout << solution(size);
}