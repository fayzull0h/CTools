#include <iostream>
#include <vector>
using namespace std;

int atomicNumber(string a) {
    string atomicSymbols[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", 
    "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", 
    "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", 
    "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"};

    for (int i = 0; i < 54; i++) {
        if (a == atomicSymbols[i]) {
            return ++i;
        }
    }
    return 0;
}

string LvlHandler(string& final, int _atomN) {
    final += to_string(_atomN) + ")";
    return final;
}

string aufbauMachine(int atomN) {
    string result = "1s(";

    if (atomN <= 2) {
        return LvlHandler(result, atomN);
    }

    atomN -= 2;
    result += "2) 2s(";
    
    if (atomN <= 2) {
        return LvlHandler(result, atomN);
    }

    result += "2)";
    atomN -= 2;

    if (atomN <= 6) {
        result += " 2p(";
        return LvlHandler(result, atomN);
    }

    atomN -= 6;
    result += " 2p(6) 3s(";

    if (atomN <= 2) {
        return LvlHandler(result, atomN);
    }

    result += "2)";
    atomN -= 2;

    if (atomN <= 6) {
        result += " 3p(";
        return LvlHandler(result, atomN);
    }

    atomN -= 6;
    result += " 3p(6) 4s(";

    if (atomN <= 2) {
        return LvlHandler(result, atomN);
    }

    if (atomN == 6 || atomN == 11) {
        result += "1) 3d(";
        atomN -= 1;
        return LvlHandler(result, atomN);
    }
    result += "2) 3d(";
    atomN -= 2;

    if (atomN <= 10) {
        return LvlHandler(result, atomN);
    }

    atomN -= 10;

    if (atomN <= 6) {
        result += "10) 4p(";
        return LvlHandler(result, atomN);
    }

    atomN -= 6;
    result += "10) 4p(6) 5s(";

    if (atomN <= 2) {
        return LvlHandler(result, atomN);
    }

    atomN -= 2;
    result += "2) 4d(";

    if (atomN <= 10) {
        return LvlHandler(result, atomN);
    }

    atomN -= 10;
    result += "10) 5p(";

    if (atomN <= 6) {
        return LvlHandler(result, atomN);
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