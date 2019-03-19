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
const int K = 111;
const int INF = 1 >> 30;
struct player {
	int arriveTime, startTime, trainTime;
	bool isVip;
}newPlayer;
struct Table {
	int endTime, numServe;
	bool isVip;
}table[K];
int convertTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
vector<player> Player;
bool cmpArrive(player a, player b) {
	return a.arriveTime < b.arriveTime;
}
bool cmpStart(player a, player b) {
	return a.startTime < b.startTime;
}
int nextVIPPlayer(int VIPi) {
	VIPi++;
	while (VIPi < Player.size() && Player[VIPi].isVip == 0) {
		VIPi++;//�ҵ���һ��VIP�ͻ�
	}
	return VIPi;
}
void allotTable(int pID, int tID) {
	if (Player[pID].arriveTime <= table[tID].endTime) {//��Ҫ�����ӽ���
		Player[pID].startTime = table[pID].endTime;
	}
	else {
		Player[pID].startTime = Player[pID].arriveTime;//���˾Ϳ�ʼ
	}
	table[tID].endTime = Player[pID].startTime + Player[pID].trainTime;//���ӽ���ʱ����ڿ�ʼʱ����Ϸ���ʱ��
	table[tID].numServe++;
}
int main() {
	int n, m, k, VIPtable;
	scanf("%d", &n);
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(21, 0, 0);
	for (int i = 0; i < n; i++) {
		int h, m, s, trainTime, isVip;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &trainTime, &isVip);
		newPlayer.arriveTime = convertTime(h, m, s);
		newPlayer.startTime = edTime;
		if (newPlayer.arriveTime >= edTime)	continue;
		if (trainTime > 120)	trainTime = 120;
		newPlayer.trainTime = trainTime * 60;
		newPlayer.isVip = isVip;
		Player.push_back(newPlayer);
	}
	scanf("%d%d", &k, &m);
	for (int i = 1; i <= k; i++) {
		table[i].endTime = stTime;
		table[i].numServe = table[i].isVip = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &VIPtable);
		table[VIPtable].isVip = 1;
	}
	sort(Player.begin(), Player.end(), cmpArrive);
	int i = 0, VIPi = -1;
	VIPi = nextVIPPlayer(VIPi);//�ҵ���һ��VIP���
	while (i < Player.size()) {
		int idx = -1, minEndTime = INF;//Ѱ�������ܿ��е�����
		for (int j = 1; j <= k; j++) {
			if (table[j].endTime < minEndTime) {
				idx = j;
				minEndTime = table[j].endTime;
			}
		}
		if (table[idx].endTime >= edTime)	break;//�Ѿ����ţ�ֱ��break
		if (Player[i].isVip == 1 && i < VIPi) {//���i����Ա��VIP����VIP>i ˵��i����Ա�Ѿ���ѵ��
			i++;
			continue;
		}
		if (table[idx].isVip == 1) {//��Ա��VIP��������VIP
			if (Player[i].isVip == 1) {
				allotTable(i, idx);//��idx�������Աi
				if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);//�ҵ���һ��VIP��Ա
				i++;
			}
			else {
				//������VIP ��Ա����VIp
				//r�����ǰ���׵�VIP��Ա�ȸ�VIp������ �Ͱ�����idx(��VIp����)�������
				if (VIPi < Player.size() && Player[VIPi].arriveTime <= table[idx].endTime) {
					allotTable(VIPi, idx);
					VIPi = nextVIPPlayer(VIPi);
				}
				else {
					allotTable(i, idx);
					i++;
				}
			}
		}
		else {
			//��������vip
			if (Player[i].isVip == 0) {//��������vip ��Ա����vip
				allotTable(i, idx);
				i++;
			}
			else {
				//��Ա��VIP�����ҵ�����Ŀ��е�VIP����
				int VIPidx = 1, minVIPEndTime = INF;
				for (int j = 1; j <= k; j++) {
					if (table[j].isVip == 1 && table[j].endTime < minVIPEndTime) {
						minVIPEndTime = table[j].endTime;//�������ʱ��
						VIPidx = j;
					}
				}
				//������е�VIP������� VIPidx
				if (VIPidx != -1 && Player[i].arriveTime >= table[VIPidx].endTime) {
					//��Ա�����Ѿ�����
					//�Ͱ����������Աi
					allotTable(i, VIPidx);
					if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);
					i++;
				}
				else {
					//�����Ա��ʱ VIP������δ���� �Ͱ�����idx�������
					allotTable(i, idx);
					if (VIPi == i)	VIPi = nextVIPPlayer(VIPi);//�ҵ���һ��VIp��Ա
					i++;//i����Ա��ʼѵ�� ��˼������е���һ����
				}
			}
		}
	}
	sort(Player.begin(), Player.end(), cmpStart);
	for (i = 0; i < Player.size()&&Player[i].startTime < edTime; i++) {
		int t1 = Player[i].arriveTime;
		int t2 = Player[i].startTime;
		printf("1%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for (i = 1; i <= k; i++) {
		printf("%d", table[i].numServe);
		if (i < k)	printf(" ");
	}
	return 0;
}