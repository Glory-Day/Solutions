#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (comp(a, b) == false) {
        cout << -1;
        return 0;
    }

    int answer = 0;
    auto it1 = b.rbegin();
    for (auto it2 = a.rbegin(); it2 != a.rend(); it2++) {
        if (*it1 == *it2) {
            it1++;
        }
        else {
            answer++;
        } 
    }

    cout << answer;
}