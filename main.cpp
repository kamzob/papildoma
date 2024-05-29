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
    string pavadinimas = "pa.txt";
    map<string, vector<int>> zodziuSarasas;
    vector<string> email;
    vector<string> URL;
    skaityti(pavadinimas, zodziuSarasas, email, URL);
    


}
