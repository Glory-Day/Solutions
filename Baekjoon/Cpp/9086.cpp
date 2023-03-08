#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        
        string answer = "";
        answer.push_back(input.front());
        answer.push_back(input.back());

        cout << answer << '\n';
    }
}