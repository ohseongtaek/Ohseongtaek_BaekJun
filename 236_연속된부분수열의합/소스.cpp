#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) 
{
    // ���� ������� �տ��� ���� 
    if ((a.second - a.first) == (b.second - b.first))
    {
        return a.first < b.first;
    }
    // ���� �ٸ���� ������ ���� 
    return (a.second - a.first) < (b.second - b.first);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> vp;

    int left = 0;
    int right = 0;
    int sum = 0;

    while (left < sequence.size())
    {
        // ���� ���ų� ū ��� 
        if (sum >= k || right >= sequence.size())
        {
            sum = sum - sequence[left];
            left++;
        }
        else
        {
            sum = sum + sequence[right];
            right++;
        }

        if (sum == k)
        {
            vp.push_back(make_pair(left, right - 1));
        }
    }

    sort(vp.begin(), vp.end(), comp);

    answer.push_back(vp[0].first);
    answer.push_back(vp[0].second);

    return answer;
}


int main()
{
    vector<vector<int>> s = { { 1, 2, 3, 4, 5 },
                               {1, 1, 1, 2, 3, 4, 5},
                               {2, 2, 2, 2, 2} };
    vector<int> k = { 7,5,6 };
	vector<vector<int>> dab = { {2, 3},
	                            {6, 6},
	                            {0, 2}};
    
    for (int i = 0; i < dab.size(); i++)
    {
        bool flag = false;
        vector<int> a = solution(s[i], k[i]);
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != dab[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
}
/*
* ������ ��Ÿ���� ���� �迭 sequence�� �κ� ������ ���� ��Ÿ���� ���� k�� �Ű������� �־��� ��, �� ������ �����ϴ� �κ� ������ ���� �ε����� ������ �ε����� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���. �̶� ������ �ε����� 0���� �����մϴ�.

���ѻ���
5 �� sequence�� ���� �� 1,000,000
1 �� sequence�� ���� �� 1,000
sequence�� �񳻸��������� ���ĵǾ� �ֽ��ϴ�.
5 �� k �� 1,000,000,000
k�� �׻� sequence�� �κ� ������ ���� �� �ִ� ���Դϴ�.
����� ��
sequence	k	result

����� �� ����
����� �� #1

{1, 2, 3, 4, 5}���� ���� 7�� ���ӵ� �κ� ������ {3, 4}���̹Ƿ� �ش� ������ ���� �ε����� 2�� ������ �ε��� 3�� �迭�� ��� {2, 3}�� ��ȯ�մϴ�.

����� �� #2

{1, 1, 1, 2, 3, 4, 5}���� ���� 5�� ���ӵ� �κ� ������ {1, 1, 1, 2}, {2, 3}, {5}�� �ֽ��ϴ�. �� �� {5}�� ���̰� ���� ª���Ƿ� �ش� ������ ���� �ε����� ������ �ε����� ���� {6, 6}�� ��ȯ�մϴ�.

����� �� #3

{2, 2, 2, 2, 2}���� ���� 6�� ���ӵ� �κ� ������ {2, 2, 2}�� 3���� ��찡 �ִµ�, ���̰� ª�� ������ ���� ���� ��� ���ʿ� ���� ������ ã���Ƿ� {0, 2}�� ��ȯ�մϴ�.
*/