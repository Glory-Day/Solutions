#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j * j <= i; j++)
        {
            if (j * j == n)
            {
                sum++;
                
                continue;
            }
            
            if (i % j == 0)
            {
                sum += 2;
            }
        }
        
        if (2 < sum)
        {
            answer++;
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