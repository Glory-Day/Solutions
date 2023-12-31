#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 3진수로 변환하는 함수.
vector<int> decode(int n, int m) {
    // 변환된 3진수.
    vector<int> bits;

    while (n != 0) {
        // 3진수의 비트 단위.
        int bit = 0;
        // 2 * m이 변환해야하는 숫자 n보다 작으면 비트는 2로 결정된다.
        if (n >= 2 * m) {
            bit = 2;
        }
        // m이 변환해야하는 숫자 n보다 작으면 비트는 1로 결정된다.
        else if (n >= m) {
            bit = 1;
        }

        // 결정된 비트를 배열에 저장한다.
        bits.push_back(bit);
        // n을 다음 비트 단위 결정을 위해 (비트) * m만큼 뺀다.
        n -= bit * m;
        // m을 3나눠 비트의 자리수를 설정한다.
        m /= 3;
    }

    // m이 남는다는 것은 나머지 자릿수를 결정하기 전에 n이 0이 됨으로써 나머지 자릿수를 0으로 저장한다. 
    while (m >= 1) {
        bits.push_back(0);
        m /= 3;
    }

    return bits;
}

// 3진수를 뒤집어서 10진수로 변환한다.
int encode(vector<int> bits) {
    // 변환된 10진수.
    int digit = 0;
    // (비트) * 3^(자릿수)를 비트의 순서대로 더한다.
    for (int i = 0, j = 1; i < bits.size(); i++, j *= 3) {
        int bit = bits[i];
        digit += bit * j;
    }

    return digit;
}

int solution(int n) {
    int answer = 0;

    // 변환해야하는 n보다 작은 최대 3의 m승을 저장한다.
    // m은 3진수의 자릿수를 결정한다.
    int m = 0;
    for (int i = 1; i <= n; i *= 3) {
        m = i;
    }

    // 3진수로 변환하고 3진수를 뒤집은 10진수를 저장한다.
    vector<int> bits = decode(n, m);
    answer = encode(bits);

    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
}