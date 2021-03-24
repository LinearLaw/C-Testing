#pragma once

class Television {
	// ��ң��������Ϊ��Ԫ��
	friend class Remote;
public:
	enum { On, Off }; // ���ӻ�״̬
	enum { minVol, maxVol = 100 }; // ���� ��1-100
	enum { minChannel = 1, maxChannel = 255 }; // Ƶ����1-255

	Television();

	void OnOrOff();
	void VolumeUp();
	void VolumeDown();
	void ChannelUp();
	void ChannelDown();
	void ShowTeleState();

private:
	int mState; // ���ӻ�״̬
	int mVolume; // ����
	int mChannel; // Ƶ��
};

class Remote {
public:
	Remote(Television *tele);

public:
	void OnOrOff();
	void VolumeUp();
	void VolumeDown();
	void ChannelUp();
	void ChannelDown();
	void ShowTeleState();
	void SetChannel(int channel);
private:
	Television *mTele;
};