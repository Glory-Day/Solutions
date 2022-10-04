#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// 인자로 들어온 숫자가 소수인지 판별하는 함수이다.
bool checkPrime(int number) {
    // number의 약수는 number의 제곱근 보다 작거나 같다.
    // 2 ~ sqrt(number)까지 숫자를 나눠 나머지가 0이 되면 number는 소수가 아니다.
    for(int i = 2; i <= sqrt(number); i++) {
        if(number % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int N = nums.size();
    
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            for(int k = j + 1; k < N; k++) {
                if(checkPrime(nums[i] + nums[j] + nums[k])) {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    cout << solution(nums);
}