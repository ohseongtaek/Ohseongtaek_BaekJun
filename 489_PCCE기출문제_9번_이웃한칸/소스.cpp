#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) 
{
    int answer = 0;

    int x[4] = { -1,0,1,0 };
    int y[4] = { 0,1,0,-1 };

    int cx = h;
    int cy = w;

    int tx = cx;
    int ty = cy;
    
    string strColor = board[h][w];

    for (int i = 0; i < 4; i++)
    {
        tx = cx + x[i];
        ty = cy + y[i];

        if (tx <= -1 || ty <= -1 || tx > (board.size() -1 ) || ty > (board.size() - 1))
        {
            continue;
        }
        else
        {
            if (strColor == board[tx][ty])
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<vector<string>>> b = { { {"blue", "red", "orange", "red"},
                                            {"red", "red", "blue", "orange"},
                                            {"blue", "orange", "red", "red"},
                                            {"orange", "orange", "red", "blue"} },

                                         { {"yellow", "green", "blue"},
                                            {"blue", "green", "yellow"},
                                            {"yellow", "blue", "blue"}} };
    vector<int> h = { 1,0 };
    vector<int> w = { 1,1 };
    vector<int> d = { 2, 1 };

    for (int i = 0; i < h.size(); i++)
    {
        int dab = solution(b[i], h[i], w[i]);
        if (dab == d[i])
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
 �� ĭ���� ���� ĥ���� 2���� ���� �������� �ֽ��ϴ�. 
 
 ���� �� ĭ�� ����� ��, ��, �Ʒ�, ����, ������ ĭ �� ���� ����� ĥ���� ĭ�� ������ ���Ϸ��� �մϴ�.

������ �� ĭ�� ĥ���� ���� �̸��� ��� ������ ���ڿ� ����Ʈ board�� 
�� ĭ�� ��ġ�� ��Ÿ���� �� ���� h, w�� 

�־��� �� board{h}{w}�� �̿��� ĭ�� �� ���� ������ ĥ���� �ִ� ĭ�� ������ return �ϵ��� solution �Լ��� �ϼ��� �ּ���.


�̿��� ĭ�� �� �� ���� ĭ�� ���� ������ ��ĥ�Ǿ� �ִ��� Ȯ���ϴ� ������ ������ �����ϴ�.

1. ������ ������ ���� n�� ����� board�� ���̸� �����մϴ�.
2. ���� ������ ��ĥ�� ĭ�� ������ ������ ���� count�� ����� 0�� �����մϴ�.
3. h�� w�� ��ȭ���� ������ ���� ����Ʈ dh, dw�� ����� ���� {0, 1, -1, 0}, {1, 0, 0, -1}�� �����մϴ�.
4. �ݺ����� �̿��� i ���� 0���� 3���� 1 �� ������Ű�� �Ʒ� �۾��� �ݺ��մϴ�.
    4-1. üũ�� ĭ�� h, w ��ǥ�� ��Ÿ���� ���� h_check, w_check�� ����� ���� h + dh{i}, w + dw{i}�� �����մϴ�.
    4-2. h_check�� 0 �̻� n �̸��̰� w_check�� 0 �̻� n �̸��̶�� ������ �����մϴ�.
        4-2-a. board{h}{w}�� board{h_check}{w_check}�� ���� �����ϴٸ� count�� ���� 1 ������ŵ�ϴ�.
5. count�� ���� return�մϴ�.
���� �ǻ��ڵ�� �۵������ �ٸ� �ڵ带 �ۼ��ص� ��������ϴ�.
���ѻ���
1 �� board�� ���� �� 7
board�� ���̿� board{n}�� ���̴� �����մϴ�.
0 �� h, w < board�� ����
1 �� board{h}{w}�� ���� �� 10
board{h}{w}�� ���� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
����� ��
board	h	w	result
{{"blue", "red", "orange", "red"}, {"red", "red", "blue", "orange"}, {"blue", "orange", "red", "red"}, {"orange", "orange", "red", "blue"}}	1	1	2
{{"yellow", "green", "blue"}, {"blue", "green", "yellow"}, {"yellow", "blue", "blue"}}	0	1	1
����� �� ����
����� �� #1

�־��� ���带 ��Ÿ���� �Ʒ� �׸��� ����, board{1}{1}�� ������ ĭ���� ȭ��ǥ�� ����Ű�� ĭ���Դϴ�. ���� board{1}{1} �ֺ��� "red" ĭ�� �� 2���Դϴ�.
9-1.jpg

����� �� #2

�־��� ���带 ��Ÿ���� �Ʒ� �׸��� ����, board{0}{1}�� ������ ĭ���� ȭ��ǥ�� ����Ű�� ĭ���Դϴ�. ���� board{0}{1} �ֺ��� "green"ĭ�� �� 1���Դϴ�.
9-2.jpg

cpp�� �����ϴ� ��� ����Ʈ�� �迭�� ������ �ǹ��̴� Ǯ�̿� �������ּ���.
ex) ��ȣ�� ��� ���� ����Ʈ numbers�� �־����ϴ�. => ��ȣ�� ��� ���� �迭 numbers�� �־����ϴ�.
java�� �����ϴ� ��� ����Ʈ�� �迭, �Լ��� �޼ҵ�� ������ �ǹ��̴� Ǯ�̿� �������ּ���.
ex) solution �Լ��� �ùٸ��� �۵��ϵ��� �� ���� ������ �ּ���. => solution �޼ҵ尡 �ùٸ��� �۵��ϵ��� �� ���� ������ �ּ���.
*/