#pragma once

// 1������
class BigBase {
public:
	BigBase(int x);
	void func();

public :
	int p;
};

// 1-2��ֱ�Ӽ̳е����������� Base1 Base2
class Base1 : public BigBase {
public:
	Base1();
};

class Base2:public BigBase{
public:
	Base2();
};

// 1-3��Derived_D ֱ�Ӽ̳�Base1 Base2
class Derived_D:public Base1,public Base2{
public:
	Derived_D();

	void calcBase12();
};

// 2-2��ʹ����̳�
class BaseV1 : virtual public BigBase {
public:
	BaseV1();
};
class BaseV2 : virtual public BigBase {
public:
	BaseV2();
};

// 2-3��Derived_V �̳�Base1 Base2
class Derived_V {
public:
	Derived_V();
	void calcBaseV12();
};


void testVirtualInherit();