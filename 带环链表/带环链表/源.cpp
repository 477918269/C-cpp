ListNode *detectCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (fast == NULL || fast->next == NULL)
		return NULL;

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
-------------------- -
作者：Linkin_ygw
来源：CSDN
原文：https ://blog.csdn.net/linkin_ygw/article/details/54644863 
版权声明：本文为博主原创文章，转载请附上博文链接！