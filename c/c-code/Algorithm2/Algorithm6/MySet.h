
/*	set����
	1�����е�Ԫ�ػ����Ԫ�صļ�ֵ�Զ�����
	2��set��Ԫ�ؼ���keyҲ��value -> Ҳ���ǵ����ڵ�ֻ��һ��ֵ
	3��set����������Ԫ������ͬ��key

 */

#include "rbtree.h"

typedef struct {
	RBTree* tree;
	int length;
} Set;

// 1����ʼ��һ��set
int set_init(Set* set, int data[], int length);

// 2������һ���ڵ�
int set_insert(Set *set, void  *data);

// 3��ɾ��һ���ڵ�
int set_remove(Set *set, void **data);

// 4����սڵ�
int set_clear(Set *set);

// 5������һ���ڵ�
int set_find(Set* set, void *data);

// 6�����������ϵĽ���
int set_intersection(Set *seti, Set *set1, Set *set2);

// 7�����������ϵĲ���
int set_union(Set *setu, Set *set1, Set *set2);

// 8�����������ϵĲ
int set_difference(Set *setd, Set *set1, Set *set2);