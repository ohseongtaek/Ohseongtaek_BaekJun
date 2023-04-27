#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int DP[151][151];

int AlgorithmPoint = 0;
int CodingPoint = 0;

int CalcDP(int alp, int cop, vector<vector<int>>& problems)
{
    if (AlgorithmPoint <= alp && CodingPoint <= cop)
    {
        return 0;
    }
    else
    {
        int& result = DP[alp][cop];

        if (result != -1)
        {
            return result;
        }
        else
        {
            result = 987654321;
            result = min(result, CalcDP(min(AlgorithmPoint, alp + 1), cop, problems) + 1);
            result = min(result, CalcDP(alp, min(CodingPoint, cop + 1), problems) + 1);

            for (int i = 0; i < problems.size(); i++)
            {
                if (alp < problems[i][0] || cop < problems[i][1])
                {
                    continue;
                }

                result = min(result, CalcDP(min(AlgorithmPoint, alp + problems[i][2]), min(CodingPoint, cop + problems[i][3]), problems) + problems[i][4]);
            }

            return result;
        }
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) 
{
    int answer = 0;
    memset(DP, -1, sizeof(DP));

    // �ִ�� ���ؾ��ϴ� �ڵ��°� �˰��� ����ϱ� 
    for (int i = 0; i < problems.size(); i++)
    {
        AlgorithmPoint = max(AlgorithmPoint, problems[i][0]);
        CodingPoint = max(CodingPoint, problems[i][1]);
    }

    answer = CalcDP(alp, cop, problems);
    return answer;
}

/*
�ڵ��� 5�� �ø��ϴ�. �˰�� 10, �ڵ��� 15�� �Ǹ� �ð��� 5��ŭ �ҿ�˴ϴ�.

1�� ������ 5�� Ǳ�ϴ�. �˰�� 20, �ڵ��� 20�� �Ǹ� �ð��� 10��ŭ �ҿ�˴ϴ�. 15�� �ð��� �ҿ��Ͽ� ��� ������ Ǯ �� �ִ� �˰�°� �ڵ����� ���� �� �ֽ��ϴ�.
����� �� #2

1�� ������ 2�� Ǳ�ϴ�. �˰�� 4, �ڵ��� 2�� �Ǹ� �ð��� 4��ŭ �ҿ�˴ϴ�.
�ڵ��� 3�� �ø��ϴ�. �˰�� 4, �ڵ��� 5�� �Ǹ� �ð��� 3��ŭ �ҿ�˴ϴ�.
2�� ������ 2�� Ǳ�ϴ�. �˰�� 10, �ڵ��� 7�� �Ǹ� �ð��� 4��ŭ �ҿ�˴ϴ�.
4�� ������ 1�� Ǳ�ϴ�. �˰�� 10, �ڵ��� 11�� �Ǹ� �ð��� 2��ŭ �ҿ�˴ϴ�. 13�� �ð��� �ҿ��Ͽ� ��� ������ Ǯ �� �ִ� �˰�°� �ڵ����� ���� �� �ֽ��ϴ�.
*/

int main()
{
    vector<int> alp = { 10,0 };
    vector<int> cop = { 10,0 };
    vector<int> dab = { 15,23 };
                                        //�˰�� �ڵ��� �����˰�� �����ڵ��� Ǫ�½ð� 
    vector<vector<vector<int>>> pr = { { {10, 15, 2, 1, 2}, { 20,20,3,3,4 }},
                                         {{0, 0, 2, 1, 2}, { 4,5,3,1,2 }, { 4,11,4,0,2 }, { 10,4,0,4,2 }} };
    
    for (int i = 0; i < alp.size(); i++)
    {
        int ans = solution(alp[i], cop[i], pr[i]);
        if (ans == dab[i])
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
�˰��� ���� ������ �˰��
�ڵ带 �����ϴ� �ɷ��� �ڵ����̶�� ǥ���մϴ�.
�˰�°� �ڵ����� 0 �̻��� ������ ǥ���˴ϴ�.

���� ���, ����� ���� �˰���� 15, �ڵ����� 10�̶�� �����غ��ڽ��ϴ�.

A��� ������ �˰�� 10, �ڵ��� 10�� �䱸�Ѵٸ� A ������ Ǯ �� �ֽ��ϴ�.
B��� ������ �˰�� 10, �ڵ��� 20�� �䱸�Ѵٸ� �ڵ����� �����ϱ� ������ B ������ Ǯ �� �����ϴ�.

Ǯ �� ���� ������ �ذ��ϱ� ���ؼ��� �˰�°� �ڵ����� ������ �մϴ�. 
�˰�°� �ڵ����� ���̱� ���� ������ ���� ������� �ֽ��ϴ�.

�˰���� ���̱� ���� �˰��� ���θ� �մϴ�. 
�˰�� 1�� ���̱� ���ؼ� 1�� �ð��� �ʿ��մϴ�.

�ڵ����� ���̱� ���� �ڵ� ���θ� �մϴ�. 
�ڵ��� 1�� ���̱� ���ؼ� 1�� �ð��� �ʿ��մϴ�.

���� Ǯ �� �ִ� ���� �� �ϳ��� Ǯ�� �˰�°� �ڵ����� ���Դϴ�. 
�� �������� ������ Ǯ�� �ö󰡴� �˰�°� �ڵ����� ������ �ֽ��ϴ�.

������ �ϳ� Ǫ�� ���� ������ �䱸�ϴ� �ð��� �ʿ��ϸ� ���� ������ ���� �� Ǫ�� ���� �����մϴ�.

����� �־��� ��� �������� Ǯ �� �ִ� �˰�°� �ڵ����� ��� �ִܽð��� ���Ϸ� �մϴ�.

�ʱ��� �˰�°� �ڵ����� ���� ���� alp�� cop, 
������ ������ ���� 2���� ���� �迭 problems�� �Ű������� �־����� ��, 
��� �������� Ǯ �� �ִ� �˰�°� �ڵ����� ��� �ִܽð��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

��� �������� 1�� �̻� Ǯ �ʿ�� �����ϴ�. 
����� �� ������ �������ּ���.

���ѻ���
�ʱ��� �˰���� ��Ÿ���� alp�� �ʱ��� �ڵ����� ��Ÿ���� cop�� �Է����� �־����ϴ�.
0 �� alp,cop �� 150
1 �� problems�� ���� �� 100

problems�� ���Ҵ� {alp_req, cop_req, alp_rwd, cop_rwd, cost}�� ���·� �̷���� �ֽ��ϴ�.
alp_req�� ������ Ǫ�µ� �ʿ��� �˰���Դϴ�.
0 �� alp_req �� 150
cop_req�� ������ Ǫ�µ� �ʿ��� �ڵ����Դϴ�.
0 �� cop_req �� 150
alp_rwd�� ������ Ǯ���� �� �����ϴ� �˰���Դϴ�.
0 �� alp_rwd �� 30
cop_rwd�� ������ Ǯ���� �� �����ϴ� �ڵ����Դϴ�.
0 �� cop_rwd �� 30
cost�� ������ Ǫ�µ� ��� �ð��Դϴ�.
1 �� cost �� 100
��Ȯ�� �׽�Ʈ ���̽� ���ѻ���

0 �� alp,cop �� 20
1 �� problems�� ���� �� 6
0 �� alp_req,cop_req �� 20
0 �� alp_rwd,cop_rwd �� 5
1 �� cost �� 10
ȿ���� �׽�Ʈ ���̽� ���ѻ���

�־��� ���� �� �߰� ���ѻ��� �����ϴ�.
����� ��


���ѽð� �ȳ�

��Ȯ�� �׽�Ʈ : 10��
ȿ���� �׽�Ʈ : ���� �ۼ��� ���� �ڵ��� ���� �ð��� ���� ���
*/
