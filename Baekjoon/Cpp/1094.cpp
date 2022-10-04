#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    bitset<8> bits = n;

    int answer = 0;
    for (auto i: bits.to_string()) {
        answer += i - '0';
    }

    cout << answer;
}