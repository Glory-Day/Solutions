#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int idxs[205];
string words[10];
bool visited[10];
vector<int> arr;
vector<string> ss;

void set(int idx) {
    int j = 0;
    for (int i = 1; i < ss[idx].size(); i++) {
        while (j > 0 && ss[idx].at(i) != ss[idx].at(j)) {
            j = idxs[j - 1];
        }

        if (ss[idx].at(i) == ss[idx].at(j)) idxs[i] = ++j;
    }
}

void dfs(int n) {
    if (arr.size() == n) {
        string tmp;

        for (int i = 0; i < arr.size(); i++) {
            tmp.append(words[arr[i]]);
        }

        ss.push_back(tmp);

        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr.push_back(i);
            dfs(n);
            arr.pop_back();
            visited[i] = false;
        }
    }
}

int kmp(int idx) {
    int tmp = 0;
    string a = ss[idx], b = ss[idx];
    a.append(ss[idx]);

    int j = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        while (j > 0 && a.at(i) != b.at(j)) {
            j = idxs[j - 1];
        }

        if (a.at(i) == b.at(j)) {
            if (j == b.size() - 1) {
                tmp++, j = idxs[j];
            }
            else j++;
        }
    }

    return tmp;
}

int main() {
    int n, m;
    cin >> n;

    arr = { 1 };

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }

    dfs(n);

    cin >> m;

    int answer = 0;
    for (int i = 0; i < ss.size(); i++) {
        set(i);
        if (kmp(i) == m) answer += n;
    }

    cout << answer;
}