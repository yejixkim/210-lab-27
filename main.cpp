// COMSC 210 | Lab 27 | Yeji Kim

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;

    // insert villagers into the map
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    villagers.insert({
        "Del", make_tuple(8, "Alligator", "Got a snack?")
    });

    // display villagers using a range-based for loop
    cout << "Villager details:" << endl;

    for (const auto& pair : villagers) {
        cout << pair.first << " [" 
             << get<0>(pair.second) << ", "
             << get<1>(pair.second) << ", "
             << get<2>(pair.second) << "]" << endl;
    }

    // display villagers using iterators
    cout << "\nVillager details (iterators):" << endl;

    for (map<string, tuple<int, string, string>>::iterator it =
            villagers.begin();
        it != villagers.end(); ++it) {

        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    villagers.erase("Kyle");

    // search for a villager
    string searchKey = "Raymond";
    auto it = villagers.find(searchKey);

    if (it != villagers.end()) {
        cout << "\nFound " << searchKey << ":" << endl;

        cout << it->first << " ["
            << get<0>(it->second) << ", "
            << get<1>(it->second) << ", "
            << get<2>(it->second) << "]" << endl;
    } else {
        cout << "\n" << searchKey << " not found." << endl;
    }

    // report size, clear the map, and report size again
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

return 0;
}