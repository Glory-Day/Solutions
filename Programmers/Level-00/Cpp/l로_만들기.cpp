#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < (int)myString.length(); i++)
    {
        if (myString[i] < 'l')
        {
            myString[i] = 'l';
        }
    }
    
    answer = myString;
    
    return answer;
}

int main()
{
    string myString;
    cin >> myString;

    string answer = solution(myString);
    
    cout << answer;

    return 0;
}