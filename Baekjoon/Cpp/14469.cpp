#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool cmp(const pii& a, const pii& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    sort(arr.begin(), arr.end(), cmp);

    int answer = 0;
    for (auto& i: arr) {
        int a = i.first;
        int b = i.second;
        
        if (answer < a) {
            answer = a + b;
        }
        else {
            answer += b;
        }
    }

    cout << answer;
}