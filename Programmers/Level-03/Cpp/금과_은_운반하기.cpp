#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 10e9 * 10e5 * 4;

    ll begin = 0, end = 10e9 * 10e5 * 4;
    while (begin <= end) {
        ll mid = (begin + end) / 2ll;

        ll cache[3] = { 0,0,0 };
        for (int i = 0; i < s.size(); i++) {
            ll arr[4] = { (ll)g[i],(ll)s[i],(ll)w[i],(ll)t[i] };

            ll mv = mid / (arr[3] * 2ll);
            if (mid % (arr[3] * 2ll) >= t[i]) mv++;

            cache[0] += (arr[0] < mv * arr[2]) ? arr[0] : mv * arr[2];
            cache[1] += (arr[1] < mv * arr[2]) ? arr[1] : mv * arr[2];
            cache[2] += (arr[0] + arr[1] < mv * arr[2]) ? arr[0] + arr[1] : mv * arr[2];
        }

        if (cache[0] >= a && cache[1] >= b && cache[2] >= a + b) {
            end = mid - 1;
            answer = min(mid, answer);
        }
        else {
            begin = mid + 1;
        }
    }

    return answer;
}

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;
    
    vector<int> g;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        g.push_back(input);
    }
    
    cin >> n;
    
    vector<int> s;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        s.push_back(input);
    }

    cin >> n;
    
    vector<int> w;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        w.push_back(input);
    }

    cin >> n;
    
    vector<int> t;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        t.push_back(input);
    }

    long long answer = solution(a, b, g, s, w, t);

    cout << answer;
}