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


bool comp(int a, int b) {
    return a > b;
}

//// �ݴ�� �������� ���� ���Ŀ� ���Ϳ��� �����ϴ� ����� �ƴ�
//// �״�� B ���Ϳ� ���ϴ� ����� �̿��ߴ�.
int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    // �������� ����
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);

    // A������ ���� ���� ���� B������ ���� ū������ ũ�ų� ���ٸ� �̴� 0 �� �ǹ��Ѵ� ���� 0 ����
    if (A[A.size() - 1] >= B[0]) {
        return answer;
    }

    // B������ �ε����� ��Ÿ���� ����
    int B_idx = 0;

    // A���͸� ��ȸ�ϸ鼭 ���� ū ���� B������ ���� ū ���� ���ϸ鼭 ũ�ٸ� answer++ , B������ �ε����� �÷��ش�
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < B[B_idx]) {
            answer++;
            B_idx++;
        }
    }

    return answer;
}

//// TestCase �� ��� ��� but ��� �ð��ʰ��� ����
//// �ϱ� �˰����� ��� ������������ �����Ŀ� A������ ���� ���� ũ�⸦ B ������ ó������ ���� ū���� ������ answer++�� �ϴ� �����̸�
//// A���Ϳ� ���� ū ũ���� ���ڰ� �ִ°�쿡�� �ش� ���Ҹ� ���ִ� �˰����̴�.

/*
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    bool all_biger = true;

    for(int i=0; i<A.size(); i++){
        int diff_a = A[i];

        for(int j=0; j<B.size(); j++){
            if(diff_a < B[j]){
                answer++;
                A.erase(A.begin()+i);
                i--;
                B.erase(B.begin()+j);
                all_biger = false;
                break;
            }
            else{
                continue;
            }
        }
        if(all_biger==true){
            A.erase(A.begin()+i);
            i--;
        }
    }

    return answer;
}
*/
int main() {

    vector<int> a = { 5,1,3,7 };
    vector<int> b = { 2,2,6,8 };

    cout << solution(a, b) << endl;


    return 0;
}