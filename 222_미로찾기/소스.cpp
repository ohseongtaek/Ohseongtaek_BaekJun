#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit[101][101];

int solution(vector<string> maps) 
{
    int answer = 0;

    pair<int, int> lever = { -1,-1 };
    pair<int, int> Start = { -1,-1 };
    pair<int, int> m[4] = { {-1,0},{1,0},{0,-1},{0,1} };

    bool blever = false;
    bool bend = false;
    
    memset(visit, -1, sizeof(visit));
    // ������ ã�� 
    for (int i = 0; i < maps.size(); i++)
    {
        string test = maps[i];
        int idx = test.find("S");

        if (idx != std::string::npos)
        {
            Start.first = i;
            Start.second = idx;
            break;
        }
    }

    visit[Start.first][Start.second] = 0;
    
    // ���������� �������� �ִܰŸ� ã�� 
    queue<pair<int, int>> qp;
    int count = 0;
    qp.push(Start);

    while (qp.empty() == false)
    {
        auto pfront = qp.front();
        qp.pop();

        if (maps[pfront.first][pfront.second] == 'L')
        {
            count = visit[pfront.first][pfront.second];
            lever = { pfront.first, pfront.second };
            blever = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nX = pfront.first + m[i].first;
            int nY = pfront.second + m[i].second;

            if (nX < 0 || nX >= maps.size())
            {
                continue;
            }
            if (nY < 0 || nY >= maps[0].size())
            {
                continue;
            }

            if (visit[nX][nY] >= 0)
            {
                continue;
            }


            if (maps[nX][nY] == 'O' || maps[nX][nY] == 'L' || maps[nX][nY] == 'S' || maps[nX][nY] == 'E')
            {
                visit[nX][nY] = visit[pfront.first][pfront.second] + 1;
                pair<int, int> tp = { nX,nY };
                qp.push(tp);
            }
        }
    }

    if (blever == false)
    {
        return -1;
    }

    //�������� end���� ������ ã�� 
    queue<pair<int, int>> eqp;

    memset(visit, -1, sizeof(visit));
    visit[lever.first][lever.second] = 0;
    int ecount = 0;
    eqp.push(lever);
    
    while (eqp.empty() == false)
    {
        auto pfront = eqp.front();
        eqp.pop();

        if (maps[pfront.first][pfront.second] == 'E')
        {
            ecount = visit[pfront.first][pfront.second];
            bend = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nX = pfront.first + m[i].first;
            int nY = pfront.second + m[i].second;

            if (nX < 0 || nX >= maps.size())
            {
                continue;
            }
            if (nY < 0 || nY >= maps[0].size())
            {
                continue;
            }

            if (visit[nX][nY] >= 0)
            {
                continue;
            }


            if (maps[nX][nY] == 'O' || maps[nX][nY] == 'L' || maps[nX][nY] == 'E' || maps[nX][nY] == 'S')
            {
                visit[nX][nY] = visit[pfront.first][pfront.second] + 1;
                pair<int, int> tp = { nX,nY };
                eqp.push(tp);
            }
        }
    }

    if (bend == false)
    {
        return -1;
    }

    answer = count + ecount;
    return answer;
}

int main()
{
    vector<vector<string>> m = {   {"SOOOL",
                                    "XXXXO",
                                    "OOOOO",
                                    "OXXXX",
                                    "OOOOE"},

                                   {"LOOXS",
                                    "OOOOX",
                                    "OOOOO",
                                    "OOOOO",
                                    "EOOOO"} };

    vector<int> an = { 16,-1 };

    for (int i = 0; i < an.size(); i++)
    {
        int da = solution(m[i]);

        if (da == an[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

}


/*
1 x 1 ũ���� ĭ��� �̷���� ���簢�� ���� ������ �̷ο��� Ż���Ϸ��� �մϴ�. 
�� ĭ�� ��� �Ǵ� ������ �����Ǿ� ������, 
������ �� ĭ�� ������ �� ���� ��η� �� ĭ���θ� �̵��� �� �ֽ��ϴ�. 
��ε� �� �� ĭ���� �̷θ� ���������� ���� �ִµ�, �� ���� ������ ��ܼ��� �� �� �ֽ��ϴ�. 
���� ���� ��ε� �� �� ĭ�� �ֽ��ϴ�. 
����, ��� �������� ���� ������ �ִ� ĭ���� �̵��Ͽ� ������ ��� �� �̷θ� ���������� ���� �ִ� ĭ���� �̵��ϸ� �˴ϴ�. 
�̶� ���� ������ ����� �ʾҴ��� �ⱸ�� �ִ� ĭ�� ������ �� �ֽ��ϴ�. 
�̷ο��� �� ĭ�� �̵��ϴµ� 1�ʰ� �ɸ��ٰ� �� ��, �ִ��� ������ �̷θ� ���������µ� �ɸ��� �ð��� ���Ϸ� �մϴ�.

�̷θ� ��Ÿ�� ���ڿ� �迭 maps�� �Ű������� �־��� ��, �̷θ� Ż���ϴµ� �ʿ��� �ּ� �ð��� return �ϴ� solution �Լ��� �ϼ����ּ���. ����, Ż���� �� ���ٸ� -1�� return ���ּ���.

���ѻ���
5 �� maps�� ���� �� 100
5 �� maps{i}�� ���� �� 100
maps{i}�� ���� 5���� ���ڵ�θ� �̷���� �ֽ��ϴ�.
S : ���� ����
E : �ⱸ
L : ����
O : ���
X : ��
���� ������ �ⱸ, ������ �׻� �ٸ� ���� �����ϸ� �� ������ �����մϴ�.
�ⱸ�� ������ ������� �ʾƵ� ������ �� ������, ��� ���, �ⱸ, ����, �������� ���� �� ������ �� �ֽ��ϴ�.
����� ��
maps	result
	16
	-1
����� �� ����
����� �� #1

�־��� ���ڿ��� ������ ���� �̷��̸�

image1

������ ���� �̵��ϸ� ���� ���� �ð��� Ż���� �� �ֽ��ϴ�.

image2

4�� �̵��Ͽ� ������ ���� �ⱸ���� �̵��ϸ� �� 16���� �ð��� �ɸ��ϴ�. ���� 16�� ��ȯ�մϴ�.

����� �� #2

�־��� ���ڿ��� ������ ���� �̷��Դϴ�.

image3

���� �������� �̵��� �� �ִ� ������ ��� Ż���� �� �����ϴ�. ���� -1�� ��ȯ�մϴ�.

*/