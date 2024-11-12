#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    int sum = 0;
    for (auto i: arr) 
    {
        sum += i;
    }
    
    answer = (double)sum / (double)arr.size();
    
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

    double answer = solution(arr);

    cout << answer;

    return 0;
}