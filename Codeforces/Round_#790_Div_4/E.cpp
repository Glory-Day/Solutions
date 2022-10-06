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
    문제 설명: 수열과 쿼리가 주어진다. 
    수열의 수 중 몇개를 임의로 선택해서 그 합이 쿼리의 숫자보다 크거나 같아야한다.
    선택한 숫자들의 개수를 최소로 해야할때 쿼리의 답을 출력한다.

    풀이: 숫자를 선택하는 개수를 최소로 하기위해서는 가장 큰 숫자를 선택해야한다.
    따라서 수열을 내림차순으로 정렬한 뒤에 구간마다 더한다.
    위의 과정을 거치면 수열은 오름차순으로 정렬된 상태임으로 이진탐색(Lower Bound)를 통해서 최소가 되는 위치를 구하면 된다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        vector<int> qs;
        for (int i = 0; i < q; i++) {
            int input;
            cin >> input;
            qs.push_back(input);
        }

        sort(arr.begin(), arr.end(), greater<int>());

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < q; i++) {
            int idx = lower_bound(arr.begin(), arr.end(), qs[i]) - arr.begin() + 1;
            if (n + 1 == idx) cout << -1 << '\n';
            else cout << idx << '\n';
        }
    }
}