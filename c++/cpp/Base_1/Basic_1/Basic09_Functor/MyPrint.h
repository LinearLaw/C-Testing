#pragma once

// 1������һ����
class MyPrint {
public:
	MyPrint();
	// 2������������()����
	void operator() (int num);
	int m_num;
};

// 3��ʹ��
void testMyPrint();