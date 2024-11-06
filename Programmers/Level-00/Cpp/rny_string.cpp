#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    
    for (int i = 0; i < (int)rny_string.size(); i++)
    {
        if (rny_string[i] == 'm')
        {
            answer += "rn";
            
            continue;
        }
        
        answer += rny_string[i];
    }
    
    return answer;
}

int main()
{
    string rny_string;
    cin >> rny_string;

    string answer = solution(rny_string);
    
    cout << answer;

    return 0;
}