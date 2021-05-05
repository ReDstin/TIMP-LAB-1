#include <iostream> 
#include <cctype> 
#include"Cipher.h" 
using namespace std;
bool isValid(int key,const string& s )
{
    for (auto c:s)
        if (!isalpha(c))
            return false;
    if (key > s.size())
        return false;
    return true;
}
int main(int argc, char **argv)
{
    int key;
    string text;
    unsigned op;
    do {
       cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
       cin>>op;
       if (op > 2)
        cout<<"Invalid operation"<<endl;
            else if (op > 0) {
            cout<<"Cipher ready. Input text: ";
            cin>>text;
            cout<<"Cipher ready. Input key: ";
            cin>>key;
            if (!isValid(key, text)) {
                cerr<<"Error!\n";
            } else {
                Cipher cipher(key, text);
                if (op==1) {
                    cout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"Decrypted text:"<<cipher.decrypt(text)<<endl;
                }
            }
    }
}
while (op != 0);
return 0;
}
