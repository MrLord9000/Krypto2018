#include "FileInput.hpp"
#include "platform-specific.hpp"

using namespace std;

int main()
{
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif //_WIN32

    cout <<         "==============================\n"
                    "| Podstawy kryptografii 2018 |\n"
                    "| Version: inDev 0.01        |\n"
                    "| Made by: Adriannna Dudek   |\n"
                    "|          Julita Włodarczyk |\n"
                    "|          Filip Mazurek     |\n"
                    "==============================\n"
                    "|  DES-X (Des Extended)      |\n"
                    "==============================\n";

    FileInput fileHandler("A:\\Kod_projekty\\Krypto_Repo\\Krypto2018\\Projekt_1\\testText.txt");
    string plainText;
    fileHandler.loadFile(plainText);
    cout << plainText;
    fileHandler.closeFile();

    return 0;
}