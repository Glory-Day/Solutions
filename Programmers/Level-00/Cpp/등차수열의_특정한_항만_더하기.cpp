#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    for (int i = 0, j = a; i < (int)included.size(); i++, j += d)
    {
        answer += (included[i] == true ? j : 0);
    }
    
    return answer;
}

int main()
{
    int a, d;
    cin >> a >> d;

    int n;
    cin >> n;

    vector<bool> included;
    for (int i = 0; i < n; i++)
    {
        int cache;
        cin >> cache;
        
        included.push_back(cache);
    }

    int answer = solution(a, d, included);

    cout << answer;

    return 0;
}