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
const int maxn = 510;
const int INF = 0xfffffff;
int n, m, st, ed, G[maxn][maxn], weight[maxn];
int d[maxn], w[maxn], num[maxn], visit[maxn] = { 0 };
void Dijkstra(int s) {
	for (int i = 0; i < maxn; i++)	d[i] = INF;
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;//s�ı����1
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {//�ҵ�δ���ʵĶ�����d[]��С��
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)  return;
		visit[u] = 1;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && G[u][v] != INF) {//
				//d[u]�洢�ľ���һ����Դ���·��
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];//
					w[v] = w[u] + weight[v];//����Ԯ��������
					num[v] = num[u];//�����ͬ
				}
				else if (d[u] + G[u][v] == d[v]) {//�ҵ�һ����ͬ���ȵ�·��
					if (w[u] + weight[v] > w[v]) {//ͬ��·�� ·�����о�Ԯ�ӵ��ܺ͸���
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];//���·����Ŀ
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);//�ڶ����ǵ�Ȩ
		//��Ȩ��ָÿ�����еľ�Ԯ������
	}
	int u, v;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[v][u]);
		G[u][v] = G[v][u];
	}
	Dijkstra(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;

}