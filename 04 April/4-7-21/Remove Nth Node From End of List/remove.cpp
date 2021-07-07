#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int lengthOfNodeList(ListNode* head)
{
    int index = 0;
    while (head)
    {
        head = (*head).next;
        index++;
    }
    return index;
}
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int length = lengthOfNodeList(head);
    int indexToRemove = length - n;
    int nextIndex = 0;
    ListNode* currentHead = &(*head);
    while (currentHead)
    {
        if (length == 1) return nullptr;

        else if (nextIndex+1 == length - 1 && nextIndex+1 == indexToRemove) 
        { 
            (*currentHead).next = nullptr; 
            return head; 
        }
        else if (nextIndex == indexToRemove)
        {
            (*currentHead).val = (*(*currentHead).next).val;
            (*currentHead).next = (*(*currentHead).next).next;
            currentHead = (*currentHead).next;
            nextIndex++;
        }
        else
        {
            currentHead = (*currentHead).next;
            nextIndex++;
        }
    }
    return head;
}
int main()
{
    ListNode* listnode = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    // ListNode* listnode = new ListNode(1, new ListNode(2));
    ListNode* removedList = removeNthFromEnd(listnode, 2);

    while (removedList)
    {
        cout << (*removedList).val << endl;
        removedList = (*removedList).next;
    }
}
