#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    
    for (int i = 0; i < (int)index_list.size(); i++)
    {
        answer.push_back(my_string[index_list[i]]);
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int n;
    cin >> n;

    vector<int> index_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> index_list[i];
    }

    string answer = solution(my_string, index_list);

    cout << answer;

    return 0;
}