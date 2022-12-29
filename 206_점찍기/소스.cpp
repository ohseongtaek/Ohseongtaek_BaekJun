#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* time out 
long long solution(int k, int d) 
{
	long long answer = 0;
	
	for (int i = 0; i <= d; i += k)
	{
		for (int j = 0; j <= d; j += k)
		{
			if (i == 0 && j == 0)
			{
				answer++;
			}
			else
			{
				double len = sqrt(pow(i, 2) + pow(j, 2));
				if (len > d)
				{
					break;
				}
				else
				{
					answer++;
				}
			}
		}
	}
	return answer;
}
*/

long long getCountY(int x, int d)
{
	//x2+y2<=d2 ==> y2 <= d2-x2
	long long left = sqrt((pow(d, 2) - pow(x, 2)));
	return left;
}

long long solution(int k, int d)
{
	long long answer = 0;
	
	// ���� ������ �̿� 
	for (int i = 0; i <= d; i += k)
	{
		long long yCnt = getCountY(i, d);
		long long kyCnt = yCnt / k;
		long long kyfCnt = floor(kyCnt);
		answer += kyfCnt + 1;
	}

	return answer;
}

int main()
{
	vector<int> k = { 2,1 };
	vector<int> d = { 4,5 };
	vector<int> ans = { 6,26 };

	for (int i = 0; i < k.size(); i++)
	{
		long long a = solution(k[i], d[i]);
		if (a == ans[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error" << endl;
		}
	}
}








/*
��ǥ����� �����ϴ� ������ x��� y���� �����ϴ� 2���� ��ǥ��鿡 ���� �����鼭 ��� �ֽ��ϴ�.������ �� ���� ���� k, d�� �־��� �� ������ ���� ���� ������ �մϴ�.

����(0, 0)���κ��� x�� �������� a*k(a = 0, 1, 2, 3 ...), y�� �������� b*k(b = 0, 1, 2, 3 ...)��ŭ ������ ��ġ�� ���� ����ϴ�.
������ �Ÿ��� d�� �Ѵ� ��ġ���� ���� ���� �ʽ��ϴ�.
���� ���, k�� 2, d�� 4�� ��쿡��(0, 0), (0, 2), (0, 4), (2, 0), (2, 2), (4, 0) ��ġ�� ���� ��� �� 6���� ���� ����ϴ�.

���� k�� �������� �Ÿ��� ��Ÿ���� ���� d�� �־����� ��, ���� �� �� �� �������� return �ϴ� solution �Լ��� �ϼ��ϼ���.

���ѻ���
1 �� k �� 1, 000, 000
1 �� d �� 1, 000, 000
����� ��
k	d	result
2	4	6
1	5	26
����� �� ����
����� �� #1

������ ���ÿ� �����ϴ�.
����� �� #2

(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (3, 0), (3, 1), (3, 2), (3, 3), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (5, 0) ��ġ�� ���� ���� �� ������, �� 26�� �Դϴ�.
*/