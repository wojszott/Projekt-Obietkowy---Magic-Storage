
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

void addItem(vector<unique_ptr<ConsoleElement>>& group, int category) { //function to add items to the storage/vector->group
    string itemName;
    string string1, string2, string3;
    int variable1, variable2;

    cout << "Enter the name of the item: " << endl;
    cin.ignore();
    getline(cin, itemName);

    switch (category) { //switch for different sections
        case 0: {
            cout << "Enter the number of arrows: " << endl;
            if (!(cin >> variable1) || variable1 < 0) {
                cerr << "Invalid input for arrow count." << endl;
                return;
            }
            group.emplace_back(std::make_unique<Quiver>(itemName, variable1));
            break;
        }
        case 1: {
            vector<string> armorParts;
            cout << "Enter armor parts (separated by space): " << endl;
            while (cin >> string1) {
                armorParts.push_back(string1);
                if (cin.get() == '\n') {
                    break;
                }
            }
            group.emplace_back(std::make_unique<ArmorParts>(itemName, armorParts));
            break;
        }
        case 2: {
            vector<string> ingredients;

            cout << "Enter potion effects: " << endl;
            cin >> string1;
            cout << "Enter potion duration: " << endl;
            cin >> variable1;

            cout << "Enter potion ingredients (separated by space): " << endl;
            while (cin >> string3) {
                ingredients.push_back(string3);
                if (cin.get() == '\n') {
                    break;
                }
            }

            group.emplace_back(std::make_unique<Potions>(itemName, string1, variable1, ingredients));
            break;
        }
        case 3: {
            Weapons weapon(itemName);
            group.emplace_back(std::make_unique<Weapons>(itemName));
            break;
        }
        case 4: {
            cout << "Enter artifact location:" << endl;
            cin >> string1;
            cout << "Enter artifact properties:" << endl;
            cin >> string2;
            cout << "Enter artifact value:" << endl;
            if (!(cin >> variable1)) {
                cerr << "Invalid input for artifact value." << endl;
                return;
            }
            group.emplace_back(std::make_unique<Artifacts>(itemName, string1, string2, variable1));
            break;
        }
        case 5: {
            cout << "Enter quest bounty:" << endl;
            if (!(cin >> variable1)) {
                cerr << "Invalid input for quest bounty." << endl;
                return;
            }
            cout << "Enter quest difficulty:" << endl;
            cin >> string1;
            cout << "Enter quest location:" << endl;
            cin >> string2;
            cout << "Enter quest description:" << endl;
            cin.ignore();
            getline(cin, string3);
            cout << "Enter required party count:" << endl;
            if (!(cin >> variable2)) {
                cerr << "Invalid input for required party count." << endl;
                return;
            }
            group.emplace_back(std::make_unique<Quests>(itemName, variable1, string1, string2, string3, variable2));
            break;
        }
        case 6: {
            vector<string> places, mobs, treasure;
            cout << "Enter area names (separated by space): " << endl;
            while (cin >> string1) {
                places.push_back(string1);
                if (cin.get() == '\n') {
                    break;
                }
            }
            cout << "Enter list of enemies appearing there (separated by space): " << endl;
            while (cin >> string2) {
                mobs.push_back(string2);
                if (cin.get() == '\n') {
                    break;
                }
            }
            cout << "Enter possible loot (separated by space): " << endl;
            while (cin >> string3) {
                treasure.push_back(string3);
                if (cin.get() == '\n') {
                    break;
                }
            }
            group.emplace_back(std::make_unique<Maps>(itemName, places, mobs, treasure));
            break;
        }
        case 7: {
            Foods food(itemName);
            group.emplace_back(std::make_unique<Foods>(itemName));
            break;
        }
        case 8: {
            cout << "Enter material count:" << endl;
            if (!(cin >> variable1)) {
                cerr << "Invalid input for material count." << endl;
                return;
            }
            cout << "Enter material rarity:" << endl;
            cin >> string1;
            cout << "Enter material purpose:" << endl;
            cin >> string2;
            group.emplace_back(std::make_unique<Materials>(itemName, variable1, string1, string2));
            break;
        }
        default: {
            cerr << "Invalid category." << endl;
            return;
        }
    }
    cout << "Item added successfully!" << endl;
}
void adding_items(vector<vector<unique_ptr<ConsoleElement>>>& group) { //adding some items so it's not empty

    Quiver quiver("Basic Quiver", 20);
    group[0].push_back(std::make_unique<Quiver>(std::move(quiver)));

    ArmorParts armor("Steel Armor", {"Helmet", "Chestplate", "Gauntlets", "Leggings"});
    group[1].push_back(std::make_unique<ArmorParts>(std::move(armor)));

    Potions healthPotion("Health Potion", "Healing", 60, {"Herb", "Water"});
    group[2].push_back(std::make_unique<Potions>(std::move(healthPotion)));

    Weapons sword("Iron Sword");
    group[3].push_back(std::make_unique<Weapons>(std::move(sword)));

    Artifacts ring("Mystic Ring", "Hidden Cave", "Magic Power Boost", 100);
    group[4].push_back(std::make_unique<Artifacts>(std::move(ring)));

    Quests mainQuest("Save the Kingdom", 500, "Hard", "Castle", "Defeat the Evil King", 4);
    group[5].push_back(std::make_unique<Quests>(std::move(mainQuest)));

    Maps worldMap("Fantasy World", {"Forest", "Mountain", "Desert"}, {"Dragon", "Goblin", "Skeleton"}, {"Gold", "Gems", "Treasure Chest"});
    group[6].push_back(std::make_unique<Maps>(std::move(worldMap)));

    Foods apple("Fresh Apple");
    group[7].push_back(std::make_unique<Foods>(std::move(apple)));

    Materials iron("Iron Ingot", 10, "Common", "Crafting");
    group[8].push_back(std::make_unique<Materials>(std::move(iron)));
}
