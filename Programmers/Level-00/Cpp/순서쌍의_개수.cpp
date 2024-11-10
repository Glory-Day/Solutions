#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            answer++;
            
            continue;
        }
        
        if (n % i == 0)
        {
            answer += 2;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}