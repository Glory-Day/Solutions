#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    for (int i = 0; i < (int)numbers.size() && answer <= n; i++)
    {
        answer += numbers[i];
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cin >> n;

    int answer = solution(numbers, n);
    
    cout << answer;

    return 0;
}