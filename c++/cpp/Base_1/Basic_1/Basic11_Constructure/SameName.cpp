#include <iostream>
#include "SameName.h"
using namespace std;

// 1������
Base::Base():mParam(0) {}
void Base::Print() { cout << mParam << endl; }
void Base::func() { cout << "Base func" << endl; }
void Base::func(int param) { cout << "Base func(int param)" << endl; }


// 2������
Derived::Derived() :mParam(10) {}

// 2.1��������ʸ���ĳ�Ա����
void Derived::Print() {
	// ʹ��Base::���Է��ʵ�����ĳ�Ա����
	cout << "Base: " << Base::mParam << endl;
	cout << "Derived: " << mParam << endl;
}

//	2.2�������ض������ĺ���
void Derived::func() { cout << "Derived func" << endl; }
void Derived::testFunc() {
	Base::func(); // �ͳ�Ա�������ƣ�������Base::����
	func();
}

/*	2.3���������ػ���ĳ�Ա����
	Tips��
		������಻���ظ����func�����������ǿ���ʹ�ø�������غ����ġ�
		��������func֮�󣬻����func���غ����ͻᱻ���أ�����ֱ�ӵ���
*/
void Derived::func(int p1,int p2){ cout << "Derived func(int p1, int p2)" << endl; }



void testSameName() {
	Derived d;

	cout << "----1��������ʸ����Ա����-----" << endl;
	d.Print();  // 0   10

	cout << "----2����������ѱ��ض���ĸ��ຯ��-----" << endl;
	d.testFunc();

	cout << "----3�����������˺�������������غ����ᱻ����-----" << endl;
	// d.func(1); // ��ʱ�޷�ֱ��ʹ�ø����func(int param)����
	d.func(1,2);
	cout << "---------" << endl;

	


}