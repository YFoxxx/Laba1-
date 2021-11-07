#include <iostream>
#include <fstream>
#include <string>
#include "my_func.h" 

using namespace std;

int main() {
    int n;
    ifstream in_file;
    ofstream fout;
    string n_str;

    in_file.open("INPUT.txt");
    if (in_file.is_open()) {
        getline(in_file, n_str);
    }
    else {
        cout << "Error" << endl;
    }
    in_file.close();

    n = StringToInt(n_str);

    if (clause(n) == true) {
        fout.open("OUTPUT.txt");
        if (n % 2 == 0) {
            brakets(n, fout);
        }
        else {
            brakets(n-1, fout);
        }
        fout.close();
    } 
    else {
        cout << " Error!" << endl;
    }
    return 0;
}