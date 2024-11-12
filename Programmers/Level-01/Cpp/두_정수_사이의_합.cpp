#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a <= b)
    {
        for(LL i = (LL)a; i <= (LL)b; i++)
        {
            answer += i;
        }
    }
    else
    {
        for(LL i = (LL)b; i <= (LL)a; i++)
        {
            answer += i;
        }
    }
    
    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    long long answer = solution(a, b);

    cout << answer;

    return 0;
}