#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    switch (n)
    {
        case 1:
            answer.insert(answer.begin(), num_list.begin(), num_list.begin() + slicer[1] + 1);
            
            break;
        case 2:
            answer.insert(answer.begin(), num_list.begin() + slicer[0], num_list.end());
            
            break;
        case 3:
            answer.insert(answer.begin(), num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
            
            break;
        case 4:
            for (int i = slicer[0]; i <= slicer[1]; i += slicer[2])
            {
                answer.push_back(num_list[i]);
            }
            
            break;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> slicer(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> slicer[i];
    }

    int m;
    cin >> m;

    vector<int> num_list(m);
    for (int i = 0; i < m; i++)
    {
        cin >> num_list[i];
    }

    vector<int> answer = solution(n, slicer, num_list);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}