#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) 
{
	int answer = 0;
	int idx = 0;
	map<int, int> store;

	for (int i = 0; i < tangerine.size(); i++)
	{
		if (store.find(tangerine[i]) != store.end())
		{
			store[tangerine[i]]++;
		}
		else
		{
			store.insert(make_pair(tangerine[i], 1));
		}
	}

	vector<pair<int, int>> vp_store(store.begin(), store.end());
	sort(vp_store.begin(), vp_store.end(),cmp);

	while (true)
	{
		if (k <= vp_store[idx].second)
		{
			answer++;
			break;
		}
		else
		{
			answer++;
			k -= vp_store[idx].second;
		}

		idx++;
	}

	return answer;
}

int main()
{
	vector<int> k = { 6,4,2 };
	vector<vector<int>> tan = { { 1, 3, 2, 5, 4, 5, 2, 3 }, { 1, 3, 2, 5, 4, 5, 2, 3 }, { 1, 1, 1, 1, 2, 2, 2, 3 } };
	vector<int> r = { 3,2,1 };

	for (int i = 0; i < k.size(); i++)
	{
		int d = solution(k[i], tan[i]);
		if (d == r[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error " << endl;
		}
	}
}

/*
��ȭ�� ���������� ���� ��Ȯ�߽��ϴ�. 
��ȭ�� ��Ȯ�� �� �� 'k'���� ��� ���� �ϳ��� ��� �Ǹ��Ϸ��� �մϴ�. 
�׷��� ��Ȯ�� ���� ũ�Ⱑ �������� �ʾ� ���⿡ ���� �ʴٰ� ������ ��ȭ�� ���� ũ�⺰�� �з����� �� 
���� �ٸ� ������ ���� �ּ�ȭ�ϰ� �ͽ��ϴ�.

���� ���, 
��ȭ�� ��Ȯ�� �� 8���� ũ�Ⱑ {1, 3, 2, 5, 4, 5, 2, 3} �̶�� �սô�. 
��ȭ�� �� 6���� �Ǹ��ϰ� �ʹٸ�, 
ũ�Ⱑ 1, 4�� ���� ������ ���� ���� ���� ���ڿ� ������, 
���� ũ���� ������ 2, 3, 5�� �� 3������ �Ǹ� �̶��� ���� �ٸ� ������ �ּ��� ���Դϴ�.

��ȭ�� �� ���ڿ� �������� 
���� ���� k�� 
���� ũ�⸦ ���� �迭 tangerine�� �Ű������� �־����ϴ�. 
��ȭ�� �� k���� �� �� ũ�Ⱑ 
���� �ٸ� ������ ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
1 �� k �� tangerine�� ���� �� 100,000
1 �� tangerine�� ���� �� 10000000
����� ��
k	tangerine	result
6		3
4		2
2		1
����� �� ����
����� �� #1

�������� ������ �����Դϴ�.
����� �� #2

��ȭ�� ũ�Ⱑ 2�� �� 2���� 3�� �� 2�� �Ǵ� 2�� �� 2���� 5�� �� 2�� �Ǵ� 3�� �� 2���� 5�� �� 2���� ���� �Ǹ��� �� �ֽ��ϴ�. �̶��� ũ�� ������ 2������ �� ���� �ּҰ� �˴ϴ�.
����� �� #3

��ȭ�� ũ�Ⱑ 1�� �� 2���� �Ǹ��ϰų� 2�� �� 2���� �Ǹ��� �� �ֽ��ϴ�. �̶��� ũ�� ������ 1������, �� ���� �ּҰ� �˴ϴ�.

*/