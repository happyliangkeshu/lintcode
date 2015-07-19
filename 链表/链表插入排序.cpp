// 链表插入排序
// 用插入排序对链表排序
// Given 1->3->2->0->null, return 0->1->2->3->null

// 查找插入位置
ListNode * findinsertpos(ListNode *head, ListNode * ins){
	auto p = head;
	auto p_prev = p;
	while(p && ins->val > p->val){
		p_prev = p;
		p = p->next;
	}
	return p_prev;
}
ListNode *insertionSortList(ListNode *head) {
	ListNode dummy(INT_MIN);
	// dummy结点，如果插入位置在head之前，也没问题。
	auto p = head;
	while(p){
		auto pos = findinsertpos(&dummy, p);
		auto temp = p->next;
		// p是要插入的元素，p插入在pos与pos->next 之间
		p->next = pos->next;
		pos->next = p;
		
		p = temp;
	}
	return dummy.next;
}