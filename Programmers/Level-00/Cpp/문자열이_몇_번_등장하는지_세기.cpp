#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i <= (int)(myString.length() - pat.length()); i++)
    {
        answer += (int)(myString.substr(i, (int)pat.length()) == pat);
    }
    
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