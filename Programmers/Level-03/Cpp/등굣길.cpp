#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> map(n+1, vector<int>(m+1, 1));
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];

        map[y][x] = 0;

        if (x == 1) {
            for (int j = y; j <= n; j++) {
                map[j][1] = 0;
            }
        }

        if (y == 1) {
            for (int j = x; j <= m; j++) {
                map[1][j] = 0;
            }
        }
    }

    for(int y = 2; y <= n; y++) {
        for(int x = 2; x <= m; x++) {
            if(!map[y][x]) continue;

            map[y][x] = (map[y - 1][x] + map[y][x - 1]) % 1000000007;
        }
    }

    answer = map[n][m];

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<vector<int>> puddles;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        puddles.push_back({ a,b });
    }

    int answer = solution(m, n, puddles);

    cout << answer;
}