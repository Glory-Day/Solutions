#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

long long solution(long long n) {
    long long answer = -1;
    
    for (LL i = 1; i * i <= n; i++) 
    {
        if (i * i == n)
        {
            answer = (i + 1) * (i + 1);
        }
    }
    
    return answer;
}

int main()
{
    long long n;
    cin >> n;

    long long answer = solution(n);

    cout << answer;

    return 0;
}