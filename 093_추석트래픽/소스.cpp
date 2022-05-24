#include <string>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#define endl '\n'
using namespace std;


//�ð� ���ڿ��� ��� ms ������ ���� function
int time_To_MS(string time) {

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    int ms = stoi(time.substr(9, 3));

    minute += hour * 60;
    second += minute * 60;
    ms += second * 1000;

    return ms;
}


int doing_To_MS(string doing) {
    //�Է������� 0.2s �̷����� ���� s���������
    doing.erase(doing.end() - 1);

    //float to ms control
    float end_ms_temp = stof(doing);
    int end_ms = end_ms_temp * 1000;
    return end_ms;
}


int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < lines.size(); i++) {
        //������ �������� ���ڿ� �и�
        //time �� doing ������ ����ϸ� ��
        stringstream ss(lines[i]);
        string trash_date, time, doing;
        ss >> trash_date >> time >> doing;

        int end_time = time_To_MS(time);

        //ó���� ���� �����ϹǷ� +1 ���ֱ�
        int start_time = end_time - doing_To_MS(doing) + 1;

        start.push_back(start_time);
        end.push_back(end_time);
    }

    // debug code
    for (int i = 0; i < start.size(); i++) {
        cout << start[i] << endl;
        cout << end[i] << endl;
        cout << "================" << endl;
    }

    //�ִ� count �� ������ ����
    int max_temp_count = 0;

    //������ �ð��� �������� 1�ʰ� ó���Ǵ� ���� count �ϴ� for��
    for (int i = 0; i < end.size(); i++) {
        int count = 1;
        //������ �ð��� �������� 1�ʱ� ������ +1000 �ϱ�
        int end_time_cal = end[i] + 1000;
        for (int j = i + 1; j < start.size(); j++) {
            if (start[j] < end_time_cal) {
                count++;
            }
        }
        max_temp_count = max(count, max_temp_count);
    }

    answer = max_temp_count;

    return answer;
}

int main() {
    vector<string> v = { "2016-09-15 20:59:57.421 0.351s",
                       "2016-09-15 20:59:58.233 1.181s",
                       "2016-09-15 20:59:58.299 0.8s",
                       "2016-09-15 20:59:58.688 1.041s",
                       "2016-09-15 20:59:59.591 1.412s",
                       "2016-09-15 21:00:00.464 1.466s",
                       "2016-09-15 21:00:00.741 1.581s",
                       "2016-09-15 21:00:00.748 2.31s",
                       "2016-09-15 21:00:00.966 0.381s",
                       "2016-09-15 21:00:02.066 2.62s" };
    cout << "solution ? " << solution(v) << endl;
    cout << endl;
}