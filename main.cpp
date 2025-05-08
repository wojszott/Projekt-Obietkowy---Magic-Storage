/*
   Author: Wojciech Szott
   Description: A program to manage items in a storage.
*/

#include <iostream>
#include <vector>
#include <memory>
#include "Classes.h"
#include "Functions.h"
using namespace std;


int main() { //user interface + calling the functions
    cout << "Welcome" << endl;
    // Create a vector of vectors, used to store item names for display purposes
    vector<vector<unique_ptr<ConsoleElement>>> group(9);
    adding_items(group);

    // User interface
    cout << "Welcome to the Magical Storage!" << endl;
    cout << "What are your intentions today?" <<endl;
    int option = 1;
    while (option!=0) {
       cout << "1-I would like to see the contents of the storage." <<endl;
       cout << "2-I would like to add to the contents of the storage." <<endl;
       cout << "0-Actually, never mind I need to go" <<endl;
       cin >> option;
        switch (option) {
            case 0:
                continue;
            case 1: {
               cout << "What would you like to see?" <<endl;
               cout << "0-Quivers 1-ArmorParts 2-Potions 3-Weapons" <<endl;
               cout << "4-Artifacts 5-Quests 6-Maps 7-Foods 8-Materials" <<endl;
                int option2;
               cin >> option2;
                if (option2 >= 0 && option2 < 9) {
                    for (int i = 0; i < group[option2].size(); i++) {
                       cout << i << ". " << endl;
                        group[option2][i]->displayInfo();
                    }
                   cout <<endl;
                } else {
                    cout << "Invalid item number." <<endl;
                }
               cout << "What item would you like to inspect?" <<endl;
               cout << "Enter the number of the item you want to see:" <<endl;
                int item_nr;
               cin >> item_nr;
                if (item_nr >= 0 && item_nr < group[option2].size()) {
                    group[option2][item_nr]->displayInfo();
                } else {
                   cout << "Invalid item number." <<endl;
                }
                break;
            }
            case 2: {
               cout << "What would you like to add?" <<endl;
                cout << "0-Quivers 1-ArmorParts 2-Potions 3-Weapons" <<endl;
                cout << "4-Artifacts 5-Quests 6-Maps 7-Foods 8-Materials" <<endl;
                int category;
               cin >> category;

                if (category >= 0 && category < 9) {
                    addItem(group[category], category);
                } else {
                   cout << "Invalid category." <<endl;
                }
                break;
            }
            default:
               cout << "Invalid option." <<endl;
        }
    }

   cout << "See you soon <3" <<endl;
    return 0;
}
