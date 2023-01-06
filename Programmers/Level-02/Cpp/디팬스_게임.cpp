#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    int sum = 0;
    int m = enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++) {
        pq.push(enemy[i]);

        if (pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }

        if (sum > n) {
            return i;
        }
    }

    answer = m;

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    int m;
    cin >> m;

    vector<int> enemy;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        enemy.push_back(input);
    }

    int answer = solution(n, k, enemy);

    cout << answer;
}