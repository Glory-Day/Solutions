#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        my_string[i] = tolower(my_string[i]);
    }
    
    sort(my_string.begin(), my_string.end());
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    string answer = solution(my_string);
    
    cout << answer;

    return 0;
}