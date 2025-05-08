
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class ConsoleElement { //main class
public:
    string name;

    ConsoleElement(string itemName) : name(itemName) {}

    virtual void displayInfo() const {
        cout << "Enter information for " << name << endl;
    }
};

class ConsoleItem : public ConsoleElement { //class for items
public:
    ConsoleItem(string itemName) : ConsoleElement(itemName) {}

    void displayInfo() const override {
        cout << "Item name: " << name << endl;
    }
};

class ConsoleInfo : public ConsoleElement { //class for information
public:
    ConsoleInfo(string itemName) : ConsoleElement(itemName) {}

    void displayInfo() const override {
        cout << "Info name: " << name << endl;
    }
};
//classes for sections
class Quiver : public ConsoleItem {
public:
    int arrows;

    Quiver(string itemName, int arrowCount) : ConsoleItem(itemName), arrows(arrowCount) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "count: " << arrows << endl;
    }
};

class ArmorParts : public ConsoleItem {
public:
    vector<string> parts;

    ArmorParts(string itemName, vector<string> armorParts) : ConsoleItem(itemName), parts(armorParts) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "armor parts: " << endl;
        for (const auto &part : parts) {
            cout << part << " " << endl;
        }
        cout << endl;
    }
private:
    vector<string> armorParts;
};

class Potions : public ConsoleItem {
public:
    string effects;
    int duration;
    vector<string> ingredients;

    Potions(string itemName, string potionEffects, int potionDuration, vector<string> potionIngredients)
            : ConsoleItem(itemName), effects(potionEffects), duration(potionDuration), ingredients(potionIngredients) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "duration: " << duration << endl;
        cout << "effects: " << effects << endl;
        cout << "ingredients: " << endl;
        for (const auto& ingredient : ingredients) {
            cout << ingredient << " " << endl;
        }
        cout << endl;
    }
private:
    string potionEffect;
    int potionDuration;
    vector<string> potionIngredients;
};

class Weapons : public ConsoleItem {
public:
    Weapons(string itemName) : ConsoleItem(itemName) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
    }
};

class Artifacts : public ConsoleItem {
public:
    string location;
    string properties;
    int value;

    Artifacts(string itemName, string artifactLocation, string artifactProperties, int artifactValue)
            : ConsoleItem(itemName), location(artifactLocation), properties(artifactProperties), value(artifactValue) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "location: " << location << endl;
        cout << "properties: " << properties << endl;
        cout << "value: " << value << endl;
    }
};

class Quests : public ConsoleInfo {
public:
    int bounty;
    string difficulty;
    string location;
    string description;
    int party_count;

    Quests(string itemName, int questBounty, string questDifficulty, string questLocation, string questDescription, int questPartyCount)
            : ConsoleInfo(itemName), bounty(questBounty), difficulty(questDifficulty), location(questLocation), description(questDescription), party_count(questPartyCount) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "bounty: " << bounty << endl;
        cout << "difficulty: " << difficulty << endl;
        cout << "location: " << location << endl;
        cout << "description: " << description << endl;
        cout << "party count: " << party_count << endl;
    }
};

class Maps : public ConsoleInfo {
public:
    vector<string> areas;
    vector<string> enemies;
    vector<string> loot;

    Maps(string itemName, vector<string> mapAreas, vector<string> mapEnemies, vector<string> mapLoot)
            : ConsoleInfo(itemName), areas(mapAreas), enemies(mapEnemies), loot(mapLoot) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "areas: " << endl;
        for (const auto& area : areas) {
            cout << area << " " << endl;
        }
        cout << endl;
        cout << "enemies: " << endl;
        for (const auto& enemy : enemies) {
            cout << enemy << " " << endl;
        }
        cout << endl;
        cout << "loot: " << endl;
        for (const auto& lootItem : loot) {
            cout << lootItem << " " << endl;
        }
        cout << endl;
    }
private:
    vector<string> mapPlaces;
    vector<string> mapMobs;
    vector<string> mapTreasure;
};


class Foods : public ConsoleItem {
public:
    Foods(string itemName) : ConsoleItem(itemName) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
    }

};

class Materials : public ConsoleItem {
public:
    int count;
    string rarity;
    string purpose;

    Materials(string itemName, int materialCount, string materialRarity, string materialPurpose)
            : ConsoleItem(itemName), count(materialCount), rarity(materialRarity), purpose(materialPurpose) {}

    void displayInfo() const override {
        cout << "name: " << name << endl;
        cout << "count: " << count << endl;
        cout << "rarity: " << rarity << endl;
        cout << "purpose: " << purpose << endl;
    }
};