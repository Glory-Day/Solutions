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
    문제 설명: 수열이 주어진다. 수열의 수를 하나 빼는 연산을 할 수 있다.
    연산을 몇번째해서 모든 수열의 수를 같게 만들 수 있는지 줄력한다.

    풀이: 수열 중에서 가장 작은 수를 구한다. 그 다음 다른 수열의 수의 차를 더해주면 된다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end());

        int answer = 0;
        int mn = arr.front();
        for (int i = 0; i < n; i++) {
            if (arr[i] > mn) answer += arr[i] - mn;
        }

        cout << answer << '\n';
    }
}