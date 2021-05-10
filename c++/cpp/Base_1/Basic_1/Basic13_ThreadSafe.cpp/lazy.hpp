#include <iostream>
#include <pthread.h>

using namespace std;

/*
����ʽ����Ҫ�����̰߳�ȫ

*/
template<class T>
class singleton {
protected:
	singleton() {};

private:
	singleton(const singleton&) {};
	singleton& operator=(const singleton&) { };

	// ��������
	static T* m_instance;
	// ��
	static pthread_mutex_t mutex;

public:
	static T* GetInstance();
};

template<class T>
T* singleton<T>::GetInstance() {

	/* ���������⣬ÿ�ν�����Ҫ������Ӱ��Ч�� */
	pthread_mutex_lock(&mutex);
	if (m_instance == NULL) {
		m_instance = new T();
	}
	pthread_mutex_lock(&mutex);

	/* �Ľ���ʹ��˫����	
	*/



	return m_instance;
}

template<class T>
pthread_mutex_t singleton<T>::mutex = PTHREAD_MUTEX_INITIALIZER;

template <class T>
T* singleton<T>::m_instance = NULL;
