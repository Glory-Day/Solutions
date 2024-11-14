#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    answer = arr[0];
    for (int i = 1; i < (int)arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = solution(arr);

    cout << answer;

    return 0;
}