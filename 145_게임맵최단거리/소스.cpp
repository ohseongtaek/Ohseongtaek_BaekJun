#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// ���ѻ��� 
//n�� m�� ���� 1 �̻� 100 ������ �ڿ����Դϴ�.
//n�� m�� ���� ���� ����, �ٸ� ���� ������, n�� m�� ��� 1�� ���� �Է����� �־����� �ʽ��ϴ�.
//maps�� 0�� 1�θ� �̷���� ������, 0�� ���� �ִ� �ڸ�, 1�� ���� ���� �ڸ��� ��Ÿ���ϴ�.
//ó���� ĳ���ʹ� ���� ���� ���� �����(1, 1) ��ġ�� ������, ���� ������ ���� ���� ���� �ϴ���(n, m) ��ġ�� �ֽ��ϴ�.

int visit[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    memset(visit, 0, sizeof(visit));
    visit[0][0] = 1;

    // X Y �࿡ ���� Queue ���� 
    queue<pair<int, int>> qp;

    // ó�� ��ǥ Ǫ�� 
    qp.push(make_pair(0, 0));

    // ť�� ����������� ���� 
    while (!qp.empty())
    {
        int CurrentX = qp.front().first;
        int CurrentY = qp.front().second;
        qp.pop();

        if (CurrentX == sizeX - 1 && CurrentY == sizeY - 1)
        {
            return visit[CurrentX][CurrentY];
        }

        // �Ʒ� ������ �� ���� ���ư��鼭 �湮 ���Ѱ� Ȯ�� 
        for (int i = 0; i < 4; i++)
        {
            int nextX = CurrentX + dir[i][0];
            int nextY = CurrentY + dir[i][1];

            if (nextX >= 0 && nextX < sizeX && nextY >= 0 && nextY < sizeY)
            {
                if (maps[nextX][nextY] == 1 && visit[nextX][nextY] == 0)
                {
                    visit[nextX][nextY] = visit[CurrentX][CurrentY] + 1;
                    qp.push({ nextX,nextY });
                }
            }
        }
    }
     
   return -1;
}

int main()
{
    vector<vector<int>> v = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };
    // return 11
    vector<vector<int>> v2 = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1} };
    // return -1
 
    int dab = solution(v);
    cout << dab << endl;

    return 0;
}