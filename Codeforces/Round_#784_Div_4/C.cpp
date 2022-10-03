#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/*
    문제 설명: 임의의 수열이 주어진다. 이때 홀수 칸 또는 짝수 칸을 1 증가시켜서 모든 수열을
    홀수 또는 짝수로 바꿀 수 있는지 출력한다.

    풀이: 모든 수열의 수가 홀수 또는 짝수가 되기 위해서는 홀수칸에는 홀수 또는 짝수만 짝수칸에는 홀수 또는 짝수만 있어야한다.
*/

int arr[51];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        fill(arr, arr + 51, 0);

        pii a = { 0,0 }, b = { 0,0 };
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];

            if (i % 2 == 1) {
                a.first++;
                if (arr[i] % 2 == 1) a.second++; 
            }
            else {
                b.first++;
                if (arr[i] % 2 == 1) b.second++;
            }
        }

        string answer = "NO\n";
        if ((a.first == a.second || !a.second) && (b.first == b.second || !b.second)) {
            answer = "YES\n";
        }

        cout << answer;
    }
}