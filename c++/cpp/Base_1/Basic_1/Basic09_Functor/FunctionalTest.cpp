#include <iostream>
#include <vector>
#include <algorithm>

#include <functional>

#include "FunctionalTest.h"

using namespace std;
/*
	4.3���ڽ���������
		template<class T> T plus<T>		//�ӷ��º���
		template<class T> T minus<T>	//�����º���
		template<class T> T multiplies<T>	//�˷��º���
		template<class T> T divides<T>	//�����º���
		template<class T> T modulus<T>	//ȡģ�º���
		template<class T> T negate<T>	//ȡ���º���

		template<class T> bool equal_to<T>		//����
		template<class T> bool not_equal_to<T>	//������
		template<class T> bool greater<T>		//����
		template<class T> bool greater_equal<T>	//���ڵ���
		template<class T> bool less<T>			//С��
		template<class T> bool less_equal<T>	//С�ڵ���

		template<class T> bool logical_and<T>	//�߼���
		template<class T> bool logical_or<T>	//�߼���
		template<class T> bool logical_not<T>	//�߼���
 */

// 1��ȡ���º���
void testNegate(){
	negate<int> n;
	cout << n(50) << endl;
}

// 2���ӷ��º���
void testPlus() {
	plus<int> p;
	cout << p(354,26) << endl;
}

// 3�����ڷº���
void testGreater() {
	vector<int> a = { 23,12,534,4,25,545,234,34,234,5,74,41,5 };

	// �Ӵ�С����
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}

void runFunctionalTest() {
	cout << "---1��ȡ��---" << endl;
	testNegate();

	cout << "---2���ӷ�---" << endl;
	testPlus();
	
	cout << "---3������---" << endl;
	testGreater();
}


