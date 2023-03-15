#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
    vector<deque<char>> arr;
    for (int i = 0; i < 5; i++) {
        string input;
        cin >> input;

        deque<char> tmp;
        for (int j = 0; j < input.size(); j++) {
            tmp.push_back(input[j]);
        }
        for (int j = 0; j < 15 - input.size(); j++) {
            tmp.push_back('*');
        }

        arr.push_back(tmp);
    }

    string answer = "";
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] != '*') {
                answer.push_back(arr[j][i]);
            }
        }
    }

    cout << answer;
}