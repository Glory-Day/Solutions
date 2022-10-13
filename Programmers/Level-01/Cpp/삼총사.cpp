#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    string s = "";
    for (int i = 0; i < number.size() - 3; i++) {
        s.push_back('0');
    }

    for (int i = 0; i < 3; i++) {
        s.push_back('1');
    }

    do {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum += number[i];
            }
        }

        if (!sum) {
            answer++;
        }
    } while (next_permutation(s.begin(), s.end()));

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> number;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        number.push_back(input);
    }

    int answer = solution(number);

    cout << answer;
}