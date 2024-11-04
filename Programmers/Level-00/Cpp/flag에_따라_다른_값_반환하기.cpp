#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = (flag == true ? a + b : a - b);
    
    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    bool flag;
    cin >> flag;

    int answer = solution(a, b, flag);

    cout << answer;

    return 0;
}