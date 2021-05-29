#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// int main()
// {
//     map<string, set<string>> name_map;
//     int n;
//     cin >> n;
//     while (n > 0)
//     {
//         string s1;
//         string s2;
//         cin >> s1 >> s2;
//         if (name_map.find(s2) != name_map.end())
//         {
//             name_map[s2].insert(s1);
//         }
//         else
//             name_map[s2] = set<string>{s1};
//         n--;
//     }

//     set<string> seen;
//     queue<string> name_queue;
//     int queue_nums = 0;
//     while (!name_map.empty())
//     {
//         string name = name_map.begin()->first;
//         name_queue.push(name);
//         while (!name_queue.empty())
//         {
//             string name = name_queue.front();
//             name_queue.pop();
//             seen.insert(name);
//             for (auto itr = name_map[name].begin(); itr != name_map[name].end(); itr++)
//             {
//                 if (seen.find(*itr) == seen.end())
//                 {
//                     name_queue.push(*itr);
//                 }
//             }
//             name_map.erase(name);
//         }
//         queue_nums++;
//     }
//     cout << queue_nums;

//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    map<string, string> name_map;
    while (n > 0)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        name_map.insert(pair<string, string>(s1, s2));
        n--;
    }
    // for (auto itr = name_map.begin(); itr != name_map.end(); itr++)
    // {
    //     cout << itr->first << ":" << itr->second << endl;
    // }

    set<string> seen;
    int queue_num = 0;
    while (!name_map.empty())
    {
        string name = name_map.begin()->first;
        while (name_map.find(name) != name_map.end())
        {
            if (seen.find(name) == seen.end() && seen.find(name_map[name]) == seen.end())
            {
                queue_num++;
            }
            seen.insert(name);
            seen.insert(name_map[name]);
            string temp = name;
            name = name_map[name];
            name_map.erase(temp);
        }
    }
    cout << queue_num;
    return 0;
}