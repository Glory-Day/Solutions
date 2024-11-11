#include <iostream>
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

int main()
{
    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    vector<int> answer = solution(k, score);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}