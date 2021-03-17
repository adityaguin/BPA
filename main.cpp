// Contestant ID: 39989

#include <iostream>
#include <string>

using namespace std;

// Caesar_Cipher class with class variables and functions encrypt and decrypt
class Caesar_Cipher{
public:
    string input, answer; // input is the original string, answer is the encrypted string
                          // answer is used for decryption into original string
    int shift_amount;
    void encrypt(); // Function to encrypt the input string
    void decrypt(); // Function to decrypt the encrypted string
};

// Encrypting the input string
void Caesar_Cipher::encrypt(){
    for(int i = 0; i < input.size(); ++i){
        if(input[i]>=97 && input[i]<=122){
            int t1 = (int)(input[i]) + shift_amount;
            t1 = ((t1 % 97) % 26) + 97; // Need to take care of shifting z one over using mod
            answer += (char)(t1);
        }
        else{
            int t1 = (int)(input[i]) + shift_amount;
            t1 = ((t1 % 65) % 26) + 65;
            answer += (char)(t1);
        }

    }
    cout << "The encrypted value is: " << answer << endl;
}

void Caesar_Cipher::decrypt(){
    string secondanswer; // Used for decrypting the encrypted string
    for(int i = 0; i < answer.size(); ++i){
        if(answer[i]>=97 && answer[i]<=122){
            int t1 = (int)(answer[i]) + (26-shift_amount); // Shifting left by x == shifting right
            t1 = ((t1 % 97) % 26) + 97;                    // by 26-x places
            secondanswer += (char)(t1);
        }
        else{
            int t1 = (int)(answer[i]) + (26-shift_amount);
            t1 = ((t1 % 65) % 26) + 65;
            secondanswer += (char)(t1);
        }

    }
    cout << "When decrypted again the result is: " << secondanswer << endl << endl;
}

int main()
{
    Caesar_Cipher c1;

    while(1){
        c1.answer = "";
        cout << "Enter a word to encrypt (or EXIT to close application): ";
        cin >> c1.input;
        // If user enters EXIT, the program stops
        if(c1.input == "EXIT"){
            system("PAUSE");
            break;
        }
        cout << "Enter an amount to shift the input by (must be between 1 and 5): ";
        cin >> c1.shift_amount;
        while(c1.shift_amount < 1 || c1.shift_amount > 5){
            cout << "Enter an amount to shift the input by (must be between 1 and 5): ";
            cin >> c1.shift_amount;
        }
        cout << endl;
        // Calling the class methods for encryption and decryption of string entered
        c1.encrypt();
        c1.decrypt();
    }
    return 0;
}
