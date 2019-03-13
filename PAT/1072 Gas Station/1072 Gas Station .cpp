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
const int maxn = 1050;
const int INF = 1000000000;
int n, m, k, ds;//n�Ƿ���������m�Ǻ�ѡ��gas station, k�Ǳߣ�ds��gas �ķ���Χ
int G[maxn][maxn], visit[maxn];
int d[maxn];
int getID(char str[]) {
	int ID = 0, len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] != 'G') {
			ID = ID * 10 + (str[i] - '0');
		}
	}
	if (str[0] == 'G')	return n + ID;
	return ID;
}
void Dijkstra(int s) {
	memset(visit, 0, sizeof(visit));
	fill(d, d + maxn, INF);
	d[s] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, MIN = INF;
		for (int j = 1; j <= n + m; j++) {
			if (visit[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)	return;
		visit[u] = 1;
		for (int v = 1; v <= n + m; v++) {
			if (visit[v] == 0 && G[u][v] < INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	int u, v, w;
	char city1[10], city2[10];
	fill(G[0], G[0] + maxn * maxn, INF);//������֪ case���ַ���������б��
	for (int i = 0; i < k; i++) {
		scanf("%s %s %d", city1, city2, &w);
		u = getID(city1);
		v = getID(city2);
		G[u][v] = G[v][u] = w;
	}
	//ansdis���ʹ������̾���
	//ansAvg�����Сƽ�����룬ansID������ռ���վ
	double ansdis = -1, ansAvg = INF;
	int ansID = -1;
	for (int i = n + 1; i <= n + m; i++) {//ö�����м���վ
		double minDis = INF, avg = 0;
		Dijkstra(i);//����Dijkstra�㷨������d����
		for (int j = 1; j <= n; j++) {//����ÿ����������·��
			if (d[j] > ds) {//���ھ������ds�ľ���ֱ������
				minDis = -1;
				break;
			}
			if (d[j] < minDis)	minDis = d[j];
			avg += 1.0 * d[j] / n;//��ȡƽ������
		}
		if (minDis == -1)	continue;
		if (minDis > ansdis) {
			ansID = i;
			ansdis = minDis;
			ansAvg = avg;
		}
		else if (minDis == ansdis && avg < ansAvg) {
			ansID = i;
			ansAvg = avg;
		}
	}
	if (ansID == -1) {
		printf("No Solution\n");
		return 0;
	}
	printf("G%d\n", ansID - n);
	printf("%.1f %.1f", ansdis, ansAvg);
	return 0;
}