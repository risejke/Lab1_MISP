#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& c)
{
    for(auto a:c)
        if (!iswalpha(a) || !iswupper(a))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned pa;
    wcout<<L"Cipher ready. Input key: ";
    wcin>>key;
    if (!isValid(key)) {
        wcerr<<L"Key not valid\n";
        return 1;
    }
    wcout<<L"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-Exit, 1-Encrypt, 2-Decrypt): ";
        wcin>>pa;
        if (pa > 2) {
            wcout<<L"Wrong operation\n";
        } else if (pa >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (pa==1) {
                    wcout<<L"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Operation aborted: Invalid text\n";
            }
        }
    } while (pa!=0);
    return 0;
}