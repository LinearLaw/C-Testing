#include <iostream>
#include "MyPrint.h"

using namespace std;

/*
	4.1����������
	�������е�()����������������Ǻ�������Ҳ�����º�����
*/

// 1�����캯��
MyPrint::MyPrint() {
	m_num = 0;
}
// 2������������()����
void MyPrint::operator() (int num) {
	cout << num << endl;
	m_num++;
}

// 3��ʹ��
void testMyPrint() {
	MyPrint m;
	m(20);

	m(40);
	/*	Tips��
		�������� ��ʵ��������ͨ�����ĸ�������Լ�¼��������״̬
		����MyPrint�࣬��һ����Աm_num��
			ÿ�ε����˷º�����m_num��������+1��
			����൱�ڼ�¼�˵����˶��ٴκ�����
	*/
	cout << "------------" << endl;
	cout << m.m_num << endl;
}