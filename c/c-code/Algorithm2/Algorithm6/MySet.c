
#include <stdio.h>
#include <stdlib.h>

#include "MySet.h";

/*
	ʹ��rbtreeʵ��STL set

	����ֵ��
		1 �ɹ�
		0 ʧ��
*/

// 1����ʼ��һ��set
int set_create(Set* set) {
	set->tree = create_rbtree();
	set->length = 0;
	return 1;
}
int set_init(Set* set, int data[], int length) {

	// ����һ�ú����
	set_create(set);
	int successCount = 0;
	for (int i = 0; i < length; i++) {
		if (set_insert(set, data[i]) == 1) {
			successCount++;
		}
	}
	printf("== set init success\n");
	printf("== insert count:%d\n", length);
	printf("== success count:%d\n", successCount);
	return 1;
};

// 2������һ���ڵ�
int set_insert(Set *set, int data) {
	if (set == NULL) {
		return 0;
	}
	if (insert_rbtree(set->tree, data) == 0) {
		set->length++;
		return 1;
	}
	return 0;
};

// 3��ɾ��һ���ڵ�
int set_remove(Set *set, int data) {
	if (set == NULL) {
		return 0;
	}
	delete_rbtree(set->tree, data);
	return 1;
};

// 4����սڵ�
int set_clear(Set *set) {
	if (set == NULL) {
		return 0;
	}
	destroy_rbtree(set->tree);
	set->tree = NULL;
	set->length = 0;
	return 1;
};

// 5������һ���ڵ�
int set_find(Set* set, int data) {
	if (set == NULL) {
		return 0;
	}
	if (rbtree_search(set->tree, data) == 0) {
		return 1;
	}
	return 0;
};

/* 6�����������ϵĽ���
	ǰ�����set1��ÿ������һ���ڵ㣬��ȥset2�в��Ҹýڵ��Ƿ���ڣ�
		������ڣ�������뵽seti
*/
int set_intersection(Set *seti, Set *set1, Set *set2) {
	set_preorder_findi(seti, set1->tree->node, set2);
	return 1;
};
void set_preorder_findi(Set* seti, RBTree tree, Set *set2)
{
	if (tree != NULL)
	{
		if (set_find(set2, tree->key) == 1) {
			set_insert(seti, tree->key);
		}
		set_preorder_findi(seti,tree->left,set2);
		set_preorder_findi(seti,tree->right,set2);
	}
}

/* 7�����������ϵĲ���
	�ֱ����set1��set2��������뵽setu���ɡ�
*/
int set_union(Set *setu, Set *set1, Set *set2) {
	set_preorder_findu(setu, set1->tree->node);
	set_preorder_findu(setu, set2->tree->node);
	return 1;
};
void set_preorder_findu(Set* seti, RBTree tree)
{
	if (tree != NULL)
	{
		set_insert(seti, tree->key);
		set_preorder_findu(seti, tree->left);
		set_preorder_findu(seti, tree->right);
	}
}

/* 8�����������ϵĲ
	ǰ�����set1��ÿ�ν�����key��set2�в��ң�û�в��ҵ�����뵽setd
	ǰ�����set2��ÿ�ν�����key��set1�в��ң�û�в��ҵ�����뵽setd

*/
int set_difference(Set *setd, Set *set1, Set *set2) {
	set_preorder_findd(setd, set1->tree->node, set2);
	set_preorder_findd(setd, set2->tree->node, set1);
	return 1;
};
void set_preorder_findd(Set* setd, RBTree tree, Set *set2)
{
	if (tree != NULL)
	{
		if (set_find(set2, tree->key) != 1) {
			set_insert(setd, tree->key);
		}
		set_preorder_findd(setd, tree->left,set2);
		set_preorder_findd(setd, tree->right, set2);
	}
}

// 9����ӡset
void print_set(Set* set) {
	if (set != NULL) {
		printf("\n== set����ϸ��Ϣ\n");
		printf("set length:%d\n", set->length);
		print_rbtree(set->tree);
	}
};