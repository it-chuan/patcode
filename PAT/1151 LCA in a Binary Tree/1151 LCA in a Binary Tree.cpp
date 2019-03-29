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
int m, n;//m�ǲ��ԵĶ���ԣ�n���ܽ����
vector<int> In, Pre;
map<int, int> pos;
void LCA(int inl, int inr, int preRoot, int a, int b) {
	if (inl > inr)	return;
	int inRoot = pos[Pre[preRoot]], aIn = pos[a], bIn = pos[b];//������������ţ�u����������ţ�v�����������
	if (aIn < inRoot&&bIn < inRoot) {//u �� v ���ڸ������
		LCA(inl, inRoot - 1, preRoot + 1, a, b);//���ڵ������������preRoot + 1
		//���ݹ�������
	}
	else if ((aIn < inRoot&&bIn > inRoot)||(aIn > inRoot&&bIn < inRoot)) {
		printf("LCA of %d and %d is %d.\n", a, b, In[inRoot]);
	}
	else if (aIn > inRoot&&bIn > inRoot) {//���ڸ����ұߣ���ݹ�������
		LCA(inRoot + 1, inr, preRoot + inRoot - inl + 1, a, b);//
	}
	else if (aIn == inRoot) {
		printf("%d is an ancestor of %d.\n", a, b);
	}
	else if (bIn == inRoot) {
		printf("%d is an ancestor of %d.\n", b, a);
	}
}
int main() {
	cin >> m >> n;
	In.resize(n + 1), Pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> In[i];
		pos[In[i]] = i;//��������˳��洢����
	}
	for (int i = 1; i <= n; i++) {
		cin >> Pre[i];
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (pos[u] == 0 || pos[v] == 0) {
			if (pos[u] == 0 && pos[v] == 0)	printf("ERROR: %d and %d are not found.\n", u, v);
			else if(pos[u] == 0)	printf("ERROR: %d is not found.\n", u);
			else if(pos[v] == 0)	printf("ERROR: %d is not found.\n", v);
		}
		else {
			LCA(1, n, 1, u, v);//preRoot��1�����������е�һ����ʼ��һ��Ҳ�Ǹ��ڵ�
		}
	}
	return 0;
}