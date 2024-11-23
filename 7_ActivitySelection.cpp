#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

vector<Activity> Solve(vector<Activity>& act) {
    if (act.empty()) return {};

    sort(act.begin(), act.end(), compare);
    vector<Activity> res;
    res.push_back(act[0]);

    for (int i = 1; i < act.size(); i++) {
        if (act[i].start >= res.back().end){
            res.push_back(act[i]);
        }
    }
    return res;
}

int main() {
    vector<Activity> activities = {
        {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    vector<Activity> selected = Solve(activities);

    cout << "Selected Activities:" << endl;
    for (auto activity : selected) {
        cout << "(" << activity.start << ", " << activity.end << ")" << endl;
    }

    return 0;
}