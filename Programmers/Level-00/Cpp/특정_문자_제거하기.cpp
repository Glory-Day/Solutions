#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    auto iter = my_string.find(letter);
    while (iter != string::npos)
    {
        my_string.erase(iter, 1);
        
        iter = my_string.find(letter);
    }
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string, letter;
    cin >> my_string >> letter;

    string answer = solution(my_string, letter);

    cout << answer;
}