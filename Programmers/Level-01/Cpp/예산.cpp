#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    // 가장 많은 물품을 구매해줄 수 있는 부서의 개수.
    int sum=0;

    // 오름차순으로 부서의 금액을 정렬한다.
    // 가장 적은 예산을 가진 부서부터 구매해주면 가장 많이 부서들에게 물품을 줄 수 있다.
    sort(d.begin(), d.end());

    // 물품을 구매할 수 있는 부서의 개수를 저장한다.
    for(int i = 0; i < d.size(); i++) {
        sum += d[i];

        if(sum <= budget) {
            answer++;
        }
        else break;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> d;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        d.push_back(input);
    }

    int budget;
    cin >> budget;

    cout << solution(d, budget);
}