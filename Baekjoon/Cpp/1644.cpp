#include <iostream>
#include <vector>

using namespace std;

vector<int> eratos(int n) {
    vector<bool> arr(n + 1, true);

    arr[0] = arr[1] = false;

    int idx = 2;
    while (idx <= n) {
        if (!arr[idx]) {
            idx++;
            continue;
        }

        for (int i = 2; idx * i <= n; i++) {
            arr[idx * i] = false;
        }

        idx++;
    }

    vector<int> ps;
    for (int i = 0; i <= n; i++) {
        if (arr[i]) ps.push_back(i);
    }

    return ps;
}

int main() {
    int n;
    cin >> n;

    vector<int> ps = eratos(n);

    int answer = 0, len = ps.size();
    int b = 0, e = 0, sum = 0;
    while (b <= e) {
        if (sum >= n) sum -= ps[b++];
        else if (e == len) break;
        else sum += ps[e++];

        if (sum == n) answer++;
    }

    cout << answer;
}