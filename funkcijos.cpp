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
                    cout << zodis << endl;
                    zodziai.push_back(zodis);

                }
            }
            
        }
        else break;
    }
    failas.close();
  
    
   
}
