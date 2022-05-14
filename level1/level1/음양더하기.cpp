#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++)
    {
        int num (0);
        if (signs[i]) num += absolutes[i];
        else num -= absolutes[i];

        answer += num;

    }

    return answer;
}

int main()
{
    vector<int> absolutes = { 4,7,12 };
    vector<bool> signs = { true,false,true };

    cout << solution(absolutes, signs);

}