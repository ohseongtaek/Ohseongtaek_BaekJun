#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    // stations �� ������������ ���ĵǾ��ִ�.
    // ���� 1�� ����Ʈ ���� �����ؼ� stations �迭�� ���Ե��� ������ �������� �ϳ��� ��ġ�ϴ� ������ ���ư���.

    int idx = 0;
    int apt = 1;

    while (apt <= n) {
        if (stations[idx] - w <= apt && apt <= stations[idx] + w) {
            apt = stations[idx] + w;
            idx++;
        }
        else {
            answer++;
            apt += 2 * w;
        }
        apt++;
    }


    return answer;
}


int main() {
    int n = 16;
    vector<int> station = { 9 };
    int w = 2;
    cout << solution(n, station, w) << endl;
    return 0;
}