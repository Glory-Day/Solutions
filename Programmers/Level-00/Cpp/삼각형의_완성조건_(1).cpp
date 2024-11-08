#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    sort(sides.begin(), sides.end());
    
    if (sides[2] < sides[0] + sides[1])
    {
        answer = 1;
    }
    else
    {
        answer = 2;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> sides(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sides[i];
    }

    int answer = solution(sides);

    cout << answer;

    return 0;
}