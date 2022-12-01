#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    priority_queue<int> pq;
    for (int i = 0; i < score.size(); i++) {
        pq.push(-score[i]);
        
        if (k < pq.size()) {
            pq.pop();
        }

        answer.push_back(-pq.top());
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> score;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        score.push_back(input);
    }

    vector<int> answer = solution(k, score);

    for (auto i: answer) {
        cout << i << ' ';
    }
}