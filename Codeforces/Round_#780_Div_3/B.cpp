#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/*
    문제 설명: 사탕의 종류 개수가 주어지고, 종류별 사탕의 개수들이 주어진다.
    사탕을 먹을 때 매번 다른 종류의 사탕을 먹어야한다. 
    위 행동이 가능한지의 유무를 출력한다.

    풀이: 매번 다른 종류의 사탕을 먹을려면 사탕들의 개수들의 차가 0이나 1이여야한다.
    만약 차가 2이상일 경우에는 매번 다른 사탕을 먹을 수 없다.
*/

int arr[200001];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + n + 1);

        if (arr[n] - arr[n - 1] > 1) cout << "NO\n";
        else cout << "YES\n";
    }
}