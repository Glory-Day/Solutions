#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string input_string) {
    string answer = "";

    string tmp = "";
    tmp.push_back(input_string[0]);

    vector<string> arr;
    int n = input_string.size();
    for (int i = 0; i < n - 1; i++) {
        if (input_string[i] == input_string[i + 1]) {
            tmp.push_back(input_string[i + 1]);
        }
        else {
            arr.push_back(tmp);
            tmp.clear();
            tmp.push_back(input_string[i + 1]);
        }
    }
    arr.push_back(tmp);

    vector<int> visited(26, 0);
    for (auto& i: arr) {
        visited[i.front() - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (visited[i] > 1) {
            answer.push_back('a' + i);
        }
    }

    return answer.empty() ? "N" : answer;
}

int main() {
    string input_string;
    cin >> input_string;

    string answer = solution(input_string);

    cout << answer;
}