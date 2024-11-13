#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> a, b;
    for (int i = 0; i < (int)topping.size(); i++)
    {
        if (a.find(topping[i]) == a.end())
        {
            a[topping[i]] = 1;
        }
        else
        {
            a[topping[i]]++;
        }
    }
    
    for (int i = 0; i < (int)topping.size(); i++)
    {
        a[topping[i]]--;
        if (a[topping[i]] == 0)
        {
            a.erase(topping[i]);
        }
        
        if (b.find(topping[i]) == b.end())
        {
            b[topping[i]] = 1;
        }
        else
        {
            b[topping[i]]++;
        }
        
        if ((int)a.size() == (int)b.size())
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> topping(n);
    for (int i = 0; i < n; i++)
    {
        cin >> topping[i];
    }

    int answer = solution(topping);

    cout << answer;

    return 0;
}