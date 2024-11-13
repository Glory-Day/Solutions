#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long width = w;
    long long height = h;
    
    answer = width * height - (width + height - gcd(width, height));
    
    return answer;
}

int main()
{
    int w, h;
    cin >> w >> h;

    long long answer = solution(w, h);

    cout << answer;

    return 0;
}