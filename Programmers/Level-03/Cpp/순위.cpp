#include <iostream>
#include <vector>

using namespace std;

bool map[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 0; i < results.size(); i++){
        map[results[i][0]][results[i][1]] = true;
    }

    for(int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (map[i][k] && map[k][j]){
                    map[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 1; j <= n; j++){
            if (map[i][j] || map[j][i]){
                count++;
            }
        }
        
        if (count == n - 1){
            answer++;
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> results;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        results.push_back({ a,b });
    }

    int answer = solution(n, results);

    cout << answer;
}