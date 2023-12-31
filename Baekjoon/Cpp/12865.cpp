#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii arr[101];
int cache[101][100001];

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (arr[i].first <= j) {
                if (arr[i].second + cache[i - 1][j - arr[i].first] > cache[i - 1][j]) {
                    cache[i][j] = arr[i].second + cache[i - 1][j - arr[i].first];
                }
                else cache[i][j] = cache[i - 1][j];
            }
            else cache[i][j] = cache[i - 1][j];
        }
    }

    cout << cache[n][w];
}