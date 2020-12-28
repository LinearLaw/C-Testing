/**
 * C����ʵ�ֵĺ����(Red Black Tree)
 *
 * @author skywang
 * @date 2013/11/18
 */

#include <stdio.h>
#include "rbtree.h"
#include "MySet.h"

#define CHECK_INSERT 0    // "����"�����ļ�⿪��(0���رգ�1����)
#define CHECK_DELETE 0    // "ɾ��"�����ļ�⿪��(0���رգ�1����)
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

void pastMain() {
    int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
    int i, ilen = LENGTH(a);
    RBRoot* root = NULL;

    root = create_rbtree();
    printf("== ԭʼ����: ");
    for (i = 0; i < ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < ilen; i++)
    {
        insert_rbtree(root, a[i]);
#if CHECK_INSERT
        printf("== ��ӽڵ�: %d\n", a[i]);
        printf("== ������ϸ��Ϣ: \n");
        print_rbtree(root);
        printf("\n");
#endif
    }

    printf("== ǰ�����: ");
    preorder_rbtree(root);

    printf("\n== �������: ");
    inorder_rbtree(root);

    printf("\n== �������: ");
    postorder_rbtree(root);
    printf("\n");

    if (rbtree_minimum(root, &i) == 0)
        printf("== ��Сֵ: %d\n", i);
    if (rbtree_maximum(root, &i) == 0)
        printf("== ���ֵ: %d\n", i);
    printf("== ������ϸ��Ϣ: \n");
    print_rbtree(root);
    printf("\n");

#if CHECK_DELETE
    for (i = 0; i < ilen; i++)
    {
        delete_rbtree(root, a[i]);

        printf("== ɾ���ڵ�: %d\n", a[i]);
        if (root)
        {
            printf("== ������ϸ��Ϣ: \n");
            print_rbtree(root);
            printf("\n");
        }
    }
#endif

    destroy_rbtree(root);
}

void printArray(int a[], int length) {
	for (int i = 0; i < length; i++) {
		if (i != 0) {
			printf(", ");
		}
		printf("%d", a[i]);
	}
	printf("\n\n");
}

void currentMain() {
	int a[] = { 12,23,53,25,34,24,32,78,66 };

	printf("\n------------\n");

	// 1����ʼ��һ��set
	printf("== 1��set_init\n");
	Set* set = (Set*)malloc(sizeof(Set));
	int res1 = set_init(set, a, sizeof(a) / sizeof(a[0]));	
	print_set(set);	
	printf("Result: %d \n", res1);

	printf("\n------------\n");

	// 2������һ���ڵ�
	printf("== 2��set_insert\n");
	int res2 = set_insert(set, 30);
	print_set(set);
	printf("Result: %d \n", res2);
	
	printf("\n------------\n");

	// 3��ɾ��һ���ڵ�
	printf("== 3��set_remove\n");
	int res3 = set_remove(set, 30);
	print_set(set);
	printf("Result: %d \n", res3);

	printf("\n------------\n");

	// 4����սڵ�
	printf("== 4��set_clear\n");
	int res4 = set_clear(set);
	print_set(set);
	printf("Result: %d \n", res4);

	printf("\n------------\n");

	// 5������һ���ڵ�
	printf("== 5��set_find\n");
	int res5 = set_find(set,30);
	print_set(set);
	printf("Result: %d \n", res5);

	printf("\n------------\n");
	printf("== ����1\n");
	int a1[] = { 12,3,4,5,6,7,8,9,10 };	 // ����1
	int a1Len = sizeof(a1) / sizeof(a1[0]);
	Set* set1 = (Set*)malloc(sizeof(Set));
	set_init(set1, a1, a1Len);
	printf("a1:");
	printArray(a1,a1Len);

	printf("== ����2\n");
	int a2[] = {4,5,3,34,235,36};	// ����2
	int a2Len = sizeof(a2) / sizeof(a2[0]);
	Set* set2 = (Set*)malloc(sizeof(Set));
	set_init(set2, a2, a2Len);
	printf("a2:");
	printArray(a2, a2Len);

	printf("\n------------\n");
	// 6�������������ϵĽ���
	printf("== 6��set_intersection\n");
	Set* seti = (Set*)malloc(sizeof(Set));	// ����
	set_create(seti);
	set_intersection(seti, set1, set2);
	print_set(seti);

	printf("\n------------\n");
	// 7�������������ϵĲ���
	printf("== 7��set_union\n");
	Set* setu = (Set*)malloc(sizeof(Set));	// ����
	set_create(setu);
	set_union(setu, set1, set2);
	print_set(setu);

	printf("\n------------\n");
	// 8�������������ϵĲ
	printf("== 7��set_union\n");
	Set* setd = (Set*)malloc(sizeof(Set));	// �
	set_create(setd);
	set_difference(setd, set1, set2);
	print_set(setd);
}



void main()
{
	// pastMain();

	printf("------------\n");

	currentMain();
}