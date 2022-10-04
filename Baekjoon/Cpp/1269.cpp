#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> st;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        st.insert(input);
    }

    int tmp = 0;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        tmp += st.find(input) != st.end();
    }

    int answer = (n - tmp) + (m - tmp);
    
    cout << answer;
}