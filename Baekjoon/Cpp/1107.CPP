#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    string number;
    cin >> number;

    int n;
    cin >> n;

    vector<char> cache;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cache.push_back(input + '0');
    }

    int answer = abs(100 - stoi(number));
    pii mn = { 0,0 };
    string a = number;
    string b = number;
    while (n != 10) {
        bool na = true, nb = true;
        for (int i = 0; i < cache.size(); i++) {
            if (a.find(cache[i]) != string::npos) {
                na = false;
                int tmp = stoi(a);
                a = to_string((tmp == 0) ? 0 : tmp - 1);
                break;
            }
        }

        if (na) {
            answer = min(answer, (int)a.size() + mn.first);
            break;
        }
        else {
            mn.first++;
        }

        for (int i = 0; i < cache.size(); i++) {
            if (b.find(cache[i]) != string::npos) {
                nb = false;
                b = to_string(stoi(b) + 1);
                break;
            }
        }

        if (nb) {
            answer = min(answer, (int)b.size() + mn.second);
            break;
        }
        else {
            mn.second++;
        }
    }

    cout << answer;
}