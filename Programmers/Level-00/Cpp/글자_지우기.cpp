#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    sort(indices.begin(), indices.end());
    
    for (int i = 0, j = 0; i < (int)my_string.length(); i++)
    {
        if (i == indices[j])
        {
            j++;
            
            continue;
        }
        
        answer.push_back(my_string[i]);
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int n;
    cin >> n;

    vector<int> indices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> indices[i];
    }

    string answer = solution(my_string, indices);

    cout << answer;

    return 0;
}