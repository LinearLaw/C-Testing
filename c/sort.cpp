#include "./sqlist.cpp"

void BubbleSort(RecType R[],int n){
	int i,j;
	RecType tmp;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			// �Ƚ�j��j-1�Ĵ�С������С�Ĺؼ��ֽ�����ǰ�ƶ�
			if(R[j].key < R[j-1].key){
				tmp = R[j];
				R[j]=R[j-1];
				R[j-1] = tmp;
			}
		}
		printf("  i=%d:  ",i);
		DispList(R,n);
	}
}

int main(){
	int n = 10; // ��������˳�����
	RecType R[MAXL]; // ˳�����󳤶�
	KeyType a[] = {9,8,7,6,5,4,3,2,1,0}; // ˳���Ԫ��
	CreateList(R,a,n);

	printf("����ǰ��");
	DispList(R,n);
	printf("�����");
	DispList(R,n);
	return 1;

}