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
int main() {
	int n, x;
	long long p;
	cin >> n >> p;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + res; j < n; j++) {
			if (v[j] <= v[i] * p) {//����pҪ��long long,��Ϊv[i]*p���ܻ����
				int len = j - i + 1;
				if (res < len)	res = len;
			}//���v[j] > v[i]*p �Ϳ���ֹͣ�ˣ���һ��i��ʼ��
			//res������󳤶�
			else break;
		}
	}
	cout << res;
	return 0;
}