//
//  funkcijos.cpp
//  egzaminas
//
//  Created by Kamilė Zobėlaitė on 2024-05-25.
//

#include "funkcijos.h"

void skaityti(string pavadinimas)
{
    ifstream failas(pavadinimas);
    try {
         if (!failas)
             throw runtime_error("Failas neegzistuoja arba nepasiekiamas.");
     } catch(const std::exception& e) {
         cerr << "Klaida: " << e.what() << endl;
         return;
     }
    string eilute;
    vector<string> zodziai;
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            if(!eilute.empty()){
                istringstream iss(eilute);
                string zodis;
                while (iss>>zodis) {
                    
                    transform(zodis.begin(), zodis.end(), zodis.begin(), ::tolower);
                    cout << zodis << " ";
                    string rezultatas;
                    rezultatas = pasalinti_ne_zodziu_simbolius(zodis);
                    cout << rezultatas << endl;
                    zodziai.push_back(zodis);

                }
            }
            
        }
        else break;
    }
    failas.close();
  
}
std::string pasalinti_ne_zodziu_simbolius(std::string ivestis) {
    std::string rezultatas;

    for (char simbolis : ivestis) {
        if ((std::isalnum(simbolis) && !isdigit(simbolis)) || yra_lietuviska_raide(simbolis)) { // Patikriname, ar simbolis yra žodžio simbolis
            rezultatas += simbolis;
        }
    }

    return rezultatas;
}
bool yra_lietuviska_raide(char simbolis) {
    // Lietuviškos raidės su diakritiniais ženklais
    std::string lietuviskos_raides = "ąčęėįšųūž";
    return lietuviskos_raides.find(simbolis) != std::string::npos;
}
