#pragma once


typedef struct TableNode {
	int index;	// �ڽӽڵ������
	int distance;	// ���ڽӽڵ�ľ���
	TableNode* next;
}TableNode;


void TableInsert(TableNode* root, TableNode* newNode);