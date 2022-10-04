#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    // 내적 공식: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1]
    for(int i = 0; i < a.size(); i++) {
        answer += a[i] * b[i];
    }
    
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> a, b;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    cout << solution(a, b);
}