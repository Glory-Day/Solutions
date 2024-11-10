#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < (int)numbers.size(); i++)
    {
        numbers[i] *= 2;
    }
    
    answer = numbers;
    
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

    vector<int> answer = solution(numbers);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}