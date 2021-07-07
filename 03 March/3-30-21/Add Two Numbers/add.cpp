#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *finalSum = new ListNode();
        ListNode *nextl1 = l1;
        ListNode *nextl2 = l2;
        ListNode *nextSum = finalSum;
        while (nextl1 || nextl2)
        {
            int l1Val = nextl1 ? (*nextl1).val : 0;
            int l2Val = nextl2 ? (*nextl2).val : 0;
            int sum = (*nextSum).val + l1Val + l2Val;
            int carry = 0;
            if (sum >= 10)
            {
                sum = sum - 10;
                carry = 1;
            }
            (*nextSum).val = (!nextl1 && !nextl2 && carry == 1) ? carry : sum;
            if (nextl1) nextl1 = nextl1 -> next;
            if (nextl2) nextl2 = nextl2 -> next;
            if (nextl1 || nextl2 || carry == 1)
            {
                (*nextSum).next = new ListNode(carry);
                nextSum = nextSum -> next;
            }
        }
        return finalSum;
    }
int main()
{
    ListNode l1 {2, (new ListNode(4, new ListNode(3)))};
    ListNode l2 {5, (new ListNode(6, new ListNode(4)))};
    // ListNode l1 {9, (new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))))};
    // ListNode l2 {9, (new ListNode(9, new ListNode(9, new ListNode(9))))};
    ListNode *sum = addTwoNumbers(&l1, &l2);
    ListNode *nextNode = sum;
    while (nextNode)
    {
        cout << (*nextNode).val << " ";
        nextNode = nextNode -> next; 
    }
    cout << endl;
}