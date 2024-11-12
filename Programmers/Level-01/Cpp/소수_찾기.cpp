#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer=0;

    vector<bool> primeNumber(n + 1, true);
    primeNumber[0] = primeNumber[1] = false;
    for (int i = 2; i <= n; i++)
    {
        int mult = 2;
        while(i * mult <= n && primeNumber[i] == true)
        {
            primeNumber[i * mult] = false;
            mult++;
        }
    }
    
    for (int i = 0;i <= n; i++)
    {
        if (primeNumber[i])
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