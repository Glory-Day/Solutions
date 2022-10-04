#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int cnts[26];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        for (int j = s.size() - 1, d = 1; j >= 0; j--, d *= 10) {
            cnts[s[j] - 'A'] += d;
        }
    }

    sort(cnts, cnts + 26, greater<int>());

    int i = 0;
    int d = 9;
    int sum = 0;
    while (cnts[i] != 0) {
        sum += (cnts[i] * d);
        i++, d--;
    }

    cout << sum;
}