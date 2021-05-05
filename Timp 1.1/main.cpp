#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;
bool isValid(const string& s)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>,wchar_t>
    codec;
    wstring ws = codec.from_bytes(s);
    for(auto wc:ws)
        if (!isalpha(wc,loc) || !isupper(wc,loc))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    cout<<"Шифр готов. Введите ключ: ";
    cin>>key;
    if (!isValid(key)) {
        cerr<<"Ключ не загружен"<<endl;
    }
    cout<<"Ключ загружен"<<endl;
    modAlphaCipher cipher(key);
    do {
        cout<<"Шифр готов. Введите операцию (0-выход, 1-шифровать,2-расшифровать): ";
        cin>>op;
        if (op > 2) {
            cout<<"Операция не принята, введите 0, 1 или 2"<<endl;
        } else if (op >0) {
            cout<<"Шифр готов. Введите текст: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"Зашифрованный текст:"<<cipher.encrypt(text)<<endl;
                }else{
                cout<<"Расшифрованный текст:"<<cipher.decrypt(text)<<endl;            
                }} else {
                cout<<"Операция не удалась: неверный форма текста"<<endl;
            }
        }
    } while (op!=0);
    return 0;
}
