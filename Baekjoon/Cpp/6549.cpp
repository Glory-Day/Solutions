#include <iostream>
#include <algorithm>

using namespace std;

typedef long ll;

ll arr[100000];

ll f(int l, int r)
{
    if (l == r) return arr[l];

    int mid = (l + r) / 2;
    int b = mid;
    int e = mid;
    ll h = arr[mid];
    ll temp = max(f(l, mid), f(mid + 1, r));
    while (l < b || e < r) {
        if (l < b && (e == r || arr[b - 1] > arr[e + 1])) {
            b--;
            h = min(h, arr[b]);
        }
        else {
            e++;
            h = min(h, arr[e]);
        }
        temp = max(temp, h * (e - b + 1));
    }

    return temp;
}

int main(void)
{
    while (true) {
        int n;
        cin >> n;
        
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << f(0, n - 1) << '\n';
    }
}