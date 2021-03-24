#include <iostream>
#include "Television.h"
using namespace std;


/*	1�����ӻ���
*/
Television::Television() {
	this->mChannel = Off;
	this->mVolume = minVol;
	this->mChannel = minChannel;
}
// �����ػ�
void Television::OnOrOff() { this->mState = (this->mState == On ? Off : On);}
// �� / ������
void Television::VolumeUp() {
	if (this->mVolume == maxVol) { return; }
	this->mVolume++;
}
void Television::VolumeDown() {
	if (this->mVolume == minVol) { return; }
	this->mVolume--;
}

// ��Ƶ��
void Television::ChannelUp() {
	if (this->mChannel == maxChannel) { return; }
	this->mChannel++;
}
void Television::ChannelDown() {
	if (this->mChannel == minChannel) { return; }
	this->mChannel--;
}

void Television::ShowTeleState() {
	cout << "״̬��" << (mState == On ? "�ѿ���" : "�ѹػ�") << endl;
	if (mState == On) {
		cout << "��ǰ������" << mVolume << endl;
		cout << "��ǰƵ����" << mChannel << endl;
	}
	cout << "-------------" << endl;
}

/*-------------------------------------------------------------*/


/*	2��ң������
*/
Remote::Remote(Television *tele) {
	mTele = tele;
}
void Remote::OnOrOff() { mTele->OnOrOff(); }
void Remote::VolumeUp() { mTele->VolumeUp(); }
void Remote::VolumeDown() { mTele->VolumeDown(); }
void Remote::ChannelUp() { mTele->ChannelUp(); }
void Remote::ChannelDown() { mTele->ChannelDown(); }
void Remote::ShowTeleState() { mTele->ShowTeleState(); }

// �Լ���չ�ķ���
void Remote::SetChannel(int channel) {
	if (channel < Television::minChannel || channel > Television::maxChannel) {
		return;
	}
	/*	˵����
		���mChannel��һ��private�ĳ�Ա��
		����������ȴֱ�ӷ����ˣ���ΪTelevision��Remote��������Ԫ��
	*/
	mTele->mChannel = channel;
}