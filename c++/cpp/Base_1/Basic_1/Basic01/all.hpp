#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Hello01() {
	cout << "hello world" << 123456 << endl;
}

// int atk = 200;
void Test02() {
	int atk = 100;

	cout << "�ֲ�����atkֱ�����ü��ɣ�" << atk << endl;
	// cout << "��::���Է��ʵ�ȫ�ֱ����µ�atk" << ::atk << endl;
}

/*--------------------------------------------*/
class A {
public:
	A(int param) {
		mParam = param;
	}
public:
	int mParam;
};
void Test03() {
	A a1(100);
	A* a2 = new A(200);

	/*	��ʹ��ָ���Ա������ָ�룬
		ֱ��ʹ��ָ�룬ָ��ĳһ�����ĳһ��Ա��
		���Ҫ������һ�����ͬ����Ա��Ҫ�ٴ���һ��ָ��
	*/
	int *p1 = &a1.mParam;

	/*	ʹ��ָ���Ա������ָ�룬
		��ʱ��������a1����a2��mParam�������������ָ��������
	*/
	int A::*p2 = &A::mParam;

	cout << "*p1 : " << *p1 << endl;
	cout << "a1.*p2 : " << a1.*p2 << endl; // ����һ��������.����
	cout << "a2->*p2 : " << a2->*p2 << endl; // ����һ������ָ�룬��->����
}

void testHello(){
	// 1.1��hello world
	Hello01();

	// 1.2��ȫ�ֱ�����������
	Test02();

	// 1.3��ָ�����Ա��ָ��
	cout << "-----------" << endl;
	Test03();
}
