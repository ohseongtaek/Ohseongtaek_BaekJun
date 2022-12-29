#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Column;

//col ��° �÷��� �������� �������� �����ϸ� �⺻Ű�� ������������ 
bool cmp(vector<int> a, vector<int> b)
{
	if (a[Column - 1] == b[Column - 1])
	{
		return a[0] > b[0];
	}
	return a[Column - 1] < b[Column - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
	int answer = 0;
	vector<int> vec;
	Column = col;
	
	sort(data.begin(), data.end(), cmp);

	for (int i = row_begin; i <= row_end; i++)
	{
		int gogo = i - 1;
		int sum = 0;

		for (int j = 0; j < data[gogo].size(); j++)
		{
			sum += data[gogo][j] % i;
		}

		vec.push_back(sum);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		answer = answer ^ vec[i];
	}

	return answer;
}

int main()
{
	vector<vector<int>> v = { {2,2,6},{1,5,10},{4,2,9},{3,8,3} };
	int col = 2;
	int row = 2;
	int row2 = 3;
	int r = 4;

	if (r == solution(v, col, row, row2))
	{
		cout << " good " << endl;
	}
	else
	{
		cout << " error " << endl;
	}
}

/*
��ȣ�� �����ϴ� � �����ͺ��̽��� �� ���̺��� ��� ���� Ÿ���� �÷���� �̷���� �ֽ��ϴ�. 
���̺��� 2���� ��ķ� ǥ���� �� ������ ���� �÷��� ��Ÿ����, ���� Ʃ���� ��Ÿ���ϴ�.

ù ��° �÷��� �⺻Ű�μ� ��� Ʃ�ÿ� ���� �� ���� �ߺ����� �ʵ��� ����˴ϴ�. 
��ȣ�� �� ���̺� ���� �ؽ� �Լ��� ������ ���� �����Ͽ����ϴ�.

�ؽ� �Լ��� col, row_begin, row_end�� �Է����� �޽��ϴ�.
���̺��� Ʃ���� col��° �÷��� ���� �������� �������� ������ �ϵ�, ���� �� ���� �����ϸ� �⺻Ű�� ù ��° �÷��� ���� �������� �������� �����մϴ�.
���ĵ� �����Ϳ��� S_i�� i ��° ���� Ʃ�ÿ� ���� �� �÷��� ���� i �� ���� ���������� ������ �����մϴ�.
row_begin �� i �� row_end �� ��� S_i�� �����Ͽ� bitwise XOR �� ���� �ؽ� �����μ� ��ȯ�մϴ�.
���̺��� ������ data�� �ؽ� �Լ��� ���� �Է� col, row_begin, row_end�� �־����� �� ���̺��� �ؽ� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
1 �� data�� ���� �� 2,500
1 �� data�� ������ ���� �� 500
1 �� data{i}{j} �� 1,000,000
data{i}{j}�� i + 1 ��° Ʃ���� j + 1 ��° �÷��� ���� �ǹ��մϴ�.
1 �� col �� data�� ������ ����
1 �� row_begin �� row_end �� data�� ����

������ ����� ���� Ʃ���� �����ϸ� {4, 2, 9}, {2, 2, 6}, {1, 5, 10}, {3, 8, 3} �� �˴ϴ�.
S_2 = (2 mod 2) + (2 mod 2) + (6 mod 2) = 0 �Դϴ�.
S_3 = (1 mod 3) + (5 mod 3) + (10 mod 3) = 4 �Դϴ�.
���� �ؽ� ���� S_2 XOR S_ 3 = 4 �Դϴ�.
*/