#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    // 0 ~ 9까지 더할 숫자를 저장할 변수를 생성 및 초기화한다.
    int sum = 0;
    
    // 0 ~ 9까지 한번씩 더한다.
    for (int i = 0; i < 10; i++) {
        sum += i;
    }

    // numbers의 숫자들을 0 ~ 9까지 모두 더한 변수에 순차적으로 뺀다.
    // 그러면 남은 숫자는 numbers에 없는 숫자들이 더해진다.
    for (auto &i : numbers) {
        sum -= i;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    for (int i = 0 ; i < n; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    cout << solution(numbers);
}