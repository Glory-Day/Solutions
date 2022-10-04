#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c;
vector<int> arr;

void dfs(int b, int e, int sum, vector<int>& v) {
    if (sum > c) return;

    if (b > e) {
        v.push_back(sum);
        return;
    }

    dfs(b + 1, e, sum, v);
    dfs(b + 1, e, sum + arr[b], v);
}

int main() {
    int n;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    vector<int> v1, v2;
    dfs(0, n / 2 - 1, 0, v1);
    dfs(n / 2, n - 1, 0, v2);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int e = v2.size() - 1, answer = 0;
    for (int b = 0; b < v1.size(); b++) {
        while (e >= 0 && v1[b] + v2[e] > c) e--;
        answer += e + 1;
    }

    cout << answer;
}