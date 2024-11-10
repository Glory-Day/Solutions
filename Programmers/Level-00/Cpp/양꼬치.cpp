#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    k -= n / 10;
    answer = n * 12000 + k * 2000;
    
    return answer;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int answer = solution(n, k);

    cout << answer;

    return 0;
}