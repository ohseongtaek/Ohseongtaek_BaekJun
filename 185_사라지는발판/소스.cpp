#include <string>
#include <iostream>
#include <vector>

using namespace std;

int visit[5][5];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int MinMaxAlgorithm(int posAx, int posAy, int posBx, int posBy, vector<vector<int>> &board, int N, int M)
{
    int nRtn = 0;

    // �湮�Ѱ�� => ĭ�� ���°�츦 �ǹ��� 
    if (visit[posAx][posAy] == true)
    {
        return 0;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int next_x = posAx + dx[dir];
        int next_y = posAy + dy[dir];

        // ������ ����� ��� , �̹� �湮�� ���, ���忡�� ó������ 0���� ���ǵ� ��� 
        if ((next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) || visit[next_x][next_y] || board[next_x][next_y] == false)
        {
            continue;
        }

        // ������ �湮�� ���� 1�� �����ν� ĭ�� ������� ������ 
        visit[posAx][posAy] = 1;

        // ��͸� ���� A�� ��ġ �̵��� ���� B�� ��ġ�� �̵��ϰ� �� A�� ��ġ�� �̵��ϴ� ��Ͱ� ������ 
        // ���� ¦�� => �÷��̾� �й� 
        // ���� Ȧ�� => �÷��̾� �¸� 
        int posValue = MinMaxAlgorithm(posBx, posBy, next_x, next_y, board, N, M) + 1;

        // �ش� �������� ���Ϳ� ���� �ٽ� 0���� �������� 
        visit[posAx][posAy] = 0;

        // �й� -> �¸��� �� ��� 
        if (nRtn % 2 == 0 && posValue % 2 == 1)
        {
            nRtn = posValue;
        }
        // �й� -> ��� �й� => �ִ� ���� 
        else if (nRtn % 2 == 0 && posValue % 2 == 0)
        {
            nRtn = max(nRtn, posValue);
        }
        // �¸� -> ��� �¸� => �ּڰ� ���� 
        else if (nRtn % 2 == 1 && posValue % 2 == 1)
        {
            nRtn = min(nRtn, posValue);
        }
    }
    return nRtn;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    int answer = -1;

    // Ư�� ������ �˰����� �ִ��� �˾�����, ã�� ������
    // Min Max tree Algorithm => https://blog.naver.com/zzabbo/70076811364

    int N = board.size();
    int M = board[0].size();

    answer = MinMaxAlgorithm(aloc[0], aloc[1], bloc[0], bloc[1], board, N, M);

    return answer;
}

int main()
{
    vector<vector<vector<int>>> bd = { {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
                                       {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
                                       {{1, 1, 1, 1, 1}},
                                       {{1}} };
    vector<vector<int>> a = { {1, 0},
                              {1, 0}, 
                              {0, 0}, 
                              {0, 0} };

    vector<vector<int>> b = { {1, 2},
                              {1, 2},
                              {0, 4},
                              {0, 0} };
    vector<int> dab = { 5,4,4,0 };

    for (int i = 0; i < dab.size(); i++)
    {
        int answer = solution(bd[i], a[i], b[i]);
        if (dab[i] == answer)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << ", want = " << dab[i] << endl;
        }
    }
}
