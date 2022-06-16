#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
    {
        return a[0] < b[0];
    }
}

int getManyPeople(vector<vector<int>> timetable)
{
    map<int, int> mCnt;
    int nRtn = 0;

    // map data�� ��� �ð����� �ְ� �ִ��� ������ 
    for (int i = 0; i < timetable.size(); i++)
    {
        int start = timetable[i][0];
        int end = timetable[i][1];

        for (int s = start; s <= end; s++)
        {
            mCnt[s] += 1;
            nRtn = max(nRtn, mCnt[s]);
        }
    }
    return nRtn;
}

int solution(int n, int m, vector<vector<int>> timetable) 
{
    int answer = 0;
    int people = 0;

    // �ϴ� ������ ���� �ð����̺��� ����������� ���� 
    sort(timetable.begin(), timetable.end(), comp);
    
    people = getManyPeople(timetable);

    // ���� ũ�� ���̸� ��ġ �ϴ� ��� 
    // 1���̰ų� 2���̸� �̹� ���������� 
    if (people == 1)
    {
        answer = 0;
        return answer;
    }
    else if (people == 2)
    {
        // 2�ΰ�� ������ ���밢������ ��ġ�ϸ� �� (�� �Ÿ��� ���ϴ� ������ �Ʒ�����)
        answer = n * 2 - 2;
        return answer;
    }
    else
    {
        // n�� ���� ���ؼ� �ִ� �Ÿ��� = ���� �밢�� ��ġ�� ���� 
        for (int dist = 2 * n - 2; dist > 0; dist--)
        {
            // �簢���� ũ�⸸ŭ �ݺ��� 
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    set<pair<int, int>> sp;
                    sp.insert({ i,j });
                    int temp = 1;

                    // �Ÿ��� ���� �ٿ����� �ִ� ���� ����� 
                    for (int y = i; y < n; y++)
                    {
                        for (int x = 0; x < n; x++)
                        {
                            if (y < i || (y == i && x <= j))
                            {
                                continue;
                            }

                            set<pair<int, int>>::iterator iter;

                            for (iter = sp.begin(); iter != sp.end(); iter++)
                            {
                                int d = abs(y - (*iter).first) + abs(x - (*iter).second);
                                // �ִ� �Ÿ����� ���� �Ÿ��� �۴ٸ� ������ 
                                if (d < dist)
                                {
                                    break;
                                }
                            }

                            if (iter == sp.end())
                            {
                                sp.insert({ y,x });
                                temp++;
                            }

                            if (temp == people)
                            {
                                answer = dist;
                                return answer;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    vector<int> n = { 3,2,2,4 };
    vector<int> m = { 2,1,2,5 };
    vector<vector<vector<int>>> tb = { {{1170, 1210}, {1200, 1260}} ,
                                       {{840, 900}},
                                       {{600, 630}, {630, 700}},
                                       {{1140, 1200}, {1150, 1200}, {1100, 1200}, {1210, 1300}, {1220, 1280}} };

    vector<int> dab = { 4,0,2,4 };

    for (int i = 0; i < dab.size(); i++)
    {
        int answer = solution(n[i], m[i], tb[i]);

        if (answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << " , want = " << dab[i] << endl;
        }
    }
    return 0;
}
