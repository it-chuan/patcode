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
vector<int> b;
int main() {
	int n, m, a, b, k, in[1010] = { 0 };
	cin >> n >> m;
	vector<int> v[1010];

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);//�ڽӱ�a
		in[b]++;//b�����+1
	}
	cin >> k;
	vector<int> ans;
	for (int j = 0; j < k; j++) {
		int judge = 1;
		vector<int> tin(in, in + n + 1);//in��ʾ��ʼλ�ã��ұ߱�ʾĩβ��־
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (tin[a] != 0&&judge) {
				ans.push_back(j);
				judge = 0;
			}
			else {
				for (auto it : v[a])	tin[it]--;
				/*for (auto it = v[a].begin(); it != v[a].end(); it++) {
					//��ݵ�for(auto it : v[a])// tin[it]--;
					tin[*it]--;
				}*/
			}
		}
	}
	int flag = 0;//��������ո񣬵�һ�δ�ӡ�ǲ�������ո��
	for (auto it : ans) {
		if (flag) printf(" ");
		printf("%d", it);
		flag = 1;
	}
	return 0;
}