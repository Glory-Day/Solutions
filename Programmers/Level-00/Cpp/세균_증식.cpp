#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = n;
    
    for (int i = 0; i < t; i++)
    {
        answer *= 2;
    }
    
    return answer;
}

int main()
{
    int n, t;
    cin >> n >> t;

    int answer = solution(n, t);

    cout << answer;

    return 0;
}