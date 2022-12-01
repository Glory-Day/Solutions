#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool cmp(const pii& a, const pii& b) {
    if (a.second == b.second) {
        return a.first < a.second;
    }

    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    map<int, int> mp;
    for (int i = 0; i < tangerine.size(); i++) {
        if (mp.find(tangerine[i]) != mp.end()) {
            mp[tangerine[i]]++;
        }
        else {
            mp[tangerine[i]] = 1;
        }
    }

    vector<pii> cache(mp.begin(), mp.end());
    sort(cache.begin(), cache.end(), cmp);

    while (k > 0) {
        k -= cache.back().second;
        cache.pop_back();
        answer++;
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tangerine;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        tangerine.push_back(input);
    }

    int answer = solution(k, tangerine);

    cout << answer;
}