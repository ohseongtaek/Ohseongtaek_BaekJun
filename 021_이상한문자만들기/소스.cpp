#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int wordCnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            wordCnt = 0;
            answer += s[i];
            continue;
        }
        else
        {
            // ¦�� : �ҹ���->�빮��, �빮�ڴ� �״��
            if (wordCnt % 2 == 0)
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    answer = answer + s[i];
                }
                else
                {
                    answer = answer + char(s[i] - 'a' + 'A');
                }
            }
            // Ȧ�� : �빮�� �ҹ��� �ҹ��ڴ� �״�� 
            else
            {
                if ('a' <= s[i] && s[i] <= 'z')
                {
                    answer = answer + s[i];
                }
                else
                {
                    answer = answer + char(s[i] - 'A' + 'a');
                }
            }
        }
        wordCnt++;
    }

    return answer;
}