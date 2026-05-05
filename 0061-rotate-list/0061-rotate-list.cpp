class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            n++;
            temp = temp->next;
        }
        k = k % n;

        while (k--) {
            ListNode* dummy = head;
            ListNode* prev = NULL;

            while (dummy->next) {
                prev = dummy;
                dummy = dummy->next;
            }

            prev->next = NULL;

            dummy->next = head;
            head = dummy;
        }

        return head;
    }
};