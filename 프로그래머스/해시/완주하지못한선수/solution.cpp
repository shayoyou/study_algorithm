/*
* 프로그래머스
* 코딩테스트 연습 > 해시 > 완주하지 못한 선수
https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> map;

    for (auto& name : completion)
        map[name]++;

    for (auto& name : participant)
    {
        if (--map[name] < 0)
            return name;
    }
}

int main()
{
    string res = solution({ "leo", "kiki", "eden" }, { "eden", "kiki" });
    cout << res << endl;

    return 0;
}
