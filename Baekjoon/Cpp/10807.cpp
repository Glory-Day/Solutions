#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cache(201, 0);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cache[input + 100]++;
    }

    int v;
    cin >> v;

    cout << cache[v + 100];
}