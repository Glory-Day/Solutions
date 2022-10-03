#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

/*
    문제 설명: 수열이 주어지고 수열의 수 중에서 3번 이상 나온 수를 출력한다.
    만약 3번 이상 나온 수가 없으면 -1을 출력한다.

    풀이: 수열의 수의 최대값만큼 배열을 생성한 뒤, 수열의 수와 일치하는 배열 칸에 1씩 증가한다.
    3 이상이 나오면 해당 인덱스 번호를 출력하고 없으면 -1을 출력한다.
*/

int cnts[200001];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        fill(cnts, cnts + 200001, 0);

        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            cnts[input]++;
        }

        int answer = -1;
        for (int i = 1; i <= n; i++) {
            if (cnts[i] >= 3) answer = i; 
        }

        cout << answer << '\n';
    }
}