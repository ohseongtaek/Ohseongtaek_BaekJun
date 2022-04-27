#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// �ִ� �ð� 99�ð� 59�� 59�� => �ʷ� ��ȯ 359999
#define TIME_MAX 360000

typedef long long ll;

int strTimeConvert(string strTime)
{
    int hour = stoi(strTime.substr(0, 2)) * 3600;
    int min = stoi(strTime.substr(3, 2)) * 60;
    int sec = stoi(strTime.substr(6, 2));

    return hour + min + sec;
}

string nTimeConvert(int ntime)
{
    string strRtn = "";
    
    ntime = ntime - 1;

    int hour = ntime / 3600;
    int min = (ntime % 3600) / 60;
    int sec = (ntime % 3600) % 60;

    if (hour <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(hour);
    strRtn += ":";

    if (min <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(min);
    strRtn += ":";
    
    if (sec <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(sec);
    
    return strRtn;
}

string solution(string play_time, string adv_time, vector<string> logs) 
{
    string answer = "";
    
    // ��ü �� �ð��� 0���� �ʱ�ȭ 
    vector<int> ALL_Play_Time(TIME_MAX, 0);

    // Convert
    int nPtime = strTimeConvert(play_time);
    int nADtime = strTimeConvert(adv_time);

    // ������ ���� ����ð��� ��ü �ð� ���� ����ð������� +1(���� ��� �ð�)�� �� �����̴�.
    int Last_ad_time = nPtime - nADtime + 1;

    // ���� �ð� 
    int Good_time = 1;

    // ���� ��� �ð��� �ִ��� ���ϱ� ���� ���� 
    ll AD_play_time = 0;
    ll MAX_play_time = 0;

    // �÷��� Ÿ�ӿ� ���� �� 
    // ���� : ������ ����ð� = ����� ����� �ð� - ����� ���۵� �ð�(���� ���, 00�� 00�� 01�ʺ��� 00�� 00�� 10�ʱ��� �������� ����Ǿ��ٸ�, ������ ����ð��� 9�� �Դϴ�.)
    for (int i = 0; i < logs.size(); i++)
    {
        int start_time = strTimeConvert(logs[i].substr(0, 8));
        int end_time = strTimeConvert(logs[i].substr(9, 8));

        // �� ������ �ϳ��� �÷��ش� !
        for (int j = start_time + 1; j <= end_time; j++)
        {
            ALL_Play_Time[j]++;
        }
    }

    // ���� ó�� ����Ҽ��ִ� 1�ʿ� ����� �ϰ� ������ ����ð��� �ϳ��� ����
    // ���� ��� �ð� �� �ִ��� ������ 
    for (int i = 1; i <= nADtime; i++)
    {
        AD_play_time += ALL_Play_Time[i];
        MAX_play_time += ALL_Play_Time[i];
    }

    // ������ ������ 1�ʿ� ������ ��������ð��� �ִ��� �Ʒ� �ݺ������� ����
    for (int i = 2; i <= Last_ad_time; i++)
    {
        // 2�ʺ��� �ð��� ������ �ð��� 1�ʸ� ���� ���Ŀ� 1�ʽð��븦 ���ִ°Ͱ� ������
        AD_play_time += ll(ALL_Play_Time[i + nADtime - 1] - (ALL_Play_Time[i - 1]));
        if (AD_play_time > MAX_play_time)
        {
            MAX_play_time = AD_play_time;
            // ���� ���� ��� ���� �ð��� ���� 
            Good_time = i;
        }
    }

    answer = nTimeConvert(Good_time);

    return answer;
}

int main()
{
    vector<string> p = { "02:03:55","99:59:59","50:00:00" };
    vector<string> a = { "00:14:15","25:00:00","50:00:00" };
    vector<vector<string>> v = { {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"} ,
                                 {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"},
                                 {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"} };

    vector<string> answer = { "01:30:59","01:00:00","00:00:00" };

    for (int i = 0; i < p.size(); i++)
    {
        string result = solution(p[i], a[i], v[i]);
        if (result == answer[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
            cout << result << " " << answer[i] << endl;
        }
    }

    return 0;
}                       