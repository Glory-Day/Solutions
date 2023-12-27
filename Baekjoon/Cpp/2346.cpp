#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    deque<pii> dq;
    for (int i = 0; i < n ; i++) {
        int a;
        cin >> a;
        dq.push_back({ a,i + 1 });
    }

    vector<int> answer;
    do {
        int a = dq.front().first;
        int b = dq.front().second;
        
        dq.pop_front();
        if (a < 0) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        pii tmp;
        for (int i = 1; i < abs(a); i++) {
            if (a > 0) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        answer.push_back(b);
    }
    while (dq.empty() == false);

    for (int& i: answer) {
        cout << i << ' ';
    }
}