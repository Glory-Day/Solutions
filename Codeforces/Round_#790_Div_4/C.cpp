#include <iostream>
#include <climits>
#include <cmath>
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
    문제 설명: n가지 문자열이 주어진다. 임의의 두 문자열 선택해서 같게 만들어야 한다.
    이때 문자열을 같게 만드는 연산을 할 수 있다.
    (1) 문자열의 문자를 바로 전, 후로 바꿀 수 있다.
    (2) 'a' 같은 경우 'b'로만 바꿀 수 있다.
    (3) 'z' 같은 경우 'y'로만 바꿀 수 있다.
    위 연산을 몇번째 수행해서 같게 만드는 최소 수행횟수를 출력한다.

    풀이: 두 문자열을 선택한다. 그 다음 연산횟수를 구한다.
    연산횟수를 변수에 저장한다음 다음 두 문자열의 연산횟수와 비교하면서 최솟값을 구한다.
*/

int f(string a, string b) {
    int sum = 0;
    int len = a.size();
    for (int i = 0; i < len; i++) {
        if (a[i] == 'a') {
            sum += (abs(b[i] - a[i]));
        }
        else if (a[i] == 'z') {
            sum += (abs(a[i] - b[i]));
        }
        else {
            sum += min(abs(b[i] - a[i]), abs(a[i] - b[i]));
        }
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> arr;
        for (int i = 0; i < n; i++) {
            string input;
            cin >> input;
            arr.push_back(input);
        }

        int answer = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                answer = min(answer, f(arr[i], arr[j]));
            }
        }

        cout << answer << '\n';
    }
}