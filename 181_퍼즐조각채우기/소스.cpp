#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �湮�� ���� ������ ���
bool visit[51][51];

//  ���� �����¿쿡 ���� �迭 
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

vector<pair<int,int>> BFS(vector<vector<int>>& gb, int blockVlaue, int i, int j)
{
    // �湮 üũ �� BFS�� (�̾����ִ� ��� ��������) (����ִ� ��� ��������)
    visit[i][j] = true;

    vector<pair<int, int>> vp;
    queue<pair<int, int>> qp;

    qp.push(make_pair(i, j));
    vp.push_back(make_pair(i, j));

    while (qp.empty() == false)
    {
        int y = qp.front().first;
        int x = qp.front().second;
        qp.pop();

        // �����¿� ��� �� üũ �ϱ� 
        for (int i = 0; i < 4; i++)
        {
            int temp_y = y + dy[i];
            int temp_x = x + dx[i];

            // BFS ���� ����� ��� 
            if (temp_y <0 || temp_x<0 || temp_x >= gb.size() || temp_y >= gb.size())
            {
                continue;
            }

            // �湮�� ���� �ְų� ��Ͽ� ���� ���� �ٸ� ��� !
            if (visit[temp_y][temp_x] || gb[temp_y][temp_x] != blockVlaue)
            {
                continue;
            }

            visit[temp_y][temp_x] = true;
            qp.push(make_pair(temp_y, temp_x));
            vp.push_back(make_pair(temp_y, temp_x));
        }
    }
    return vp;
}

vector<pair<int, int>> ConvertPosZero(vector<pair<int, int>> vp_block, int len)
{
    int j_min = len;
    int i_min = len;

    // ������ ���� ���� ��ǥ�� ã�´�.
    for (int i = 0; i < vp_block.size(); i++)
    {
        j_min = j_min > vp_block[i].second ? vp_block[i].second : j_min;
        i_min = i_min > vp_block[i].first ? vp_block[i].first : i_min;
    }

    // ���� ���� ��ǥ��ŭ ��� ��ǥ���� ���ְ� 0���� ��ġ�� �����Ѵ�.
    for (int i = 0; i < vp_block.size(); i++)
    {
        vp_block[i].first -= i_min;
        vp_block[i].second -= j_min;
    }

    return vp_block;
}

// 90 �� ȸ�� !
void rotation(vector<pair<int, int>>& rTable)
{
    int row = 0;
    
    for (int i = 0; i < rTable.size(); i++)
    {
        row = row < rTable[i].first ? rTable[i].first : row;
    }

    for (int i = 0; i < rTable.size(); i++)
    {
        int y = rTable[i].first;
        int x = rTable[i].second;
        rTable[i].first = x;
        rTable[i].second = row - y;
    }
}


int Board_Table_Matching(vector<vector<pair<int, int>>> &board, vector<vector<pair<int, int>>> &table)
{
    int answer = 0;
    vector<bool> table_visit(table.size(), false);

    for (vector<pair<int, int>> vp : board)
    {
        for (int i = 0; i < table.size(); i++)
        {
            //�̹� ����� �Ϸ��� �����ΰ�� ���� 
            if (table_visit[i] == true)
            {
                continue;
            }

            vector<pair<int, int>> temp_table = table[i];
            if (vp.size() != temp_table.size())
            {
                continue;
            }

            bool flag = false;

            // 4���� ȸ���� ���� for�� 
            for (int R = 0; R < 4; R++)
            {
                int cnt = 0; 

                for (int j = 0; j < vp.size(); j++)
                {
                    for (int k = 0; k < temp_table.size(); k++)
                    {
                        // ���� �´� ��� ! ĭ�� ������ŭ cnt �� �����ش� 
                        if (vp[j].first == temp_table[k].first && vp[j].second == temp_table[k].second)
                        {
                            cnt++;
                            continue;
                        }
                    }
                }

                // ���� �ʴ� ��� 
                if (cnt != vp.size())
                {
                    rotation(temp_table);
                    continue;
                }

                // ĭ�� �� �´� ��� !
                answer += vp.size();
                table_visit[i] = true;
                flag = true;
                break;
            }

            if (flag == true)
            {
                break;
            }
        }
    }

    return answer;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int answer = -1;
    
    vector<vector<pair<int, int>>> board_block;
    vector<vector<pair<int, int>>> table_block;

    // ���Ӻ����� ����� ��ǥ�� ���ϰ� �ش� ��ǥ�� 0���� ������ 
    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board.size(); j++)
        {
            // ������̸� �湮�� ���� ���� ����� ��� ��� ã�ƿ��� 
            if (game_board[i][j] == 0 && visit[i][j] == 0)
            {
                vector<pair<int, int>> vp_block = BFS(game_board, 0, i, j);
                vector<pair<int, int>> vp_PosZero = ConvertPosZero(vp_block, game_board.size());
                board_block.push_back(vp_PosZero);
            }
        }
    }

    // 
    memset(visit, 0, sizeof(visit));

    // ���̺��� ��� ��ǥ�� ���ϰ� �ش� ��ǥ�� 0���� ������ 
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.size(); j++)
        {
            // ������̸� �湮�� ���� ���� ����� ��� ��� ã�ƿ��� 
            if (table[i][j] == 1 && visit[i][j] == 0)
            {
                vector<pair<int, int>> vp_block = BFS(table, 1, i, j);
                vector<pair<int, int>> vp_PosZero = ConvertPosZero(vp_block, table.size());
                table_block.push_back(vp_PosZero);
            }
        }
    }

    // ���� ��ǥ�� ��Ī 
    answer = Board_Table_Matching(board_block, table_block);

    return answer;
}

int main()
{
    vector<vector<vector<int>>> gb = { {{1, 1, 0, 0, 1, 0}, 
                                        {0, 0, 1, 0, 1, 0}, 
                                        {0, 1, 1, 0, 0, 1}, 
                                        {1, 1, 0, 1, 1, 1}, 
                                        {1, 0, 0, 0, 1, 0}, 
                                        {0, 1, 1, 1, 0, 0}} ,

                                       {{0, 0, 0}, 
                                        {1, 1, 0}, 
                                        {1, 1, 1}} };


    vector<vector<vector<int>>> tb = { {{1, 0, 0, 1, 1, 0}, 
                                        {1, 0, 1, 0, 1, 0}, 
                                        {0, 1, 1, 0, 1, 1}, 
                                        {0, 0, 1, 0, 0, 0}, 
                                        {1, 1, 0, 1, 1, 0}, 
                                        {0, 1, 0, 0, 0, 0}} ,

                                       {{1, 1, 1}, 
                                        {1, 0, 0}, 
                                        {0, 0, 0}} };
    vector<int> dab = { 14,0 };

    // �� �� ĭ�� ä�� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
    for (int i = 0; i < gb.size(); i++)
    {
        int ans = solution(gb[i], tb[i]);

        if (ans == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << ans << " want = " << dab[i] << endl;
        }
    }
}