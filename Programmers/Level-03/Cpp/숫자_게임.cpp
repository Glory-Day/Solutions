#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int a = A.size() - 1;
    int b = B.size() - 1;
    while (a >= 0) {
        if (A[a] < B[b]) {
            b--, answer++;
        }
        a--;
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> A;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        A.push_back(input);
    }

    vector<int> B;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        B.push_back(input);
    }

    int answer = solution(A, B);

    cout << answer;
}