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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        for (ListNode* i = list1; i != nullptr; i = i->next)
        {
            arr.push_back(i->val);
        }

        for (ListNode* i = list2; i != nullptr; i = i->next)
        {
            arr.push_back(i->val);
        }

        sort(arr.begin(), arr.end());

        if (arr.empty())
        {
            return nullptr;
        }

        ListNode* list = nullptr;
        ListNode* node1 = new ListNode(arr.back());
        for (int i = (int)arr.size() - 2; i >= 0; i--)
        {
            ListNode* node2 = new ListNode(arr[i], node1);
            
            node1 = node2;
        }

        list = node1;

        return list;
    }
};

int main()
{
    int n;
    cin >> n;

    ListNode* list1 = nullptr;
    if (0 < n)
    {
        vector<int> arr1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        ListNode* node1 = new ListNode(arr1.back());
        for (int i = n - 2; i >= 0; i--)
        {
            ListNode* node2 = new ListNode(arr1[i], node1);
            
            node1 = node2;
        }

        list1 = node1;
    }

    cin >> n;

    ListNode* list2 = nullptr;
    if (0 < n)
    {
        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        ListNode* node1 = new ListNode(arr2.back());
        for (int i = n - 2; i >= 0; i--)
        {
            ListNode* node2 = new ListNode(arr2[i], node1);
            
            node1 = node2;
        }

        list2 = node1;
    }

    ListNode* answer = Solution().mergeTwoLists(list1, list2);

    for (ListNode* i = answer; i != nullptr; i = i->next)
    {
        cout << i->val << ' ';
    }

    return 0;
}