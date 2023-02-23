#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;

    map<char, int> cim;
    vector<int> v;

    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int baseline = (year * 12 * 28) + (month - 1) * 28 + day;

    for (int i = 0; i < terms.size(); i++)
    {
        stringstream ss(terms[i]);
        char lank;
        int t_month;

        ss >> lank >> t_month;

        cim[lank] = t_month;
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        int ty = stoi(privacies[i].substr(0, 4));
        int tm = stoi(privacies[i].substr(5, 2));
        int td = stoi(privacies[i].substr(8, 2));

        char a = privacies[i].back();

        int temp = (ty * 12 * 28) + (tm - 1) * 28 + td + (cim[a] * 28 - 1);

        v.push_back(temp);
    }


    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < baseline)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;

    /*
    today.erase(4,1);
    today.erase(6,1);

    vector<pair<long long, string>> vpterm;

    long long lltoday = stoll(today);

    for (int i = 0; i < terms.size(); i++)
    {
        string temp = terms[i];
        string lank = temp.substr(0, 1);
        long long month = stoll(temp.substr(2, temp.size() - 2));
        month = month * 100;

        vpterm.push_back(make_pair(month, lank));
    }


    for (int i = 0; i < privacies.size(); i++)
    {
        string lank = privacies[i].substr(privacies[i].size() - 1);
        privacies[i].erase(10);
        privacies[i].erase(4, 1);
        privacies[i].erase(6, 1);

        // ���ڸ� ����ϰ� �Ѱ��� �ٿ��� �׸��� 0�ΰ�� month���� �� �� month �� 0�̸� year ���� �Ѱ� ���� 
        long long dayLimit = stoll(privacies[i].substr(privacies[i].size() - 2));
        long long month = stoll(privacies[i].substr(privacies[i].size() - 4, 2));
        long long year = stoll(privacies[i].substr(privacies[i].size() - 8, 4));
        
        dayLimit--;
        
        if (dayLimit <= 0)
        {
            month--;
            if (month <= 0 || month >= 13)
            {
                year--;
                month = 12;
            }

            dayLimit = 28;
        }

        char mon[3] = { 0, };
        char day[3] = { 0, };

        sprintf(mon, "%02d", (int)month);
        sprintf(day, "%02d", (int)dayLimit);

        string result = to_string(year) + mon + day;

        long long one = 0;
        for (int j = 0; j < vpterm.size(); j++)
        {
            if (lank == vpterm[j].second)
            {
                one = stoll(result);
                one += vpterm[j].first;
                break;
            }
        }

        // �� ����ó�� 
        string one2 = to_string(one);
        long long month2 = stoll(one2.substr(one2.size() - 4, 2));
        long long year2 = stoll(one2.substr(one2.size() - 8, 4));
        long long dayLimit2 = stoll(one2.substr(one2.size() - 2));

        while (month2 > 12)
        {
            year2++;
            month2 -= 12;
        }

        char mon2[3] = { 0, };
        char day2[3] = { 0, };

        sprintf(mon2, "%02d", (int)month2);
        sprintf(day2, "%02d", (int)dayLimit2);

        string result2 = to_string(year2) + mon2 + day2;

        if (stoll(result2) < stoll(today))
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
    */
}

int main()
{

    vector<string> today = { "2022.05.19", "2020.01.01", "2024.06.08", "2022.02.28" };
    vector<vector<string>> terms = { {"A 6", "B 12", "C 3"}, {"Z 3", "D 5"}, {"A 18"}, {"A 23"} };
    vector<vector<string>> privacies = { {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"} ,
                                         {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"},
                                         {"2022.06.08 A"},
                                         {"2020.01.28 A"} };


    vector<vector<int>> answer = { {1, 3} , {1, 4, 5}, {1}, {1} };

    for (int i = 0; i < today.size(); i++)
    {
        vector<int> dab = solution(today[i], terms[i], privacies[i]);

        bool flag = false;
        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != answer[i][j])
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
}


/*
���� ��� ���Ǹ� �� ������ 1~n������ �з��Ǵ� �������� n���� �ֽ��ϴ�. 
��� ������ ���� ���� ������ �� ������� �������� ���� ��ȿ�Ⱓ�� ������ �ֽ��ϴ�. 
����� �� ���������� � ������� �����ƴ��� �˰� �ֽ��ϴ�. 
������ ���������� ��ȿ�Ⱓ �������� ���� �����ϸ�, ��ȿ�Ⱓ�� �����ٸ� �ݵ�� �ı��ؾ� �մϴ�.

���� ���, 
A��� ����� ��ȿ�Ⱓ�� 12 ���̰�, 2021�� 1�� 5�Ͽ� ������ ���������� A������� �����Ǿ��ٸ� �ش� ���������� 2022�� 1�� 4�ϱ��� ���� �����ϸ� 2022�� 1�� 5�Ϻ��� �ı��ؾ� �� ���������Դϴ�.

����� ���� ��¥�� �ı��ؾ� �� �������� ��ȣ���� ���Ϸ� �մϴ�.

��� ���� 28�ϱ��� �ִٰ� �����մϴ�.

������ ���� ��¥�� 2022.05.19�� ���� �����Դϴ�.

��� ����	��ȿ�Ⱓ
A	6 ��
B	12 ��
C	3 ��
��ȣ	�������� ���� ����	��� ����
1	2021.05.02	A
2	2021.07.01	B
3	2022.02.19	C
4	2022.02.20	C
ù ��° ���������� A����� ���� 2021�� 11�� 1�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� �������Ƿ� �ı��ؾ� �� ���������Դϴ�.
�� ��° ���������� B����� ���� 2022�� 6�� 28�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� ������ �ʾ����Ƿ� ���� ���� �����մϴ�.
�� ��° ���������� C����� ���� 2022�� 5�� 18�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� �������Ƿ� �ı��ؾ� �� ���������Դϴ�.
�� ��° ���������� C����� ���� 2022�� 5�� 19�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� ������ �ʾ����Ƿ� ���� ���� �����մϴ�.
���� �ı��ؾ� �� �������� ��ȣ�� {1, 3}�Դϴ�.

���� ��¥�� �ǹ��ϴ� ���ڿ� today, ����� ��ȿ�Ⱓ�� ���� 1���� ���ڿ� �迭 terms�� ������ ���������� ������ ���� 1���� ���ڿ� �迭 privacies�� �Ű������� �־����ϴ�. �̶� �ı��ؾ� �� ���������� ��ȣ�� ������������ 1���� ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
today�� "YYYY.MM.DD" ���·� ���� ��¥�� ��Ÿ���ϴ�.
1 �� terms�� ���� �� 20
terms�� ���Ҵ� "��� ���� ��ȿ�Ⱓ" ������ ��� ������ ��ȿ�Ⱓ�� ���� �ϳ��� ������ ���ڿ��Դϴ�.
��� ������ A~Z�� ���ĺ� �빮�� �ϳ��̸�, terms �迭���� ��� ������ �ߺ����� �ʽ��ϴ�.
��ȿ�Ⱓ�� ���������� ������ �� �ִ� �� ���� ��Ÿ���� �����̸�, 1 �̻� 100 �����Դϴ�.
1 �� privacies�� ���� �� 100
privacies{i}�� i+1�� ���������� ���� ���ڿ� ��� ������ ��Ÿ���ϴ�.
privacies�� ���Ҵ� "��¥ ��� ����" ������ ��¥�� ��� ������ ���� �ϳ��� ������ ���ڿ��Դϴ�.
��¥�� "YYYY.MM.DD" ������ ���������� ������ ��¥�� ��Ÿ����, today ������ ��¥�� �־����ϴ�.
privacies�� ��� ������ �׻� terms�� ��Ÿ�� ��� ������ �־����ϴ�.
today�� privacies�� �����ϴ� ��¥�� YYYY�� ����, MM�� ��, DD�� ���� ��Ÿ���� ��(.) �ϳ��� ���еǾ� �ֽ��ϴ�.
2000 �� YYYY �� 2022
1 �� MM �� 12
MM�� �� �ڸ����� ��� �տ� 0�� �ٽ��ϴ�.
1 �� DD �� 28
DD�� �� �ڸ����� ��� �տ� 0�� �ٽ��ϴ�.
�ı��ؾ� �� ���������� �ϳ� �̻� �����ϴ� �Է¸� �־����ϴ�.
����� ��
today	terms	privacies	result
"2022.05.19"	{"A 6", "B 12", "C 3"}	{"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"}	{1, 3}
"2020.01.01"	{"Z 3", "D 5"}	{"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"}	{1, 4, 5}
����� �� ����
����� �� #1

���� ���ÿ� �����ϴ�.
����� �� #2

��� ����	��ȿ�Ⱓ
Z	3 ��
D	5 ��
��ȣ	�������� ���� ����	��� ����
1	2019.01.01	D
2	2019.11.15	Z
3	2019.08.02	D
4	2019.07.01	D
5	2018.12.28	Z
���� ��¥�� 2020�� 1�� 1���Դϴ�.

ù ��° ���������� D����� ���� 2019�� 5�� 28�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� �������Ƿ� �ı��ؾ� �� ���������Դϴ�.
�� ��° ���������� Z����� ���� 2020�� 2�� 14�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� ������ �ʾ����Ƿ� ���� ���� �����մϴ�.
�� ��° ���������� D����� ���� 2020�� 1�� 1�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� ������ �ʾ����Ƿ� ���� ���� �����մϴ�.
�� ��° ���������� D����� ���� 2019�� 11�� 28�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� �������Ƿ� �ı��ؾ� �� ���������Դϴ�.
�ټ� ��° ���������� Z����� ���� 2019�� 3�� 27�ϱ��� ���� �����ϸ�, ��ȿ�Ⱓ�� �������Ƿ� �ı��ؾ� �� ���������Դϴ�.
*/