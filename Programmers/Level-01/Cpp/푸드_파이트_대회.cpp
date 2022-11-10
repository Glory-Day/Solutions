#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    int n = food.size();
    for (int i = 0; i < n; i++) {
        food[i] /= 2;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < food[i]; j++) {
            answer.push_back(i + '0');
        }
    }

    answer.push_back('0');

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < food[i]; j++) {
            answer.push_back(i + '0');
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> food;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        food.push_back(input);
    }

    string answer = solution(food);

    cout << answer;
}