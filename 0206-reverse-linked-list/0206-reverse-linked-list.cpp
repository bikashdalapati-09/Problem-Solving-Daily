/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;

        while (head) {
            st.push(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(0);
        head = dummy;

        while (!st.empty()) {
            int val = st.top();
            dummy->next = new ListNode(val);
            st.pop();
            dummy = dummy->next;
        }
        return head->next;
    }
};