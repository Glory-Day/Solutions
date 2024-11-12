#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    if (num == 1)
    {
        return 0;
    }
    
    long long number = num;
    for (int i = 1; i <= 500; i++)
    {
        if (number % 2 == 0)
        {
            number/=2;
        }
        else
        {
            number = number * 3 + 1;
        }
        
        answer++;
        
        if (number == 1)
        {
            break;
        }
    }
    
    if (answer <= 500 && number == 1)
    {
        return answer;
    }

    return -1;
}

int main()
{
    int num;
    cin >> num;

    int answer = solution(num);

    cout << answer;

    return 0;
}