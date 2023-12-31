#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    // commands의 첫번째 원소는 정렬의 시작 index이다.
    // commands의 두번째 원소는 정렬의 마지막 index이다.
    // commands의 세번째 원소는 정렬된 원소의 index이다.
    for(int i = 0; i < commands.size(); i++) {
        vector<int> numbers;
        
        // numbers에 array[commands[0]] ~ array[commands[1]]에 해당되는 숫자들을 넣는다.
        for(int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++) {
            numbers.push_back(array[j]);
        }

        // array[commands[0]] ~ array[commands[1]]를 정렬한다.
        sort(numbers.begin(), numbers.end());

        // commands[2]에 해당되는 숫자를 numbers의 index로 사용해 answer에 넣는다.
        answer.push_back(numbers[commands[i][2] - 1]);
    }

    return answer;
}

int main() {
    int n; 
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        array.push_back(input);
    }

    cin >> n;
    vector<vector<int>> commands;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < 3; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }
        commands.push_back(inputs);
    }

    vector<int> answer = solution(array, commands);
    for (int& i: answer) {
        cout << i << ' ';
    }
}