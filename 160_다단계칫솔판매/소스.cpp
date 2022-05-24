#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

// Input 
// vector<string> enroll    => �Ǹſ� �̸� 
// vector<string> referral  => �� �Ǹſ��� �ٴܰ� ������ ������Ų �ٸ� �Ǹſ��� �̸��� ���� �迭 (���� ����)
// vector<string> seller    => �Ǹŷ� ���� �������� �Ǹſ� �̸��� ������ �迭
// vector<int> amount       => �Ǹŷ� ���� �������� �Ǹ� ������ ������ �迭 amount

// Output
// �Ǹſ����� ��е� ���ͱ��� ������ ����Ͽ�(����������), �Է����� �־��� enroll�� �̸��� ���Ե� ������ ���� �����ϸ� �˴ϴ�.

// Rule 
// �Ǹſ��� �Ǹ��� ������ 10%�� �ʴ��� ������� ���� => ��ͷ� ��� ��������� ��
// ��, ������ 1% �̸��� ��쿡�� ��� ���� 
// ex) 3�ܰ谡 �ִٰ� �Ҷ� A->B->C
// C �Ǹű� 20�� 
// C ���ͷ� 18�� , B ���ͷ� 2��
// B �� 10%�� A���� ��������� ������ 1�� �̸��̶� ��� �ڱⰡ ���� 

// Exception 
// [1] 1 <= enroll.size() <= 10,000 (�ֻ��� ��ȣ�� �̸��� ������ ���ԵǾ� ���� ����)
// [2] referral.size() == enroll.size() (�ֻ��� �� ��ȣ�� ��õ�� ����� ��� "-" �� ǥ�õǰ� enroll �� ����� referral �� ����� ���Խ�Ų����)
// [3] enroll �� ������ ������ ������ ������ 
// [4] 1 <= seller.size() <= 100,000
// [5] seller ���� �ߺ��� �̸��� �� �� ���� !
// [6] amount.size() == seller.size() 
// [7] ĩ�� 1���� ������ 100�� 
// [8] �������� �̸� 10���� �̳� ���ĺ� �ҹ��ڷ� ���� 


#define PEN_MONEY 100

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> m_str_int;

    // ��ȣ�� �� �ʱ�ȭ 
    m_str_int["-"] = 0;
    // �ٸ� ������� �� �ʱ�ȭ 
    for (int i = 0; i < enroll.size(); i++)
    {
        m_str_int[enroll[i]] = 0;
    }
    
    // �Ǹ��� ������� ��ϸ�ŭ for��
    for (int i = 0; i < seller.size(); i++)
    {
        string current_man = seller[i];
        int money = amount[i] * PEN_MONEY;
        int up_money = money / 10;

        // �Ǹ��ڴ� ���ͱ��� 10���θ� �����ϰ� ��� ������ 
        m_str_int[current_man] += money - up_money;

        // ������ 10% ���ͱ��� �������� 10�� �̸� Ȥ�� �� ���� ��ȣ�� ��쿡�� ã�� 
		bool find_minho = false;
        bool not_money = false;
		while (1)
		{
            for (int j = 0; j < enroll.size(); j++)
            {
                // ���� �Ǹ��ڿ� ���� ��� referral �� ��õ�� ���� referral ���� ���ͱ��� �� 
                if (current_man == enroll[j])
                {
                    string next_man = referral[j];
                    int next_money = up_money / 10;
                    if (next_money == 0)
                    {
                        m_str_int[next_man] += up_money;
                        not_money = true;
                    }
                    else
                    {
                        m_str_int[next_man] += up_money - (up_money / 10);
                    }

                    up_money = next_money;
                    current_man = next_man;
                    if (next_man == "-")
                    {
                        find_minho = true;
                        break;
                    }
                }
            }

            if (not_money == true || find_minho == true)
            {
                break;
            }
		}
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(m_str_int[enroll[i]]);
    }

    return answer;
}


int main()
{
    vector<vector<string>> en =  { {"john", "mary", "edward", "sam",    "emily", "jaimie", "tod",    "young"} ,  {"john", "mary", "edward", "sam",    "emily", "jaimie", "tod",    "young"} };
    vector<vector<string>> ref = { {"-",    "-",    "mary",   "edward", "mary",  "mary",   "jaimie", "edward"} , {"-",    "-",    "mary",   "edward", "mary",  "mary",   "jaimie", "edward"} };

    vector<vector<string>> sel = { {"young", "john", "tod", "emily", "mary"} , {"sam", "emily", "jaimie", "edward"} };
    vector<vector<int>> am =     { {    12,      4,     2,       5,     10} ,  {   2,       3,        5,        4} };

    vector<vector<int>> dab = { {360, 958, 108, 0, 450, 18, 180, 1080} , {0, 110, 378, 180, 270, 450, 0, 0} };
   
    for (int i = 0; i < en.size(); i++)
    {
        vector<int> answer = solution(en[i], ref[i], sel[i], am[i]);
        
        bool flag = true;

        if (answer.size() != dab[i].size())
        {
            cout << " Error = size is Diff " << endl;
            cout << "answer size = " << answer.size() << ", dab size = " << dab[i].size() << endl;
            cout << " answer array = ";
            for (int j = 0; j < answer.size(); j++)
            {
                cout << answer[j] << " ";
            }
            cout << endl;

            cout << " dab[i] array = ";
            for (int j = 0; j < dab[i].size(); j++)
            {
                cout << dab[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < answer.size(); j++)
            {
                if (dab[i][j] != answer[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                cout << "[" << i << "]" << " is good " << endl;
            }
            else
            {
                cout << " not compare " << endl;
                for (int j = 0; j < answer.size(); j++)
                {
                    cout << "answer = " << answer[j] << ", dab = " << dab[i][j] << endl;
                }
            }
        }
    }
}

