#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int cache[200001];
int map[200001];

int find(int nd) {
    if (map[nd] == nd) return nd;
    return map[nd] = find(map[nd]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);

    if (a != b) {
        if (cache[a] < cache[b]) swap(a, b);
        cache[a] += cache[b];
        map[b] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        fill(cache, cache + 200000, 1);
        for (int i = 0; i < 200001; i++) map[i] = i;

        unordered_map<string, int> mp;
        
        int cnt;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;

            if (mp.count(a) == 0) mp[a] = cnt++;
            if (mp.count(b) == 0) mp[b] = cnt++;

            unite(mp[a], mp[b]);

            cout << max(cache[find(mp[a])], cache[find(mp[b])]) << '\n';
        }
    } 
}