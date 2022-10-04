#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0, j = 0; i < n; i++, j++) {
        if (computers[i][j]) {
            answer++;
            
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int nd = q.front();
                q.pop();

                if (!computers[nd][nd]) continue;

                computers[nd][nd] = 0;
                for (int nnd = 0; nnd < n; nnd++) {
                    if (computers[nd][nnd]) {
                        computers[nd][nnd] = 0;
                        q.push(nnd);
                    }
                }
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> computers;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        computers.push_back(temp);
    }

    int answer = solution(n, computers);

    cout << answer;
}