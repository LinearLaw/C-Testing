// ˳�������㷨

#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;

// ����Ԫ�ص�����
typedef struct{
	KeyType key;
	InfoType data;
} RecType;

// x��y��˳����н���
void swap(RecType x,RecType y){
	RecType tmp = x;
	x=y;
	y=tmp;
}

// ����˳���
void CreateList(RecType R[],KeyType keys[],int n){
	for(int i = 0;i<n;i++){
		R[i].key = keys[i];
	}
}

// ���δ�ӡ����˳����ڵ�keyԪ��
void DispList(RecType R[],int n){
	for(int i =0;i<n;i++){
		printf("%d",R[i].key);
	}
	printf("\n");
}





