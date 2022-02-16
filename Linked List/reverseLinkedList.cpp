/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:
      Input: head = [1,2,3,4,5]
      Output: [5,4,3,2,1]
*/

// 3-pointer solution
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* n = curr->next;

    while(n != NULL) {
        curr->next = prev;
        prev = curr;
        curr = n;
        n = n->next;
    }

    //Joininh the last node in the original array to the second last node
    curr->next = prev;

    return curr;
}

// Time Complexity = O(n)
