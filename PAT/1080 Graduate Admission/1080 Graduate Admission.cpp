#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
struct student {
	int GE, GI, id;
	vector<int> app;
	int rank;
	int total = 0;
};
bool cmp(student a, student b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.GE != b.GE)  return a.GE > b.GE;
	else return a.id > b.id;

}
int main() {
	int n, m, k;
	cin >> n >> m >> k;//����������ѧУ������ÿ��־Ը��
	vector<int> quota(m);
	vector<student> stu(n);

	for (int i = 0; i < m; i++) {
		cin >> quota[i];
	}
	int GE, GI;
	vector<vector<int>> accept(m);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].GE >> stu[i].GI;
		stu[i].total = (stu[i].GE + stu[i].GI);
		stu[i].id = i;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;//־Ը
			stu[i].app.push_back(x);
		}
	}
	//����id�ҳ�����ŵĴ���
	vector<int> hash(n);
	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < n; i++) {
		hash[stu[i].id] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < stu[i].app.size(); j++) {
			int t = stu[i].app[j];//־ԸѧУ
			if (quota[t] > 0) {
				accept[t].push_back(stu[i].id);
				quota[t]--;
				break;
			}
			else if (quota[t] == 0) {
				if (accept[t].size() == 0)  continue;
				int L = accept[t].size() - 1;//�����Ȩ�÷ֺ�GE�ɼ������ѧУ���¼ȡ����ͬ
				int lastId = accept[t][L];//��һ����¼ȡ��ID
				int r = hash[lastId];

				if (stu[i].total == stu[r].total&&stu[i].GE == stu[r].GE) {
					//����õ�����ѧ����id������������
					accept[t].push_back(stu[i].id);

					break;//��λѧ��¼ȡ�ˣ�����һλѧ�� �ӵ�һ־Ը��ʼ
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(accept[i].begin(), accept[i].end());
		for (int j = 0; j < accept[i].size(); j++) {
			printf("%d", accept[i][j]);
			if (j != accept[i].size() - 1)  printf(" ");
		}
		printf("\n");
	}
	return 0;
}