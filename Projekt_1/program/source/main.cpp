#include "FileInput.hpp"
#include "platform-specific.hpp"
#include "CarriageControl.hpp"

using namespace std;

int main()
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    system("cls");
    #endif //_WIN32

    cout <<         "================================\n"
                    "| Podstawy kryptografii 2018   |\n"
                    "| Version: inDev 0.01          |\n"
                    "| Made by: Adriannna Dudek     |\n"
                    "|          Julita Włodarczyk   |\n"
                    "|          Filip Mazurek       |\n"
                    "================================\n"
                    "|  DES-X (Des Extended)        |\n"
                    "================================\n";

    cout <<         "| How to load data?            |\n"
                    "| 1. File                      |\n"
                    "| 2. Manual                    |\n"
                    "| Choose:                      |\n"
                    "================================\n";
    gotoxy(10, 12);
    char choice;
    cin >> choice;

    string plainText;

    switch(choice)
    {
        case '1':
        {
            cls();
            
            cout << "============================================================================\n"
                    "| Chosen input type: file                                                  |\n"
                    "| Input file path:                                                         |\n"
                    "| (WARNING! File path must be either absolute, or relative to your working |\n"
                    "| directory in terminal!)                                                  |\n"
                    "============================================================================\n";
            gotoxy(19, 2);

            string path;
            cin >> path;
            gotoxy(1, 6);
            FileInput fileHandler(path);
            fileHandler.loadFile(plainText);

            cout << "@\tFile open succesful, proceeding in 4 s...";
            wait(4000);

        break;
        }
            
        case '2':
        {
            cls();

            cout << "============================================================================================\n"
                    "| Chosen input type: manual                                                                |\n"
                    "| Type your input:                                                                         |\n"
                    "============================================================================================\n";
            gotoxy(19, 2);

            cin >> plainText;
            gotoxy(1, 4);

            cout << "@\tPlaintext input succesful, proceeding in 4 s...";
            wait(4000);
            break;
        }  
    }
    cls();
    cout << plainText;

    return 0;
}