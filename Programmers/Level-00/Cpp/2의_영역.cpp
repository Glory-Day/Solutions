#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    deque<int> caches(arr.begin(), arr.end());
    while (caches.empty() == false)
    {
        if (caches.front() == 2)
        {
            break;
        }
        
        caches.pop_front();
    }
    
    while (caches.empty() == false)
    {
        if (caches.back() == 2)
        {
            break;
        }
        
        caches.pop_back();
    }
    
    if (caches.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        for (int i = 0; i < (int)caches.size(); i++)
        {
            answer.push_back(caches[i]);
        }
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

    vector<int> answer = solution(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}