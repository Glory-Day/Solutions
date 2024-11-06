#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int index = myString.find_last_of(pat);
    if (index != string::npos)
    {
        answer = myString.substr(0, index - (int)pat.length() + 1) + pat;
    }
    
    return answer;
}

int main()
{
    string myString, pat;
    cin >> myString >> pat;

    string answer = solution(myString, pat);
    
    cout << answer;

    return 0;
}