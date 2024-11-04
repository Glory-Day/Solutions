#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    switch (ineq[0])
    {
        case '<':
            answer = (int)(eq == "=" ? n <= m : n < m);
            break;
        case '>':
            answer = (int)(eq == "=" ? n >= m : n > m);
            break;
    }
    
    return answer;
}

int main()
{
    string ineq, eq;
    cin >> ineq >> eq;

    int n, m;
    cin >> n >> m;

    int answer = solution(ineq, eq, n, m);

    cout << answer;

    return 0;
}