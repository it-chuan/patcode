#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int pos[100010];
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	int left = n - 1, num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;//��ʾĳĳ�� �ڵڼ���λ��
		if (num == i && num != 0)
			left--;
	}
	int k = 1;
	while (left > 0) {//ֻҪ���������ڱ�λ��
		if (pos[0] == 0) {
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);//0���ڵ�λ����k���ڵ�λ�ý���
					ans++;
					break;
				}
				k++;
			}
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);//0��λ����7�� ��7��λ����2������һ�£� 0��λ����2�� 7��λ����7
			ans++;
			left--;//7�ص����Լ���λ����
		}
	}
	printf("%d\n", ans);
}