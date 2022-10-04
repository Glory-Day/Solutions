#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <utility>

#define MAX 987654321

using namespace std;

typedef long long ll;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    ll answer = 0;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, MAX));

    for (int i = 0; i < fares.size(); i++) {
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][k] == MAX || map[k][j] == MAX) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    ll dest[3] = { map[s][a] + map[a][b],map[s][b] + map[b][a],map[s][a] + map[s][b] };
    answer = min(dest[0], min(dest[1], dest[2]));

    for (int i = 1; i <= n; i++) {
        if (i == s || i == a || i == b) continue;
        answer = min(answer, (ll)(map[s][i] + map[i][a] + map[i][b]));
    }

    return answer;
}

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;

    int m;
    cin >> m;

    vector<vector<int>> fares;
    for (int i = 0; i < m; i++) {
        int c, d, e;
        cin >> c >> d >> e;

        fares.push_back({ c,d,e });
    }

    int answer = solution(n, s, a, b, fares);

    cout << answer;
}