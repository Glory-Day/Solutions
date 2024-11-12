#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int sum = 0;
    string number = to_string(x);
    for (auto i: number) 
    {
        sum += i - '0';
    }
    
    answer = (x % sum) ? false : true;
    
    return answer;
}

int main()
{
    int x;
    cin >> x;

    bool answer = solution(x);

    cout << answer;

    return 0;
}