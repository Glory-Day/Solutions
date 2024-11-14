#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const string to_n_number(int number, const int n)
{
    string result = "";
    
    map<int, char> mp = { {10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'} };
    
    if (0 < number)
    {
        while (0 < number)
        {        
            int mod = number % n;
            number /= n;

            result.push_back((mod < 10 ? mod + '0' : mp[mod]));
        }

        reverse(result.begin(), result.end());
    }
    else
    {
        result = "0";
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int index = 0;
    string cache = "";
    while (0 < t)
    {
        cache.append(to_n_number(index, n));
        
        if (index % m == p - 1)
        {
            answer.push_back(cache[index]);
            
            t--;
        }
        
        index++;
    }
    
    return answer;
}

int main()
{
    int n, t, m, p;
    cin >> n >> t >> m >> p;

    string answer = solution(n, t, m, p);

    cout << answer;

    return 0;
}