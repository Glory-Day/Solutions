#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool visited[8];
set<string> st;

bool check(string a, string b) {
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (b[i] == '*') continue;
        if (a[i] != b[i]) return false;
    }

    return true;
}

void dfs(int lv, vector<string>& user_id, vector<string>& banned_id) {
    int answer = 0;

    if (lv == banned_id.size()) {
        string temp = "";
        for (int i = 0; i < user_id.size(); i++) {
            if (visited[i]) temp += user_id[i];
        }
        st.insert(temp);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if (check(user_id[i], banned_id[lv]) && !visited[i]) {
            visited[i] = true;
            dfs(lv + 1, user_id, banned_id);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    dfs(0, user_id, banned_id);

    answer = st.size();

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> user_id;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        user_id.push_back(input);
    }

    cin >> n;

    vector<string> banned_id;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        banned_id.push_back(input);
    }

    int answer = solution(user_id, banned_id);

    cout << answer;
}