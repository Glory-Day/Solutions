#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> map;

int getDistance(pii& a, pii& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int dfs(int b, int e) {
    int answer = INT_MAX;
    
    int d = e - b + 1;
    if (d <= 3) {
        for (int i = b; i < e; i++) {
            for (int j = i + 1; j <= e; j++) {
                answer = min(answer, getDistance(map[i], map[j]));
            }
        }
    }
    else {
        int mid = (b + e) / 2;
        int l = dfs(b, mid - 1);
        int r = dfs(mid + 1, e);
        answer = min(l, r);

        vector<pii> ds;
        ds.push_back({ map[mid].second,map[mid].first });

        for (int i = mid - 1; i >= b; i--) {
            if ((map[mid].first - map[i].first) * (map[mid].first - map[i].first) >= answer) break;
            ds.push_back({ map[i].second,map[i].first });
        }

        for (int i = mid + 1; i <= e; i++) {
            if ((map[mid].first - map[i].first) * (map[mid].first - map[i].first) >= answer) break;
            ds.push_back({ map[i].second,map[i].first });
        }

        sort(ds.begin(), ds.end());

        for (int i = 0; i < ds.size() - 1; i++) {
            for (int j = i + 1; j < ds.size(); j++) {
                if ((ds[i].first - ds[j].first) * (ds[i].first - ds[j].first) >= answer) break;
                answer = min(answer, getDistance(ds[i], ds[j]));
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        map.push_back({ a,b });
    }

    sort(map.begin(), map.end());

    int answer = dfs(0, n - 1);

    cout << answer;
}