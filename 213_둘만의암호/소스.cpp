#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) 
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < index; j++)
        {
            bool exitflag = false;

            while (true)
            {
                s[i]++;
                if (s[i] == 123)
                {
                    s[i] = 97;
                }

                if (skip.find(s[i]) == std::string::npos)
                {
                    exitflag = true;
                }

                if (exitflag == true)
                {
                    break;
                }
            }
        }
        answer += s[i];
    }
    return answer;
}

int main()
{
    string s = "aukks";
    string sk = "wbqd";
    int idx = 5;

    string result = solution(s, sk, idx);
    
    if (result == "happy")
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}



/*
���ڿ� s�� �� ���ĺ��� index��ŭ ���� ���ĺ����� �ٲ��ݴϴ�.
index��ŭ�� ���� ���ĺ��� z�� �Ѿ ��� �ٽ� a�� ���ư��ϴ�.
skip�� �ִ� ���ĺ��� �����ϰ� �ǳʶݴϴ�.
���� ��� s = "aukks", skip = "wbqd", index = 5�� ��, a���� 5��ŭ �ڿ� �ִ� ���ĺ��� f���� [b, c, d, e, f]���� 'b'�� 'd'�� skip�� ���ԵǹǷ� ���� �ʽ��ϴ�. ���� 'b', 'd'�� �����ϰ� 'a'���� 5��ŭ �ڿ� �ִ� ���ĺ��� [c, e, f, g, h] ������ ���� 'h'�� �˴ϴ�. ������ "ukks" ���� �� ��Ģ��� �ٲٸ� "appy"�� �Ǹ� ����� "happy"�� �˴ϴ�.

�� ���ڿ� s�� skip, �׸��� �ڿ��� index�� �Ű������� �־��� �� �� ��Ģ��� s�� ��ȯ�� ����� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
5 �� s�� ���� �� 50
1 �� skip�� ���� �� 10
s�� skip�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
skip�� ���ԵǴ� ���ĺ��� s�� ���Ե��� �ʽ��ϴ�.
1 �� index �� 20
����� ��
s	skip	index	result
"aukks"	"wbqd"	5	"happy"
����� �� ����
����� �� #1
���� ����� ��ġ�մϴ�.
*/