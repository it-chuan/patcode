#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxm = 110;
int dp[maxn] = { 0 }, w[maxn];
int choice[maxn][maxm], flag[maxn], ans[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = m; v >= w[i]; v--) {
			if (dp[v] <= dp[v - w[i]] + w[i]) {
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = 1;
			}
			else {
				choice[i][v] = 0;//֮����Ҫ���򣬾����������
				//��Ϊ��̬�滮����������Ǻ���Ĵ𰸸���ǰ��Ľ����
				//��������Ҫ���СӲ��ֻҪ���Ҳ��ȡ��
				//Ȼ��choice��k��n��ʼ��������Ҳ��ɵ�Ӳ��
				//����41�б�֤�˸ոպ�ȡ��m����ֵ��
			}
		}
	}
	if (dp[m] != m) {
		printf("No Solution");
	}
	else {
		int k = n, v = m, num = 0;
		while (k > 0) {
			if (choice[k][v]) {
				ans[num++] = w[k];
				v -= w[k];//�պ�����Ӳ����С�ļ��� �ܺ�Ϊv
			}
			k--;
		}
		for (int i = 0; i < num; i++) {
			printf("%d", ans[i]);
			if (i != num-1)	printf(" ");
		}
	}
	return 0;
}