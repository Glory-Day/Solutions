#include <iostream>

using namespace std;

int main() {
    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;

    int answer = 0;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;

        int d1 = (x - a) * (x - a) + ((y + h / 2) - b) * ((y + h / 2) - b);
        int d2 = (x + w - a) * (x + w - a) + ((y + h / 2) - b) * ((y + h / 2) - b);
        int h2 = (h / 2) * (h / 2);

        if (a >= x && a <= x + w && b >= y && b <= y + h) answer++;
        else if (d1 <= h2 || d2 <= h2) answer++;
    }

    cout << answer;
}