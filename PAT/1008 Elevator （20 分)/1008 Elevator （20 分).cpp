#include <cstdio>
int main() {
	int now = 0, total = 0, to;
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &to);
		if (now < to) {
			total += (to - now) * 6;
		}//�������  ���¥����ͬ ҲҪ����ͣ��ʱ��
		else	total += (now - to) * 4;
		total += 5;
		now = to;
	}
	printf("%d", total);
}