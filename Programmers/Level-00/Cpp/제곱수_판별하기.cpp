#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    
    for (int i = 1; i * i <= 1000000; i++)
    {
        if (i * i == n)
        {
            answer = 1;
            
            break;
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