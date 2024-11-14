#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<tuple<string, int, int>> caches;
    for (int i = 0; i < (int)files.size(); i++)
    {
        string copy = files[i];
        
        reverse(copy.begin(), copy.end());
        
        string head = "";
        string number = "";
        while (isdigit(copy.back()) == false)
        {
            head.push_back(tolower(copy.back()));
            
            copy.pop_back();
        }
        
        while (isdigit(copy.back()) == true && (int)number.size() < 5)
        {
            number.push_back(copy.back());
            
            copy.pop_back();
        }
        
        cout << head << ' ' << number;
        
        caches.push_back(make_tuple(head, stoi(number), i));
    }
    
    sort(caches.begin(), caches.end(), 
         [](const tuple<string, int, int>& a, const tuple<string, int, int>& b) {
             if (get<0>(a) == get<0>(b))
             {
                 if (get<1>(a) == get<1>(b))
                 {
                     return get<2>(a) < get<2>(b);
                 }
                 
                 return get<1>(a) < get<1>(b);
             }
             
             return get<0>(a) < get<0>(b);
         });
    
    for (int i = 0; i < (int)caches.size(); i++)
    {
        answer.push_back(files[get<2>(caches[i])]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> files(n);
    for (int i = 0; i < n; i++)
    {
        cin >> files[i];
    }

    vector<string> answer = solution(files);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}