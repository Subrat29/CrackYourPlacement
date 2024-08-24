#include <vector>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // Dummy node to handle edge cases more easily
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Step 1: Move `prev` to the node just before `left`
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Step 2: Reverse the sublist from `left` to `right`
    ListNode* curr = prev->next;
    ListNode* next = nullptr;
    ListNode* reverseTail = curr;

    for (int i = left; i <= right; i++) {
        next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }

    // Step 3: Connect the tail of the reversed sublist to the remaining part
    reverseTail->next = curr;

    // Step 4: Return the modified list
    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Creating the linked list [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    std::cout << "Reversed List between positions " << left << " and " << right << ": ";
    printList(head);

    // Test Case 2: Creating the linked list [5]
    ListNode* singleNode = new ListNode(5);

    std::cout << "Original Single Node List: ";
    printList(singleNode);

    int singleLeft = 1, singleRight = 1;
    singleNode = reverseBetween(singleNode, singleLeft, singleRight);

    std::cout << "Reversed Single Node List between positions " << singleLeft << " and " << singleRight << ": ";
    printList(singleNode);

    return 0;
}
