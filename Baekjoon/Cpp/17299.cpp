#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    vector<int> cache(1000001, 0);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        cache[input]++;
    }

    stack<int> st;
    vector<int> answer(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && cache[arr[st.top()]] < cache[arr[i]]) {
            answer[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}