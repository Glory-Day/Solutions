#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int answer = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        answer += a + b;
        pq.push(a + b);
    }

    cout << answer;
}