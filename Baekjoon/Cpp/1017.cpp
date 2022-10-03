#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

struct _matched {
    int a[51], b[51];
} matched;

bool cache[2001];
bool visited[51];
vector<int> map[51];

void eratosSieve() {
    fill(cache, cache + 2000, true);
    
    cache[0] = cache[1] = false;
    for (int i = 2; i <= 2000; i++) {
        for (int j = 2; i * j <= 2000; j++) {
            cache[i * j] = false;
        }
    }
}

bool dfs(int n) {
    if (visited[n]) return false;

    visited[n] = true;
    for (auto i: map[n]) {
        if (matched.b[i] == -1 || dfs(matched.b[i])) {
            matched.a[n] = matched.b[n] = i;
            matched.a[i] = matched.b[i] = n;
            return true;
        }
    }

    return false;
}

void bipartiteMatch(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cache[arr[i] + arr[j]]) {
                map[i].push_back(j);
                map[j].push_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    eratosSieve();
    bipartiteMatch(arr);

    vector<int> answer;
    for (auto i: map[0]) {
        fill(matched.a, matched.a + 50, -1);
        fill(matched.b, matched.b + 50, -1);

        matched.a[0] = matched.b[0] = i;
        matched.a[i] = matched.b[i] = 0;

        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (matched.a[j] == -1) {
                fill(visited, visited + 50, false);
                visited[0] = visited[i] = true;

                if (dfs(j)) cnt++;
            }
        }

        if (cnt == n / 2) answer.push_back(arr[i]);
    }

    sort(answer.begin(), answer.end());

    if (answer.size()) for (auto& i: answer) cout << i << ' ';
    else cout << -1;
}