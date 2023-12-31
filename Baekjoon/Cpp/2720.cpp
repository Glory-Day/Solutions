#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int cache[4] = { 25,10,5,1 };
        int answer[4] = { 0,0,0,0 };
        for (int i = 0; i < 4; i++) {
            while (input >= cache[i]) {
                input -= cache[i];
                answer[i]++;
            }
        }

        for (auto& j: answer) cout << j << ' ';
        cout << '\n';
    }
}