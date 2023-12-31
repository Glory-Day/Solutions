#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    set<int> st;

    int answer = 0;
    for (int i = 0; i < k; i++) {
        int a = arr[i];
        
        if (st.find(a) != st.end() || st.size() < n) {
            st.insert(a);
            continue;
        }

        int mx = -1, j = -1;
        for (auto it = st.begin(); it != st.end(); it++) {
            int tmp = 0;
            vector<int> sub;
            sub.assign(arr.begin() + i + 1, arr.begin() + k);

            auto idx = find(sub.begin(), sub.end(), *it);
            if (idx != sub.end()) tmp = idx - sub.begin();
            else tmp = k - i - 1;

            if (tmp > mx) {
                mx = tmp, j = *it;
            }
        }

        st.erase(j);
        st.insert(a);
        answer++;
    }

    cout << answer;
}