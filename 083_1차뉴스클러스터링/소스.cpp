#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <ctype.h>
using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;

    double U_hap = 0, N_gyo = 0;

    map<string, int> m;


    //////////////////////////////
    /////��� ���� �ҹ��ڷ� ��ȯ/////
    //////////////////////////////
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
        else {
            continue;
        }
    }
    for (int i = 0; i < str2.size(); i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = str2[i] + 32;
        }
        else {
            continue;
        }
    }

    ///////////////////////////////////
    /////��� ���� 2���� �ڸ��� ���/////
    ///////////////////////////////////
    for (int i = 1; i < str1.size(); i++) {
        if (isalpha(str1[i - 1]) != 0 && isalpha(str1[i]) != 0) {
            string temp = "";
            temp += str1[i - 1];
            temp += str1[i];
            U_hap++;

            if (m.count(temp)) {  //���ڸ� map �Լ��� ���� �� ���� ++
                m[temp]++;
            }
            else {               //ó�� ���� ���ڴ� ������ 1�� set
                m[temp] = 1;
            }

        }
    }


    for (int i = 1; i < str2.size(); i++) {
        if (isalpha(str2[i - 1]) != 0 && isalpha(str2[i]) != 0) {
            string temp = "";
            temp += str2[i - 1];
            temp += str2[i];

            if (m.count(temp)) {      // ������ ++
                if (m[temp] > 0) {    // �������� ����ó��
                    m[temp]--;
                    N_gyo++;
                }
                else {
                    U_hap++;
                }
            }
            else {
                U_hap++;
            }
        }
    }

    ////////////////////////////////////
    ///////////////�� ����///////////////
    ////////////////////////////////////

    if (U_hap != 0) {
        answer = ((double)answer * (N_gyo / U_hap));
    }

    return answer;
}