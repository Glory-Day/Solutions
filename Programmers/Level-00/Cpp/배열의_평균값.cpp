#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for (int i = 0; i < (int)numbers.size(); i++)
    {
        answer += (double)numbers[i];
    }
    
    answer /= (double)numbers.size();
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> emergency(n);
    for (int i = 0; i < n; i++)
    {
        cin >> emergency[i];
    }

    double answer = solution(emergency);

    cout << answer;

    return 0;
}