#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    answer = count_if(array.begin(), array.end(), [&](const int n) {
        return height < n;
    });
    
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

    int height;
    cin >> height;

    int answer = solution(array, height);

    cout << answer;

    return 0;
}