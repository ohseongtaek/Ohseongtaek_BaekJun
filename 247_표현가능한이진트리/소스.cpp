#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool DividedAndConquer(string str)
{
    bool flag = false;

    // �� 0�ΰ�� üũ 
    for (int j = 0; j < str.size(); j++)
    {
        char szTemp = str[j];
        if (szTemp != '0')
        {
            flag = true;
            break;
        }
    }

    if (str.size() == 1 || flag == false)
    {
        return true;
    }

    int nMid = str.size() / 2;
    string strLeft = str.substr(0, nMid);
    string strRight = str.substr(nMid + 1);

    if (str[nMid] == '1' && DividedAndConquer(strLeft) && DividedAndConquer(strRight))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string changeToFullDec(string str) {
    string ret = str;
    int idx = 2;
    while (true) {
        if (str.length() <= idx - 1) break;
        idx *= 2;
    }
    for (int i = 0; i < idx - 1 - str.length(); i++) ret = "0" + ret;
    return ret;
}

vector<int> solution(vector<long long> numbers) 
{
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long& num = numbers[i];
        string strBinary = "";
        
        //2���� ��ȯ
        while (num)
        {
            strBinary = to_string(num % 2) + strBinary;
            num = num / 2;
        }
        //cout << strBinary << endl;

        //0�е��ϱ� 
        int len = strBinary.size();
        int idx = 2;
        while (true)
        {
            if (strBinary.size() <= idx - 1)
            {
                break;
            }
            idx = idx * 2;
        }
        for (int j = 0; j < idx - 1 - len; j++)
        {
            strBinary = "0" + strBinary;
        }

        //�� ���
        answer.push_back(DividedAndConquer(strBinary));
    }

    return answer;
}

int main()
{
    vector<vector<long long>> v = { {7, 42, 5}, {63, 111, 95} };
    vector<vector<int>> v2 = { {1, 1, 0} ,{1, 1, 0} };

    for (int i = 0; i < v.size(); i++)
    {
        bool flag = false;
        vector<int> dab = solution(v[i]);
        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != v2[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << " error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
} 

/*
����� ����Ʈ���� ���� ǥ���ϴ� ���� �����մϴ�.

����Ʈ���� ���� ǥ���ϴ� ����� ������ �����ϴ�.

�������� ������ �� ���ڿ��� �����մϴ�.
�־��� ����Ʈ���� ���� ��带 �߰��Ͽ� ��ȭ ����Ʈ���� ����ϴ�. ��Ʈ ���� �״�� �����մϴ�.
������� ��ȭ ����Ʈ���� ������ ���� ���� ������ ���� ������ ������, ���ʿ� �ִ� ������� ���캾�ϴ�. ����� ���̴� ���캸�� ������ ������ ��ġ�� �ʽ��ϴ�.
���캻 ��尡 ���� �����, ���ڿ� �ڿ� 0�� �߰��մϴ�. ���캻 ��尡 ���� ��尡 �ƴ϶��, ���ڿ� �ڿ� 1�� �߰��մϴ�.
���ڿ��� ����� �������� �������� ��ȯ�մϴ�.
����Ʈ������ ���� ��尡 �ƴ� ���� �ڽ��� ���� �ڽ��� ��Ʈ�� ����Ʈ���� ���麸�� �����ʿ� ������, �ڽ��� ������ �ڽ��� ��Ʈ�� ����Ʈ���� ���麸�� ���ʿ� �ִٰ� �����մϴ�.

������ ���ʿ� �ִ� ������� ���캸�� 0�� 1�� ������ ���ڿ��� �߰��ϸ� "0111010"�� �˴ϴ�. �� �������� �������� ��ȯ�ϸ� 58�Դϴ�.

����� ���� �־�������, �ϳ��� ����Ʈ���� �ش� ���� ǥ���� �� �ִ��� �˰� �ͽ��ϴ�.

����Ʈ���� ����� ���� ���� ���� 1���� ���� �迭 numbers�� �־����ϴ�. numbers�� �־��� ������� �ϳ��� ����Ʈ���� �ش� ���� ǥ���� �� �ִٸ� 1��, ǥ���� �� ���ٸ� 0�� 1���� ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� numbers�� ���� �� 10,000
1 �� numbers�� ���� �� 1015
����� ��
numbers	result
{7, 42, 5}	    {1, 1, 0}
{63, 111, 95}	{1, 1, 0}
*/