#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    int n = (int)my_string.length();
    int m = (int)is_suffix.length();
    if (n - m >= 0)
    {
        string cache = my_string.substr(n - m, n);
        
        answer = (int)(cache == is_suffix);
    }
    
    return answer;
}

int main()
{
    string my_string, is_suffix;
    cin >> my_string >> is_suffix;

    int answer = solution(my_string, is_suffix);

    cout << answer;

    return 0;
}