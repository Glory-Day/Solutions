#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll calc(vector<vector<int>>& land, int P, int Q, ll height) {
    ll value = 0;
    
    int n = land.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] < height) {
                value += (height - land[i][j]) * P;
            }
            else if (land[i][j] > height) {
                value += (land[i][j] - height) * Q;
            }
        }
    }

    return value;
}

ll solution(vector<vector<int>> land, int P, int Q) {
    ll answer = LLONG_MAX;

    int n = land.size();
    
    ll b = LLONG_MAX, e = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b > land[i][j]) {
                b = land[i][j];
            }
            if (e < land[i][j]) {
                e = land[i][j];
            }
        }
    }

    while (b <= e) {
        ll mid = (b + e) / 2ll;
        ll l = calc(land, P, Q, mid);
        ll r = calc(land, P, Q, mid + 1ll);

        if (l < r) {
            answer = l;
            e = mid - 1;
        }
        else {
            answer = r;

            if (l == r) {
                break;
            }

            b = mid + 1ll;
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> land;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }
        land.push_back(inputs);
    }

    int P, Q;
    cin >> P >> Q;

    ll answer = solution(land, P, Q);

    cout << answer;
}