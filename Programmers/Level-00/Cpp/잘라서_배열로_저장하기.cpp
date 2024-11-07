#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    string cache = "";
    for (int i = 0; i < (int)my_str.length(); i++)
    {
        if (0 < i && i % n == 0)
        {
            answer.push_back(cache);
            cache.clear();
        }
        
        cache.push_back(my_str[i]);
    }
    
    if (0 < (int)cache.length())
    {
        answer.push_back(cache);
    }
    
    return answer;
}

int main()
{
    string my_str;
    cin >> my_str;

    int n;
    cin >> n;

    vector<string> answer = solution(my_str, n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}