#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void processFiles() {
    ifstream pFile("P.txt"), iFile("I.txt"), bFile("B.txt");
    ofstream report("Report.txt");

    if (!pFile.is_open() || !iFile.is_open() || !bFile.is_open()) {
        cerr << "Не вдалося відкрити файли." << endl;
        return;
    }

    vector<string> fullNames;
    string pLine, iLine, bLine;

    while (getline(pFile, pLine) && getline(iFile, iLine) && getline(bFile, bLine)) {
        string fullName = pLine + " " + iLine + " " + bLine;
        fullNames.push_back(fullName);
    }

    pFile.close();
    iFile.close();
    bFile.close();

    report << "Повний список імен:\n";
    for (const auto& name : fullNames) {
        report << name << endl;
    }

    report << "\nЗагальна кількість записів: " << fullNames.size() << endl;
    report.close();

    cout << "Обробка завершена. Звіт записано у файл Report.txt" << endl;
}

int main() {
    processFiles();
    return 0;
}
