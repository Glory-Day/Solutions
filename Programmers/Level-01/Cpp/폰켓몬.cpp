#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int maximum = 0;

    // nums의 최대값을 저장한다.
    for (int& i: nums) {
        maximum = max(maximum, i);
    }

    // nums의 최대값만큼 boolean type 배열을 생성한다.
    vector<bool> checks(maximum + 1, false);

    // checks에 nums의 값을 index로 사용해 false를 true로 변환한다.
    for (int& i: nums) {
        checks[i] = true;
    }

    // checks 원소 중 true인 값의 개수를 샌다.
    // 이는 각기 다른 원소의 개수를 새는 것과 같다.
    for (auto i: checks) {
        answer += (i ? 1 : 0);
    }

    // 비둘기집의 원리로 중복되지 않은 원소의 개수가 nums의 절반보다 작으면 이는 중복되지 않은 원소의 개수가 가장 많은 종류를 선택하는 것과 같다.
    // 반대로, 중복되지 않은 원소의 개수가 nums의 절반 보다 크다면 nums의 절반이 가장 많은 종류를 선택하는 것과 같다. 
    return min(answer, (int)nums.size() / 2);
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