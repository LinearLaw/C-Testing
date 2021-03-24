#pragma once
#include <string>

using namespace std;

/*
4.5����Ԫ����
	��A�����Լ��ķ���
	��B������B�У��� A�ķ��� ����Ϊfriend
	A������Ϊ friend �ķ���������ֱ�ӷ��� B �� private ��Ա

	��B�У���A����Ϊ��Ԫ��
*/

class Building;

// ��һ���࣬MyFriend
class MyFriend {
public:
	void lookAtBedRoom(Building &building);
	void playInBedRoom(Building &building);
};

/* �ڶ����࣬Building�����ڲ�ָ��������Ԫ��
	��Ԫ���԰���MyFriend�ķ���
		���԰���ȫ�ֺ���
		���԰�MyFriendҲ��Ϊ�ࣻ

	ָ��������Ԫ֮�����ⲿ������Ԫ���Ϳ��Է��ʵ�Building�����private�����ˣ�
*/
class Building {
	// 1��ȫ�ֺ�������Ԫ����
	friend void CleanBedRoom(Building &building);

	// 2����Ա��������Ԫ����
	friend void MyFriend::lookAtBedRoom(Building &building);
	friend void MyFriend::playInBedRoom(Building &building);

	// 3����Ԫ��
	friend class MyFriend;

public:
	Building();
public:
	string msRoom;
private:
	string mBedroom;
};