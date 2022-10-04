#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef struct _Point {
    ll x, y;

    bool operator ==(_Point p) {
        return p.x == x && p.y == y;
    }

} Point;

typedef struct _Line
{
    Point a, b, middle;
    ll distance;

    ll getArea(_Line& l) {
        ll area1 = llabs((ll)(a.x * (ll)(b.y - l.a.y)) + (ll)(b.x * (ll)(l.a.y - a.y)) + (ll)(l.a.x * (ll)(a.y - b.y)));
        ll area2 = llabs((ll)(a.x * (ll)(b.y - l.b.y)) + (ll)(b.x * (ll)(l.b.y - a.y)) + (ll)(l.b.x * (ll)(a.y - b.y)));

        return (area1 + area2) / 2ll;
    }

} Line;

Point ps[1500];
Line ls[1500 * 1500 / 2];

bool compare(Line& a, Line& b) {
    if (a.distance != b.distance) {
        return a.distance < b.distance;
    }
    else if (a.middle.x != b.middle.x) {
        return a.middle.x < b.middle.x;
    }
    
    return a.middle.y < b.middle.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ps[i] = { a,b };
    }

    ll length = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ls[length++] = { ps[i],ps[j],{ ps[i].x + ps[j].x,ps[i].y + ps[j].y },(ll)((ps[i].x - ps[j].x) * (ps[i].x - ps[j].x)) + (ll)((ps[i].y - ps[j].y) * (ps[i].y - ps[j].y)) };
        }
    }

    sort(ls, ls + length, compare);

    ll answer = 0;
    for (int i = 0; i < length - 1; i++) {
        int j = i + 1;
        while (ls[i].distance == ls[j].distance && ls[i].middle == ls[j].middle) {
            answer = max(answer, ls[i].getArea(ls[j]));
            j++;
        }
    }

    cout << answer;
}
