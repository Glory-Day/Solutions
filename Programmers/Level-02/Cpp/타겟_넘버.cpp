#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[21];
int result;

void DFS(vector<int> numbers, int sum, int level, int target) {
    for(int i = level; i < numbers.size(); i++) {
        sum -= (numbers[i] * 2);
        
        //cout << level << ": " << sum << endl;
        
        if(sum == target) result++;
        else if(sum < target) {
            sum += (numbers[i] * 2);
            continue;
        }
        else DFS(numbers, sum, i + 1, target);
        
        sum += (numbers[i] * 2);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    int sum = 0;
    for (auto i: numbers)
    {
        sum += i;
    }
    
    if (sum == target) return 1;
    else DFS(numbers, sum, 0, target);
    
    return result;
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

    int target;
    cin >> target;

    int answer = solution(numbers, target);

    cout << answer;

    return 0;
}