#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    vector<char> caches = { 'a','e','i','o','u' };
    for (int i = 0; i < 5; i++)
    {
        auto iter = my_string.find(caches[i]);
        while (iter != string::npos)
        {
            my_string.erase(iter, 1);
            
            iter = my_string.find(caches[i]);
        }
    }
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    string answer = solution(my_string);

    cout << answer;

    return 0;
}