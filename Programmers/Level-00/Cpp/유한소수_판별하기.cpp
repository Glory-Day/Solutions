#include <iostream>

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int a, int b) {
    int answer = 1;
    
    int g = gcd(a, b);
    a /= g;
    b /= g;
    
    int p = 2;
    vector<int> caches;
    while (b != 1)
    {
        if (b % p == 0)
        {
            b /= p;
            
            if ((p == 2 || p == 5) == false)
            {
                answer = 2;
                
                break;
            }
            
            continue;
        }
        
        p++;
    }
    
    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int answer = solution(a, b);

    cout << answer;
}