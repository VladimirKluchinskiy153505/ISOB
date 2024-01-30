#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
using namespace std;
const int letter_count = 26, first_lower = 97, first_upper = 65;
const char* filename = "C:\\Users\\avdot\\Desktop\\3Cource\\6Round\\ISOB\\LabWorks\\LabWork1\\orig_text.txt";
string encrypt_text(string& text, string& key_word)
{
    string cipher = "";
    int text_size = text.size(), key_word_size = key_word.size();
    for (int i = 0; i < text_size; ++i) {
        char& sym = text[i];
        int key_word_index = i % key_word_size;
        int shift = 0;
        if (65 <= key_word[key_word_index] && key_word[key_word_index] <= 90) {
            shift = int(key_word[key_word_index]) - 65;
        }
        else if (97 <= key_word[key_word_index] && key_word[key_word_index] <= 122) {
            shift = int(key_word[key_word_index]) - 97;
        }
        if (isalpha(sym)) {
            if (isupper(sym)) {
                cipher += char(int(sym)-65+shift)%letter_count + 65;
            }
            else {
                cipher += char(int(sym)-97 + shift) % letter_count + 97;
            }
        }
        else {
            cipher += sym;
        }
    }
    return cipher;
}

string decrypt_text(string& cipher, string& key_word)
{
    string decrypt_text= "";
    int cipher_size = cipher.size(), key_word_size = key_word.size();
    for (int i = 0; i < cipher_size; ++i) {
        char& sym = cipher[i];
        int key_word_index = i % key_word_size;
        int shift = 0;
        if (65 <= key_word[key_word_index] && key_word[key_word_index] <= 90) {
            shift = int(key_word[key_word_index]) - 65;
        }
        else if (97 <= key_word[key_word_index] && key_word[key_word_index] <= 122) {
            shift = int(key_word[key_word_index]) - 97;
        }
        if (isalpha(sym)) {
            if (isupper(sym)) {
                decrypt_text += char(int(sym) - 65 + 26 - shift) % letter_count + 65;
            }
            else {
                decrypt_text += char(int(sym) - 97 +26- shift) % letter_count + 97;
            }
        }
        else {
            decrypt_text += sym;
        }
    }
    return decrypt_text;
}
string read_from_file(string&& filename) {
    ifstream inputFile(filename);
    string content = "";
    string str;
    if (!inputFile.is_open()) {
        std::cerr << "Failed to read" << '\n';
        return "";
    }
    while (!inputFile.eof()) {
        getline(inputFile, str);
        content += str;
    }
    inputFile.close();
    return content;
}
int main()
{
  //  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << setw(10) << "Vigenere Cipher" << '\n';
    string original_text = read_from_file(filename);
    string key_word = "QWefeo";
    cout << "Enter key\n";
    getline(cin, key_word);
    string cipher = encrypt_text(original_text, key_word);
    cout << "Cipher: " << cipher << '\n';
    string decrypted = decrypt_text(cipher, key_word);
    cout << "Encrypted text: " << decrypted << '\n';
    
    return 0;
}
