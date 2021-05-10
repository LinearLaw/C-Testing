#include <iostream>

using namespace std;

/*
����ģʽʵ�ֵ���

*/

// 1������һ��������
template <class T>
class singleton {
protected:
	singleton() {};

private:
	// ���ÿ������캯��
	singleton(const singleton&) {};
	// ���ø�ֵ��
	singleton& operator=(const singleton^&) {};

	static T* m_instance; // ��������

public:
	static T* GetInstance();
};

// 2����ȡ��������
template <class T>
T* singleton<T>::GetInstance() {
	return m_instance;
}

// 3��������ص�ʱ�򣬾ͽ����������ʼ��
template <class T>
T* singleton<T>::m_instance = new T();