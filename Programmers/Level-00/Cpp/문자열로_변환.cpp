#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = to_string(n);
    return answer;
}

int main()
{
    int n;
    cin >> n;

    string answer = solution(n);

    cout << answer;

    return 0;
}