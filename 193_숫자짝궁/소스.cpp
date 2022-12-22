#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string solution(string X, string Y) 
{
	string answer = "";
	string answer2 = "";

	map<int, int> mx;
	map<int, int> my;

	for (int i = 0; i < X.length(); i++)
	{
		mx[X[i]-48]++;
	}
	for (int i = 0; i < Y.length(); i++)
	{
		my[Y[i]-48]++;
	}

	int idx = 9;

	while (true)
	{
		int mm = min(mx[idx], my[idx]);

		if (mm == 0)
		{
			idx--;
		}
		else
		{
			for (int i = 0; i < mm; i++)
			{
				answer += to_string(idx);
			}
			idx--;
		}

		if (idx == -1)
		{
			break;
		}
	}

	answer2 = answer;

	if (answer == "")
	{
		answer2 = "-1";
	}
	else
	{
		answer.erase(unique(answer.begin(), answer.end()), answer.end());
		int idx = answer.find("0");
		if (idx != std::string::npos)
		{
			answer.erase(idx, 1);
			if (answer == "")
			{
				answer2 = "0";
			}
			else
			{
				
			}
		}
	}

	return answer2;
}

int main()
{
	vector<string> v = { "100","100","100","12321","5525" };
	vector<string> v2 = { "2345","203045","123450","42531","1255" };
	vector<string> dab = { "-1","0","10","321","552" };

	for (int i = 0; i < v.size(); i++)
	{
		cout << solution(v[i], v2[i]) << endl;
	}
}

/*
�� ���� X, Y�� ������ �ڸ����� �������� ��Ÿ���� ���� k(0 �� k �� 9)���� �̿��Ͽ� ���� �� �ִ� ���� ū ������ �� ���� ¦���̶� �մϴ�
(��, �������� ��Ÿ���� ���� �� ���� ¦���� �� �ִ� ���ڸ� ����մϴ�). 
X, Y�� ¦���� �������� ������, ¦���� -1�Դϴ�. 
X, Y�� ¦���� 0���θ� �����Ǿ� �ִٸ�, ¦���� 0�Դϴ�.

���� ���, X = 3403�̰� Y = 13203�̶��, X�� Y�� ¦���� X�� Y���� �������� ��Ÿ���� 3, 0, 3���� ���� �� �ִ� ���� ū ������ 330�Դϴ�. �ٸ� ���÷� X = 5525�̰� Y = 1255�̸� X�� Y�� ¦���� X�� Y���� �������� ��Ÿ���� 2, 5, 5�� ���� �� �ִ� ���� ū ������ 552�Դϴ�(X���� 5�� 3��, Y���� 5�� 2�� ��Ÿ���Ƿ� ���� 5 �� ���� ¦ ���� �� �����ϴ�.)
�� ���� X, Y�� �־����� ��, X, Y�� ¦���� return�ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
3 �� X, Y�� ����(�ڸ���) �� 3,000,000�Դϴ�.
X, Y�� 0���� �������� �ʽ��ϴ�.
X, Y�� ¦���� ����� ū ������ �� �����Ƿ�, ���ڿ��� ��ȯ�մϴ�.

X, Y�� ¦���� �������� �ʽ��ϴ�. ���� "-1"�� return�մϴ�.
����� �� #2

X, Y�� ����� ���ڴ� 0���θ� �����Ǿ� �ֱ� ������, �� ���� ¦���� ���� 0�Դϴ�. ���� "0"�� return�մϴ�.
����� �� #3

X, Y�� ¦���� 10�̹Ƿ�, "10"�� return�մϴ�.
����� �� #4

X, Y�� ¦���� 321�Դϴ�. ���� "321"�� return�մϴ�.
����� �� #5

������ ����� ���ÿ� �����ϴ�.
*/