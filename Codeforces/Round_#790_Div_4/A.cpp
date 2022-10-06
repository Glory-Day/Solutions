#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
    문제 설명: 6자리 문자열이 주어진다. 
    처음 3자리의 합과 마지막 3자리의 합이 같은지 출력한다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int a = 0, b = 0;
        for (int i = 0; i < 3; i++) {
            a += (s[i] - '0');
        }

        for (int i = 3; i < 6; i++) {
            b += (s[i] - '0');
        }

        if (a == b) cout << "YES\n";
        else cout << "NO\n";
    }
}