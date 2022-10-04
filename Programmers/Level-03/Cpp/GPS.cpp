#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 987654321

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;

    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < m; i++) {
        arr[edge_list[i][0]].push_back(edge_list[i][1]);
        arr[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    vector<vector<int>> cache(k, vector<int>(n + 1, MAX));

    cache[0][gps_log[0]] = 0;
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            int mn = cache[i - 1][j];

            for (int l = 0; l < arr[j].size(); l++) {
                mn = min(cache[i - 1][arr[j][l]], mn);
            }

            if (gps_log[i] != j) {
                cache[i][j] = mn + 1;
            }
            else {
                cache[i][j] = mn;
            }
        }
    }

    answer = cache[k - 1][gps_log[k - 1]];
    if (answer >= MAX) answer = -1;

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge_list;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({ a,b });
    }

    int k;
    cin >> k;

    vector<int> gps_log;
    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        gps_log.push_back(input);
    }

    int answer = solution(n, m, edge_list, k, gps_log);

    cout << answer;
}