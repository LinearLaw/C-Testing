#include <iostream>
#include <unordered_set>

using namespace std;

// set����Ѿ�������һ�����ݣ���ִ��insert��û��Ч��
void insertTest() {
	unordered_set<int> s;

	s.insert(500);
	s.insert(500);

	for (auto& a: s) {
		cout << a << endl;
	}
}