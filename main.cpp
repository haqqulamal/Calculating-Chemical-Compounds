#include <iostream>
#include <map>
#include <string>
#include <regex>

using namespace std;

// Fungsi untuk menghitung jumlah atom dalam sebuah senyawa kimia
map<string, int> hitungJumlahAtom(string senyawa) {
    map<string, int> jumlahAtom;
    regex pola("([A-Z][a-z]*)(\\d*)"); // Pola regex untuk memisahkan unsur dan jumlahnya
    smatch cocok;

    // Mencocokkan setiap unsur dan jumlahnya dalam senyawa
    while (regex_search(senyawa, cocok, pola)) {
        string unsur = cocok[1];
        int jumlah = cocok[2].str().empty() ? 1 : stoi(cocok[2].str()); // Mengonversi jumlah unsur menjadi integer

        jumlahAtom[unsur] += jumlah;

        senyawa = cocok.suffix(); // Melanjutkan pencarian dari sisipan setelah pasangan unsur-jumlah saat ini
    }

    return jumlahAtom;
}

int main() {
    string senyawa;
    cout << "Masukkan rumus senyawa kimia: ";
    getline(cin, senyawa);

    map<string, int> jumlahAtom = hitungJumlahAtom(senyawa);

    // Menampilkan jumlah atom setiap unsur dalam senyawa
    cout << "Jumlah atom setiap unsur dalam senyawa:\n";
    for (auto const &pair : jumlahAtom) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

