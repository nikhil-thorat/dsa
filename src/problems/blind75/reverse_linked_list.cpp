#include <bits/stdc++.h>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
} ListNode;

void solve()
{
    /*
     * PROBLEM STATEMENT
     * Given the beginning of singly linked list head,
     * reverse the list and return the new beginning of
     * the list.
     *
     * EXAMPLE
     * Input : head = {0,1,2,3,4}
     * Output : {4,3,2,1,0}
     *
     * BRUTE FORCE APPROACH
     * Convert the linked list into the array, reverse
     * the array and then convert the reversed array
     * back into the linked list. Time complexity
     * O(N). Space complexity O(N).
     *
     * OPTIMIAL APPROACH
     * In-place reversal, use prev and curr pointers
     * with next pointer to keep track of the list
     * and update the pointer of curr to point at
     * prev, update prev and curr. Time complexity
     * becomes O(N). Space complexity becomes O(1).
     */

    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    ListNode *curr = head;

    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    std::cout << std::endl;

    ListNode *prev = NULL;
    curr = head;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    curr = head;

    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 0;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
