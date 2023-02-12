#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pii> a, b;
    for (int i = 1; i <= n - 1; i++) {
        int input;
        cin >> input;
        a.push_back({ input,i });
    }
    
    for (int i = 1; i <= m; i++) {
        int input;
        cin >> input;
        b.push_back({ input,i });
        
        if (i == 1) {
            a.push_back({ input,n });
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    cout << a.front().second << ' ' << b.front().second;
}