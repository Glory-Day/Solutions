#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int answer = solution(A, B);

    cout << answer;

    return 0;
}