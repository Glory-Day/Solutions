#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    
    int size = (int)arr.size();
    for (int i = (size % 2 == 0 ? 1 : 0); i < size; i += 2)
    {
        arr[i] += n;
    }
    
    answer = arr;
    
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

    cin >> n;

    vector<int> answer = solution(arr, n);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}