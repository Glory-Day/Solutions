#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int b;
        switch (a) {
            case 1:
                cin >> b;
                dq.push_front(b);
                break;
            case 2:
                cin >> b;
                dq.push_back(b);
                break;
            case 3:
                if (dq.empty()) {
                    b = -1;
                }
                else {
                    b = dq.front();
                    dq.pop_front();
                }
                answer.push_back(b);
                break;
            case 4:
                if (dq.empty()) {
                    b = -1;
                }
                else {
                    b = dq.back();
                    dq.pop_back();
                }
                answer.push_back(b);
                break;
            case 5:
                b = dq.size();
                answer.push_back(b);
                break;
            case 6:
                b = dq.empty();
                answer.push_back(b);
                break;
            case 7:
                b = dq.empty() ? -1 : dq.front();
                answer.push_back(b);
                break;
            case 8:
                b = dq.empty() ? -1 : dq.back();
                answer.push_back(b);
                break;
        }
    }

    for (int& i: answer) {
        cout << i << '\n';
    }
}