#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/*
    문제 설명: 수열이 주어지면 해당 수열을 a, b로 옮긴다. 
    이때 a로 옮길때는 규칙 1, b로 옮길때는 규칙 2에 적힌대로 옮긴다.
    (1) 수열의 맨 마지막 숫자를 a의 가운데에 넣는다. 이때 a에 숫자 개수가 홀수이면 왼쪽, 오른쪽을 임의로 선택해서 넣는다.
    (2) a의 가운데의 숫자를 b의 맨 마지막에 넣는다. 이때 a에 숫자 개수가 짝수이면 왼쪽, 오른쪽을 임의로 선택해서 넣는다.
    b에 저장된 수열이 오름차순이 될 수 있으면 "YES"를 없으면 "NO"를 출력한다. 

    풀이: 수열의 마지막을 기준으로 2개씩 숫자를 묶는다.
    S = { [a1, a2], ..., [an-1, an] }
    이유는 규칙 1에따라 맨 마지막에 숫자로부터 처음까지 홀수번쨰의 숫자는 무조건 a가 짝수이기 때문에 가운데에 들어가고 짝수번째 숫자는 왼쪽, 오른쪽으로 들어간다.
    따라서 a에 처음과 끝에서 가운데까지 차례로 2개씩 묶인 숫자들이 들어가게 된다.
    a = { an-1 or an, ..., a1 or a2, a1 or a2, ..., an-1 or an }
    이 다음, 규칙 2에 따라 차례로 가운데의 숫자가 맨 앞으로 오게되고 양 끝의 숫자는 임의의 순서대로 2개씩 묶여 b에 들어가게 된다.
    따라서 수열에서 변할 수 있는 부분은 2개씩 묶인 숫자들만 위치가 변하게 된다.
    b는 오름차순으로 변해야 함으로 두 개씩 묶인 숫자의 대소를 비교해서 왼쪽 숫자가 오른쪽 숫자보다 크면 위치를 바꾼다.
    그 다음, 수열이 오름차순인지 검사하면 된다.
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

        for (int i = n - 1; i > 0; i -= 2) {
            if (arr[i - 1] > arr[i]) swap(arr[i], arr[i - 1]);
        }

        bool check = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                check = false;
                break;
            }
        }

        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}