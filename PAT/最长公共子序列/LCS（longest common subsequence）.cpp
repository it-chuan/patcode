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
const int N = 100;
char A[N], B[N];
int dp[N][N];
int main() {
	int n;
	scanf("%[^\n]", A + 1);
	getchar();
	scanf("%[^\n]", B + 1);
	int lenA = strlen(A + 1);
	int lenB = strlen(B + 1);
	for (int i = 0; i <= lenA; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j <= lenB; j++) {
		dp[0][j] = 0;
	}//�߽�Ϊ0��
	//״̬ת�Ʒ���
	for (int i = 1; i <= lenA; i++) {
		for (int j = 1; j <= lenB; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			//dp[i][j] ��ʾ A��ǰi����B��ǰj������󹫹�����
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				//d[i][j]�̳�dp[i-1][j]��dp[i][j-1]�Ľϴ���
			}
		}
	}
	printf("%d", dp[lenA][lenB]);
	return 0;
}