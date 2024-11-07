#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    
    int mx = max(M, N);
    int mn = min(M, N);
    
    answer = (mx - 1) * mn + mn - 1;
    
    return answer;
}

int main()
{
    int M, N;
    cin >> M >> N;

    int answer = solution(M, N);

    cout << answer;

    return 0;
}