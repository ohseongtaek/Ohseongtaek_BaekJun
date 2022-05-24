#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> vecGrid;
bool visit[510][510][4];
int nRow, nColumn;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Change_Dir(char C, int Dir)
{
    if (C == 'L')
    {
        if (Dir == 0) return 3;
        if (Dir == 1) return 2;
        if (Dir == 2) return 0;
        if (Dir == 3) return 1;
    }
    else if (C == 'R')
    {
        if (Dir == 0) return 2;
        if (Dir == 1) return 3;
        if (Dir == 2) return 1;
        if (Dir == 3) return 0;
    }
}


int ShootLight(int x, int y, int d, int len)
{
    // �湮�� ��ǥ�� ������ ���� �������� ���� ���� ��쿡�� ������ ������ Ȥ�� ���� ������ �� �� ���� ���
    if (visit[x][y][d] == true)
    {
        return len;
    }

    visit[x][y][d] = true;

    int nextX = x;
    int nextY = y;
    int nextD = d;
    pair<int, int> pairChangedDir;
    if (vecGrid[x][y] != 'S')
    {
        nextD = Change_Dir(vecGrid[x][y], d);
        nextX = x + dx[nextD];
        nextY = y + dy[nextD];
    }
    else
    {
        nextX = x + dx[nextD];
        nextY = y + dy[nextD];
    }
    
    if (nextX < 0)
    {
        nextX = nRow - 1;
    }
    if (nextY < 0)
    {
        nextY = nColumn - 1;
    }
    if (nextX == nRow)
    {
        nextX = 0;
    }
    if (nextY == nColumn)
    {
        nextY = 0;
    }

    return ShootLight(nextX,nextY,nextD,len+1);

}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    // ��� ���� ���� �� �߰� �� �迭 �ʱ�ȭ 
    nRow    = grid.size();
    nColumn = grid[0].size();
    vecGrid = grid;

    // ��� ��忡�� 4�������� ���� �߻��ϴ� 3�� for�� 
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            // 0 : �Ʒ����� �� 
            // 1 : ������ �Ʒ� 
            // 2 : �����ʿ��� ����
            // 3 : ���ʿ��� ������ 
            for (int dir = 0; dir < 4; dir++)
            {
                //���� i,j ��忡 �ִ� ���� dir �������� �߻� 
                int nRtn = ShootLight(i, j, dir, 0);

                // nRtn �� 0�� �ƴ� ��쿡 ����Ŭ ���� �ֱ� 
                if (nRtn != 0)
                {
                    answer.push_back(nRtn);
                }
            }
        }
    }

    // �������� ���� 
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> t = { "SL","LR" };
    
    vector<int> test = solution(t);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << endl;
    }
    return 0;
}