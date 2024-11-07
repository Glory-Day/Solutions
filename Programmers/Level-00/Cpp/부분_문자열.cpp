#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    answer = (int)(str2.find(str1) != string::npos);
    
    return answer;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int answer = solution(str1, str2);
    
    cout << answer;

    return 0;
}