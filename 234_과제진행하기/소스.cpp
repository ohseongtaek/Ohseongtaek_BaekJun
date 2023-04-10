#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool comp(vector<string> a, vector<string> b)
{
    int hour = 0;
    int min = 0;

    hour = stoi(a[1].substr(0, 2)) * 60;
    min = stoi(a[1].substr(3, 2));

    int aValue = hour + min;
   
    hour = stoi(b[1].substr(0, 2)) * 60;
    min = stoi(b[1].substr(3, 2));

    int bValue = hour + min;

    if (aValue == bValue)
    {
        int aWork = stoi(a[2]);
        int bWork = stoi(b[2]);
     
        return aWork < bWork;
    }
    else 
    {
        return aValue < bValue;
    }
}

int getTime(string t)
{
    int h = stoi(t.substr(0, 2)) * 60;
    int m = stoi(t.substr(3, 2));

    return h + m;
}

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;
    stack<int> s;
    sort(plans.begin(), plans.end(), comp);

    int idx = 0;
    while (true)
    {
        int cTime = getTime(plans[idx][1]) + stoi(plans[idx][2]);

        // ���� ������ ������ ������ ��� ������ Ŭ����Ƿ� �̷����� 
        if (idx + 1 == plans.size())
        {
            answer.push_back(plans[idx][0]);
            break;
        }
        else
        {
            int nTime = getTime(plans[idx + 1][1]);

            // ���� �ð��� �������� ���� ��� 
            if (cTime <= nTime)
            {
                answer.push_back(plans[idx][0]);
                
                //�����ð��� �ִٸ� ���� �ֱٿ� �� �۾� �ٽ� �۾��ϱ� 
                int value = nTime - cTime;
                if (value > 0)
                {
                    while (true)
                    {
                        if (s.empty() == true)
                        {
                            break;
                        }
                        int recentWorkidx = s.top();
                        s.pop();
                        int rtime = stoi(plans[recentWorkidx][2]);
                        if (rtime <= value)
                        {
                            answer.push_back(plans[recentWorkidx][0]);
                            value -= rtime;
                        }
                        else
                        {
                            plans[recentWorkidx][2] = to_string(stoi(plans[recentWorkidx][2]) - value);
                            value = 0;
                            s.push(recentWorkidx);
                        }

                        if (value <= 0)
                        {
                            break;
                        }
                    }
                }
            }
            // ���� �ð��� �������� ������ ��� 
            else
            {
                plans[idx][2] = to_string(cTime - nTime);
                s.push(idx);
            }
        }
        idx++;
    }

    int a = s.size();
    for (int i = 0; i < a; i++)
    {
        answer.push_back(plans[s.top()][0]);
        s.pop();
    }

    return answer;
}

int main()
{
    int m = 10;          
    int n = 10;
    int sx = 3;
    int sy = 7;
    vector<vector<vector<string>>> vv = {
                                        { {"korean", "11:40", "30"}, { "english", "12:10", "20" },  { "math", "12:30", "40" }},
                                        { {"science", "12:40", "50"},{ "music", "12:20", "40" },    { "history", "14:00", "30" }, { "computer", "12:30", "100" }},
                                        { {"aaa", "12:00", "20"},    { "bbb", "12:10", "30" },      { "ccc", "12:40", "10" }},
                                         {{"1", "00:00", "30"}, {"2", "00:10", "10"}, {"3", "00:30", "10"}, {"4", "00:50", "10"}} };
                                        
    vector<vector<string>> vd = { {"korean", "english", "math"},
                                  {"science", "history", "computer", "music"},
                                  {"bbb", "ccc", "aaa"},
                                  {"2","3","1","4"} };

    bool flag = false;
    for (int i = 0; i < vv.size(); i++)
    {
        vector<string> dab = solution(vv[i]);
        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != vd[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }

   
}
/*
������ ���� ��� ������ ���� ������� ������ �Ϸ��� ��ȹ�� �������ϴ�.

������ �����ϱ�� �� �ð��� �Ǹ� �����մϴ�.
���ο� ������ ������ �ð��� �Ǿ��� ��, ������ ���� ���̴� ������ �ִٸ� ���� ���̴� ������ ���߰� ���ο� ������ �����մϴ�.
�������̴� ������ ������ ��, ��� ���� ������ �ִٸ�, ����� ������ �̾ �����մϴ�.
����, ������ ���� �ð��� ���� �����ؾ� �Ǵ� ������ ��� ����� ������ ��� �ִٸ�, ���� �����ؾ� �ϴ� �������� �����մϴ�.
����� ������ ���� ���� ���, ���� �ֱٿ� ���� �������� �����մϴ�.
���� ��ȹ�� ���� ������ ���ڿ� �迭 plans�� �Ű������� �־��� ��, ������ ���� ������� �̸��� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���.


���ѻ���
3 �� plans�� ���� �� 1,000
plans�� ���Ҵ� {name, start, playtime}�� ������ �̷���� �ֽ��ϴ�.
name : ������ �̸��� �ǹ��մϴ�.
2 �� name�� ���� �� 10
name�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
name�� �ߺ��Ǵ� ���Ҵ� �����ϴ�.
start : ������ ���� �ð��� ��Ÿ���ϴ�.
"hh:mm"�� ���·� "00:00" ~ "23:59" ������ �ð����� �� �ֽ��ϴ�.
��� ������ ���� �ð��� �޶� ��ĥ ���� �����ϴ�.
������ "00:00" ... "23:59" ������ �����ϸ� �˴ϴ�. ��, �ÿ� ���� ���� �������� �� ���� ������ �����Դϴ�.
playtime : ������ ��ġ�µ� �ɸ��� �ð��� �ǹ��ϸ�, ������ ���Դϴ�.
1 �� playtime �� 100
playtime�� 0���� �������� �ʽ��ϴ�.
�迭�� �ð������� ���ĵǾ� ���� ���� �� �ֽ��ϴ�.
�������̴� ������ ������ �ð��� ���ο� ������ �����ؾ��ϴ� �ð��� ���� ��� �������̴� ������ ���� ������ �Ǵ��մϴ�.
����� ��
plans	result
{{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}}	{"korean", "english", "math"}
{{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}}	{"science", "history", "computer", "music"}
{{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}}	{"bbb", "ccc", "aaa"}
����� �� ����
����� �� #1

"korean", "english", "math"������ ������ �����մϴ�. "korean" ������ "11:40"�� �����Ͽ� 30�� ���� "12:10"�� ��ġ��, ��� "english" ������ �����մϴ�. 20�� ���� "12:30"�� "english" ������ ��ġ��, ��� "math" ������ �����մϴ�. 40�� ���� "01:10"�� "math" ������ ��Ĩ�ϴ�. ���� "korean", "english", "math" ������ ������ �����Ƿ� ���ʴ�� �迭�� ��� ��ȯ�մϴ�.

����� �� #2

"music", "computer", "science", "history" ������ ������ �����մϴ�.

�ð�	���� �� ����	��� ���� ����	����


 ,{ "music", "12:20", "40" },{ "computer", "12:30", "100" }},{"science", "12:40", "50"},{ "history", "14:00", "30" }, 

"12:20"	"music"	{ }	"music"�� �����մϴ�.
"12:30"	"computer"	{"music"}	"music"�� ��� ���߰�(���� �ð� 30��) "computer"�� �����մϴ�
"12:40"	"science"	{"music", "computer"}	"computer"�� ��� ���߰�(���� �ð� 90��) "science"�� �����մϴ�
"13:30"	"computer"	{"music"}	"science"�� ������ ���� �ֱٿ� ���� "computer"�� �ٽ� �����մϴ�
"14:00"	"history"	{"music", "computer"}	"computer"�� ��� ���߰�(���� �ð� 60��) "history"�� �����մϴ�
"14:30"	"computer"	{"music"}	"history"�� ������ ���� �ֱٿ� ���� "computer"�� �ٽ� �����մϴ�"
"15:30"	"music"	{ }	"computer"�� ������ ���� �ֱٿ� ���� "music"�� �ٽ� �����մϴ�"
"16:00"	-	{ }	"music"�� �����ϴ�
���� {"science", "history", "computer", "music"} ������ ������ ��Ĩ�ϴ�.

����� �� #3

���� ����
*/