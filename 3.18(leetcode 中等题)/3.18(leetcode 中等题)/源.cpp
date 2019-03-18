/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* cur = head;
		ListNode* pur = head->next;
		ListNode* newhead = pur;

		while (cur && cur->next)
		{
			ListNode* key = pur->next;
			if (key != nullptr && key->next != nullptr)
			{
				pur->next = cur;
				cur->next = key->next;
				cur = key;
				pur = key->next;
			}
			else
			{
				pur->next = cur;
				cur->next = key;
				cur = key;


			}


		}
		return newhead;
	}
};