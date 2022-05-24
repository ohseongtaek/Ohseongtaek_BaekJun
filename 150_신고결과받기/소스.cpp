#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> ReporterList;
    map<string, int> ReportedList;
    
    for (int i = 0; i < report.size(); i++)
    {
        string str_reporter = "";
        string str_reported = "";
        string str_reporter_reported = report[i];

        // ���ڿ� �Ľ� 
        int nEmpty = str_reporter_reported.find(' ');

        // �Ű��� 
        str_reporter = str_reporter_reported.substr(0, nEmpty);

        // �Ű� ���ѻ�� 
        str_reported = str_reporter_reported.substr(nEmpty);

        // �Ű��� �� ����� �Ű��� ����� �������� ��찡 ���� 
        // ���� �Ű��ڰ� �Ű��� �̷��� ���ٸ� �־���
        if (ReporterList[str_reporter].find(str_reported) == ReporterList[str_reporter].end())
        {
            ReportedList[str_reported]++;
            ReporterList[str_reporter].insert(str_reported);
        }
    }
    
#ifdef _DEBUG
    map<string, set<string>>::iterator iter1;
    map<string, int>::iterator iter2;
    set<string>::iterator iter3;

    for (iter1 = ReporterList.begin(); iter1 != ReporterList.end(); iter1++)
    {
        cout << iter1->first << " | ";
        for (iter3 = iter1->second.begin(); iter3 != iter1->second.end(); iter3++)
        {
            cout << *iter3 << " ";
        }
        cout << endl;
    }
    
    cout << "========================================================" << endl;

    for (iter2 = ReportedList.begin(); iter2 != ReportedList.end(); iter2++)
    {
        cout << iter2->first << " " << iter2->second << endl;
    }
#endif 

    for (int i = 0; i < id_list.size(); i++)
    {
        int nWarning = 0;
        string str_id_list = id_list[i];

        map<string, set<string>>::iterator map_iter;
        set<string>::iterator set_iter;

        for (map_iter = ReporterList.begin(); map_iter != ReporterList.end(); map_iter++)
        {
            if (map_iter->first == str_id_list)
            {
                for (set_iter = map_iter->second.begin(); set_iter != map_iter->second.end(); set_iter++)
                {
                    if (ReportedList[*set_iter] >= k)
                    {
                        nWarning++;
                    }
                }
            }
        }

        answer.push_back(nWarning);
    }

    return answer;
}

int main()
{
    vector<string> id = { "muzi", "frodo", "apeach", "neo" };
    vector<string> re = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k = 2;

    vector<int> dab = solution(id, re, k);
    cout << endl;
    for (int i = 0; i < dab.size(); i++)
    {
        cout << dab[i] << endl;
    }
}