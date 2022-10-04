#include <iostream>
#include <vector>

#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef long long ll;

vector<int> arr;
int answer;

void merge(int b, int m, int e, int k) {
    int tmp[e + 2];
    int i = b, j = m + 1, t = 1;
    while (i <= m && j <= e) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        }
        else {
            tmp[t++] = arr[j++];
        }
    }

    while (i <= m) {
        tmp[t++] = arr[i++];
    }

    while (j <= e) {
        tmp[t++] = arr[j++];
    }

    i = b, t = 1;
    while (i <= e) {
        arr[i++] = tmp[t++];

        if (++answer == k) {
            cout << tmp[t - 1];
        }
    }
}

void sort(int b, int e, int k) {
    if (b >= e) {
        return;
    }

    int m = (b + e) / 2;

    sort(b, m, k);
    sort(m + 1, e, k);
    merge(b, m, e, k);
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(0, n - 1, k);

    if (answer < k) {
        cout << -1;
    }
}