#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//��Ʈ ��� ������ �Բ� DP �� Ǯ����� 
struct numInfo
{
    int num;
    int numCnt;
};

numInfo DP[5000001];

bool comp(numInfo& a, numInfo& b) 
{
    if (a.numCnt == b.numCnt)
    {
        return a.num < b.num;
    }
    else
    {
        return a.numCnt > b.numCnt;
    }
    
}

vector<int> solution(int e, vector<int> starts) 
{
    vector<int> answer;
    
    for (int i = 1; i <= e; i++) 
    {
        DP[i].num = i;
        for (int k = 1; k <= e / i; k++) 
        {
            DP[i * k].numCnt++;
        }
    }

    sort(DP + 1, DP + e + 1, comp);

    for (auto s : starts) 
    {
        for (int i = 1; i <= e; i++) 
        {
            if (DP[i].num >= s && DP[i].num <= e)
            {
                answer.push_back(DP[i].num);
                break;
            }
        }
    }
    return answer;
}

int main()
{
    int e = 8;
    vector<int> s = { 1,3,7 };
    vector<int> d = { 6,6,8 };

    vector<int> ans = solution(e, s);

    bool flag = true;

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] != ans[i])
        {
            flag = false;
        }

        if (flag == false)
        {
            break;
        }
    }


    if (flag == false)
    {
        cout << " error " << endl;
    }
    else
    {
        cout << " good " << endl;
    }
}


/*
�׸�1.png
������ �� e�� ���� ���Ͽ� �˷��ְ� e ������ ������ �� s�� ���� �� ����մϴ�. 
����� �� s�� ���ؼ� s���� ũ�ų� ���� e ���� �۰ų� ���� �� �߿��� ���ܿ��� ���� ���� ������ ���� ���ؾ� �մϴ�. 
���� ���� ���� ������ ���� ���� ����� �� �� ���� ���� ���� ���ؾ� �մϴ�.

������ ���찡 ������ ���ϴ��� Ȯ���ϱ� ���� ��ſ��� ���α׷� ������ �Ƿ��Ͽ����ϴ�. 
e�� s�� ��� starts�� �Ű������� �־��� �� �� ������ �� ����� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� e �� 5,000,000
1 �� starts�� ���� �� min {e,100,000}
1 �� starts�� ���� �� e
starts���� �ߺ��Ǵ� ���Ұ� �������� �ʽ��ϴ�.
����� ��
e	starts	result
8	[1,3,7]	[6,6,8]
����� �� ����
���ܿ��� 1 ~ 8�� �����ϴ� Ƚ���� ������ �����ϴ�.

1�� ���� : 1
2�� ���� : 2, 3, 5, 7
3�� ���� : 4
4�� ���� : 6, 8

[1, 8] ���������� 6�� 8�� ���� 4���� �����Ͽ� ���� ������ 6�� �� ���� ���̹Ƿ� 6�� �����Դϴ�.
[3, 8] ���������� ���� �����Ƿ� 6�� �����Դϴ�.
[7, 8] ���������� 7�� 2��, 8�� 4�� �����ϹǷ� 8�� �����Դϴ�.

*/