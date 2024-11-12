#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    
    answer = (num % 2 == 1 ? "Odd" : "Even");
    
    return answer;
}

int main()
{
    int num;
    cin >> num;

    string answer = solution(num);

    cout << answer;

    return 0;
}