#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

//�̿����� ID�� ��� ���ڿ� �迭 id_list, �� �̿��ڰ� �Ű��� �̿����� ID ������ ��� ���ڿ� �迭 report
// ���� ������ �Ǵ� �Ű� Ƚ�� k�� �Ű�����
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, set<string>> report_map;
    unordered_map<string, int> idx_map;

    std::string reporter_id;
    std::string bad_player_id;

    for (int i = 0; i < id_list.size(); i++)
    {
        idx_map[id_list[i]] = i;
    }

    stringstream ss;

    for (auto& id_id : report)
    {
        ss.str(id_id);

        ss >> reporter_id >> bad_player_id;
        report_map[bad_player_id].insert(reporter_id);

        ss.clear();
    }

    for (auto it : report_map)
    {
        if (it.second.size() >= k)
        {
            for (auto set_it : it.second)
            {
                int idx = idx_map[set_it];
                answer[idx]++;
            }
        }
    }

    return answer;
}


int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;
    solution(id_list, report, k);
    return 0;
}