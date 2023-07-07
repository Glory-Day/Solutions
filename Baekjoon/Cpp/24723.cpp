#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = (1 << n);

    cout << answer;
}