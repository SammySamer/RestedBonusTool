//calculate when I can do my guardians, so that by day 8, I am at 100 rested bonus

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main () {
    vector<string> daysOfWeek{ "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
    "Monday", "Tuesday" };
    bool guardian1Done[7] = {};
    bool guardian2Done[7] = {};
    int restedBonusByDay[7] = {};

    //Rest bonus as of today
    int restedBonus = 80;  

    //Wednesday (April 5th) is 0, and any day after increments by 1
    //So, Friday (April 7th) would be 2.
    //All the way to next Wednesday (April 12th), would be 7
    int startDay = 5;
    for (int days = startDay; days <= 7; days++) {
        if (days != startDay) {
            restedBonus += 20;
            if (guardian1Done[days - 1])
                restedBonus -= 30;
            if (guardian2Done[days - 1])
                restedBonus -= 30;
        }

        if (restedBonus < 0)
            restedBonus = 0;
        else if (restedBonus > 100)
            restedBonus = 100;
        else
            ;

        int oppCost = (7 - days) * 20 + restedBonus;
        if (oppCost == 100) {
            for (int i = days; i <= 7; i++){
                restedBonusByDay[i] = restedBonus;
                restedBonus += 20;
            }
            restedBonus -= 20;
            break;
        }

        if (oppCost <= 140 && restedBonus == 0) {
            guardian1Done[days] = true;
            guardian2Done[days] = true;
        }

        else if (oppCost >= 130 && oppCost < 160) {
            guardian1Done[days] = true;
        }
        
        else if (oppCost >= 160) {
            guardian1Done[days] = true;
            guardian2Done[days] = true;
        }

        else 
            ;

        restedBonusByDay[days] = restedBonus;

    }


    for (int i = startDay; i <= 6; i++) {
        if (guardian1Done[i] && guardian2Done[i])
            cout << "Both guardians on " << daysOfWeek[i % 7] << ", with Rest Bonus: " << restedBonusByDay[i % 7] << endl;
        else if (guardian1Done[i])
            cout << "One guardian on " << daysOfWeek[i % 7] << ", with Rest Bonus: " << restedBonusByDay[i % 7] << endl;
        else 
            cout << "Skip guardians on " << daysOfWeek[i % 7] << ", with Rest Bonus: " << restedBonusByDay[i % 7] << endl;
    }
    
    cout << "Remaining rested by Patch Day: " 
            << restedBonus << endl;

    return 0;
}