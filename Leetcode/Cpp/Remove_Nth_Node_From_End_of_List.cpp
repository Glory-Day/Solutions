#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 1;

        ListNode* tmp = head;
        while (tmp->next != nullptr) {
            size++;
            tmp = tmp->next;
        }

        tmp = head;
        if (size - n == 0) {
            ListNode* node = head->next;
            delete head;
            head = node;
        }
        else {
            for (int i = 0; true; i++) {
                if (i == size - n - 1) {
                    ListNode* node = tmp->next->next;
                    delete tmp->next;
                    tmp->next = node;
                    break;
                }

                tmp = tmp->next;
            }
        }

        return head;
    }
};

int main() {
    int n, m;
    cin >> m;

    vector<int> arr;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    cin >> n;

    ListNode* head = new ListNode(arr.front());
    ListNode* tmp = head;
    for (int i = 1; i < m; i++) {
        ListNode* node = new ListNode(arr[i]);
        tmp->next = node;
        tmp = node;
    }

    ListNode* answer = Solution().removeNthFromEnd(head, n);

    while (answer->next != nullptr) {
        cout << answer->val << ' ';
        answer = answer->next;
    }
}