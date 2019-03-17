/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* _next;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			_next = cur->next;
			free(cur);
			cur = _next;
			if (prev == NULL)
			{
				head = head->next;

			}
			else
			{
				prev->next = _next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}