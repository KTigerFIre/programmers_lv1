#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>;
#include <cmath>
using namespace std;

struct Pose
{
    int i;
    int j;

    Pose(int _i=0, int _j=0) :i(_i), j(_j) {};

    Pose& operator=(const Pose& ref)
    {
        i = ref.i;
        j = ref.j;
        return *this;
    }
};

unordered_map<char, Pose> number_pose =
{
    {'1', Pose(0,0)},
    {'2', Pose(0,1)},
    {'3', Pose(0,2)},
    {'4', Pose(1,0)},
    {'5', Pose(1,1)},
    {'6', Pose(1,2)},
    {'7', Pose(2,0)},
    {'8', Pose(2,1)},
    {'9', Pose(2,2)},
    {'*', Pose(3,0)},
    {'0', Pose(3,1)},
    {'#', Pose(3,2)}
};


vector<string> keypad = {"123","456","789","*0#"};

int compute_cost(Pose hand, Pose goal)
{
    int cost = abs(hand.i - goal.i) + abs(hand.j - goal.j);
    return cost;
}


string solution(vector<int> numbers, string hand) {
    string answer = "";

    //init pose of both hand
    Pose right_hand = number_pose['#'];
    Pose left_hand  = number_pose['*'];

    for (auto& num : numbers)
    {
        if (num == 1 || num == 4 || num == 7)
        {
            answer.push_back('L');
            char key_char = num + '0';
            left_hand = number_pose[key_char];
        }
        else if (num == 3 || num == 6 || num == 9)
        {
            answer.push_back('R');
            char key_char = num + '0';
            right_hand = number_pose[key_char];
        }
        else
        {
            char key_char = num + '0';
            Pose goal_pose(number_pose[key_char]);
            if (compute_cost(right_hand, goal_pose) == compute_cost(left_hand, goal_pose))
            {
                if (hand == "right")
                {
                    answer.push_back('R');
                    right_hand = number_pose[key_char];
                }
                else
                {
                    answer.push_back('L');
                    left_hand = number_pose[key_char];
                }
            }
            else if (compute_cost(right_hand, goal_pose) > compute_cost(left_hand, goal_pose))
            {
                answer.push_back('L');
                left_hand = number_pose[key_char];
            }
            else
            {
                answer.push_back('R');
                right_hand = number_pose[key_char];
            }
        }
    }
    

    return answer;
}


int main()
{
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";
    cout << solution(numbers, hand);
}