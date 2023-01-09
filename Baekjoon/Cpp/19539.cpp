#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int cnt = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);

        sum += input;
        cnt += input % 2;
    }

    string answer = "NO";
    if (sum % 3 == 0 && sum / 3 >= cnt) {
        answer = "YES";
    }

    cout << answer;
}