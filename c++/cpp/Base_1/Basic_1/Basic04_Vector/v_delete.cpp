#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

// 1������ɾ����ɾ��ĳһ��Ԫ�أ�������ԭ������
void DeleteOne() {
	vector<int> a = { 12,23,534,532,34,6 };

	int temp = 534;
	int k = 0;
	for (int i = 0; i < a.size();i++) {
		if (a[i] != temp) { a[i-k] = a[i]; }
		else { k++; }
	}
	for (int i = 0; i < k;i++) { a.pop_back(); }

	printVector(a);
}
// 2��ʹ��erase��ɾ��������ָ���Ԫ��
void DeleteTwo() {
	vector<int> a = { 12,23,534,532,34,6 };

	int temp = 534;
	int k = -1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == temp) {
			k = i;
			break;
		}
	}
	if (k != -1) {
		a.erase(a.begin() + k);
	}
	printVector(a);
}

// 3������
void InsertV() {
	vector<int> a = { 12,23,532,34,6 };

	int temp = 534;
	a.insert(a.begin() + 3, temp); // ��a[2]�ĺ������534��ע����������
	printVector(a);

}


void TestVDelete() {
	cout << "----1����ͨ����ɾ" << endl;
	DeleteOne();

	cout << "----2����eraseɾ" << endl;
	DeleteTwo();

	cout << "----3��insert" << endl;
	InsertV();
}