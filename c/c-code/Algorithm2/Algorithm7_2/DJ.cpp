#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <queue>

#include "Table.h"

/*
// ���������
class Dijkstra
{
public:
	int minDis = -1;
	vector<int> minPath;
	vector<TableNode*> res;

	Dijkstra(vector<TableNode*> res) {
		this->res = res;
	}
	void findOne(int start, int end) {
		int currDis = 0;
		vector<int> currPath;
		int deep = 1;

		minDis = -1;
		vector<int> minPath = currPath;
		for (int i = 0; i < res.size() - 2; i++)
		{
			doFind(currDis, currPath, start, end, deep, i);
		}
		printPath();
	}
	void printPath() {
		int len = minPath.size();
		cout << "------min path------" << endl;
		for (int i = 0; i < len; i++)
		{
			cout << minPath[i] << "->";
		}
		cout << minDis << endl;
	}

	// ÿ�α�������·����200���ڵ㣬�����������199
	void doFind(int currDis, vector<int> currPath, int currentIndex, int end, int deep, int expand) {
		int n = res.size() - 2;
		TableNode* p = res[currentIndex]->next;
		while (p->next != NULL) {
			cout << currentIndex << "__" << deep << "__" << p->index << endl;
			if (p->index == end) {// �ҵ���Ŀ����
				if (deep == expand) {// ��ǰ���������£����䵽�����һ��
					int temp = currDis + p->distance;
					if (minDis == -1 || temp < minDis) {
						minDis = temp;
						minPath = currPath;
					}
					return;
				}
				else {
					p = p->next;
					continue;
				}
			}
			else {
				int len = currPath.size();
				if (len > n) {
					cout << "len:" << len << endl;
					return;
				}
				bool isExist = false;
				for (int i = 0; i < len; i++)
				{
					if (currPath[i] == currentIndex) {
						isExist = true;
					};
				}
				if (!isExist) {
					vector<int> newCurr;
					for (int i = 0; i < len; i++) {
						newCurr.push_back(currPath[i]);
					}
					newCurr.push_back(p->index);

					doFind(currDis + p->distance, newCurr, p->index, end, deep + 1, expand);
				}
				p = p->next;
			}
		}
	}
};
*/