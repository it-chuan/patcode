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
int G[210][210];
int main() {
	int nv, ne, m, ta, tb, k;
	scanf("%d %d", &nv, &ne);
	for (int i = 0; i < ne; i++) {
		scanf("%d %d", &ta, &tb);
		G[ta][tb] = G[tb][ta] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		vector<int> v(k);
		int hash[210] = { 0 }, isclique = 1, isMaximal = 1;
		for (int j = 0; j < k; j++) {
			scanf("%d", &v[j]);
			hash[v[j]] = 1;//���ֹ��ı������
		}
		for (int j = 0; j < k; j++) {
			if (isclique == 0)	break;
			for (int l = j + 1; l < k; l++) {
				if (G[v[j]][v[l]] == 0) {
					isclique = 0;//��·��ͨ
					//˵���ⲻ��һ��ǿ��ͨͼ
					printf("Not a Clique\n");
					break;
				}
			}
		}
		if (isclique == 0) continue;
		for (int j = 1; j <= nv; j++) {
			if (hash[j] == 0) {
				for (int l = 0; l < k; l++) {//k��ʾÿ������Ľ�����
					if (G[v[l]][j] == 0)	break;
					if (l == k - 1)	isMaximal = 0;
					//һֱ��ѭ����������˵������Ķ����j������ͨ��
					//˵�������������������ͼ������
					//˵���ⲻ�����ǿ��ͨͼ
				}
			}
			if (isMaximal == 0) {
				printf("Not Maximal\n");
				break;
			}
		}
		if (isMaximal == 1)	printf("Yes\n");
	}

	return 0;
}