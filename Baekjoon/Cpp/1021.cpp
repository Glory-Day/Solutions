#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    int i = 0;
    int answer = 0;
    while (i < m) {
        bool check = true;
        int l = 0, r = dq.size() - 1;
        while (l < r) {
            if (dq[l] == v[i]) {
                check = true;
                break;
            }
            else if (dq[r] == v[i]) {
                check = false;
                break;
            }
            l++;
            r--;
        }

        if (check) {
            while (dq.front() != v[i]) {
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
            dq.pop_front();
        }
        else {
            while (dq.back() != v[i]) {
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
            dq.push_front(dq.back());
            dq.pop_back();
            dq.pop_front();
            answer++;
        }

        i++;
    }

    cout << answer;
}