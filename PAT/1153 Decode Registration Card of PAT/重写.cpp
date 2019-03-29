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
//˼· �ָ�ɲ�ͬ��vector���飬�����ʱ���ٽ������⴦��
//���׺��Եģ���������Ż������ںŵ�ʱ�� ��Ҫ%0 d
struct student {
	string numcard;
	int site, date, score;
};
vector<student> v;
vector<student> vLevel[3];
vector<student> vsite[1000];
map<char, int> mp;
map<int, vector<student>> vdate;
bool cmp1(student a, student b) {
	if (a.score != b.score)	return a.score > b.score;
	else return a.numcard < b.numcard;
}
struct hashtable {
	int site, value = 0;
};
bool cmp2(hashtable a, hashtable b) {
	if (a.value != b.value)	return a.value > b.value;
	else return a.site < b.site;
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n);
	mp['A'] = 0;
	mp['B'] = 1;
	mp['T'] = 2;
	for (int i = 0; i < n; i++) {
		cin >> v[i].numcard >> v[i].score;
		v[i].date = stoi(v[i].numcard.substr(4, 6));
		v[i].site = stoi(v[i].numcard.substr(1, 3));
		vLevel[mp[v[i].numcard[0]]].push_back(v[i]);
		vsite[v[i].site].push_back(v[i]);
		vdate[v[i].date].push_back(v[i]);
	}
	for (int i = 1; i <= m; i++) {
		int cmd;
		cin >> cmd;
		printf("Case %d: %d ", i, cmd);
		if (cmd == 1) {
			char c;
			scanf(" %c", &c);
			cout << c << "\n";
			if (vLevel[mp[c]].size() == 0) {
				printf("NA\n");
				continue;
			}
			sort(vLevel[mp[c]].begin(), vLevel[mp[c]].end(), cmp1);
			for (int j = 0; j < vLevel[mp[c]].size(); j++) {
				cout << vLevel[mp[c]][j].numcard << " " <<vLevel[mp[c]][j].score << "\n";
			}
		}
		else if (cmd == 2) {
			int site, total = 0;
			cin >> site;
			printf("%d\n", site);
			if (vsite[site].size() == 0) {
				printf("NA\n");
				continue;
			}
			for (int j = 0; j < vsite[site].size(); j++) {
				total += vsite[site][j].score;
			}
			cout << vsite[site].size() << " " << total << "\n";
		}
		else {
			int date; cin >> date;
			printf("%06d\n", date);
			if (vdate[date].size() == 0) {
				cout << "NA\n";
				continue;
			}
			map<int, int> md;
			set<int> dsn;
			for (int j = 0; j < vdate[date].size(); j++) {
				int dsite = vdate[date][j].site;
				md[dsite]++;
				dsn.insert(dsite);//date��site��������
			}
			vector<hashtable> hash;
			for (auto it = md.begin(); it != md.end(); it++) {
				hashtable temp;
				temp.site = it->first, temp.value = it->second;
				hash.push_back(temp);
			}
			sort(hash.begin(), hash.end(), cmp2);
			for (int j = 0; j < hash.size(); j++) {
				printf("%03d %d\n", hash[j].site, hash[j].value);
			}
		}
	}
	return 0;
}