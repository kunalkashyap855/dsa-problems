/*
    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:
    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Example 1:
      Input: head = [1,2,3,4]
      Output: [1,4,2,3]
*/

void reorderList(ListNode* head) {
    if(!head)
        return;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* head2 = slow->next;
    ListNode* prev = NULL; 
    slow->next = NULL;

    // reversing second half of list
    while(head2) {
        ListNode* temp = head2->next;
        head2->next = prev;
        prev = head2;
        head2 = temp;
    }

    // Merging the two lists
    ListNode* first = head;
    ListNode* second = prev;

    while(second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

// Time Complexity = O(n) and Space Complexity = O(1)
