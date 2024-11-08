#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = "";
    
    swap(my_string[num1], my_string[num2]);
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int num1, num2;
    cin >> num1 >> num2;

    string answer = solution(my_string, num1, num2);

    cout << answer;

    return 0;
}