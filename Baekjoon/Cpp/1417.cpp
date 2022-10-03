#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n, tmp;
    cin >> n >> tmp;

    priority_queue<int> pq;
    for (int i = 0; i < n - 1; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    int answer = 0;
    while (!pq.empty() && tmp <= pq.top()) {
        int mx = pq.top();
        pq.pop();
        pq.push(mx - 1);
        tmp++, answer++;
    }

    cout << answer;
}