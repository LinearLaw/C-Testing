#include <iostream>
#include "BuildMyFriend.h"

using namespace std;

// 1��ʵ�� MyFriend �ļ�������
void MyFriend::lookAtBedRoom(Building &building) {
	cout << "My friend in my bed room : " << building.mBedroom << endl;
}
void MyFriend::playInBedRoom(Building &building) {
	cout << "My friend play in my bed room : " << building.mBedroom << endl;
}

void CleanBedRoom(Building &building) {
	cout << "��Ԫȫ�ֺ������� �� " << building.mBedroom << endl;
}
Building::Building() {
	this->mBedroom = "WWWWWW";
	this->msRoom = "LLLLLLL";
}