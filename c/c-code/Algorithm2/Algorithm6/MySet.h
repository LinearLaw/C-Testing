
/*	set����
	1�����е�Ԫ�ػ����Ԫ�صļ�ֵ�Զ�����
	2��set��Ԫ�ؼ���keyҲ��value -> Ҳ���ǵ����ڵ�ֻ��һ��ֵ
	3��set����������Ԫ������ͬ��key

 */

#include "rbtree.h"

typedef struct {
	RBRoot* tree;
	int length;
} Set;

// 1����ʼ��һ��set
int set_create(Set* set);
int set_init(Set* set, int data[], int length);

// 2������һ���ڵ�
int set_insert(Set *set, int  data);

// 3��ɾ��һ���ڵ�
int set_remove(Set *set, int data);

// 4����սڵ�
int set_clear(Set *set);

// 5������һ���ڵ�
int set_find(Set* set, int data);

// 6�����������ϵĽ���
int set_intersection(Set *seti, Set *set1, Set *set2);

// 7�����������ϵĲ���
int set_union(Set *setu, Set *set1, Set *set2);

// 8�����������ϵĲ
int set_difference(Set *setd, Set *set1, Set *set2);

void print_set(Set* set);
void set_preorder_findi(Set* seti, RBTree tree, Set *set2);
void set_preorder_findu(Set* seti, RBTree tree);
void set_preorder_findd(Set* setd, RBTree tree, Set *set2);