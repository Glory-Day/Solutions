#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<string> answer;
    while (t--) {
        int n;
        cin >> n;

        vector<string> arr;
        for (int i = 0; i < n; i++) {
            string input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end());

        bool chk = true;
        for (int i = 0; i < n - 1; i++) {
            string a = arr[i];
            string b = arr[i + 1];
            chk = true;

            if (a.size() > b.size()) {
                continue;
            }

            if (a == b.substr(0, a.size())) {
                chk = false;
                break;
            }
        }

        if (chk) {
            answer.push_back("YES");
        }
        else {
            answer.push_back("NO");
        }
    }

    for (auto& i: answer) {
        cout << i << '\n';
    }
}