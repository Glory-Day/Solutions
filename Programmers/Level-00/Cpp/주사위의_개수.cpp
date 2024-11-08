#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    
    answer = (box[0] / n) * (box[1] / n) * (box[2] / n);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> box(n);
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
    }

    cin >> n;

    int answer = solution(box, n);

    cout << answer;

    return 0;
}