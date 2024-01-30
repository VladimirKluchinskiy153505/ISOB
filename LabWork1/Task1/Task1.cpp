#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
const int letter_count = 26, first_lower = 97, first_upper = 65;
const char* filename = "C:\\Users\\avdot\\Desktop\\3Cource\\6Round\\ISOB\\LabWorks\\LabWork1\\orig_text.txt";
string encrypt_text(string& text, int key) {
    string ans = "";
    int size = text.size();
    for (int i = 0; i < size; ++i) {
        char& sym = text[i];
        if (isalpha(sym)) {
            if (isupper(sym)) {
                ans += (int(sym) + key - first_upper) % letter_count + first_upper;
            }
            else {
                ans += (int(sym) + key - first_lower) % letter_count + first_lower;
            }
        }
        else {
            ans += sym;
        }
    }
    return ans;
}
string decrypt_text(string& ciphered_text, int key) {
    string decrypted_text = "";
    for (char& now : ciphered_text) {
        if (isalpha(now)) {
            int shift = int(now) - key;
            if (isupper(now)) {
                if (shift < int('A')) {
                    shift += letter_count;
                }
            }
            else {
                if (shift < int('a')) {
                    shift += letter_count;
                }
            }
            decrypted_text += char(shift);
            }
        else {
            decrypted_text += now;
        }
    }
    return decrypted_text;
}
string read_from_file(string&& filename) {
    ifstream inputFile(filename);
    string content="";
    string str;
    if (!inputFile.is_open()) {
        std::cerr << "Failed to read" << '\n';
        return "";
    }
    while (!inputFile.eof()) {
        getline(inputFile, str);
        content+=str;
    }
    inputFile.close();
    return content;
}
int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    string original_text = read_from_file(filename);
    int key;
    cout << "Enter key\n";
    cin >> key;
    if (key < 0) {
        key = -key;
    }
    key %= 26;
    cout << "Original Text: " << original_text << '\n';
    string cipher = encrypt_text(original_text, key);
    cout <<"Cipher: "<< cipher << '\n';
    string decrypted = decrypt_text(cipher, key);
    cout << "Encrypted text: "<<decrypted << '\n';
    return 0;
}
