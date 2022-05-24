#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MIN 9999
using namespace std;
vector<string> temp_time;
vector<string> name;
vector<string> music;
vector<int> Real_time;


typedef struct ALL {
public:
    int index = 0;
    string tempname;
    string tempmusic;
    int temptime = 0;
}ALL;

// ������ ���� ����
void str_out(vector<string> temp) {
    for (unsigned i = 0; i < temp.size(); i++) {
        int count = 0;
        int j_second_count = 0;
        int j_first_count = 0;

        for (unsigned j = 0; j < temp[i].size(); j++) {
            j_second_count++;

            if (temp[i][j] == ',') {
                count++;
                string str = temp[i].substr(j_first_count, j_second_count - 1);
                if (count == 1 || count == 2) {
                    temp_time.push_back(str);
                }
                else if (count == 3) {
                    name.push_back(str);
                }
                j_first_count += j_second_count;
                j_second_count = 0;

                if (count == 3) {
                    string tt = temp[i].substr(j_first_count, temp[i].size());
                    music.push_back(tt);
                }
            }
        }
    }
}

// ���ڿ� ġȯ #�ִ°��� �տ��� �ҹ��ڷ�
string str_XY(string temp) {
    for (unsigned i = 0; i < temp.size(); i++) {
        //C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12���̴�.
        if (temp[i] == '#') {
            if (temp[i - 1] == 'E') {
                continue;
            }
            temp[i - 1] += 32;
            temp.erase(i, 1);
        }
        else {
            continue;
        }
    }
    return temp;
}

// time ���ڿ��� ���ڷ� ��ȯ �� �� ���̰��
void music_length(vector<string> v) {
    //time ���ڿ� ���ڷ� ��ȯ
    vector<int> temp_sum;
    for (unsigned i = 0; i < v.size(); i++) {
        string temp = "";
        int sum = 0;
        for (unsigned j = 0; j < v[i].size(); j++) {
            if (j == 2) {
                continue;
            }
            else {
                temp += v[i][j];
            }

        }
        // ������ ���� ���ϱ�
        for (unsigned k = 0; k < temp.length(); k++) {
            if (k == 0) {
                sum += (temp[k] - '0') * 36000;
            }
            else if (k == 1) {
                sum += (temp[k] - '0') * 3600;
            }
            else if (k == 2) {
                sum += (temp[k] - '0') * 600;
            }
            else if (k == 3) {
                sum += (temp[k] - '0') * 60;
            }
        }
        // ���� �ӽ� �����
        temp_sum.push_back(sum);

        // ���� 2�� �������� �ΰ��� ���� ���
        if (temp_sum.size() % 2 == 0) {
            Real_time.push_back((temp_sum[1] - temp_sum[0]) / 60);
            temp_sum.clear();
        }
    }
}

// �ð���ŭ ���ڿ� �ø��ų� ���̴� �Լ�
vector<string> str_add(vector<int> t, vector<string> m) {
    for (unsigned i = 0; i < t.size(); i++) {
        int count = t[i] - m[i].size();
        if (count > 0) {
            for (int j = 0; j < count; j++) {
                m[i] += m[i][j];
            }
        }
        else {
            if (count == 0) {
                continue;
            }
            else if (count < 0) {
                int x = m[i].size() - (count * -1);
                m[i].erase(x, (count * -1));
            }
        }
    }
    return m;
}
// a ba
string DAB(string n, vector<string> m) {
    vector<int> dab;
    string a = "(None)";
    vector<ALL> all_information;

    for (unsigned i = 0; i < m.size(); i++) {
        bool next = false;
        int k = m[i].size();
        for (int j = 0; j < k; j++) {

            if (n[0] == m[i][0]) {
                bool update = true;
                for (unsigned k = 0; k < n.size(); k++) {
                    if (n[k] != m[i][k]) {
                        update = false;
                    }
                }
                // ���ǿ� �´°͸� ����ü�� push
                if (update) {
                    ALL all_info;
                    all_info.index = i;
                    all_info.tempmusic = music[i];
                    all_info.tempname = name[i];
                    all_info.temptime = Real_time[i];
                    //cout << "temptime ? " << all_info.temptime << endl;
                    all_information.push_back(all_info);
                    next = true;

                    dab.push_back(i);
                }
                m[i].erase(0, 1);
            }
            else {
                m[i].erase(0, 1);
            }
            if (next) {
                break;
            }
        }

    }
    /*
        for (int i = 0; i < all_information.size(); i++) {
            cout << all_information[i].index << endl;
            cout << all_information[i].tempmusic << endl;
            cout << all_information[i].tempname << endl;
            cout << all_information[i].temptime << endl;
            cout << endl;
        }
    */

    if (all_information.size() > 1) {
        int time_max = 0;
        unsigned index_min = MIN;
        int idx = 0;
        int music_count = 0;

        //�ִ� ���ǽð��� ã�� for��
        for (unsigned i = 0; i < all_information.size(); i++) {
            time_max = max(time_max, all_information[i].temptime);
        }

        //cout << "time_max -> " << time_max <<endl;

        //�ִ� ���ǽð��� �������� �� ��ִ��� ã�� for�� �� 1���϶��� �ٷ� �ش� �̸� ����
        for (unsigned i = 0; i < all_information.size(); i++) {
            if (time_max == all_information[i].temptime) {
                music_count++;
                idx = i;
                index_min = min(index_min, i);
            }
        }

        //cout << "music_count ? " << music_count <<endl;

        //���� ��ġ + ����ð� �� ��ġ = �����Էµ� ���� ���� ��ȯ�ϴ� ����
        if (music_count > 1) {
            return all_information[index_min].tempname;
        }
        //���� ��ġ �ִ� ����ð��� 1�� ���� �ٷ� �̸� ��ȯ
        else {
            return all_information[idx].tempname;
        }

    }
    else if (all_information.size() == 1) {
        //cout << "1" << endl;
        return all_information[0].tempname;
    }
    else {
        //cout << "0" << endl;
        return a;
    }

}



string solution(string m, vector<string> musicinfos) {
    string answer = "";

    //1 �� ������ �����ϴ� �Լ� // Clear
    str_out(musicinfos);

    //2 ġȯ�ϴ� �Լ�  // Clear
    m = str_XY(m);
    for (unsigned i = 0; i < music.size(); i++) {
        music[i] = str_XY(music[i]);
        //cout <<"??? " << music[i] << endl;
    }

    //3 time ���Ϳ� �ð� ���̸�ŭ �������ִ� // Clear
    music_length(temp_time);

    //4 ���ڸ�ŭ ���ڿ� �ø��ų� ���̴� �Լ� // Clear
    music = str_add(Real_time, music);


    //debug code
    for (unsigned i = 0; i < music.size(); i++) {
        cout << music[i] << endl;
    }


    //5 �Է¹��� ���ڿ��� ������ ���� ���ǰ� ���� �����Ϳ� ���� name�� �����ϴ� �Լ�
    answer = DAB(m, music);

    return answer;
}


int main() {
    string m = "ABC";
    vector<string> str = { "13:00,13:05,ONE,D#ABC","12:00,12:06,TWO,ABCD","09:00,09:06,THREE,ABC" };
    cout << solution(m, str) << endl;
}