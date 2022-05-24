#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    int days = 0, index = 0;
    priority_queue<int> pq;

    while (days < k) {                  // day end loop
        if (days >= dates[index]) {     // days�� dates�� �迭�� ���� �ϴ� pq�� push�Ѵ�
            pq.push(supplies[index]);
            index++;
        }
        if (stock == 0) {               //���� �����ִ� �а��簡 ������ pq�� �ִ� ���� ū ���� ����Ѵ� �̶� ����ϴ� ���� ���޹޴� ���̴�
            stock += pq.top();
            pq.pop();
            answer++;
        }
        days++;
        stock--;
    }
    return answer;
}