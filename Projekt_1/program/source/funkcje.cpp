#include <iostream>
#include <fstream>
#include <cstdlib>

#include "naglowek.h"

// Adrianna Dudek, Filip Mazurek i Julita Wlodarczyk

using namespace std;

void jak_dane()
{
    cout << "Wprowadz w jaki sposob chcesz podawac dane, \n 1 - przez plik \n 2 - w terminalu " << endl; 
    short int jak;
    cin >> jak;
    if(jak != 1 || jak != 2) cout << "Wprowadziles bledna dana. Mozesz wpisac tylko 1 lub 2" << endl;

    switch(jak)
    {
        case 1: 
        cout << "Wybrales wprowadzanie przez plik " << endl;
        fstream plik;
        plik.open ("tekst.txt" , ios::in);
        if(plik.good()==false)
        {
            cout<< "Wystapil blad przy odczycie pliku" << endl;
            exit(0);
        }
         //przepisywanie z pliku do zmiennej
        plik.close();
        

        case 2:
        cout << "Wybrales wprowadzanie w terminalu " <<endl;
        cout << "Wprowadz tekst ktory chcesz zaszyfrowac"<<endl;
       // cin >> tekst;

    }

    //cout << "Twoj tekst to: " << tekst <<endl;

}