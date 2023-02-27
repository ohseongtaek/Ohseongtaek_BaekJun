#include <string>
#include <queue>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

int solution(int x, int y, int n)
{
	if (x == y)
	{
		return 0;
	}

	queue<pair<int, int>> qp;
	set<int> s;
	set<int>::iterator iter;
	int answer = 0;

	qp.push(make_pair(x, 0));

	while (!qp.empty())
	{
		auto aqp = qp.front();
		qp.pop();

		// ���� ���� ��� ���� 
		if (aqp.first == y)
		{
			answer = aqp.second;
			break;
		}
		// ���� �ٸ���� �� x�� y���� �������� ���Ѱ�� 
		else if(aqp.first < y)
		{
			int cal1 = aqp.first + n;
			int cal2 = aqp.first * 2;
			int cal3 = aqp.first * 3;

			iter = s.find(cal1);
			if (iter == s.end())
			{
				s.insert(cal1);
				qp.push(make_pair(cal1, aqp.second + 1));
			}
			iter = s.find(cal2);
			if (iter == s.end())
			{
				s.insert(cal2);
				qp.push(make_pair(cal2, aqp.second + 1));
			}
			iter = s.find(cal3);
			if (iter == s.end())
			{
				s.insert(cal3);
				qp.push(make_pair(cal3, aqp.second + 1));
			}
		}
	}

	if (answer == 0)
	{
		answer = -1;
	}

	return answer;
}

int main()
{
	vector<int> x = { 10, 10, 2 };
	vector<int> y = { 40, 40, 5 };
	vector<int> n = { 5, 30, 4 };
	vector<int> ans = { 2,1,-1 };

	for (int i = 0; i < x.size(); i++)
	{
		int r = solution(x[i],y[i],n[i]);

		bool flag = false;

		if (r != ans[i])
		{
			cout << "error" << endl;
		}
		else
		{
			cout << "good" << endl;
		}
	}
}
/*
�ڿ��� x�� y�� ��ȯ�Ϸ��� �մϴ�. ����� �� �ִ� ������ ������ �����ϴ�.

x�� n�� ���մϴ�
x�� 2�� ���մϴ�.
x�� 3�� ���մϴ�.
�ڿ��� x, y, n�� �Ű������� �־��� ��, x�� y�� ��ȯ�ϱ� ���� �ʿ��� �ּ� ���� Ƚ���� return�ϵ��� solution �Լ��� �ϼ����ּ���. �̶� x�� y�� ���� �� ���ٸ� -1�� return ���ּ���.

���ѻ���
1 �� x �� y �� 1,000,000
1 �� n < y
����� ��
x	y	n	result
10	40	5	2
10	40	30	1
2	5	4	-1
����� �� ����
����� �� #1
x�� 2�� 2�� ���ϸ� 40�� �ǰ� �̶��� �ּ� Ƚ���Դϴ�.

����� �� #2
x�� n�� 30�� 1�� ���ϸ� 40�� �ǰ� �̶��� �ּ� Ƚ���Դϴ�.

����� �� #3
x�� y�� ��ȯ�� �� ���� ������ -1�� return�մϴ�.


*/