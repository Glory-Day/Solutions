#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;

LL solution(LL n) {
    LL answer = 0;
    
    string number = to_string(n);
    sort(number.begin(), number.end(), greater<char>());
    
    answer = stoll(number);
    
    return answer;
}

int main()
{
    long long n;
    cin >> n;

    long long answer = solution(n);

    cout << answer;

    return 0;
}