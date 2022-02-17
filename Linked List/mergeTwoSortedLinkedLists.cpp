/*
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

    Example 1:
      Input: list1 = [1,2,4], list2 = [1,3,4]
      Output: [1,1,2,3,4,4]
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // checking if one or both the lists are empty
    if(list1 == NULL && list2 == NULL)
        return list1;
    else if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;

    ListNode* head = new ListNode();
    ListNode* i = NULL; ListNode* j = NULL;

    // comparing the first elements of both lists to set head
    if(list1->val <= list2->val) {
        head = list1;
        i = list1->next;
        j = list2;
    } else {
        head = list2;
        i = list1;
        j = list2->next;
    }

    ListNode* temp = head;
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

    return head;
}

// Time Complexity = O(n) <= where 'n' is the length of the longer list
