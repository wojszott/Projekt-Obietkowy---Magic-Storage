# Projekt-Obietkowy - Magic-Storage
Projekt konsolowego systemu zarządzania „magicznym” ekwipunkiem RPG, napisany w C++. Wykorzystuje programowanie obiektowe do reprezentowania różnych typów przedmiotów i informacji, takich jak: bronie, artefakty, mikstury, mapy, zadania i inne.

# Działanie

CLI pyta o wybór jednej z akcji:  
0 - zakończ interakcję  
1 - przejrzyj zawartość ekwipunku  
2 - dodaj przedmiot/informację do ekwipunktu  

Base - CLI wyświetla listę kategori  

1.1 CLI pyta o wybór jednej kategori  
1.2 CLI wyświetla listę z wybranej kategori  
1.3 CLI pyta o wybór jednego obiektu  
1.4 CLI wyświetla szczgóły wybranego obietku  

2.1 CLI pyta o wybór jednej kategori  
2.2 CLI po kolei pyta o dane w zależności od wybranej kategori  

## Struktura klas
Podstawą projektu jest klasa bazowa ConsoleElement, z której dziedziczą dwie gałęzie:  
ConsoleItem – reprezentuje przedmioty (ekwipunek)  
ConsoleInfo – reprezentuje informacje (np. mapy, zadania)  
### Przykładowe klasy dziedziczące:
Weapons – proste przedmioty  
Quiver – liczba strzał  
ArmorParts – lista elementów zbroi  
Potions – efekty, czas trwania, składniki  
Artifacts – lokalizacja, właściwości, wartość  
Quests – nagroda, trudność, opis  
Maps – lokacje, wrogowie, łupy  
Materials – ilość, rzadkość, przeznaczenie  

Każda klasa implementuje metodę displayInfo(), aby wypisać informacje o obiekcie.

Przykład: Mikstura
```
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
```

### Status projektu:
Projetk ukończony, lecz wymaga dopracowania błędów związanych z interakcją z CLI
