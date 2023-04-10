#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = 9999;

    vector<string> p;

    for (int i = 0; i < picks.size(); i++)
    {
        for (int j = 0; j < picks[i]; j++)
        {
            if (i == 0)
            {
                p.push_back("DIAMOND");
            }
            else if (i == 1)
            {
                p.push_back("IRON");
            }
            else if (i == 2)
            {
                p.push_back("STONE");
            }
        }
    }

    int msize = minerals.size();
    if (p.size() * 5 < msize)
    {
        msize = p.size() * 5;
    }

    do
    {
        int idx = 0;
        int nCount = 0;
        int AllCnt = 0;
        int sum = 0;
        string currentPick = p[idx];

        for (int i = 0; i < msize; i++)
        {
            string mineral = minerals[i];

            if (currentPick == "DIAMOND")
            {
                sum += 1;
            }
            else if (currentPick == "IRON")
            {
                if (mineral == "diamond")
                {
                    sum += 5;
                }
                else
                {
                    sum += 1;
                }
            }
            else if (currentPick == "STONE")
            {
                if (mineral == "diamond")
                {
                    sum += 25;
                }
                else if (mineral == "iron")
                {
                    sum += 5;
                }
                else if (mineral == "stone")
                {
                    sum += 1;
                }
            }


            nCount++;
            AllCnt++;
            if (nCount == 5)
            {
                idx++;
                if (AllCnt != msize)
                {
                    currentPick = p[idx];
                }
                nCount = 0;
            }

        }

        answer = min(answer, sum);

    } while (next_permutation(p.begin(),p.end()));


    return answer;
}

int main()
{
    vector<vector<int>> p = { { 1, 3, 2 }, {0, 1, 1} };
    vector<vector<string>> m = { { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" }, 
                                 { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" } };
    vector<int> dab = { 12,50 };

    for (int i = 0; i < dab.size(); i++)
    {
        int an = solution(p[i], m[i]);

        if (an == dab[i])
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
������ ��̷� ���꿡�� ������ ĳ���� �մϴ�. 
������ ���̾Ƹ�� ���, ö ���, �� ��̸� ���� 0������ 5������ ������ ������, 

��̷� ������ Ķ ���� �Ƿε��� �Ҹ�˴ϴ�. �� ��̷� ������ Ķ ���� �Ƿε��� �Ʒ� ǥ�� �����ϴ�.

���� ���, ö ��̴� ���̾Ƹ�带 Ķ �� �Ƿε� 5�� �Ҹ�Ǹ�, ö�� ���� Ķ���� �Ƿε��� 1�� �Ҹ�˴ϴ�. 
�� ��̴� ������ ������� ���� 5���� ĵ �Ŀ��� �� �̻� ����� �� �����ϴ�.

������ ������ ���� ��Ģ�� ��Ű�鼭 �ּ����� �Ƿε��� ������ ĳ���� �մϴ�.

����� �� �ִ� ����� �ƹ��ų� �ϳ��� ������ ������ ĸ�ϴ�.
�� �� ����ϱ� ������ ��̴� ����� �� ���� ������ ����մϴ�.
������ �־��� ������θ� Ķ �� �ֽ��ϴ�.
���꿡 �ִ� ��� ������ ĳ�ų�, �� ����� ��̰� ���� ������ ������ ĸ�ϴ�.
��, ��̸� �ϳ� �����ؼ� ���� 5���� �������� ĳ��, ���� ��̸� �����ؼ� ���� 5���� �������� ĳ�� ������ �ݺ��ϸ�, �� ����� ��̰� ���ų� ���꿡 �ִ� ��� ������ Ķ ������ ������ �ݺ��ϸ� �˴ϴ�.

������ ���� �ִ� ����� ������ ��Ÿ���� ���� �迭 picks�� �������� ������ ��Ÿ���� ���ڿ� �迭 minerals�� �Ű������� �־��� ��, ������ �۾��� ��������� �ʿ��� �ּ����� �Ƿε��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
picks�� {dia, iron, stone}�� ���� ������ �̷���� �ֽ��ϴ�.
0 �� dia, iron, stone �� 5
dia�� ���̾Ƹ�� ����� ���� �ǹ��մϴ�.
iron�� ö ����� ���� �ǹ��մϴ�.
stone�� �� ����� ���� �ǹ��մϴ�.
��̴� �ּ� 1�� �̻� ������ �ֽ��ϴ�.
5 �� minerals�� ���� �� 50
minerals�� ���� 3���� ���ڿ��� �̷���� ������ ������ �ǹ̴� ������ �����ϴ�.
diamond : ���̾Ƹ��
iron : ö
stone : ��
����� ��
picks	minerals	result
{1, 3, 2}	{"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"}	12
{0, 1, 1}	{"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"}	50
����� �� ����
����� �� #1

���̾Ƹ�� ��̷� �տ� �ټ� ������ ĳ�� ö ��̷� ���� ���̾Ƹ��, ö, ���� 1���� ĳ�� 12(1 + 1 + 1 + 1+ 1 + 5 + 1 + 1)�� �Ƿε��� Ķ �� ������ �̶��� �ּҰ��Դϴ�.

����� �� #2

ö ��̷� ���̾Ƹ�� 5���� ĳ�� �� ��̰� ö 5���� ĳ�� 50�� �Ƿε��� Ķ �� ������, �̶��� �ּҰ��Դϴ�.
*/