#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    
    answer = (int)(my_string.find(target) != string::npos);
    
    return answer;
}

int main()
{
    string my_string, target;
    cin >> my_string >> target;

    int answer = solution(my_string, target);
    
    cout << answer;

    return 0;
}