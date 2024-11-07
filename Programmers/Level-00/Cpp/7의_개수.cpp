#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for (int i = 0; i < (int)array.size(); i++)
    {
        string cache = to_string(array[i]);
        answer += count(cache.begin(), cache.end(), '7');
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int answer = solution(array);

    cout << answer;

    return 0;
}