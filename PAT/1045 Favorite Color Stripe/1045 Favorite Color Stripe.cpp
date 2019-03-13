#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int n, m, l, x;
int colororder[maxc], dp[maxn], A[maxn];
int main() {
	scanf("%d%d", &n, &m);
	memset(colororder, -1, sizeof(colororder));
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		colororder[x] = i;
	}
	int l, num = 0;
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d", &x);
		if (colororder[x] >= 0) {
			A[num++] = colororder[x];
		}
	}
	int ans = -1;
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] <= A[i] && dp[i] < dp[j] + 1) {//dp[i] < dp[j] + 1��˼����d[i]��ǰ�����е�״̬���ֵ + 1����Ϊa[i] >= a[j]
				//ͨ����˵���ǣ���dp[i]λ��ʱ����j����0~i-1�����ҵ�A[j] <= A[i]�ģ���������ɫ���б���С�ģ���dp[j]������һ��λ��
				//dp[i] = dp[j] + 1
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}