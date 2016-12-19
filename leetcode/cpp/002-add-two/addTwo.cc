/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *r = &head;
        int c = 0, s= 0;

        while (l1 != NULL || l2 != NULL) {
            s = ((l1 != NULL) ? l1->val : 0) +
                ((l2 != NULL) ? l2->val : 0) +
                c;
            r->next = new ListNode(s % 10);
            r = r->next;
            c = s / 10;

            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }

        if (c != 0) {
            r->next = new ListNode(c);
            r = r->next;
        }

        return head.next;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v1 = {2, 4, 3, 8};
    vector<int> v2 = {5, 6, 4, 9};

    ListNode head1(0);
    ListNode head2(0);
    ListNode *l1 = &head1, *l2 = &head2;

    for (unsigned int i = 0; i != v1.size(); i++) {
        l1->next = new ListNode(v1[i]);
        l1 = l1->next;
        l2->next = new ListNode(v2[i]);
        l2 = l2->next;
    }

    l2->next = new ListNode(9);
    l2 = l2->next;
    l2->next = new ListNode(9);
    l2 = l2->next;

    ListNode *r = s.addTwoNumbers(head1.next, head2.next);

    while (r != NULL) {
        cout << r->val << "\t";
        r = r->next;
    }

    cout << endl;
    return 0;
}
