#include <iostream>
using namespace std;

/*  1�� TestCase �ð��ʰ� �ڵ�
int solution(int n)
{
    int ans = 0;

    while(n>0){
        if( n%2 == 0 || n == 2){
            if(n==2){
                ans++;
                break;
            }
            else{
                n = n/2;
            }
        }
        else{
            n = n - 1;
            ans++;
        }
    }
    return ans;
}
*/

int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        ans = ans + (n % 2);
        n = n / 2;
    }
    return ans;
}