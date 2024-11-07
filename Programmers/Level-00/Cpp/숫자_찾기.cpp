#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    string cache = to_string(num);
    int index = cache.find_first_of(to_string(k));
    if (0 <= index)
    {
        index++;
    }
    
    answer = index;
    
    return answer;
}

int main()
{
    int num, k;
    cin >> num >> k;

    int answer = solution(num, k);

    cout << answer;

    return 0;
}