#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int age) {
    int answer = 0;
    
    answer = 2022 - age + 1;
    
    return answer;
}

int main()
{
    int age;
    cin >> age;

    int answer = solution(age);

    cout << answer;

    return 0;
}