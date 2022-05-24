#include <vector>

using namespace std;

int ost(int location, int s, int g, int x, int y, vector<vector<int>>& ALL) {

	int G_sum = 1;
	if (x < 0 || y < 0 || x >= s || y >= g || location != ALL[x][y]) {
		return 0;
	}
	else {
		ALL[x][y] = 0;		// ���Ϲ����� ���ڼ��� 0���� �ʱ�ȭ 
		G_sum = G_sum + ost(location, s, g, x - 1, y, ALL); // ��	(0,X �϶� �������,, ����ó��)
		G_sum = G_sum + ost(location, s, g, x + 1, y, ALL); // �Ʒ� (5,X �϶� ���� ���,, ����ó��)
		G_sum = G_sum + ost(location, s, g, x, y - 1, ALL); // ���� (X,0 �϶� ���� ���,, ����ó��)
		G_sum = G_sum + ost(location, s, g, x, y + 1, ALL); // ������ (X,3�϶� ���� ���,, ����ó��)
	}
	return G_sum;
}


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	int sum = 0;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) {
				continue;
			}
			else {
				sum = ost(picture[i][j], m, n, i, j, picture);
				number_of_area++;
				if (sum > max_size_of_one_area) {
					max_size_of_one_area = sum;
				}
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}