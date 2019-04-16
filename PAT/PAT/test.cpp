#include <iostream>
#include <vector>
#include <algorithm>

const char *INSERT = "Insertion Sort";
const char *MERGE = "Merge Sort";

bool sorted(const std::vector<int> &ser, int end)
{
	while (end > 0)
	{
		if (ser.at(end) < ser.at(end - 1))
		{
			return false;
		}
		end--;
	}
	return true;
}

// 0: insert
// 1: merge
// ����ǲ�������, ���������Ǵ�������, ���Դ�������, �ҵ���һ����ԭ���в�ͬ��,
// ������ֵ֮ǰ���������(ǰ��Ķ��ź���), �Ǿ��ǲ���, �������merge
// ��ʵ���Է���, merge��һ������, �������(������)Ԫ�ؾͷ���λ�ñ仯��, ������ǰ�������, ��һ������.
int detectType(const std::vector<int> &ser, const std::vector<int> &raw)
{
	int last_index = ser.size() - 1;
	for (; last_index > 0; last_index--)
	{
		if (ser.at(last_index) != raw.at(last_index))
		{
			break;
		}
	}
	if (sorted(ser, last_index))
	{
		return 0;
	}
	return 1;
}

// �ҵ��೤����������, ���� 3 1 2 8 7 5 9 4 6 0 -> 1 2 3 7 8 5 9 4 6 0
// ǰ�� 1 2 3 7 8 ������, ���� 5, �������������5(��0��ʼ��)���Ѳ�������
// ���ڲ����������, Ҳ������һ��Ҫ�����Ԫ�ؾ��ǵ�5��
// ����merge����, �������ڷֶ��Ѿ��ֵ���5, ��ԭ ���б���Ϊ5(��)-5(��)-5(��)-..., ����ÿ5��������, ����һ��, Ӧ����ÿ10��
int sortedLength(const std::vector<int> &s)
{
	int index = 1;
	while (index < s.size() - 1)
	{
		if (s.at(index) < s.at(index - 1))
		{ // equal?
			break;
		}
		index++;
	}
	return index;
}
void insertNext(std::vector<int> &s)
{
	int index = sortedLength(s);
	std::sort(s.begin(), s.begin() + index + 1); // ������������ӳ�1��
}
void mergeNext(std::vector<int> &s)
{
	int sorted_length = sortedLength(s);
	int offset = s.size() % (2 * sorted_length); // ����һ���ֶε�
	int index = 0;
	for (; index < s.size() - offset; index += 2 * sorted_length)
	{
		std::sort(s.begin() + index, s.begin() + index + 2 * sorted_length);
	}
	std::sort(s.begin() + index, s.end());
}

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> raw(N);
	std::vector<int> mid(N);

	for (auto i = 0; i < N; i++)
	{
		std::cin >> raw[i];
	}
	for (auto i = 0; i < N; i++)
	{
		std::cin >> mid[i];
	}

	int type = detectType(mid, raw);
	if (type == 0)
	{
		std::cout << INSERT << std::endl;
		insertNext(mid);
	}
	else
	{
		std::cout << MERGE << std::endl;
		mergeNext(mid);
	}
	for (auto i = mid.begin(); i != mid.end(); i++)
	{
		if (i != mid.begin())
		{
			std::cout << " ";
		}
		std::cout << *i;
	}
}