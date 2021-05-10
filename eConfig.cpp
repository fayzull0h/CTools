#include <iostream>
#include <vector>
using namespace std;

int atomicNumber(string a) {
    string atomicSymbols[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", 
    "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", 
    "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", 
    "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La"};

    for (int i = 0; i < 58; i++) {
        if (a == atomicSymbols[i]) {
            return ++i;
        }
    }
    return 0;
}

void LvlHandler(string& final, int& _atomN, string m, int n, int e) {
    final += to_string(n) + m + "(" + to_string(_atomN) + ")";
    _atomN -= e;
}

void notLvlHandler(string& final, int& _atomN, string m, int n, int e) {
    final += to_string(n) + m + "(" + to_string(e) + ") ";
    _atomN -= e;
}

string aufbauMachine(int atomN) {
    string result = "";
    int n = 0;

    if (atomN <= 2) {
        n = 1;
    } else if (atomN <= 10) {
        n = 2;
    } else if (atomN <= 18) {
        n = 3;
    } else if (atomN <= 36) {
        n = 4;
    } else if (atomN <= 54) {
        n = 5;
    } else if (atomN <= 86) {
        n = 6;
    } else n = 7;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (atomN <= 2) {
                notLvlHandler(result, atomN, "s", i, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "s", i, 2);
            }
        }
        if (i == 2 || i == 3) {
            if (atomN <= 2 ) {
                notLvlHandler(result, atomN, "s", i, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "s", i, 2);
            }
            if (atomN <= 6) {
                notLvlHandler(result, atomN, "p", i, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "p", i, 6);
            }
        }
        if (i == 4 || i == 5) {
            if (atomN <= 2 ) {
                notLvlHandler(result, atomN, "s", i, atomN);
                break;
            } else if (atomN == 6 || atomN == 11) {
                notLvlHandler(result, atomN, "s", i, 1);
                LvlHandler(result, atomN, "d", i, 1);
                break;
            } else {
                notLvlHandler(result, atomN, "s", i, 2);
            }
            if (atomN <= 10) {
                notLvlHandler(result, atomN, "d", i - 1, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "d", i - 1, 10);
            }
            if (atomN <= 6) {
                notLvlHandler(result, atomN, "p", i, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "p", i, 6);
            }
        }
        if (i == 6 || i == 7) {
            if (atomN <= 2 ) {
                notLvlHandler(result, atomN, "s", i, atomN);
                break;
            } else {
                notLvlHandler(result, atomN, "s", i, 2);
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    string s(argv[1]);
    int aNum = atomicNumber(s);
    if (aNum > 0) {
        cout << "\nAtomic Number: " << atomicNumber(s) << endl;
    } else {
        cout << "Please run the program again, you entered an invalid element." << endl;
        return 0;
    }
    
    cout << "\nElectron Configuration:\n" << aufbauMachine(aNum) << endl << endl;
    return 0;
}