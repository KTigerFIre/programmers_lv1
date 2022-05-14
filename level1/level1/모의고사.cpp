#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> first = { 1,2,3,4,5 };
vector<int> second ={ 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, };

vector<int> solution(vector<int> answers) {
    vector<int> answer = {1,2,3};

    map<int, int> table;

    for (int i = 0; i < answers.size(); i++)
    {
        int &ans = answers[i];

        int j = i % 5;
        if (ans == first[j])
        {
            table[1]++;
        }
      
        j = i % 8;
        if (ans == second[j])
        {
            table[2]++;
        }

        j = i % 10;
        if (ans == third[j])
        {
            table[3]++;
        }
    }

    int max_num = -1;

    if (!table.empty()) answer.clear();
    
    for (auto its : table)
    {
        if (max_num == its.second)
        {
            answer.push_back(its.first);
        }
        else if(max_num < its.second)
        {
            answer.clear();
            max_num = its.second;
            answer.push_back(its.first);
        }

    }

    return answer;
}

int main()
{
    vector<int> answers = { 5,5,5,5,3,4,5 };
    solution(answers);
}