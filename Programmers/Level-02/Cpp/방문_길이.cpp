#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool visited[11][11][11][11];

bool check(pii p) {
    return 0 <= p.first && p.first <= 10 && 0 <= p.second && p.second <= 10;
}

int solution(string dirs) {
    int answer = 0;

    map<char, pii> directions;
    directions.insert({ 'U',{ 0,1 } });
    directions.insert({ 'D',{ 0,-1 } });
    directions.insert({ 'R',{ 1,0 } });
    directions.insert({ 'L',{ -1,0 } });

    pii p = { 5,5 };
    for (auto i: dirs) {
        pii np = { p.first + directions[i].first,p.second + directions[i].second };

        if (!check(np)) {
            continue;
        }

        if (!visited[p.first][p.second][np.first][np.second] && !visited[np.first][np.second][p.first][p.second]) {
            visited[p.first][p.second][np.first][np.second] = true;
            visited[np.first][np.second][p.first][p.second] = true;
            answer++;
        }

        p = np;
    }

    return answer;
}

int main() {
    string dirs;
    cin >> dirs;

    int answer = solution(dirs);

    cout << answer;
}