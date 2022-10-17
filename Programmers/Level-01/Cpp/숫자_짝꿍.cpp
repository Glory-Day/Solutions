#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    int count1[10] = { 0, };
    int count2[10] = { 0, };
    for (int i = 0; i < X.size(); i++) {
        count1[X[i] - '0']++;
    }

    for (int i = 0; i < Y.size(); i++) {
        count2[Y[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        int mn = min(count1[i], count2[i]);
        for (int j = 0; j < mn; j++) {
            answer.push_back(i + '0');
        }
    }

    sort(answer.begin(), answer.end(), greater<int>());

    if (answer.front() == '0') {
        answer = "0";
    }
    else if (answer.empty()) {
        answer = "-1";
    }

    return answer;
}

int main() {
    string X, Y;
    cin >> X >> Y;

    string answer = solution(X, Y);

    cout << answer;
}