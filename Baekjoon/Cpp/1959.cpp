#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> m >> n;

    ll answer = 0;
    int y, x;
    for (y = 1, x = 1; m - (y - 1) >= 1 && n - (x - 1) >= 1; y++, x++, m--, n--, answer += 4ll) {
        int dy = m - (y - 1);
        int dx = n - (x - 1);

        if (dy == 2) {
            if (dx == 1) {
                answer += 1ll, y = m, x = n;
                break;
            }
            else {
                answer += 2ll, y++;
                break;
            }
        }
        else if (dx == 2) {
            if (dy == 1) {
                y = m, x = n;
                break;
            }
            else {
                answer += 3ll, y++;
                break;
            }
        }
        else if (dy == 1) {
            y = m, x = n;
            break;
        }
        else if (dx == 1) {
            answer += 1ll, y = m, x = n;
            break;
        }
    }

    cout << answer << '\n';
    cout << y << ' ' << x;
}