#include <cstdio>	
#include <queue>
#include <algorithm>
const int maxn = 200020;
int a[maxn];
int main() {
	int n, m, k = 0, num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int index = (n + m - 1) / 2;//��0��ʼ��ţ���λ�����±�
	//num�൱��ÿһ�����ı�ţ���1��ʼ
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (k < n&&x > a[k]) {
			while (a[k] <= x && k < n) {
				k++;
				num++;
				if (num - 1 == index) {
					printf("%d", a[k-1]);
					return 0;
				}
			}
			
		}
		num++;
		if (num - 1 == index) {
			printf("%d", x);
			return 0;
		}
	}
	while (num - 1 != index) {
		k++;
		num++;
	}
	printf("%d", a[k-1]);
	return 0;
}
