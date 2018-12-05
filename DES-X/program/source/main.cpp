#include <iostream>

#include "Des.hpp"
#include "FileIO.hpp"
#include "CarriageControl.hpp"

using namespace std;

int main()
{
    //  Changing console coding to UTF-8 
    UTF_8();
    //  Cleaning the console (from "Misc" lib)
    cls();

    cout <<         "================================\n"
                    "| Podstawy kryptografii 2018   |\n"
                    "| Version: inDev 0.1           |\n"
                    "| Made by: Adriannna Dudek     |\n"
                    "|          Julita Włodarczyk   |\n"
                    "|          Filip Mazurek       |\n"
                    "================================\n"
                    "|  DES-X (Des Extended)        |\n"
                    "================================\n";
                    
    cout <<         "| What would you like to do?   |\n"
                    "| 1. Encrypt                   |\n"
                    "| 2. Decrypt                   |\n"
                    "| Choose:                      |\n"
                    "================================\n";
    gotoxy(10, 12); //  Tell the cursor to move next to "Choose: " in the cout message.
    char cryptChoice;
    cin >> cryptChoice;

    cout <<         "| How to load data?            |\n"
                    "| 1. File                      |\n"
                    "| 2. Manual                    |\n"
                    "| Choose:                      |\n"
                    "================================\n";
    gotoxy(10, 16); //  Tell the cursor to move next to "Choose: " in the cout message.
    char inputChoice;
    cin >> inputChoice;

/*  =======================================================================================
 *  Important string plainText and cryptogram definition.
 *  This variable will be used as a main container for plain text which will get encrypted.
 */
                string plainText;
                uint64_t cryptogram;
                string temp; // delete this
//  =======================================================================================

/*  =======================================================================================
 *  Important variables desxKeys definition.
 *  This variable will be used as a main container for manual key loading.
 */
                uint64_t desxKeys[3];
//  =======================================================================================
    
/*  =======================================================================================
 *  Main switch with input choice. It either loads from a file or asks user for input.
 */
 switch(cryptChoice)
 {
 case '1':
    cout << "=ENCRYPT====================================================================\n";
    switch(inputChoice)
    {
        case '1':
        {
            //  Clearing the console
            cls();
            
            cout << "============================================================================\n"
                    "| Chosen input type: file (enter for default file plainText.txt)           |\n"
                    "| Input file path:                                                         |\n"
                    "| (WARNING! File path must be either absolute, or relative to your working |\n"
                    "| directory in terminal!)                                                  |\n"
                    "============================================================================\n";
            gotoxy(19, 2);
            /* Warning! This pseudo-window graphic style can get buggy if the input path is too long.
             * Either fix this in the future (ex. limit the max stream size) or remove it completely.
             */

            string path;
            cin.get();  // Refreshing the cin stream for getline to work properly.
            getline(cin, plainText); // Getting the line of text typed by user.
            gotoxy(1, 6);

            if(path.empty())
            {
                path = "plainText.txt";
            }

            //  File handling functions
            FileInput fileHandler(path); // Calling the parametric constructor and creating fileHandler object.
            fileHandler.loadFromFile(plainText); // Calling the loadFile member function. 
            fileHandler.closeFile();
            cout << "@\tFile open succesful, proceeding in 1 s...";
            wait(1000); //  Simple Sleep(time) function defined platform-specific.

        break;
        }
            
        case '2':
        {
            //  Clearing the console.
            cls();

            cout << "============================================================================================\n"
                    "| Chosen input type: manual                                                                |\n"
                    "| Type your input:                                                                         |\n"
                    "============================================================================================\n";
            gotoxy(19, 2);
            /* Warning! This pseudo-window graphic style can get buggy if the input path is too long.
             * Either fix this in the future (ex. limit the max stream size) or remove it completely.
             */

            cin.get();  // Refreshing the cin stream for getline to work properly.
            getline(cin, plainText); // Getting the line of text typed by user.
            gotoxy(1, 4);

            cout << "@\tPlaintext input succesful, proceeding in 1 s...";
            wait(1000);
            break;
        }  
    }
 break;

 case '2':
    cout << "=DECRYPT====================================================================\n";
    switch(inputChoice)
    {
        case '1':
        {
            //  Clearing the console
            cls();
            
            cout << "============================================================================\n"
                    "| Chosen input type: file (Enter for default file cryptogram.txt)          |\n"
                    "| Input cryptogram file path:                                              |\n"
                    "| (WARNING! File path must be either absolute, or relative to your working |\n"
                    "| directory in terminal!)                                                  |\n"
                    "============================================================================\n";
            gotoxy(30, 2);
            /* Warning! This pseudo-window graphic style can get buggy if the input path is too long.
             * Either fix this in the future (ex. limit the max stream size) or remove it completely.
             */

            string path;
            cin.get();
            getline(cin, path);    //  Getting the path from the user. 
            gotoxy(1, 6);

            if(path.empty())
            {
                path = "cryptogram.txt";
            }

            //  File handling functions
            FileInput fileHandler(path); // Calling the parametric constructor and creating fileHandler object.
            fileHandler.loadFromFile(temp); // Calling the loadFile member function. 
            fileHandler.closeFile();
            cout << "============================================================================\n"
                    "| Input keys file path:                                                    |\n"
                    "| (Enter for default desxKeys.txt)                                         |\n"
                    "============================================================================\n";

            gotoxy(24, 7);

            path.erase();
            getline(cin, path);    //  Getting the path from the user. 
            gotoxy(1, 6);

            if(path.empty())
            {
                path = "desxKeys.txt";
            }
            //cls();
            //  File handling functions
            fileHandler.setPath(path); // Calling the parametric constructor and creating fileHandler object.
            for(int i = 0; i < 3; i++)
            {
                fileHandler.loadNumber(desxKeys[i]); // Calling the loadFile member function. 
                //cout << desxKeys[i] << endl;
            }
            fileHandler.closeFile();

            cout << "@\tFile open succesful, proceeding in 1 s...";
            wait(1000); //  Simple Sleep(time) function defined platform-specific.

        break;
        }
            
        case '2':
        {
            //  Clearing the console.
            cls();

            cout << "============================================================================================\n"
                    "| Chosen input type: manual                                                                |\n"
                    "| Paste your cryptogram input:                                                             |\n"
                    "============================================================================================\n";
            gotoxy(30, 2);
            /* Warning! This pseudo-window graphic style can get buggy if the input path is too long.
             * Either fix this in the future (ex. limit the max stream size) or remove it completely.
             */

            cin.get();  // Refreshing the cin stream for getline to work properly.
            //getline(cin, cryptogram); // Getting the line of text typed by user.
            cin >> cryptogram;
            cout << "| Paste your first key:                                                                    |\n"
                    "============================================================================================\n";
            gotoxy(24, 3);
            string temp;
            cin >> desxKeys[0];

            cout << "| Paste your second key:                                                                    |\n"
                    "============================================================================================\n";
            gotoxy(25, 4);
            cin >> desxKeys[1];

            cout << "| Paste your third key:                                                                    |\n"
                    "============================================================================================\n";
            gotoxy(24, 5);
            cin >> desxKeys[2];

            cout << "@\tPlaintext input succesful, proceeding in 1 s...";
            wait(1000);
            break;
        }  
    }
 break;
 }
/*
 *  End od SWITCH loading choice
 * ======================================================================================= */ 

    //cls();

    

    switch(cryptChoice)
    {
        case '1':
        // Encrypt
        {
            Des cryptEngineMain(plainText.c_str());
            for(int i = 0; i < 3; i++)
            {
                desxKeys[i] = cryptEngineMain.getBaseKey(i);
            }
            //cout << cryptEngineMain.currentBlock;
            //cryptogram = cryptEngineMain.fromBlock(cryptEngineMain.encrypt());
            uint64_t tempCryptogram = cryptEngineMain.encrypt();
            cout << "\nYour plaintext:\t\t" << plainText << "\n";
            cout << "Generated cryptogram:\t" << tempCryptogram << "\n";
            for(int i = 0; i < 3; i++)
            {
                cout << "Key " << i << ":\t" << desxKeys[i] << "\n";
            }
        }
        break;
        case '2':
        // Decrypt
        {
            Des cryptEngineMain(cryptogram);
            cryptEngineMain.setBaseKey(desxKeys[1], 1);
            cryptEngineMain.generateRoundKeys();
            cryptogram = cryptEngineMain.decrypt();
            cout << "\nYour cryptogram:\t\t" << cryptEngineMain.getCurrentBlockStr(cryptogram) << "\n";
            cout << "Generated plaintext:\t" << plainText << "\n";
            for(int i = 0; i < 3; i++)
            {
                cout << "Key " << i << ":\t" << desxKeys[i] << "\n";
            }
        }
        break;
    }

    return 0;
}