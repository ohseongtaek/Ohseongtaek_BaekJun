#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int xnum = 0; 
    int num = 0;
    for (int i = 0; i < polynomial.size(); i++)
    {
        if (polynomial[i] == 'x')
        {
            if (polynomial[i - 1] == ' ')
            {
                xnum += 1; 
            }
            else if (i == 0) xnum += 1; //0��° �ε����� x�� �� ���
            else if ((polynomial[i - 1]) >= '0' && (polynomial[i - 1]) <= '9' && (polynomial[i - 2]) >= '1' && (polynomial[i - 2]) <= '9')
            { //2�ڸ����� ���
                int temp = ((polynomial[i - 2] - '0') * 10) + (polynomial[i - 1] - '0');
                xnum += temp;
            }
            else xnum += (polynomial[i - 1] - '0'); //���ڸ� int�� ��ȯ -> �� �ڸ� ���� ���
        }
        //���ڸ� ���
        else if ((polynomial[i]) >= '0' && (polynomial[i]) <= '9' && polynomial[i + 1] != 'x')
        {
            //�� �ڸ� ���� ���
            if ((polynomial[i - 1] == ' ' || i == 0) && ((i == polynomial.size() - 1) || polynomial[i + 1] == ' '))
            {
                num += (polynomial[i] - '0'); 
                printf("%d\n", num);
            }
            //�� �ڸ� ���� ���
            else if ((polynomial[i]) >= '0' && (polynomial[i]) <= '9' && (polynomial[i - 1]) >= '1' && (polynomial[i - 1]) <= '9')
            {
                int temp = ((polynomial[i - 1] - '0') * 10) + (polynomial[i] - '0');
                num += temp;
            }
        }
    }//for�� ������ ����

    if (xnum > 0 && num > 0) //x���, ����� ��� ���� ���
    {
        if (xnum > 1)
        {
            //sprintf(answer.c_str(), "%dx + %d", xnum, num); //x����� 1�� ���
            answer = to_string(xnum) + "x + " + to_string(num);
        }
        else
        {
            answer = "x + " + to_string(num);
            //sprintf(answer, "x + %d", num);
        }
    }
    else if (xnum > 0 && num == 0) //x����� �����ϴ� ���
    {
        if (xnum > 1)
        {
            //sprintf(answer, "%dx", xnum);
            answer = to_string(xnum) + "x";
        }
        else answer = "x";
    }
    else
    {
        //sprintf(answer, "%d", num); //����׸� ���� ���
        answer = to_string(num);
    }
    return answer;
}

int main() {
    string p1 = "3x + 7 + x";
    cout << solution(p1) << endl;  // "4x + 7"

    string p2 = "x + x + x";
    cout << solution(p2) << endl;  // "3x"

    return 0;
}
