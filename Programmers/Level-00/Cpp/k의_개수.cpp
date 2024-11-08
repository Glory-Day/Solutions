#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for (int n = i; n <= j; n++)
    {
        string cache = to_string(n);
        answer += count(cache.begin(), cache.end(), k + '0');
    }
    
    return answer;
}

int main()
{
    int i, j, k;
    cin >> i >> j >> k;

    int answer = solution(i, j, k);

    cout << answer;

    return 0;
}