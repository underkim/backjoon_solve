#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x; // 연산의 개수

    int heap[100003];
    int size = 0;

    for (int i = 0; i < x; i++)
    {

        int n; // 다음 연산
        cin >> n;
        if (n == 0) // 절댓값이 가장 작은 값을 출력 후 제거
        {
            // 힙의 1번 삭제 후 왼쪽 오른쪽 둘중 더 작은 친구에게
            int index = 1;
            cout << heap[index];        // 출력
            heap[index] = heap[size--]; // 삭제

            // 자식노드와 비교후 교환

            while (index <= size)
            { //  *2씩 증가할거임 > 부모에서 자식으로 간다는뜻
                if (index > size)
                    break;
                else if (index * 2 == size) // 자식이 하나 인경우
                {
                    if (abs(heap[index * 2]) == abs(heap[index]))
                    {
                        if (heap[index * 2] < heap[index])
                        {
                            int tmp = heap[index * 2];
                            heap[index * 2] = heap[index];
                            heap[index] = tmp;
                            index = index * 2;
                        }
                        else break;
                    }
                    else if (abs(heap[index * 2]) < abs(heap[index]))
                    {
                        int tmp = heap[index * 2];
                        heap[index * 2] = heap[index];
                        heap[index] = tmp;
                        index = index * 2;
                    }
                    else
                        break;
                }
                else // 자식이 둘 인 경우
                {
                    if (abs(heap[index * 2 + 1]) == abs(heap[index * 2]))
                    {
                        if (heap[index * 2 + 1] > heap[index * 2])
                        { // 절대 값이 같을때 왼쪽이 더 작으면
                            // 왼쪽과 부모 비교
                            if (abs(heap[index * 2]) == abs(heap[index])) // 부모랑 왼쪽이 같을떄
                            {
                                if (heap[index * 2] < heap[index]) // 값이 왼쪽이가 더 작으면 교체
                                {
                                    int tmp = heap[index * 2];
                                    heap[index * 2] = heap[index];
                                    heap[index] = tmp;
                                    index = index *2;
                                }
                                else break;
                            }
                            else if (abs(heap[index * 2]) < abs(heap[index])) // 절대값이 왼쪽이 더 작으면 교체
                            {
                                int tmp = heap[index * 2];
                                heap[index * 2] = heap[index];
                                heap[index] = tmp;
                                index = 2*index;
                            }
                            else // 부모가 더 크면 종료
                                break;
                        }
                        else // 오른쪽이 더 작으면
                        {
                            if (abs(heap[index * 2 + 1]) == abs(heap[index])) // 부모랑 오른쪽이 같을떄
                            {
                                if (heap[index * 2 + 1] < heap[index]) // 값이 오른쪽이가 더 작으면 교체
                                {
                                    int tmp = heap[index * 2 + 1];
                                    heap[index * 2 + 1] = heap[index];
                                    heap[index] = tmp;
                                    index = index * 2 +1 ; 
                                }
                                else break;
                            }
                            else if (abs(heap[index * 2 + 1]) < abs(heap[index])) // 절대값이 오른쪽이 더 작으면 교체
                            {
                                int tmp = heap[index * 2 + 1];
                                heap[index * 2 + 1] = heap[index];
                                heap[index] = tmp;
                                index = index *2 + 1;
                            }
                            else // 부모가 더 크면 종료
                                break;
                        }
                    }

                    else if (abs(heap[2 * index + 1]) < abs(heap[2 * index]))
                    {                                                     // 오른쪽이 더 작을떄
                        if (abs(heap[index * 2 + 1]) == abs(heap[index])) // 부모랑 오른쪽이 같을떄
                        {
                            if (heap[index * 2 + 1] < heap[index]) // 값이 오른쪽이가 더 작으면 교체
                            {
                                int tmp = heap[index * 2 + 1];
                                heap[index * 2 + 1] = heap[index];
                                heap[index] = tmp;
                                index = 2*index +1;
                            }
                            else break;
                        }
                        else if (abs(heap[index * 2 + 1]) < abs(heap[index])) // 절대값이 오른쪽이 더 작으면 교체
                        {
                            int tmp = heap[index * 2 + 1];
                            heap[index * 2 + 1] = heap[index];
                            heap[index] = tmp;
                            index = index*2+1;
                        }
                        else // 부모가 더 크면 종료
                            break;
                    }
                    else // 왼쪽이 더 작을떄
                    {
                        { // 절대 값이 같을때 왼쪽이 더 작으면
                            // 왼쪽과 부모 비교
                            if (abs(heap[index * 2]) == abs(heap[index])) // 부모랑 왼쪽이 같을떄
                            {
                                if (heap[index * 2] < heap[index]) // 값이 왼쪽이가 더 작으면 교체
                                {
                                    int tmp = heap[index * 2];
                                    heap[index * 2] = heap[index];
                                    heap[index] = tmp;
                                    index = index *2;
                                }
                                else break;
                            }
                            else if (abs(heap[index * 2]) < abs(heap[index])) // 절대값이 왼쪽이 더 작으면 교체
                            {
                                int tmp = heap[index * 2];
                                heap[index * 2] = heap[index];
                                heap[index] = tmp;
                                index = index*2;
                            }
                            else // 부모가 더 크면 종료
                                break;
                        }
                    }
                }
               
            }
        }

        else
        { // 배열에 x 값을 추가
            size++;
            // 맨끝에 넣고 우선순위를 비교하면서 위로 교환한다.
            int index = size;
            while ((index != 0) && abs(n) <= abs(heap[index / 2]))
            {
                if (abs(n) == abs(heap[index / 2]))
                { //  절대값이 같다면
                    if (n < heap[index / 2])
                    {
                        heap[index] = heap[index / 2]; // 자식에 부모 저장
                        heap[index / 2] = n;           // 부모에 n저장
                        break;
                    }
                    else
                    {
                        heap[index] = n; // 자식에 저장
                        break;
                    }
                }
                else
                {
                    heap[index] = heap[index / 2];
                    index /= 2;
                }
            }
        }
    }
}
