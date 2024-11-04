#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    
    answer.replace(s, (int)overwrite_string.length(), overwrite_string);
    
    return answer;
}

int main()
{
    string my_string, overwrite_string;
    cin >> my_string >> overwrite_string;

    int s;
    cin >> s;

    string answer = solution(my_string, overwrite_string, s);

    cout << answer;

    return 0;
}