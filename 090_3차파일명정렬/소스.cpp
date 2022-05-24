#include <string> 
#include <vector> 
#include <algorithm> 
#include <iostream>
using namespace std; 

// HEAD�� TAIL ���� 
pair<string, int> parse_head_tail(string file) {
	pair<string, int> ret; 
	int idx = 0;
	// HEAD �����ϱ� ���� Ž�� 
	for (char c : file) {
		if ('0' <= c && c <= '9') 
			break; 
		idx++; 
	} 
	int num = 0;
	// TAIL�� ���� �����ϱ� ���� Ž�� 
	for (int i = idx; i < file.length(); i++) {
		if (!('0' <= file[i] && file[i] <= '9'))
			break; 
		num = num * 10 + (file[i] - '0'); 
		cout << num << endl;
	} 
	// HEAD, TAIL ����
	return { file.substr(0, idx), num };
} 

// "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"

bool cmp(const string& a, const string& b) {
	pair<string, int> file_a = parse_head_tail(a); 
	pair<string, int> file_b = parse_head_tail(b); 
	// �빮�ڷ� ��ȯ
	for (char& c : file_a.first)
		c = toupper(c);
	for (char& c : file_b.first) 
		c = toupper(c); 
	// HEAD�� ��ġ�ϸ� TAIL�� ���ؼ� ���� 
	if (file_a.first == file_b.first) 
		return file_a.second < file_b.second; 
	// HEAD�� ���� 
	return file_a.first < file_b.first; 
} 

vector<string> solution(vector<string> files) {
	// ��� files �����ϱ� 
	stable_sort(files.begin(), files.end(), cmp); 

	return files; 
}

int main() {
	vector<string> files = { "img12.PNG", "img12.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> dab;
	dab = solution(files);
	for (int i = 0; i < dab.size(); i++) {
		cout << dab[i] << endl;
	}
}