#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    answer = lcm(n, 6) / 6;
    
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