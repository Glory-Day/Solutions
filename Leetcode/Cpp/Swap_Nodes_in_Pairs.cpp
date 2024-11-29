#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tail = head;
        while (tail != nullptr)
        {
            if (tail->next == nullptr)
            {
                break;
            }

            swap(tail->val, tail->next->val);

            tail = tail->next->next;
        }

        return head;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    if (0 < n)
    {
        head = tail = new ListNode(arr[0]);
        for (int i = 1; i < n; i++)
        {
            tail->next = new ListNode(arr[i]);

            tail = tail->next;
        }
    }

    ListNode* answer = Solution().swapPairs(head);

    for (ListNode* i = answer; i != nullptr; i = i->next)
    {
        cout << i->val << ' ';
    }
}