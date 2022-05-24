#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
�� ���� left�� right�� �Ű������� �־����ϴ�.
left���� right������ ��� ���� �߿���,
����� ������ ¦���� ���� ���ϰ�,
����� ������ Ȧ���� ���� �� ����
return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

int numberofaddition(int number) {
    int count = 0;
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            count++;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        int addition = numberofaddition(i);
        if (addition % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}

int main()
{
    int left = 24;
    int right = 27;
    int dab = solution(left, right);
    cout << dab << endl;
    return 0;
}
/*
13	17	43
24	27	52
*/