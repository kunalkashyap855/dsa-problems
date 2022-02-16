/*
    Given head, the head of a linked list, determine if the linked list has a cycle in it.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool hasCycle(ListNode *head) {
    if(head == NULL)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}

// Time Complexity = O(n) and Space Complexity = O(1)
// Another approach is to just have one pointer temp to traverse through the whole linked list, and as each node is traversed, change its val to something out of
// range so that you can check if the current node has that value or not, if it has that value, then there is a cycle.
