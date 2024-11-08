#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    string cache = to_string(order);
    answer += count(cache.begin(), cache.end(), '3');
    answer += count(cache.begin(), cache.end(), '6');
    answer += count(cache.begin(), cache.end(), '9');
    
    return answer;
}

int main()
{
    int order;
    cin >> order;

    int answer = solution(order);

    cout << answer;

    return 0;
}