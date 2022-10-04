#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll arr1[100001], arr2[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    ll answer = 0;
    ll mn = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        mn = min(mn, arr2[i]);
        answer += (mn * arr1[i]);
    }

    cout << answer;
}