#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> k >> n;
        
        int tmp = 1;
        vector<int> answer = { 1 };
        for (int i = 1; i < k; i++) {
            if (n - (answer[i - 1] + tmp) >= k - (i + 1)) {
                answer.push_back(answer[i - 1] + tmp);
                tmp++;
            }
            else {
                answer.push_back(answer[i - 1] + 1);
            }
        }

        for (int i = 0; i < k; i++) {
            cout << answer[i] << ' ';
        }

        cout << '\n';
    }
}