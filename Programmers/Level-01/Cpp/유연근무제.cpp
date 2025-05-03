
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
    int answer = 0;

    int n = (int)schedules.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        int hour = (schedules[i] / 100) * 100;
        int minute = schedules[i] % 100 + 10;
        hour += (minute / 60) * 100;
        hour += minute % 60;

        schedules[i] = hour;

        int day = startday;
        for (int j = 0; j < 7; j++, day++)
        {
            if (day > 7)
            {
                day = 1;
            }

            if (day == 6 || day == 7)
            {
                count++;

                continue;
            }

            if (schedules[i] >= timelogs[i][j])
            {
                count++;
            }
        }

        if (count == 7)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> schedules(n);
    for (int i = 0; i < n; i++)
    {
        cin >> schedules[i];
    }

    vector<vector<int>> timelogs(n, vector<int>(7));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> timelogs[i][j];
        }
    }

    int startday;
    cin >> startday;

    int answer = solution(schedules, timelogs, startday);

    cout << answer;
}