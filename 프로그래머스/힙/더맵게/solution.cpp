/*
* 프로그래머스
* 코딩테스트 연습 > 힙(Heap) > 더 맵게
https://programmers.co.kr/learn/courses/30/lessons/42626
*/

#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scov(scoville.begin(), scoville.end());

    while (scov.top() < K)
    {
        if (scov.size() == 1)
            return -1;

        ++answer;
        int first = scov.top();
        scov.pop();
        first += scov.top() * 2;
        scov.pop();
        scov.push(first);
    }

    return answer;
}

int main()
{
    int res = solution({ 1, 2, 3, 9, 10, 12 }, 7);
    cout << res << endl;

    return 0;
}
