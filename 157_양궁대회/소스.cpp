#include <string>
#include <iostream>
#include <vector>

#define LAST_IDX 11

using namespace std;

vector<int> answer(1, -1);  // �⺻ ���°��ų� ���°�쿡�� -1 ���� 
int diff_score_max = 0;

// �Ʒ� ������ ���ھ ������ ã�� �Լ� 
bool find_low_score(vector<int> &win) 
{
    for (int i = 10; i >= 0; i--) 
    {
        if (win[i] > answer[i])
        {
            return true;
        }
        else if (win[i] < answer[i])
        {
            return false;
        }
    }
}

// ���� ���� ��� �Լ� 
void cal_score(vector<int>& win, vector<int>& lose)
{
    int win_ryan_score = 0;
    int lose_apeach_score = 0;
    int diff_score = 0;
    // �� ���ھ� ���� ���
    for (int i = 0; i < LAST_IDX; i++)
    {
        if (win[i] > lose[i])
        {
            win_ryan_score += 10 - i;
        }
        else if (lose[i] > 0)
        {
            lose_apeach_score += 10 - i;
        }
    }
    
    // �� ���� ���� ��� 
    diff_score = win_ryan_score - lose_apeach_score;
    
    if (diff_score > 0 && diff_score >= diff_score_max)
    {
        if ((diff_score_max == diff_score) && (false == find_low_score(win)))
        {
            return;
        }
        // �ִ� ������ �����ϰ� ���� ���� 
        diff_score_max = diff_score;
        answer = win;
    }
}

// ����Ž�� 
void all_case(int index, int arrows, vector<int> &win, vector<int> &lose)
{
    // index �� �������̰ų� ȭ���� ���� ��� 
    if (index == LAST_IDX || arrows == 0)
    {
        // ���� ȭ���� �ִ� ���� ������ �ε����� �����Ѱ�쿡 0���� ��� ��������
        win[10] += arrows;
        cal_score(win, lose);
        // ���� ��� �� �ٽ� ����Լ��� ���������� ������� �ʱ�ȭ 
        win[10] -= arrows;
        return;
    }

    // ���� ȹ���ϴ� ��� 
    if (lose[index] < arrows)
    {
        int use_arrows = lose[index] + 1;
        // ����ġ ���� 1�� �� ��� ���� ȹ���� 
        win[index] += use_arrows;
        // �ε��� �ϳ� �÷��ְ� ȭ����� ������ �Ѹ�ŭ ���ֱ� 
        all_case(index + 1, arrows - use_arrows, win, lose);
        // ���� ���̽��� ������ ������� �����ֱ� 
        win[index] -= use_arrows;
    }

    // ������ ���� �ʴ� ��� Ȥ�� ���� �ε������� �������ִ� ������ ��� ȹ���� �� ���� �ε��� ������ ȹ���ϱ� ���� ��� 
    all_case(index + 1, arrows, win, lose);
}

vector<int> solution(int n, vector<int> info) 
{
    // ���� �ʱ�ȭ 0���� 11�� ������
    vector<int> win(11, 0);

    // index = 0 (0���� �ϳ��� ���̾𺸴� ���� �� ��ü ����� ������� index �ʿ�)
    // n = ȭ���
    // win = ���̾��� ���� 
    // info = ����ġ�� ���� 
    all_case(0, n, win, info);

    // ��� ���� 
    return answer;
}
int main()
{
    vector<int> a = { 5,1,9,10 };
    vector<vector<int>> aa = { {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3} };

    for (int i = 0; i < a.size(); i++)
    {
        vector<int> dab = solution(a[i], aa[i]);
        cout << " i ";
        for (int j = 0; j < dab.size(); j++)
        {
            cout << dab[j] << " ";
        }
        cout << endl;
    }

    /*[0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0]
    [-1]
    [1, 1, 2, 0, 1, 2, 2, 0, 0, 0, 0]
    [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2]*/
}
