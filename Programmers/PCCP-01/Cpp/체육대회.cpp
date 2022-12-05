#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int c;
int mx, sum;
bool visited[11];

void dfs(vector<vector<int>>& ability, int lv) {
    if (lv == c) {
        mx = max(mx, sum);
    }

    for (int i = 0; i < ability.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            sum += ability[i][lv];
            dfs(ability, lv + 1);
            sum -= ability[i][lv];
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;

    c = ability[0].size();
    mx = sum = 0;
    fill(visited, visited + 10, false);

    for (int i = 0; i < ability.size(); i++) {
        visited[i] = true;
        sum += ability[i][0];
        dfs(ability, 1);
        sum -= ability[i][0];
        visited[i] = false;
    }

    answer = mx;

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ability;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }
        ability.push_back(inputs);
    }

    int answer = solution(ability);

    cout << answer;
}