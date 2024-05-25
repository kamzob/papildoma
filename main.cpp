//
//  main.cpp
//  egzaminas
//
//  Created by Kamilė Zobėlaitė on 2024-05-25.
//

#include <iostream>
#include <string>
#include <map>
#include "funkcijos.h"

using namespace  std;

int main()
{
    string pavadinimas = "vilnius.txt";
    skaityti(pavadinimas);
    map<string, string> myDictionary;

    myDictionary.insert(pair<string, string>("zasis", "žąsiukas"));
    myDictionary.insert(pair<string, string>("banana", "die Banane"));
    for(auto pair : myDictionary)
    {
        cout << pair.first << "-" << pair.second << endl;
    }

}
