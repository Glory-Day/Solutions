#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp(vector<pii>& a, vector<pii>& b) {
    if (a.front().first == b.front().first) {
        return a.front().second < b.front().second;
    }

    return a.front().first < b.front().first;
}

pii check(pii& a, pii& b) {
    if (a.first < b.first || (a.first == b.first && a.second < b.second)) {
        return b;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pii>> arr;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >>d;
        arr.push_back({ { a,b },{ c,d } });
    }

    sort(arr.begin(), arr.end(), cmp);

    pii b = { 3,1 }, e = { 12,1 };
    pii d = { 1,1 };
    
    bool chk = false;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (check(b, arr[i][0]) == b) {
            d = check(d, arr[i][1]);
            if (check(d, e) == d) {
                chk = true;
                break;
            }
        }
        else {
            b = d;
            answer++;

            if (check(b, arr[i][0]) == b) {
                d = arr[i][1];
                if (check(d, e) == d) {
                    chk = true;
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    if (!chk) {
        cout << 0;
    }
    else {
        cout << answer + 1;
    }
}