#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int to_integer(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

int solution(int a, int b) {
    int answer = 0;
    
    int l = to_integer(to_string(a) + to_string(b));
    int r = 2 * a * b;
    if (l < r)
    {
        answer = r;
    }
    else
    {
        answer = l;
    }
    
    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int answer = solution(a, b);

    cout << answer;

    return 0;
}