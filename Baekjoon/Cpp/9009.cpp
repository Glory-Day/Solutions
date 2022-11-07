#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> cache = { 0,1 };

        int idx = 2;
        while (cache.back() < n) {
            cache.push_back(cache[idx - 1] + cache[idx - 2]);
            idx++;
        }

        vector<int> answer;
        while (n) {
            for (auto it = cache.rbegin(); it != cache.rend(); it++) {
                if (n >= (*it)) {
                    n -= (*it);
                    answer.push_back(*it);
                }
            }
        }

        for (int i = answer.size() - 2; i >= 0; i--) {
            cout << answer[i] << ' ';
        }

        cout << '\n';
    }
}