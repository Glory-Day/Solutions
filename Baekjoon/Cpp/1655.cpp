#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (mx.empty() || mx.size() == mn.size()) {
            mx.push(input);
        }
        else {
            mn.push(input);
        }

        if (!mx.empty() && !mn.empty() && mx.top() > mn.top()) {
            int a = mx.top();
            int b = mn.top();

            mx.pop();
            mx.push(b);

            mn.pop();
            mn.push(a);
        }

        cout << mx.top() << '\n';
    }
}