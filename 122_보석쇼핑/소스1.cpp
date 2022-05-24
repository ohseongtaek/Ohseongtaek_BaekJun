#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <map>
using namespace std;


// Using the two pointer Algorithm

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> gems_box;

    // �ʱ�ȭ
    for (int i = 0; i < gems.size(); i++) {
        gems_box[gems[i]] = 0;
    }

    int gems_box_total = gems_box.size();
    int start_point = 0;
    int end_point = 0;
    int gems_end = gems.size();
    int gems_count = 0;

    answer.push_back(0);
    answer.push_back(gems_end);
    while (1) {
        // ���� �������� ���� �����԰� ������ ���ٸ� �� ���� �����̴� �̶� start_point �� +1 ���ֱ� ���ؼ� �ش� ���� ī��Ʈ�� - ���ְ� �����Կ����� - �� ���ش�.
        if (gems_count >= gems_box_total) {
            if (gems_box[gems[start_point]] - 1 == 0) {
                gems_count--;
            }
            gems_box[gems[start_point++]]--;
        }

        // end_point �� ���� �����ϸ� Ż��
        else if (end_point == gems_end) {
            break;
        }

        // gems�� ������ �ߺ������� �����Կ� ������� ������ ���� ���� �����̹Ƿ� ����ī��Ʈ�� + ���ְ� �ش� ������ map �� + �׸��� end ���� + ���ش�.
        else {
            if (gems_box[gems[end_point]] == 0) {
                gems_count++;
            }
            gems_box[gems[end_point]]++;
            end_point++;
        }

        // �Ÿ��� ����ϱ� ���� ���ǹ�!
        if (gems_count == gems_box_total) {
            if (end_point - start_point < answer[1] - answer[0]) {
                answer[0] = start_point;
                answer[1] = end_point;
            }
        }
    }
    answer[0]++;
    return answer;
}
int main() {
    vector<string> g = { "A", "B", "C", "C", "D", "A","B","C","D" };
    vector<int> d;
    d = solution(g);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << endl;
    }

    return 0;
}