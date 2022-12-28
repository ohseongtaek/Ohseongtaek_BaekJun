#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetLarge(vector<int> pos, vector<int> impos)
{
	int maxNum = 0;
	vector<int> vec;

	// ù��° ������ ������ �������� ���� ��� ã�� 
	for (int i = 2; i <= pos[0]; i++)
	{
		if (pos[0] % i == 0)
		{
			bool flag = false;
			bool flag2 = false;
			for (int j = 0; j < pos.size(); j++)
			{
				if (pos[j] % i != 0)
				{
					flag = true;
					break;
				}
			}

			if (flag == false)
			{
				for (int j = 0; j < impos.size(); j++)
				{
					if (impos[j] % i == 0)
					{
						flag2 = true;
						break;
					}
				}
				if (flag2 == false)
				{
					maxNum = max(maxNum, i);
				}
			}
		}
	}

	return maxNum;
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
	int answer = 0;
	int A = 0;
	int B = 0;

	sort(arrayA.begin(), arrayA.end());
	sort(arrayB.begin(), arrayB.end());

	A = GetLarge(arrayA, arrayB);
	B = GetLarge(arrayB, arrayA);

	return (A > B) ? A : B;
}

int main()
{
	vector<vector<int>> a = { {10,17}, {10,20}, {14,35,119} };
	vector<vector<int>> b = { {5,20}, {5,17}, {18,30,102} };
	vector<int> result = { 0, 10, 7 };

	for (int i = 0; i < result.size(); i++)
	{
		int k = solution(a[i],b[i]);
		if (k == result[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error = " << k << ", wnat = " << result[i] << endl;
		}
	}
}
/*
ö���� ����� ���������κ��� ���ڰ� �ϳ��� ���� ī����� ���ݾ� ������ ���� ��, 
���� �� ���� �� �ϳ��� �����ϴ� ���� ū ���� ���� a�� ���� ���Ϸ��� �մϴ�.

ö���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ� 
���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a

���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ�, 
ö���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a

ī��鿡 10, 5, 20, 17�� ���� �ִ� ��쿡 ���� ������ ���ô�. 
����, ö���� [10, 17]�� ���� ī�带 ����, ���� [5, 20]�� ���� ī�带 ���´ٸ� 
�� ���� �� �ϳ��� �����ϴ� ���� ���� a�� �������� �ʽ��ϴ�. 

������, ö���� [10, 20]�� ���� ī�带 ����, 
���� [5, 17]�� ���� ī�带 ���´ٸ�, 
ö���� ���� ī����� ���ڴ� ��� 10���� ���� �� �ְ�, 
���� ���� ī����� ���ڴ� ��� 10���� ���� �� �����ϴ�. 
���� ö���� ����� ���� [10, 20]�� ���� ī��, [5, 17]�� ���� ī��� ���� �����ٸ� ���ǿ� �ش��ϴ� ���� ���� a�� 10�� �˴ϴ�.

ö���� ���� ī�忡 ���� ���ڵ��� ��� 3���� ���� �� ����, 
���� ���� ī�忡 ���� ���ڴ� ��� 3���� ���� �� �ֽ��ϴ�. ���� 3�� ���ǿ� �ش��ϴ� ���� �����Դϴ�. ������, ö���� ���� ī��鿡 ���� ���ڵ��� ��� 7�� ���� �� �ְ�, ���� ���� ī��鿡 ���� ���ڴ� ��� 7�� ���� �� �����ϴ�. ���� �ִ밪�� 7�� return �մϴ�.
*/