#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    for(int i = 0; i< T ;i++)
    {
        int x, y;
        cin >> x >> y;
        int an_x, an_y;
        cin >> an_x >> an_y;

        int j = 0;
           
       

        bool chk = true; // -1 확인 변수

        while(x*j <= x*y){
            int tmp_x = an_x + x*j;  // 앞이 가능한 경우의 수
            int val_x = tmp_x % y;
            if(val_x ==0) val_x = y;
             if(val_x == an_y){
             cout << tmp_x <<"\n";
             chk = false;
             break;
             }
             j++;
        }

        if(chk){
                cout << -1<<"\n";
        }

        
     }
    }



