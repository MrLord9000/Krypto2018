#include "FileInput.hpp"            //  Simple file input class
#include "platform-specific.hpp"    //  Windows or Linux specific commands such as clear/cls (unfinished)
#include "CarriageControl.hpp"      //  Simple external finctions for cursor manipulation and cleaner presentation
#include "BlockCreator.hpp"         //  First necessary cryptographic function, it contains functionality to convert strings into 64bit blocks

/*  ALL TO-DO THINGS:
 *  #include statements are probably duplicate between files in library
 *  Fix platform-specific functions to work with linux
 *  Add proper exception handling (in FileInput class).
 *  LoadFile adds an unnecessary space before data string.
 */

using namespace std;

int main()
{
    //  Changing console coding to UTF-8 
    UTF_8();
    //  Cleaning the console (from "platform-specific" lib)
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

    cout <<         "| How to load data?            |\n"
                    "| 1. File                      |\n"
                    "| 2. Manual                    |\n"
                    "| Choose:                      |\n"
                    "================================\n";
    gotoxy(10, 12); //  Tell the cursor to move next to "Choose: " in the cout message.
    char choice;
    cin >> choice;

/*  =======================================================================================
 *  Important string plainText definition.
 *  This variable will be used as a main container for plain text which will get encrypted.
 */
    string plainText;
//  =======================================================================================
    
/*  =======================================================================================
 *  Main switch with input choice. It either loads from a file or asks user for input.
 */
    switch(choice)
    {
        case '1':
        {
            //  Clearing the console
            cls();
            
            cout << "============================================================================\n"
                    "| Chosen input type: file                                                  |\n"
                    "| Input file path:                                                         |\n"
                    "| (WARNING! File path must be either absolute, or relative to your working |\n"
                    "| directory in terminal!)                                                  |\n"
                    "============================================================================\n";
            gotoxy(19, 2);
            /* Warning! This pseudo-window graphic style can get buggy if the input path is too long.
             * Either fix this in the future (ex. limit the max stream size) or remove it completely.
             */

            string path;
            cin >> path;    //  Getting the path from the user. 
            gotoxy(1, 6);

            //  File handling functions
            FileInput fileHandler(path); // Calling the parametric constructor and creating fileHandler object.
            fileHandler.loadFile(plainText); // Calling the loadFile member function. 

            cout << "@\tFile open succesful, proceeding in 3 s...";
            wait(3000); //  Simple Sleep(time) function defined platform-specific.

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

            cout << "@\tPlaintext input succesful, proceeding in 3 s...";
            wait(3000);
            break;
        }  
    }
/*
 *  End od SWITCH loading choice
 * ======================================================================================= */ 

    cls();
    cout << plainText << endl;

    /* 
     * Creating the Block class object called textBlock. This object will be responsible for
     * all the plain text block fragmentation and operations.
     */
    Block textBlock( plainText.c_str() );

    cout << "Test 64bitowego bloku: " << textBlock.getBlock();

    return 0;
}