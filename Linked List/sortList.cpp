/*
    Given the head of a linked list, return the list after sorting it in ascending order.

    Example 1:
      Input: head = [4,2,1,3]
      Output: [1,2,3,4]
    
    Example 2:
      Input: head = [-1,5,3,4,0]
      Output: [-1,0,3,4,5]
*/

ListNode* mergeLL(ListNode* list1, ListNode* list2) {
    ListNode* mergedHead = new ListNode();
    ListNode* i = NULL; ListNode* j = NULL;

    // comparing the first elements of both lists to set head
    if(list1->val <= list2->val) {
        mergedHead = list1;
        i = list1->next;
        j = list2;
    } else {
        mergedHead = list2;
        i = list1;
        j = list2->next;
    }

    ListNode* temp = mergedHead;
    while(i != NULL && j != NULL) {
        if(i->val <= j->val) {
            temp->next = i;
            temp = temp->next;
            i = i->next;
        } else {
            temp->next = j;
            temp = temp->next;
            j = j->next;
        }
    }

    // If one list if finished then adding the rest of the other list to the answer
    if(i != NULL) {
        while(i != NULL) {
            temp->next = i;
            temp = temp->next;
            i = i->next;
        }
    } else if(j != NULL) {
        while(j != NULL) {
            temp->next = j;
            temp = temp->next;
            j = j->next;
        }
    }

    return mergedHead;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    // split LL into two halves
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    ListNode* head2 = slow;
    prev->next = NULL;

    // sort two halves
    ListNode* sortedH1 = sortList(head);
    ListNode* sortedH2 = sortList(head2);

    // merge two sorted halves
    return mergeLL(sortedH1, sortedH2);
}

// Time Complexity = O(nlogn); Extra Space Complexity = O(n) <= because we are making a new LL while merging.
