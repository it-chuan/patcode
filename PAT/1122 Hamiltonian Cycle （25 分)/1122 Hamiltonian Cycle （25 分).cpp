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
const int maxn = 210;
int n, m, k;
int G[maxn][maxn] = { 0 };
int isInpath[maxn];
int judgeHamiltonianCycle(vector<int> &path) {
	if (path.size() != n + 1 || path.front() != path.back()) {
		return 0;//���·���ڵ����������n+1������β�ڵ㲻ͬ,��ǹ��ܶٻ�·
	}
	else {
		memset(isInpath, 0, sizeof(isInpath));
		for (int j = 1; j < path.size(); j++) {
			if (isInpath[path[j]] || !G[path[j - 1]][path[j]]) {
				return 0;//����ڵ��ظ�,���߲߱�����,��ô�ǹ��ܶٻ�·
			}
			isInpath[path[j]] = 1;
		}
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int num, tempNode;
		scanf("%d", &num);
		vector<int> path;//·��path
		for (int j = 0; j < num; j++) {
			scanf("%d", &tempNode);
			path.push_back(tempNode);
		}
		if (judgeHamiltonianCycle(path)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}