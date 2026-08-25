#include <iostream>
#include <string>
using namespace std;

// Function that encodes the given text using the specified shift
void encode(string* p, int* shift)
{
    *shift %= 26;
    for (auto Letter = p->begin(); Letter != p->end(); ++Letter)
    {
        if (*Letter >= 'a' && *Letter <= 'z')
        {
            *Letter = 'a' + (*Letter - 'a' + *shift) % 26;
        }
        else if (*Letter >= 'A' && *Letter <= 'Z')
        {
            *Letter = 'A' + (*Letter - 'A' + *shift) % 26;
        }
    }
}
// Function that decodes the encoded text and restores the original text
void decode(string* p, int* shift)
{
    *shift %= 26;
    for (auto Letter = p->begin(); Letter != p->end(); ++Letter)
    {
        if (*Letter >= 'a' && *Letter <= 'z')
        {
            *Letter = 'a' + (*Letter - 'a' - *shift + 26) % 26;
        }

        if (*Letter >= 'A' && *Letter <= 'Z')
        {
            *Letter = 'A' + (*Letter - 'A' - *shift + 26) % 26;
        }
    }
}

int main()
{
    // Dynamically allocated variables for the passphrase, choice, and shift
    string* passphrase = new string;
    // The text entered by the user
    int* choice = new int;
    // The user's choice between encoding and decoding
    int* shift = new int;
    // The shift value used for encoding or decoding
    // Run the program in a loop until the user enters 'q'
    while (true)
    {
        cout << "Enter a passphrase(q to quit): ";
        // Read the passphrase entered by the user
        getline(cin, *passphrase);
        if (*passphrase == "q")
            break;
        // Choose between encoding and decoding
        cout << "Select an operation : " << endl
            << "1. Encode" << endl
            << "2. Decode" << endl
            << "Enter your choice(1 / 2) : ";

        cin >> *choice;
        cout << "Enter a shift : ";
        cin >> *shift;

        // Run the encode function if choice is 1,
        // otherwise run the decode function
        if (*choice == 1)
        {
            encode(passphrase, shift);
            cout << "Encoded passphrase : "
                << *passphrase << endl;
        }
        else
        {
            decode(passphrase, shift);
            cout << "Decoded passphrase : "
                << *passphrase << endl;
        }
        // Clear the input buffer so getline() works correctly
        cin.ignore();
    }

    // Free the dynamically allocated memory
    delete passphrase;
    delete choice;
    delete shift;
}