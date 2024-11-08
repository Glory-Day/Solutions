#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer;
    
    sort(array.begin(), array.end(), [&](const int a, const int b) {
        if (abs(a - n) == abs(b - n))
        {
            return a < b;
        }
        
        return abs(a - n) < abs(b - n);
    });
    
    answer = array[0];
    
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

    cin >> n;

    int answer = solution(array, n);

    cout << answer;

    return 0;
}