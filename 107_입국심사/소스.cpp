#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//�̺й� �̿� �� �ڷ��� ���� ����
long long solution(int n, vector<int> times) {
    long long answer;

    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times[times.size() - 1];
    long long avg = (min + max) / 2;
    answer = max;


    //�������� ��Ȳ������ ��� ����
    while (min <= max) {
        long long temp_ncount = 0;
        avg = (min + max) / 2;

        //��սð����� ó���� �� �ִ� ����� �� Ȯ��
        for (int i = 0; i < times.size(); i++) {
            temp_ncount += avg / times[i];
        }

        //���� ó���� �� ���� �ϰų� ���ٸ� max���� ����
        if (temp_ncount >= n) {
            //answer�� �ϴ� �����Ѵ� �ּҰ��� �����ؾ��ϱ� ������
            answer = avg;
            max = avg - 1;
        }
        //���� ó���� �� ���� �Ѵٸ� min���� �ø�
        else {
            min = avg + 1;
        }
    }
    return answer;
}

int main() {
    int n = 6;
    vector<int> t = { 7,10 };
    cout << solution(n, t) << endl;
}