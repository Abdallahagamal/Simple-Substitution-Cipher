#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int index = 0;
    string message,key,message2,choice;
    bool x;
    //Plain alphabet
    vector<char> alphabets = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    //Cipher alphabet
    vector<char> new_alphabets;
    while (true) {
        cout << "1)Encrypting the message\n2)Decrypt the message\n3)Exit\nPlease Enter Your Choice: ";
        cin >> choice;
        if (choice=="1") {
            cout << "Enter key of 5 unique letters: ";
            ///to check the length of key and to make sure the letters is unique
            while (true) {
                x = true;
                cin >> key;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');   ///cin.ignore to make sure that the buffer is clear before the next input operation
                if (key.length() == 5) {
                    for (char ch : key) {                                  ///to check if the all characters in (key) is Alphabet
                        if (isalpha(ch)) {
                            x = true;
                        }
                        else {
                            x = false;
                        }
                    }
                    for (int i = 0; i < 5; i++) {                      ///to check there is no duplicate characters
                        for (int j = i + 1; j < 5; j++) {
                            if (key[i] == key[j]) {
                                x = false;
                            }
                        }
                    }
                    if (!x) {
                        cout << "Please enter 5 unique letters without numbers or Symbols: ";
                        continue;
                    }
                    if (x) {
                        break;
                    }
                }
                else {
                    cout << "Please enter 5 unique letters: ";
                }
            }
            ////////////////
           //To convert the characters in key to lowercase
            for (char& ch : key) {
                ch = tolower(ch);
            }

            //Add the key in cipher alphabet
            for (char ch : key) {
                new_alphabets.push_back(ch);
            }

            //Add the remaining 21 alphabets
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                auto it = find(new_alphabets.begin(), new_alphabets.end(), ch);  ///used this function to add alphabets in the vector (new_ alphabets) without duplicates
                if (it == new_alphabets.end()) {
                    new_alphabets.push_back(ch);
                }
            }

            //Get the message from the user

            cout << "Enter the message: ";
            getline(cin, message);        ///used getline function to read a line from the user


            //To convert all characters in variable message into lowercase

            for (char& ch : message) {     ///used the symbol (&) to modify on characters in the variable ( message ) 
                ch = tolower(ch);

            }
            //Encode the message 
            cout << "The Encrypt Message: ";
            for (char ch : message) {
                if (ch != ' ') {
                    auto k = find(alphabets.begin(), alphabets.end(), ch);
                    if (k != alphabets.end()) {
                        int index = distance(alphabets.begin(), k);   ///used this function to know the index of character in vector (alphabets)
                        cout << new_alphabets[index];
                    }
                }
                else if (ch == ' ') {
                    cout << " ";
                }
                else if (!isalpha(ch)) {
                    cout << "";
                }
            }
            cout << endl;
        }
        else if (choice == "2") {

            cout << "Enter key of 5 unique letters: ";
            ///to check the length of key and to make sure the letters is unique
            while (true) {
                x = true;
                cin >> key;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');   ///cin.ignore to make sure that the buffer is clear before the next input operation
                if (key.length() == 5) {
                    for (char ch : key) {                                  ///to check if the all characters in (key) is Alphabet
                        if (isalpha(ch)) {
                            x = true;
                        }
                        else {
                            x = false;
                        }
                    }
                    for (int i = 0; i < 5; i++) {                      ///to check there is no duplicate characters
                        for (int j = i + 1; j < 5; j++) {
                            if (key[i] == key[j]) {
                                x = false;
                            }
                        }
                    }
                    if (!x) {
                        cout << "Please enter 5 unique letters without numbers or Symbols: ";
                        continue;
                    }
                    if (x) {
                        break;
                    }
                }
                else {
                    cout << "Please enter 5 unique letters: ";
                }
            }
            ///////////////


           //To convert the characters in key to lowercase
            for (char& ch : key) {
                ch = tolower(ch);
            }

            //Add the key in cipher alphabet
            for (char ch : key) {
                new_alphabets.push_back(ch);
            }

            //Add the remaining 21 alphabets
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                auto it = find(new_alphabets.begin(), new_alphabets.end(), ch);  ///used this function to add alphabets in the vector (new_ alphabets) without duplicates
                if (it == new_alphabets.end()) {
                    new_alphabets.push_back(ch);
                }
            }

            //Get the message from the user

            cout << "Enter the message: ";
            getline(cin, message2);        ///used getline function to read a line from the user


            //To convert all characters in variable message into lowercase

            for (char& ch : message2) {     ///used the symbol (&) to modify on characters in the variable ( message2 ) 
                ch = tolower(ch);

            }
            //Decode the message 
            cout << "the decrypt message: ";
            for (char ch : message2) {
                if (ch != ' ') {
                    auto k = find(new_alphabets.begin(), new_alphabets.end(), ch);
                    if (k != new_alphabets.end()) {
                        int index = distance(new_alphabets.begin(), k);   ///used this function to know the index of character in vector (new_alphabets)
                        cout << alphabets[index];
                    }
                }
                else if (ch == ' ') {
                    cout << " ";
                }
                else if (!isalpha(ch)) {
                    cout << "";
                }
            }
            cout << endl;
        }
        else if (choice == "3") {
            cout << "Thank you!";
            break;
        }
        else {
            cout << "Please enter a right choice! "<<endl;
        }
    }
    return 0;
}
