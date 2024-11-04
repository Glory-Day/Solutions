#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    int answer = (int)(number % n == 0 && number % m == 0);
    
    return answer;
}

int main()
{
    int number, n, m;
    cin >> number >> n >> m;

    int answer = solution(number, n, m);

    cout << answer;

    return 0;
}