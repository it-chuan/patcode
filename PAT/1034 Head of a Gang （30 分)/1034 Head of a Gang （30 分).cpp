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
const int maxn = 2010;
map<string, int> stringToint;//����->���
map<int, string> intTostring;//���->����
map<string, int> Gang;//head ->����
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//�ڽӾ��󣬵�Ȩ
int n, k, numperson = 0;
int visit[maxn] = { 0 };
int change(string str) {
	if (stringToint.find(str) != stringToint.end()) {
		return stringToint[str];
	}
	else {
		stringToint[str] = numperson;
		intTostring[numperson] = str;
		return numperson++;
	}
}
void DFS(int nowvisit, int& head, int& numMember, int &totalvalue) {
	numMember++;
	visit[nowvisit] = 1;
	if (weight[nowvisit] > weight[head]) {
		head = nowvisit;
	}
	for (int i = 0; i < numperson; i++) {
		if (G[nowvisit][i] > 0) {
			totalvalue += G[nowvisit][i];
			G[nowvisit][i] = G[i][nowvisit] = 0;
			if (visit[i] == 0) {
				DFS(i, head, numMember, totalvalue);
			}
		}
	}
}
void DFStrave() {//��������ͼ����ͨ��
	for (int i = 0; i < numperson; i++) {
		if (visit[i] == 0) {
			int head = i, numMember = 0, totalvalue = 0;
			DFS(i, head, numMember, totalvalue);//head�ǵ�Ȩweight��ߵ�
			if (totalvalue > k&&numMember > 2) {
				Gang[intTostring[head]] = numMember;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	int w;
	string str1, str2;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFStrave();//��������ͼ����ͨ��
	printf("%d\n", Gang.size());
	for (auto it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;//����ֻ����cout���

	}
	return 0;
}