#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const long long divisor(const long long n)
{
    long long result = 1LL;
    for (long long i = 2LL; i * i <= n; i++)
    {
        if (n % i == 0LL)
        {
            result = i;
            
            if (n / i <= 10000000)
            {
                result = n / i;
                break;
            }
        }
    }
    
    return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (long long i = begin; i <= end; i++)
    {
        if (i == 1LL)
        {
            answer.push_back(0);
            continue;
        }
        
        answer.push_back((int)divisor(i));
    }
    
    return answer;
}

int main()
{
    long long begin, end;
    cin >> begin >> end;

    vector<int> answer = solution(begin, end);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}