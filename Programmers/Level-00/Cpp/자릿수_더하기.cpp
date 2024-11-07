#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string cache = to_string(n);
    for (int i = 0; i < (int)cache.length(); i++)
    {
        answer += (cache[i] - '0');
    }
    
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