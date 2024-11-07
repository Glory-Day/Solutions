#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    int answer = 0;
    
    if (date1[0] < date2[0])
    {
        answer = 1;
    }
    else if (date1[0] > date2[0])
    {
        answer = 0;
    }
    else if (date1[1] < date2[1])
    {
        answer = 1;
    }
    else if (date1[1] > date2[1])
    {
        answer = 0;
    }
    else if (date1[2] < date2[2])
    {
        answer = 1;
    }
    else if (date1[2] >= date2[2])
    {
        answer = 0;
    }
    
    return answer;
}

int main()
{
    vector<int> date1(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> date1[i];
    }

    vector<int> date2(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> date2[i];
    }

    int answer = solution(date1, date2);

    cout << answer;

    return 0;
}