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
    문제 설명: 수열 S에 n개의 자연수가 들어있다. 임의의 숫자를 2로 나눠서(나머지는 버린다) 수열을 오름차순으로 만든다.
    이때 몇번째 연산을 해서 오름차순으로 만들 수 있는지를 출력한다.
    만들 수 없으면 -1을 출력한다.

    풀이: 수열을 순회하면서 선택된 두 수의 대소를 비교한다.
    이때 왼쪽의 수가 오른쪽의 수보다 크면 왼쪽의 수를 2로 나눈다.
    위 과정을 반복하면서 0의 개수가 1개보다 많으면 이는 오름차순으로 바꿀 수 없는 수열이다.
    아니면 과정을 반복한 횟수를 출력한다.
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

        if (n == 1) cout << "0\n";
        else {
            int check = 1;
            int answer = 0;
            while (check) {
                check = 0;   
                for (int i = 0; i < n - 1; i++) {
                    if (arr[i] >= arr[i + 1]) {
                        arr[i] = arr[i] / 2;
                        check++;
                        answer++;
                        break;
                    }
                }

                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == 0) sum++;
                }

                if (sum > 1) {
                    answer = -1;
                    break;
                }
            }

            cout << answer << '\n';
        }
    }
}