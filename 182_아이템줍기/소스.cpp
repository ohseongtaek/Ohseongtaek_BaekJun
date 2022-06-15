#include <string>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

void SHOW_BOARD()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    memset(board, 0, sizeof(board));

    // ��ü������ * 2 (Case 1�� �� Ȯ���ϴٰ� ��ġ�°��� �߻��ؼ� ����)
    int Cx = characterX * 2;
    int Cy = characterY * 2;

    int Ix = itemX * 2;
    int Iy = itemY * 2;

    // �簢�� ��ǥ�� ��� 1�� ä��� 
    for (int i = 0; i < rectangle.size(); i++)
    {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;

        for (int x = start_x; x <= end_x; x++)
        {
            for (int y = start_y; y <= end_y; y++)
            {
                board[x][y] = 1;
            }
        }
    }

    // ���簢���� �������� �ʿ��ϱ� ������ ���δ� 0���� �ٽ� �ʱ�ȭ 
    for (int i = 0; i < rectangle.size(); i++)
    {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;

        for (int x = start_x + 1; x < end_x; x++)
        {
            for (int y = start_y + 1; y < end_y; y++)
            {
                board[x][y] = 0;
            }
        }
    }

    // ���� ��ǥ���� ��ǥ ��ǥ ���� ���°� �ּҰ� ã�� (BFS)
    queue<pair<int, int>> q; // ��ǥ�� ��Ÿ���� Queue
    q.push(make_pair(Cx, Cy));

    int dy[] = { 0,0,-1,1 };
    int dx[] = { 1,-1,0,0 };

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == Ix && y == Iy)
        {
            break;
        }

        // 4���� 
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (board[nextX][nextY] == 1)
            {
                q.push(make_pair(nextX, nextY));
                board[nextX][nextY] = board[x][y] + 1;
            }
        }
    }
    //SHOW_BOARD();
    return board[Ix][Iy] / 2;
}

int main()
{
    vector<vector<vector<int>>> r = { {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}} ,
                                      {{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}} ,
                                      {{1, 1, 5, 7}} ,
                                      {{2, 1, 7, 5}, {6, 4, 10, 10}} ,
                                      {{2, 2, 5, 5}, {1, 3, 6, 4}, {3, 1, 4, 6}} };
    vector<int> chx = { 1,9,1,3,1 };
    vector<int> chy = { 3,7,1,1,4 };
    vector<int> ix = { 7,6,4,7,6 };
    vector<int> iy = { 8,1,7,10,3 };

    vector<int> dab = { 17,11,9,15,10 };

    for (int i = 0; i < dab.size(); i++)
    {
        int ans = solution(r[i], chx[i], chy[i], ix[i], iy[i]);

        if (dab[i] == ans)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << ans << ", want = " << dab[i] << endl;
        }
    }

    return 0;
}



/*
���ѻ���
rectangle�� ����(��) ���̴� 1 �̻� 4 �����Դϴ�.
rectangle�� ���Ҵ� �� ���簢���� [���� �ϴ� x, ���� �ϴ� y, ���� ��� x, ���� ��� y] ��ǥ �����Դϴ�.
���簢���� ��Ÿ���� ��� ��ǥ���� 1 �̻� 50 ������ �ڿ����Դϴ�.
���� �ٸ� �� ���簢���� x�� ��ǥ, Ȥ�� y�� ��ǥ�� ���� ���� �����ϴ�.
������ �־��� ���ǿ� �´� ���簢���� �Է����� �־����ϴ�.
charcterX, charcterY�� 1 �̻� 50 ������ �ڿ����Դϴ�.
������ ��Ÿ���� �ٰ��� �׵θ� ���� �� ���� �־����ϴ�.
itemX, itemY�� 1 �̻� 50 ������ �ڿ����Դϴ�.
������ ��Ÿ���� �ٰ��� �׵θ� ���� �� ���� �־����ϴ�.
ĳ���Ϳ� �������� ó�� ��ġ�� ���� ���� �����ϴ�.
��ü ������ 50%�� ���簢���� 1���� ����Դϴ�.
��ü ������ 25%�� ���簢���� 2���� ����Դϴ�.
��ü ������ 25%�� ���簢���� 3�� �Ǵ� 4���� ����Դϴ�.


*/
