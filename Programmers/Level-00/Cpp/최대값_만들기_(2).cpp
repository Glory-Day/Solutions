#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    int l = (int)numbers.size();
    int a = numbers[0] * numbers[1];
    int b = numbers[l - 1] * numbers[l - 2];
    
    answer = (a < b ? b : a);
    
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

    int answer = solution(numbers);

    cout << answer;

    return 0;
}