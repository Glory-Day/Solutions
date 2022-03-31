#include <iostream>
#include <cmath>

using namespace std;

int n, m;
int arr1[30], arr2[7];
int cache[31][15001];

void f(int k, int w) {
    if (k > n) return;
    if (cache[k][w] != -1) return;

    cache[k][w] = 1;

    f(k + 1, w + arr1[k]);
    f(k + 1, w);
    f(k + 1, abs(w - arr1[k]));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    fill(cache[0], cache[31], -1);
    f(0, 0);

    for (int i = 0; i < m; i++) {
        if (arr2[i] > 15000) cout << "N ";
        else if (cache[n][arr2[i]] == 1) cout << "Y ";
        else cout << "N ";
    }
}