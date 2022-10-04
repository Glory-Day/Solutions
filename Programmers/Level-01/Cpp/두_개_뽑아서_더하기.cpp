#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    // 두 개의 숫자를 더하여 가장 큰 자연수는 200이다.
    // 두 개의 숫자를 더해서 나오는 숫자를 index로 사용해서 중복 처리를 한다.
    vector<bool> visited(201,false);

    // 두 개의 숫자를 선택해서 더한 다음, visited에 index로 넣어 true가 아니면 answer에 넣고 visited를 true로 바꾼다.
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++)
            if (visited[numbers[i] + numbers[j]] == false) {
                answer.push_back(numbers[i] + numbers[j]);
                visited[numbers[i] + numbers[j]] = true;
            }
    }
    
    // 더한 숫자들을 오름차순으로 정렬한다.
    sort(answer.begin(),answer.end());

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    vector<int> answer = solution(numbers);
    for (int& i: answer) {
        cout << i << ' ';
    }
}