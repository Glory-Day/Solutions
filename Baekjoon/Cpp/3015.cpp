#include <iostream>
#include <stack>
#include <utility>

#define FastInput cin.tie(nullptr)->sync_with_stdio(false);
#define FaseOutput cout.tie(nullptr)->sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    ll answer = 0;
    stack<pii> stk;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int tmp = 1;
        while (!stk.empty() && stk.top().first < input) {
            answer += stk.top().second;
            stk.pop();
        }

        if (!stk.empty()) {
            if (stk.top().first == input) {
                answer += stk.top().second;
                tmp = (stk.top().second + 1);

                if (stk.size() > 1) {
                    answer++;
                }

                stk.pop();
            }
            else {
                answer++;
            }    
        }

        stk.push({ input,tmp });
    }

    cout << answer;
}