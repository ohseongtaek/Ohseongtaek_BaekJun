#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());

    //�����°� ���� �������� �����ͺ��� ū������ ����
    //sort ���İ��� �ݴ��� ���İ���?
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_vector_queue;
    int index = 0;
    int end_time = 0;

    while (index < jobs.size() || !priority_vector_queue.empty()) {

        // 1. ó�� ���۵ɶ� ������ push�ϰ� �� ó���� 0���� ~ ó���ð� ���� �̱� ����
        //    2������ �б� ������ end time ������

        // 3. ������ ������ ������ �߰������� ó�� ������ �ð����� ���� queue �ȿ� ���Ա� ������ ���⼭ push
        if (index < jobs.size() && end_time >= jobs[index][0]) {
            priority_vector_queue.push(make_pair(jobs[index][1], jobs[index][0]));
            index++;
            continue;
        }

        // 2. ť���� ������� �ʱ� ������ ����
        // ó�� 0�� �����϶� ���� ���� ���� ������ �ð��� �����ϸ� answer�� ��-���� �ð��� �̿��� ������

        // 4. queue �ȿ� ����ִ� ���� ������ ������������ �Ǿ��ֱ� ������ top�� �̿��� ���� ������ �ð����� ���� ���ͼ� ����ϰ��ִ� ������ �ð��� ���� �ͺ��� ����� �ϴ°�
        if (!priority_vector_queue.empty()) {
            end_time = end_time + priority_vector_queue.top().first;
            answer = answer + end_time - priority_vector_queue.top().second;
            priority_vector_queue.pop();
        }

        // 5. ���� ���Դ� �۾��� �� ������ �� �� ���ο� �۾��� ��������
        else {
            end_time = jobs[index][0];
        }
    }


    return answer / jobs.size();
}

int main() {
    vector<vector<int>> v = { {0, 3}, {1, 9}, {2, 6} };
    cout << "solution ? " << solution(v) << endl;
    cout << endl;
}