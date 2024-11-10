#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    answer += hp / 5;
    hp %= 5;
    
    answer += hp / 3;
    hp %= 3;
    
    answer += hp / 1;
    hp %= 1;
    
    return answer;
}

int main()
{
    int hp;
    cin >> hp;

    int answer = solution(hp);

    cout << answer;

    return 0;
}