#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;
	int TotalCnt = 0;
	map<string, int> MapStrN_one;
	map<string, int>::iterator iter;

	for (int i = 0; i < number.size(); i++)
	{
		MapStrN_one[want[i]] = number[i];
		TotalCnt += number[i];
	}

	for (int i = 0; i < discount.size(); i++)
	{
		map<string, int> MapStrN = MapStrN_one;
		bool flag = false;

		if (TotalCnt + i > discount.size())
		{
			break;
		}

		for (int j = i; j < TotalCnt + i; j++)
		{
			MapStrN[discount[j]]--;
		}

		for (iter = MapStrN.begin(); iter != MapStrN.end(); iter++)
		{
			if (iter->second != 0)
			{
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			answer++;
		}
	}

	return answer;
}


int main()
{
	vector<vector<string>> want = { { "banana", "apple", "rice", "pork", "pot" }, {"apple"} };
	vector<vector<int>> number = { { 3, 2, 2, 2, 1 }, {10} };
	vector<vector<string>> discount = { {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"}
									,   {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"} };
	vector<int> result = { 3, 0 };
	vector<int> dab;

	for (int i = 0; i < result.size(); i++)
	{
		int k = solution(want[i], number[i], discount[i]);
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
XYZ ��Ʈ�� ������ �ݾ��� �����ϸ� 10�� ���� ȸ�� �ڰ��� �ο��մϴ�.
XYZ ��Ʈ������ ȸ���� ������� ���� �� ���� ��ǰ�� �����ϴ� ��縦 �մϴ�.
�����ϴ� ��ǰ�� �Ϸ翡 �ϳ����� ������ �� �ֽ��ϴ�.
�˶��� �����̴� �ڽ��� ���ϴ� ��ǰ�� ������ �����ϴ� ��¥�� 10�� �������� ��ġ�� ��쿡 ���缭 ȸ�������� �Ϸ� �մϴ�.

���� ���,
�����̰� ���ϴ� ��ǰ�� �ٳ��� 3��, ��� 2��, �� 2��, ������� 2��, ���� 1���̸�,
XYZ ��Ʈ���� 15�ϰ� ȸ���� ������� �����ϴ� ��ǰ�� ��¥ �������
ġŲ, ���, ���, �ٳ���, ��, ���, �������, �ٳ���, �������, ��, ����, �ٳ���, ���, �ٳ����� ��쿡 ���� �˾ƺ��ô�.

ù° ������ ���� ������ ���� �������� �ʱ� ������ ù° ������ ȸ�������� ���� �ʽ��ϴ�.
��° ������ ���� ������ �ٳ����� ���ϴ� ��ŭ ���α����� �� ���� ������ ��° ������ ȸ�������� ���� �ʽ��ϴ�.
��° ��, ��° ��, �ټ�° ������ ���� ������ ���ϴ� ��ǰ�� ������ ��ġ�ϱ� ������ �� �� �Ϸ翡 ȸ�������� �Ϸ� �մϴ�.

�����̰� ���ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 want��
�����̰� ���ϴ� ��ǰ�� ������ ��Ÿ���� ���� �迭 number,
XYZ ��Ʈ���� �����ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 discount�� �־����� ��,
ȸ����Ͻ� �����̰� ���ϴ� ��ǰ�� ��� ���� ���� �� �ִ� ȸ����� ��¥�� �� �ϼ��� return �ϴ� solution �Լ��� �ϼ��Ͻÿ�.

������ ���� ������ 0�� return �մϴ�.

���ѻ���
1 �� want�� ���� = number�� ���� �� 10
1 �� number�� ���� �� 10
number[i]�� want[i]�� ������ �ǹ��ϸ�, number�� ������ ���� 10�Դϴ�.
10 �� discount�� ���� �� 100,000
want�� discount�� ���ҵ��� ���ĺ� �ҹ��ڷ� �̷���� ���ڿ��Դϴ�.
1 �� want�� ������ ����, discount�� ������ ���� �� 12
*/