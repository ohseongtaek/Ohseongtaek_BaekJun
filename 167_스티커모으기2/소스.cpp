#include <iostream>
#include <vector>
using namespace std;

int getMaxValue(vector<int> sticker, int arrDP[], int ans, bool bFirstSelect)
{
    int stlen = 0;
    if (bFirstSelect == true)
    {
        stlen = sticker.size() - 1;
    }
    else
    {
        stlen = sticker.size();
    }
        

    for (int i = 2; i < stlen; i++)
    {
        arrDP[i] = max(arrDP[i - 2] + sticker[i], arrDP[i - 1]);
    }

    if (bFirstSelect == true)
    {
        return max(ans, arrDP[sticker.size() - 2]);
    }
    else
    {
        return max(ans, arrDP[sticker.size() - 1]);
    }
    
}


int solution(vector<int> sticker)
{
    int answer = 0;
    int arrDP[100010] = { 0, };
    bool bFirstSelect = false;

    // 33�� TC
    if (sticker.size() == 1)
    {
        return sticker[0];
    }

    // �ִ밪 ���ϱ� 
    // DP ��ȭ�� ���ϱ� DP[i] = max(DP[i - 1], DP[i - 2] + sticker[i]);
    // DP => ù��° ��ƼĿ�� ����������� ���������� ������ 

    // ù��° ��ƼĿ�� ������ ����� ��� (������ ��ƼĿ ��� ����)
    bFirstSelect = true;
    arrDP[0] = sticker[0];
    arrDP[1] = sticker[0];

    answer = getMaxValue(sticker, arrDP, answer, bFirstSelect);

    // ù��° ��ƼĿ�� ��� ���ϴ� ��� (������ ��ƼĿ ��� ����)
    bFirstSelect = false;
    arrDP[0] = 0;
    arrDP[1] = sticker[1];

    answer = getMaxValue(sticker, arrDP, answer, bFirstSelect);

    return answer;
}

int main()
{
    vector<vector<int>> v = { {14, 6, 5, 11, 3, 9, 2, 10} ,{1, 3, 2, 5, 4} };
    vector<int> dab = { 36,8 };

    for (int i = 0; i < dab.size(); i++)
    {
        int test = solution(v[i]);
        if (test == dab[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << ", [result] = " << test << ", [want] = " << dab[i] << endl;
        }
    }
    return 0;
}