#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int A, int B) 
{
    if (B == 0)
    {
        return A;
    }
    
    return GCD(B, A % B);
}

int LCM(int A, int B) 
{
    return A * B / GCD(A,B);
}

vector<int> solution(int n, int m) {
    vector<int> answer = { GCD(n, m),LCM(n, m) };
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> answer = solution(n, m);

    cout << answer[0] << ' ' << answer[1];

    return 0;
}