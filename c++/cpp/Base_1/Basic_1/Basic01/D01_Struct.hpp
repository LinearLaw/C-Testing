#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
1������struct�Ĵ�С

*/
struct AB {
	// ð�Ŵ����˵�ǰ��Ա��ռ�Ŀռ� 3bit
	// x y z ����int�ռ� 32bit��������8 B
	int x : 3; 
	int y : 4;
	int z : 5;
	double a; // 8 B

};
void run01() {
	// 8+8=16
	cout << sizeof(AB) << endl;
}