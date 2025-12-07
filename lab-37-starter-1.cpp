#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int main() {
    map<int, list<string>> hash_table;
    
    string line;

    // Open/read the file
    ifstream fin;
    fin.open("lab-37-data-3.txt");
    if (fin.good()) {
        while (fin >> line) {
            int index = gen_hash_index(line);
            hash_table[index].push_back(line);
        }
        fin.close();
    }
    else
        cout << "File not found.\n";

    // interactive menu
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "[1] Print the first 100 entries\n";
        cout << "[2] Search for a key\n";
        cout << "[3] Add a key\n";
        cout << "[4] Remove a key\n";
        cout << "[5] Modify a key\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                // display the first 100 map entries
                int count = 0;
                for(map<int, list<string>>::iterator it = hash_table.begin(); 
                    it != hash_table.end() && count < 100; ++it, ++count) {

                    cout << "Index: " << it->first << endl;
                    for (string s : it->second) {
                    cout << "  " << s << endl;
                    }
                }
                break;
            }

            case 2: {
                // search for key
                string key;
                cout << "Enter key to search: ";
                cin >> key;
                int index = gen_hash_index(key);
                if (hash_table.find(index) != hash_table.end()) {
                    bool found = false;
                    for (string s : hash_table[index]) {
                        if (s == key) {
                            found = true;
                            cout << "Key found: " << s << endl;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Key not found.\n";
                    }
                }
                else
                    cout << "Key not found.\n";

                break;
            }

            case 3: {
                // add key
                string key;
                cout << "Enter key to add: ";
                cin >> key;
                int index = gen_hash_index(key);
                hash_table[index].push_back(key);
                break;
            }

            case 4: {
                // remove key
                string key;
                cout << "Enter key to remove: ";
                cin >> key;
                int index = gen_hash_index(key);

                for (auto it = hash_table[index].begin(); it != hash_table[index].end(); ++it) {
                    if (*it == key) {
                        hash_table[index].erase(it);
                        cout << "Key removed: " << key << endl;
                        break;
                    }
                }
                break;
            }

            case 5: {
                // modify key
                string old_key, new_key;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Enter number 0-5.\n";
                break;
                        
        }
    } while (choice != 0);

    return 0;
}


int gen_hash_index(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int) s[i];
    }   
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/