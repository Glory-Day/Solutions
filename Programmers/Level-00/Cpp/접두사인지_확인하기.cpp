#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    
    string cache = my_string.substr(0, (int)is_prefix.length());
    
    answer = (int)(cache == is_prefix);
    
    return answer;
}

int main()
{
    string my_string, is_prefix;
    cin >> my_string >> is_prefix;

    int answer = solution(my_string, is_prefix);

    cout << answer;

    return 0;
}