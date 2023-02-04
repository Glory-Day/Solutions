#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        arr.push_back(input);
    }    

    string answer = arr[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < answer.size(); j++) {
            if (answer[j] != arr[i][j]) {
                answer[j] = '?';
            }
        }
    }

    cout << answer;
}