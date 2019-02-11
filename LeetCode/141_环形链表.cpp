/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *oneStep = head;
        ListNode *twoSteps = head;

        while (oneStep->next != NULL && twoSteps->next != NULL && twoSteps->next->next != NULL)
        {
            oneStep = oneStep->next;
            twoSteps = twoSteps->next->next;
            if (oneStep == twoSteps)
            {
                return true;
            }
        }

        return false;
    }
};