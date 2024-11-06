#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i < (int)myString.length(); i++)
    {
        myString[i] = tolower(myString[i]);
    }
    
    for (int i = 0; i < (int)pat.length(); i++)
    {
        pat[i] = tolower(pat[i]);
    }
    
    auto iter = myString.find(pat);
    answer = (int)(iter != string::npos);
    
    return answer;
}

int main()
{
    string myString, pat;
    cin >> myString >> pat;

    int answer = solution(myString, pat);
    
    cout << answer;

    return 0;
}