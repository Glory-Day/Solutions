#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<bool> visited;

bool dfs(string nd, vector<vector<string>>& tickets, vector<string>& answer, int lv) {
    answer.push_back(nd);

    if (lv == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == nd && !visited[i]) {
            visited[i] = true;

            if (dfs(tickets[i][1], tickets, answer, lv + 1)) return true;
            else visited[i] = false;
        }
    }

    answer.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());

    visited = vector<bool>(tickets.size(), false);
    dfs("ICN", tickets, answer, 0);

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> tickets;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        tickets.push_back({ a,b });
    }

    vector<string> answer = solution(tickets);

    for (auto& i: answer) {
        cout << i << ' ';
    }
}