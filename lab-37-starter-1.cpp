#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);

int main() {
    /*
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    */

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

    int count = 0;

    // display the firs 100 map entries
    for(map<int, list<string>>::iterator it = hash_table.begin();
        it != hash_table.end() && count < 100; ++it, ++count) {
        
    return 0;
    }
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