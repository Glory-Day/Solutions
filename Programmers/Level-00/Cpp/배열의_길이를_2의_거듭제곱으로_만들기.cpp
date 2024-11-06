#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int length = 1;
    while (length < (int)arr.size())
    {
        length *= 2;
    }
    
    int size = (int)arr.size();
    for (int i = 0; i < length - size; i++)
    {
        arr.push_back(0);
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

    vector<int> answer = solution(arr);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}