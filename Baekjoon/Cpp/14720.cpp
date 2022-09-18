#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            tmp.push_back(i);
        }
    }

    int answer = 0;
    for (int i = 0; i < tmp.size(); i++) {
        int b = 0, mx = 0;
        for (int j = tmp[i]; j < n; j++) {
            if (b == arr[j]) {
                switch (b)
                {
                    case 0: b = 1; break;
                    case 1: b = 2; break;
                    case 2: b = 0; break;
                    default: break;
                }

                mx++;
            }
        }

        answer = max(answer, mx);
    }

    cout << answer;
}