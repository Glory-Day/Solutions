#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

vector<int> getMods(int n) {
    vector<int> mods = { n };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            mods.push_back(i);
            mods.push_back(n / i);
        }
    }

    return mods;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    vector<int> aMods;
    vector<int> bMods;
    if (arrayA.size() == 1) {
        aMods = getMods(arrayA.front());
        bMods = getMods(arrayB.front());
    }
    else {
        int a = gcd(arrayA[0], arrayA[1]);
        int b = gcd(arrayB[0], arrayB[1]);
        for (int i = 2; i < arrayA.size(); i++) {
            a = gcd(a, arrayA[i]);
            b = gcd(b, arrayB[i]);
        }

        aMods = getMods(a);
        bMods = getMods(b);
    }

    vector<int> mods;
    for (int i = 0; i < aMods.size(); i++) {
        bool chk = true;
        for (int j = 0; j < arrayB.size(); j++) {
            if (arrayB[j] % aMods[i] == 0) {
                chk = false;
                break;
            }
        }

        if (chk) {
            mods.push_back(aMods[i]);
        }
    }

    for (int i = 0; i < bMods.size(); i++) {
        bool chk = true;
        for (int j = 0; j < arrayA.size(); j++) {
            if (arrayA[j] % bMods[i] == 0) {
                chk = false;
                break;
            }
        }

        if (chk) {
            mods.push_back(bMods[i]);
        }
    }

    sort(mods.begin(), mods.end());

    answer = mods.empty() ? 0 : mods.back();

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> arrayA;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arrayA.push_back(input);
    }

    vector<int> arrayB;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arrayB.push_back(input);
    }

    int answer = solution(arrayA, arrayB);

    cout << answer;
}