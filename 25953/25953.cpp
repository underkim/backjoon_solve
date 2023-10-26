#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000002 // 최대값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, T, M;
    int start, end;
    cin >> N >> T >> M >> start >> end;

    int arr[1001][10000] = {}; // T  일대 i 위치로 가는 최소값

    for (int i = 0; i < T; i++) // 초기화
        for (int j = 0; j < N; j++)
            arr[i][j] = INF;

    for (int i = 0; i < T; i++) // 모든 시작점 0으로 초기화
        arr[i][start] = 0;

    int value[1002][10000][10000] = {}; // 가중치 값 저장 배열

    int x, y, w;

    for (int i = 0; i < T; i++) // value 채우기
    {
        int visit[10002] = {};
        for (int j = 0; j < M; j++)
        {
            cin >> x >> y >> w;
            value[i + 1][x][y] = w;
        }
    }

    for (int i = 0; i < T - 1; i++)
    {
        for (int j = 0; j < N; j++) // N번
        {
            for (int k = 0; k < N; k++)
            {
                if (value[i + 1][j][k] != 0)
                {                                                                           //  k의 최솟값       // j로 가는 최솟값 + j에서 k로 오는 최소값
                    arr[i + 2][k] = min(arr[i + 2][k], arr[i + 1][j] + value[i + 2][j][k]); // T+1의 k의 최소값은 이전의
                }
            }
        }
    }

    for (int i = 0; i < T; i++)
    {
        cout << i + 1 + "테이블 \n";
        for (int j = 0; j < N; j++)
        {
            cout << arr[i + 1][j];
        }
        cout << '\n';
    }
}