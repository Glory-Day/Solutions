#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for (int i = 0; i < (int)rsp.length(); i++)
    {
        switch (rsp[i])
        {
            case '0': answer.push_back('5'); break;
            case '2': answer.push_back('0'); break;
            case '5': answer.push_back('2'); break;
        }
    }
    
    return answer;
}

int main()
{
    string rsp;
    cin >> rsp;

    string answer = solution(rsp);

    cout << answer;

    return 0;
}