// ЛР 8.1, варіант 3.
// Умова: у введеному рядку є щонайменше три коми.
// 1. Знайти індекс третьої за порядком коми.
// 2. Замінити кожну кому двома зірочками "**".
#include <iostream>
#include <string>
using namespace std;

// Рекурсивно шукає третю кому.
int thirdComma(const string& s, int i = 0, int count = 0) {
    if (i == (int)s.size()) return -1;
    if (s[i] == ',') count++;
    if (count == 3) return i;
    return thirdComma(s, i + 1, count);
}

// Рекурсивно замінює всі коми.
string replaceCommas(const string& s, int i = 0) {
    if (i == (int)s.size()) return "";
    string current = s[i] == ',' ? "**" : string(1, s[i]);
    return current + replaceCommas(s, i + 1);
}

#ifndef UNIT_TEST
int main() {
    string s;
    cout << "Enter text (at least 3 commas): ";
    getline(cin, s);
    int index = thirdComma(s);
    if (index == -1) {
        cout << "Error: fewer than 3 commas.\n";
        return 1;
    }
    cout << "Index of third comma: " << index << '\n';
    cout << "New text: " << replaceCommas(s) << '\n';
}
#endif
