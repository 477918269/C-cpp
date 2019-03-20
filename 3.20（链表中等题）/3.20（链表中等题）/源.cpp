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
	void reorderList(ListNode* head) {

		if (head == NULL || head->next == NULL)
			return;

		//快慢指针分出两段
		ListNode *slow = head, *fast = head;

		while (fast->next && fast->next->next){

			slow = slow->next;
			fast = fast->next->next;
		}


		//后端反转
		ListNode *needReverser = slow->next;
		slow->next = NULL;
		needReverser = reverse(needReverser);

		//插入前端缝隙
		ListNode *cur = head;
		while (cur && needReverser){
			ListNode *curSecond = needReverser;
			needReverser = needReverser->next;
			ListNode *nextCur = cur->next;
			curSecond->next = cur->next;
			cur->next = curSecond;

			cur = nextCur;
		}

	}

	ListNode *reverse(ListNode *head){

		ListNode *p1 = NULL;
		ListNode *p2 = head;
		ListNode *p3 = p2;

		while (p2){
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}

		return p1;


	}
};