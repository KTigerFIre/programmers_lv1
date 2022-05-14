#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    vector<bool> check(nums.size(), true);

    int k = 3;

    for (int i = 0; i < k; i++)
    {
        check[i] = false;
    }

    vector<vector<int>> combos;
    int cnt(0);
    do
    {
        cnt++;
        vector<int> combo;
        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == false)
            {
                combo.push_back(nums[i]);
            }
        }
        combos.push_back(combo);
    } while (std::next_permutation(check.begin(), check.end()));


    for (auto& combo : combos)
    {
        int sum = combo[0] + combo[1] + combo[2];
        if (is_prime(sum))
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = { 1,2,3,4 };

    cout << solution(nums);
}