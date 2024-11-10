#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    answer = (n / slice) + (int)(n % slice > 0);
    
    return answer;
}

int main()
{
    int slice, n;
    cin >> slice >> n;

    int answer = solution(slice, n);

    cout << answer;

    return 0;
}