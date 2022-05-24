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


bool found_humun_number(int& mid, int& k, vector<int>& stone) {
    int count = 0;

    for (int i = 0; i < stone.size(); i++) {
        // ���ӵǰ� ���;� �Ѵ� ���� ���°͸�ŭ ī��Ʈ
        if (stone[i] - mid <= 0) {
            count++;
        }
        // �߰��� ����� ������ 0���� �ٽý���
        else {
            count = 0;
        }
        // ���� k���� ������ �� ���� ����� �ǳʾ� �ϱ� ������ true ����
        if (count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int min_number = 1;
    int max_number = *max_element(stones.begin(), stones.end());
    int mid = 0;


    while (min_number <= max_number) {

        mid = (min_number + max_number) / 2;

        // �߰�����ŭ�� ���� �ǳ����� 0���� �������� k��ŭ �������� Ȯ���Ѵ� ������ �׸�ŭ �ǳ��� ���Ѵٴ� �� ���� -1
        if (found_humun_number(mid, k, stones)) {
            max_number = mid - 1;
        }
        // k��ŭ ������ ���ϸ� �� �ǳμ��ִٴ°� +1
        else {
            min_number = mid + 1;
        }
    }
    return min_number;

}

int main() {
    int n = 3;
    vector<int> a = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1, 15 };
    int d = solution(a, n);
    cout << d << endl;

    return 0;
}