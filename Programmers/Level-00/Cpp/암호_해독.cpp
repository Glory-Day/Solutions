#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    for (int i = code - 1; i < (int)cipher.length(); i += code)
    {
        answer.push_back(cipher[i]);
    }
    
    return answer;
}

int main()
{
    string cipher;
    cin >> cipher;

    int code;
    cin >> code;

    string answer = solution(cipher, code);

    cout << answer;

    return 0;
}