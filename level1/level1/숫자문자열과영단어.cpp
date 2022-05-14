#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> number_map =
{   {"zero",0 },
    {"one", 1 },
    {"two", 2 },
    {"three", 3 },
    {"four", 4 },
    {"five", 5 },
    {"six", 6 },
    {"seven", 7 },
    {"eight", 8 },
    {"nine", 9 },
};


int solution(string s) {
    int answer = 0;

    for (auto& its : number_map)
    {
        auto key = its.first;

        while (s.find(key) != s.npos)
        {
            s.replace(s.find(key), key.size(), to_string(its.second));
        }
    }

    return stoi(s);
}

int soultion2(string s)
{
    //regex로 풀면 더 쉽게 가능
}

int main()
{
    string s = "one4oneseveneight";
    cout << solution(s);
}