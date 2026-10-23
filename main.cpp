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

    villagers.insert({
        "Del", make_tuple(8, "Alligator", "Got a snack?")
    });

    // keep displaying the menu until the user chooses to exit
    int choice = 0;

    while (choice != 4) {
        // display menu
        cout << "\n1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        // get user choice
        cout << "Enter choice: ";
        cin >> choice;

        // increase or decrease friendship based on user choice
        if (choice == 1 || choice == 2) {
            // ask which villager to update
            string name;
            cout << "Villager name: ";
            cin >> name;

            // search for villager by name
            auto it = villagers.find(name);

            if (it != villagers.end()) {
                // get villager's current friendship level
                int friendship = get<0>(it->second);

                if (choice == 1) {
                    // increase friendship lvl by 1, up to max of 10
                    if (friendship < 10) {
                        get<0>(it->second) = friendship + 1;
                        cout << name << "'s friendship increased." << endl;
                    } else {
                        cout << name << "'s friendship is already 10." << endl;
                    }
                } else {
                    if (friendship > 0) {
                        // decrease friendship lvl by 1, down to min of 0
                        get<0>(it->second) = friendship - 1;
                        cout << name << "'s friendship decreased." << endl;
                    } else {
                        cout << name << "'s friendship is already 0." << endl;
                    }
                }
            } else {
                cout << name << " not found." << endl;
            }

            // display updated villager info
            displayVillagers(villagers);
        }
        // search for villager by name and display their info
        else if (choice == 3) {
            // ask which villager to search for
            string name;
            cout << "Villager name: ";
            cin >> name;

            // look up villager in the map
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
        // exit the program
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        // handle invalid input
        else {
            cout << "Invalid choice. Please choose 1-4." << endl;
        }
    }

    return 0;
}