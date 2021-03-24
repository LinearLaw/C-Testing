#pragma once

class MyArray {
public:
	MyArray();
	~MyArray();

	// ����һ����������������ʼ��
	explicit MyArray(int capacity);

	void SetData(int pos, int val);
	int GetData(int pos);

	void PushBack(int val);
	int GetLength();

private:
	int mCapacity;	// ����һ�������ɶ��ٸ�Ԫ��
	int mSize;		// ��ǰ�ж��ٸ�Ԫ��
	int* pAddress;	// ָ��洢���ݵĿռ�
};

