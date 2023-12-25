#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (v[i] == false) {
            dq.push_back(a);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        dq.push_front(a);

        cout << dq.back() << ' ';

        dq.pop_back();
    }
}