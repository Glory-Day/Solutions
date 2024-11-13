#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

using pii = pair<int, int>;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    stack<pii> st;
    st.push({ 0,numbers[0] });
    
    vector<int> caches((int)numbers.size());
    
    for (int i = 1; i < (int)numbers.size(); i++)
    {
        while (true)
        {
            if (st.empty() == false && st.top().second < numbers[i])
            {
                caches[st.top().first] = numbers[i];
                
                st.pop();
            }
            else
            {
                st.push({ i,numbers[i] });
                
                break;
            }
        }
    }
    
    while (st.empty() == false)
    {
        caches[st.top().first] = -1;
        st.pop();
    }
    
    answer = caches;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    vector<int> answer = solution(numbers);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}