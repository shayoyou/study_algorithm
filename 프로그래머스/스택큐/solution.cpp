/*
* 프로그래머스
* 코딩테스트 연습 > 스택/큐 > 프린터
https://programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<int> idxs;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++)
    {
        idxs.push(i);
        pq.push(priorities[i]);
    }

    while (true)
    {
        int idx = idxs.front();
        if (priorities[idx] == pq.top())
        {
            ++answer;
            if (idx == location)
                break;

            idxs.pop();
            pq.pop();
        }
        else
        {
            idxs.pop();
            idxs.push(idx);
        }
    }

    return answer;
}

int main()
{
    int res = solution({ 1, 1, 9, 1, 1, 1 }, 0);
    //int res = solution({ 2, 1, 3, 2 }, 2);
    cout << res << endl;

    return 0;
}
