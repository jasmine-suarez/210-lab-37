#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    int total = 0;

    ifstream fin;
    fin.open("lab-37-data-3.txt");
    if (fin.good()) {
        string line;
        while (fin >> line)
            total += sum_ascii(line);
        fin.close();
    }
    else
        cout << "File not found.\n";

    cout << "Total sum of ASCII values: " << total << endl;

    return 0;
}

int sum_ascii(string s) {
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