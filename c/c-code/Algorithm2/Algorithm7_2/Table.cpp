#include <iostream>
#include "Table.h"

// ����һ���ڵ�
void TableInsert(TableNode* root, TableNode* newNode) {
	TableNode* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	return;
}