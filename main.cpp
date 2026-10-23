// COMSC 210 | Lab 27 | Yeji Kim

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// display all villagers and their details
void displayVillagers(
    const map<string, tuple<int, string, string>>& villagers) {

    cout << "\nVillager details:" << endl;

    // go through each villager in the map
    for (const auto& pair : villagers) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }
}

int main() {
    // declare a map to store villager names + their info
    //each tuple contains friendship level, species, and catchphrase
    map<string, tuple<int, string, string>> villagers;

    // insert villagers into the map
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    // keep displaying the menu until the user chooses to exit
    int choice = 0;

    while (choice != 6) {
        // display menu
        cout << "\n1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;

        // get user choice
        cout << "Enter choice: ";
        cin >> choice;


        if (choice == 1) {
            string name;
            int friendshipLevel;
            string species;
            string catchphrase;

            cout << "Villager name: ";
            cin >> name;

            // check whether the villager is already in the map
            if (villagers.find(name) != villagers.end()) {
                cout << name << " already exists." << endl;
            } else {
                cout << "Friendship level: ";
                cin >> friendshipLevel;

                if (friendshipLevel >= 0 && friendshipLevel <= 10) {
                    cout << "Species: ";
                    cin >> species;

                    cout << "Catchphrase: ";
                    cin.ignore();
                    getline(cin, catchphrase);

                    villagers[name] = make_tuple(
                        friendshipLevel, species, catchphrase
                    );

                    cout << name << " added." << endl;
                } else {
                    cout << "Friendship level must be between 0 and 10."
                         << endl;
                }
            }

            displayVillagers(villagers);
        }
        else if (choice == 2) {
            string name;

            cout << "Villager name: ";
            cin >> name;

            if (villagers.erase(name) > 0) {
                cout << name << " deleted." << endl;
            } else {
                cout << name << " not found." << endl;
            }

            displayVillagers(villagers);
        }
        else if (choice == 3 || choice == 4) {
            string name;

            cout << "Villager name: ";
            cin >> name;

            auto it = villagers.find(name);

            if (it != villagers.end()) {
                int friendship = get<0>(it->second);

                if (choice == 3) {
                    if (friendship < 10) {
                        get<0>(it->second) = friendship + 1;
                        cout << name << "'s friendship increased." << endl;
                    } else {
                        cout << name << "'s friendship is already 10."
                             << endl;
                    }
                } else {
                    if (friendship > 0) {
                        get<0>(it->second) = friendship - 1;
                        cout << name << "'s friendship decreased." << endl;
                    } else {
                        cout << name << "'s friendship is already 0."
                             << endl;
                    }
                }
            } else {
                cout << name << " not found." << endl;
            }

            displayVillagers(villagers);
        }
        else if (choice == 5) {
            string name;

            cout << "Villager name: ";
            cin >> name;

            auto it = villagers.find(name);

            if (it != villagers.end()) {
                cout << "Found " << name << ":" << endl;
                cout << it->first << " ["
                     << get<0>(it->second) << ", "
                     << get<1>(it->second) << ", "
                     << get<2>(it->second) << "]" << endl;
            } else {
                cout << name << " not found." << endl;
            }

            displayVillagers(villagers);
        }
        else if (choice == 6) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please choose 1-6." << endl;
        }
    }

    return 0;
}