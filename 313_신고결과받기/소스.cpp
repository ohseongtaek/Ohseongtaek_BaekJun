#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> count;
    map<string, int> PushAnswer;
    map<string, int> warning;
    map<string, int>::iterator iteration;
   
    // �ߺ����� 
    report.erase(unique(report.begin(), report.end()), report.end());

    // �Ű� �� ī��Ʈ
    for (int i = 0; i < report.size(); i++)
    {
        int iter = report[i].find(" ");
        int length = report[i].size();
        //string src = report[i].substr(0,iter);
        string dst = report[i].substr(iter, length - iter);

        warning[dst]++;
    }

    // �Ű� �� �Ѵ� �̸� Ȯ�� �� ���Ϳ� ���� 
    for (iteration = warning.begin(); iteration != warning.end(); iteration++)
    {
        if (iteration->second >= k)
        {
            count.push_back(iteration->first);
        }
    }

    // ���Ϳ� ������ �Ϳ� ���� �Ű��� �̸� ����
    for (int i = 0; i < report.size(); i++)
    {
        int iter = report[i].find(" ");
        int length = report[i].size();
        string src = report[i].substr(0, iter);
        string dst = report[i].substr(iter, length - iter);
        for (int i = 0; i < count.size(); i++)
        {
            if(count[i] == dst)
            {
                PushAnswer[src]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        bool flag = false;
        for (iteration = PushAnswer.begin(); iteration != PushAnswer.end(); iteration++)
        {
            if (iteration->first == id_list[i])
            {
                flag = true;
                answer.push_back(iteration->second);
                break;
            }
        }
        if (flag == false)
        {
            answer.push_back(0);
        }
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