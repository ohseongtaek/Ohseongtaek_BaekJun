#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int finger[(const int)1e5 + 1][10][10];

const int AlreadyFinger[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};
int DP(int idx, int left, int right, string& number)
{
	if (idx == number.length())
	{
		return 0;
	}

	int& result = finger[idx][left][right];

	if (result != -1)
	{
		return result;
	}

	int cur = number[idx] - '0';

	if (left == cur || right == cur)
	{
		return result = 1 + DP(idx + 1, left, right, number);
	}

    result = min(DP(idx + 1, cur, right, number) + AlreadyFinger[left][cur], DP(idx + 1, left, cur, number) + AlreadyFinger[right][cur]);
	return result;}int solution(string numbers) 
{
    int answer = 0;
    memset(finger, -1, sizeof(finger));
    answer = DP(0, 4, 6, numbers);
    return answer;
}

int main()
{
    vector<string> number = { "1756", "5123" };
    vector<int> d = { 10,8 };
    
        
    for (int i = 0; i < d.size(); i++)
    {
        int ans = solution(number[i]);
        if (ans == d[i])
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
����� �׻� �޼� ������ 4 ����, ������ ������ 6 ���� �ΰ� Ÿ������ �����մϴ�. 
���� �հ����� ������ ���� ���ڸ� ������ ������ ���� �ð��� ��ϴ�. ����� � �� ���ڸ� �������� �Է��ϴ� �ð� ����� ��� ����ġ�� �з��Ͽ����ϴ�.

�̵����� �ʰ� ���ڸ����� �ٽ� ������ ���� ����ġ�� 1�Դϴ�.
�����¿�� ������ ���ڷ� �̵��Ͽ� ������ ���� ����ġ�� 2�Դϴ�.
�밢������ ������ ���ڷ� �̵��Ͽ� ������ ���� ����ġ�� 3�Դϴ�.
���� �ʰ� �������� ���� ���ڸ� ���� ���� �� ��Ģ�� ���� ����ġ ���� �ּҰ� �Ǵ� ��θ� �����ϴ�.
���� ��� 1 ���� �ִ� �հ����� 0 ���� �̵��Ͽ� ������ ���� 2 + 2 + 3 = 7 ��ŭ�� ����ġ�� �����ϴ�.
��, ���� ������ ��ư�� ũ�Ⱑ �۱� ������ ���� ���� ��ư ���� ���ÿ� �� ���� �հ����� �÷����� �� �����ϴ�. 
��, � ���ڸ� ������ �� ���ʿ� �� ���� ���� �÷��� �ִ� �հ����� �ִٸ� �ݵ�� �� �հ������� ������ �մϴ�.

���ڷ� �̷���� ���ڿ� numbers�� �־����� �� �ּ����� �ð����� Ÿ������ �ϴ� ����� ����ġ ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� numbers�� ���� �� 100,000
numbers�� �ƶ��� ���ڷθ� �̷���� ���ڿ��Դϴ�.
����� ��
numbers	result
"1756"	10
"5123"	8
����� �� ����
����� �� #1
�޼� ������ 17, ������ ������ 56�� ������ ����ġ 10���� �ּ��Դϴ�.

����� �� #2
������ ������ 5, �޼� ������ 123�� �����ų� ������ ������ 5, �޼� ������ 1, ������ ������ 23�� ������ ����ġ 8�� �ּ��Դϴ�.
*/