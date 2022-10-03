#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    for (int i = 1; i < n; i++) {
        int g = gcd(v[0], v[i]);
        cout << v[0] / g << "/" << v[i] / g << '\n';
    }
}