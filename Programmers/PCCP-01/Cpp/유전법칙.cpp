#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(int group, int index, int level) {
    if (level == 2) {
        return index;
    }

    int ret = dfs(group / 4, group % 4, level - 1);
    if (ret == 1 || ret == 2) {
        return index;
    }

    return ret;
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    string cases[4] = { "RR","Rr","Rr","rr" };

    for (auto& query: queries) {
        int group = (query[1] - 1) / 4;
        int index = (query[1] - 1) % 4;

        if (query[0] == 1) {
            answer.push_back("Rr");
        }
        else {
            answer.push_back(cases[dfs(group, index, query[0])]);
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> queries;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({ a,b });
    }

    vector<string> answer = solution(queries);

    for (auto& i: answer) {
        cout << i << '\n';
    }
}