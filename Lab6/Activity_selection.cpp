#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an activity
struct Activity {
    int start;
    int end;
};
// Function to compare two activities based on their end times
bool compareActivities(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

// Function to solve the activity selection problem
vector<Activity> selectActivities(vector<Activity>& activities) {
    // Sort activities based on their end times
    sort(activities.begin(), activities.end(), compareActivities);

    vector<Activity> selectedActivities;
    // The first activity is always selected
    selectedActivities.push_back(activities[0]);

    // Iterate through the remaining activities
    for (int i = 1; i < activities.size(); ++i) {
        // If the start time of the current activity is after or equal to the end time of the last selected activity, select it
        if (activities[i].start >= selectedActivities.back().end) {
            selectedActivities.push_back(activities[i]);
        }
    }

    return selectedActivities;
}

int main() {
    vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8},
        {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    vector<Activity> selected = selectActivities(activities);

    cout << "Selected Activities:" << endl;
    for (const Activity& activity : selected) {
        cout << "Start: " << activity.start << ", End: " << activity.end << endl;
    }
    return 0;
    }
