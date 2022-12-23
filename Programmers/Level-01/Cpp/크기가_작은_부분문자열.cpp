#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int solution(string t, string p) {
    int answer = 0;
    
    ll b = stoll(p);
    int len = p.size();
    for (int i = 0; i <= t.size() - len; i++) {
        ll a = stoll(t.substr(i, len));
        if (a <= b) {
            answer++;
        }
    }

    return answer;
}

int main() {
    string t, p;
    cin >> t >> p;

    int answer = solution(t, p);

    cout << answer;
}