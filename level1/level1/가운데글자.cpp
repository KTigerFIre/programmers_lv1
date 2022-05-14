#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";

    if (s.size() % 2 == 0)
    {
        int pos = (s.size() / 2) -1;
        answer += s.substr(pos, 2);
    }
    else
    {
        int pos = (s.size() / 2);
        answer += s.substr(pos, 1);
    }

    return answer;
}

int main()
{
    string s = { "abcd" };
    solution(s);
    return 0;
}