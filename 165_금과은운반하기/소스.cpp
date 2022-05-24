#include <string>
#include <iostream>
#include <vector>

using namespace std;

// �̺�Ž�� 
// �ð��� �ְ� �߰� ������ �������� ���������� Ȯ�� 

typedef long long ll;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
    ll llstart = 0;

    // �־��� �ð� = 10��9�¸�ŭ �� ���� �ʿ��ϰ�, �ű���ִ°� 1���̸� �� 1�������̴� �ð��� 10�� 5���� ��� (������ 10e5 �� ��) 
    ll llend = (10e5 * 2) * ((2 * 10e9) / 1) + 10e5;
    ll answer = llend;

    int icitysize = g.size();

    while (llstart <= llend)
    {
        // �߰��� ��� 
        ll llmidValue = (llstart + llend) / 2;

        ll lltotalgold = 0;
        ll lltotalsil = 0;
        ll lltotalGS = 0;

        for (int i = 0; i < icitysize; i++)
        {
            ll llgetMaxweight = 0;
            ll llroundtrip_cnt = 0;
            
            // �պ� �ð� ���
            if (llmidValue % ((ll)t[i] * 2) >= t[i])
            {
                llgetMaxweight = (llmidValue / ((ll)t[i] * 2) + 1) * w[i];
            }
            else
            {
                llgetMaxweight = (llmidValue / ((ll)t[i] * 2)) * w[i];
            }


            // �� ���
            if ((ll)g[i] <= llgetMaxweight)
            {
                lltotalgold += (ll)g[i];
            }
            else
            {
                lltotalgold += llgetMaxweight;
            }

            // �� ���
            if ((ll)s[i] <= llgetMaxweight)
            {
                lltotalsil += (ll)s[i];
            }
            else
            {
                lltotalsil += llgetMaxweight;
            }

            // ��+�� ��� 
            if (((ll)g[i]+ (ll)s[i]) <= llgetMaxweight)
            {
                lltotalGS += (ll)g[i] + (ll)s[i];
            }
            else
            {
                lltotalGS += llgetMaxweight;
            }

        }

        // ��� ������ �ð��̸� �ּڰ� �ֱ� 
        if ((lltotalgold >= a) && (lltotalsil >= b) && (lltotalGS >= (a + b)))
        {
            llend = llmidValue - 1;
            answer = min(llmidValue, answer);
        }
        else
        {
            llstart = llmidValue + 1;
        }
    }
    return answer;
}


int main()
{
    vector<int> a = { 10,90 };
    vector<int> b = { 10,500 };

    vector<vector<int>> g = { {100},{70,70,0} };
    vector<vector<int>> s = { {100},{0,0,500} };
    vector<vector<int>> w = { {7},{100,100,2} };
    vector<vector<int>> t = { {10},{4,8,1} };

    vector<int> r = { 50,499 };

    for (int i = 0; i < g.size(); i++)
    {
        long long time = solution(a[i], b[i], g[i], s[i], w[i], t[i]);
        
        if (r[i] == time)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << time << ", [want]" << r[i] << endl;
        }
        cout << endl;
    }

    return 0;
}


/*
int a => ���µ� �ʿ��� �� kg 
int b => ���µ� �ʿ��� �� kg
vector<int> g => g[i] ������ �ݷ� 
vector<int> s => s[i] ������ ���� 
vector<int> w => w[i] �ִ� ��� ���� ���� 
vector<int> t => t[i] �� �ð� 

���ѻ���
0 �� a, b �� 109
1 �� g�� ���� = s�� ���� = w�� ���� = t�� ���� = ���� ���� �� 105
0 �� g[i], s[i] �� 109
1 �� w[i] �� 102
1 �� t[i] �� 105

���� => �Ѱ��� ���ø� ���µ� ���� ���õ��� ������ �ִ°��� (1:N ����)
    => ������ ���ø� ���°��� ������ �ִ� ���õ��� �����Ҽ��ִ� Ʈ���� ��� 1����
    => �� ���õ��� ������ �ִ� �����鵵 �������� 
    => ���� �Ʒ� ���ѻ����� ���� 
        a �� g�� ��� ���� ��
        b �� s�� ��� ���� ��

���� => �� �� �� �� ���� �ʰ� ��ݵǴ°��� �������� �պ�+1������ �����ϸ� �ɵ�..?


*/
