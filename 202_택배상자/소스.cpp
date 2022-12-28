#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) 
{
	int answer = 0;
	int index = 0;
	vector<int> save1;
	save1.push_back(10000001);

	for (int i = 1; i < order.size() + 1; i++) 
	{
		if (order[index] == i) 
		{
			index += 1;
		}
		else if (order[index] == save1.back()) 
		{
			save1.pop_back();
			index += 1;
			i -= 1;
		}
		else 
		{
			save1.push_back(i);
		}
	}

	while (save1.size() != 1) 
	{
		if (save1.back() == order[index]) 
		{
			index += 1;
			save1.pop_back();
		}
		else 
		{
			break;
		}
	}
	return index;
}

/* �ð��ʰ� �ڵ� 
int solution(vector<int> order) 
{
	int answer = 0;
	bool flag = false;
	stack<int> belt;
	stack<int> belt_sub;

	for (int i = order.size(); i > 0; i--)
	{
		belt.push(i);
	}

	while (flag == false)
	{
		
		int want = order[0];
		int BeltNum = 0;
		int BeltSubNum = 0;
		
		if (!belt.empty())
		{
			BeltNum = belt.top();
		}

		if (!belt_sub.empty())
		{
			BeltSubNum = belt_sub.top();
		}

		if (want == BeltNum)
		{
			belt.pop();
			answer++;
			order.erase(order.begin());
		}
		else if (want == BeltSubNum)
		{
			belt_sub.pop();
			answer++;
			order.erase(order.begin());
		}
		else
		{
			if (want < BeltNum)
			{
				flag = true;
			}
			else
			{
				belt_sub.push(BeltNum);
				belt.pop();
			}
		}

		if (order.size() == 0 || (true == belt.empty() && true == belt_sub.empty()))
		{
			flag = true;
		}
	}
	return answer;
}
*/
int main()
{
	vector<vector<int>> number = { {4, 3, 1, 2, 5}	, {5, 4, 3, 2, 1} , {2, 1, 4, 3, 6, 5, 8, 7, 10, 9}, {1,2,3,4,5} };
	vector<int> result = { 2, 5, 10, 5 };

	for (int i = 0; i < result.size(); i++)
	{
		int k = solution(number[i]);
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
����� �ù���ڸ� Ʈ���� �ƴ� ���� �մϴ�. 
���簡 �Ǿ�� �ϴ� �ù���ڴ� ũ�Ⱑ ��� ������ 
1�� ���ں��� n�� ���ڱ��� ��ȣ�� �����ϴ� ������� �����̳� ��Ʈ�� �Ϸķ� ���� ���翡�� ���޵˴ϴ�.

�����̳� ��Ʈ�� �� �������θ� ������ �����ؼ� ��Ʈ�� ���� �������(1�� ���ں���) ���ڸ� ���� �� �ֽ��ϴ�. 

������ �����̳� ��Ʈ�� ���� ������� �ù���ڸ� ���� �ٷ� Ʈ���� �ư� �Ǹ� �ù� ������ ����ϴ� ������ �ù���ڰ� �Ƿ� �ִ� ������ ���� �ʾ� ��޿� ������ ����ϴ�. 
���� �ù� ������ �̸� �˷��� ������ �°� ���簡 �ù���ڸ� �Ǿ�� �մϴ�.

���� �����̳� ��Ʈ�� �� �տ� ���� ���ڰ� ���� Ʈ���� �Ǿ�� �ϴ� ������ �ƴ϶�� 
�� ���ڸ� Ʈ���� ���� ������ �� ������ ��� �ٸ� ���� �����ؾ� �մϴ�. 
������ ���� ������ �Ժη� ���� �� �� ���� ���� �����̳� ��Ʈ�� �߰��� ��ġ�Ͽ����ϴ�. 
���� �����̳� ��Ʈ�� �� �ڷ� �̵��� ���������� �Ա� �ܿ� �ٸ� ���� ���� �־ �� ���� ���ڸ� �� �� �ֽ��ϴ�
(��, ���� �������� ���� �����̳� ��Ʈ�� ������ ���ں��� ������ �˴ϴ�).
���� �����̳� ��Ʈ�� �̿��ص� ������ ���ϴ� ������� ���ڸ� ���� �� �Ѵٸ�, 
�� �̻� ���ڸ� ���� �ʽ��ϴ�.

���� ���, ���簡 5���� ���ڸ� �Ǿ�� �ϸ�, 
�ù� ������ �˷��� ������ ������ �����̳� ��Ʈ�� �� ��°, �� ��°, ù ��°, �� ��°, �ټ� ��° ���� �ù���� ������ ���, 
����� �켱 ù ��°, �� ��°, �� ��° ���ڸ� ���� �����̳� ��Ʈ�� �����մϴ�. 
�� �� �� ��° ���ڸ� Ʈ���� �ư� ���� �����̳� ��Ʈ���� �� ��° ���� ���� Ʈ�����ƽ��ϴ�. 
�������� ù ��° ���ڸ� �Ǿ�� ������ ���� �����̳� ��Ʈ������ �� ��° ���ڸ�, ������ �����̳� ��Ʈ���� �ټ� ��° ���ڸ� ���� �� �ֱ� ������ ���̻��� ���ڴ� ���� �� �����ϴ�. 
���� Ʈ������ 2���� ���ڸ� �Ǹ��� �˴ϴ�.

��� ���ڸ� ���� �����̳� ��Ʈ�� ��� �ְ�, �������� �ϳ��� ���� Ʈ���� �ƽ��ϴ�.
*/