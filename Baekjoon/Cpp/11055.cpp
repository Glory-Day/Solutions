#include <iostream>
#include <algorithm>

using namespace std;

int nums[1001];
int cache[1001];
int answer[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && cache[j] >= cache[mx]) {
                answer[i] = max(answer[j] + nums[i], answer[i]);
                mx = j;
            }
        }
        cache[i] = cache[mx] + 1;
    }

    sort(answer, answer + n + 1);
    cout << answer[n];
}