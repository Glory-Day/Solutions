#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int i = 1; i <= r2; i++)
    {
        int a = floor(sqrt((long long)r2 * r2 - (long long)i * i));
        int b = ceil(sqrt((long long)r1 * r1 - (long long)i * i));
        if (r1 < i)
        {
            b = 0LL;
        }
        
        answer += (a - b + 1);
    }
    
    answer *= 4LL;
    
    return answer;
}

int main()
{
    int r1, r2;
    cin >> r1 >> r2;

    long long answer = solution(r1, r2);

    cout << answer;

    return 0;
}