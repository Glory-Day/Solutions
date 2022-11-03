#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    int n = cookie.size();
    cookie.insert(cookie.begin(), 0);

    vector<int> cache(n + 1);
    for (int i = 1; i <= n; i++) {
        cache[i] = cache[i - 1] + cookie[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = 2 * cache[j] - cache[i - 1];
            int idx = lower_bound(cache.begin(), cache.end(), tmp) - cache.begin();
            if (idx <= n && cache[idx] == tmp) {
                answer = max(cache[j] - cache[i - 1], answer);
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> cookie;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cookie.push_back(input);
    }

    int answer = solution(cookie);

    cout << answer;
}