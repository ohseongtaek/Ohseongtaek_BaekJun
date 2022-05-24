#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solution(string dirs) {

    int borad[10][10][10][10]; // ��x ��y ��x ��y

    // �ʱ� x,y ��ǥ
    int pos_x = 5;
    int pos_y = 5;

    // ������ �� ++
    int road = 0;

    // ���ڿ� "" �϶�����
    while (!dirs.empty()) {

        // ù��° ���� ��������
        char temp = dirs[0];
        //cout << temp << endl;
        // up �϶� y++
        if (temp == 'U') {
            // ���� �ʰ��ϴ��� Ȯ���ʰ��ϸ� �׳� ����
            if (pos_y < 10) {
                // ���� x,y ���� �̵��� x,y �� �̷��� �ִ��� Ȯ��
                if (borad[pos_x][pos_y][pos_x][pos_y + 1] != 1) {
                    // �̷��� ������ 1�� set
                    borad[pos_x][pos_y][pos_x][pos_y + 1] = 1;
                    // �ݴ�ε� �̵��ص� road ���� ������ �ʱ� ������ �̰͵� 1�� set
                    borad[pos_x][pos_y + 1][pos_x][pos_y] = 1;
                    // ���� road++
                    road++;
                }
                pos_y++;
            }
        }

        // down �϶� y--
        else if (temp == 'D') {
            if (pos_y > 0) {
                if (borad[pos_x][pos_y][pos_x][pos_y - 1] != 1) {
                    borad[pos_x][pos_y][pos_x][pos_y - 1] = 1;
                    borad[pos_x][pos_y - 1][pos_x][pos_y] = 1;
                    road++;
                }
                pos_y--;
            }
        }

        // right �϶� x++
        else if (temp == 'R') {
            if (pos_x < 10) {
                if (borad[pos_x][pos_y][pos_x + 1][pos_y] != 1) {
                    borad[pos_x][pos_y][pos_x + 1][pos_y] = 1;
                    borad[pos_x + 1][pos_y][pos_x][pos_y] = 1;
                    road++;
                }
                pos_x++;
            }
        }

        // left �϶� x--
        else if (temp == 'L') {
            if (pos_x > 0) {
                if (borad[pos_x][pos_y][pos_x - 1][pos_y] != 1) {
                    borad[pos_x][pos_y][pos_x - 1][pos_y] = 1;
                    borad[pos_x - 1][pos_y][pos_x][pos_y] = 1;
                    road++;
                }
                pos_x--;
            }
        }

        // ���ڿ� �Ǿ� delete
        //cout << "x ? " << pos_x << " y ? " << pos_y << "   road?????  " << road << endl;
        dirs.erase(0, 1);
    }

    return road;
}



int main() {

    string s = "LULLLLLLU";
    int a = solution(s);
    cout << a << endl;
    return 0;

}