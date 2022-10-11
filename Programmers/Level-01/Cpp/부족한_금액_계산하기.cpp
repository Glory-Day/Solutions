#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int price, int money, int count) {
    ll answer = -1;

    ll total = 0;
    for (int i = 1; i <= count; i++) {
        total += (price * i);
    }

    answer = (total < money) ? 0 : total - money;

    return answer;
}

int main() {
    int price, money, count;
    cin >> price >> money >> count;

    ll answer = solution(price, money, count);

    cout << answer;
}