#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

// 1��set�Խṹ���������
// �ؼ������� < �����
struct Box {
	int val;
	bool operator< (const Box& temp)const {
		return val < temp.val;
	}
};
void sortStructSet() {
	vector<int> a = { 3,4,2,1 };
	set<Box> s;
	for (int i = 0; i < a.size(); i++) {
		Box temp;
		temp.val = a[i];
		s.insert(temp);
	}

	for (const Box& t : s) {
		cout << t.val << endl;	// 1,2,3,4
	}
}

// 2��set��������������
// �ؼ������� < �����
class R {
public:
	int val;
	bool operator<(const R& t) {
		return val < t.val;
	}
};

void sortClassSet() {
	vector<int> a = { 3,4,2,1 };
	set<Box> s;
	for (int i = 0; i < a.size(); i++) {
		Box temp;
		temp.val = a[i];
		s.insert(temp);
	}

	for (const Box& t : s) {
		cout << t.val << endl;	// 1,2,3,4
	}
}

// 3��ʹ������ν��
class Player { // ���
public:
	int id;
	int score;
	Player(int i, int s) :id(i), score(s) {}
};
class SPlayer { // ν�ʣ���Ϊset�ıȽ�����
public:
	bool operator()(const Player& a, const Player& b) {
		return a.score > b.score;
	}
};

void sortSetByFunctor() {
	set<Player, SPlayer> t; // set�ĵڶ��������Խ���һ��ν�ʣ���Ϊ�Ƚ�����
	Player a1(1, 100);
	Player a2(2, 250);
	Player a3(3, 400);
	Player a4(4, 202);

	t.insert(a1);
	t.insert(a2);
	t.insert(a3);
	t.insert(a4);

	for (const Player& temp : t) {
		cout << "id:" << temp.id << " score:" << temp.score << endl;
	}
}

// 4��priority_queue
void sortClassPriorityQueue() {
	vector<int> a = { 3,4,2,1 };
	priority_queue<Box> q;
	for (int i = 0; i < a.size(); i++) {
		Box temp;
		temp.val = a[i];
		q.push(temp);
	}

	while (q.size() > 0) {
		Box t = q.top();
		cout << t.val << endl;  // 4,3,2,1  ע��˳���set�Ƿ���
		q.pop();
	}

}