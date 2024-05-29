//
//  funkcijos.h
//  egzaminas
//
//  Created by Kamilė Zobėlaitė on 2024-05-25.
//

#ifndef funkcijos_h
#define funkcijos_h
#include "biblioteka.h"
void skaityti(string pavadinimas, map<string, vector<int>>& zodziuSarasas, vector<string>& email, vector<string>& URL);
string pasalinti_ne_zodziu_simbolius(std::string ivestis);
bool yra_lietuviska_raide(char simbolis);
void kuriamMAP(string& zodis, int& eilNr, map<string, vector<int>>& zodziuSarasas);
void spausdinti(map<string, vector<int>> &zodziuSarasas, vector<string> &email, vector<string> &URL);
bool arEmail(string email);
bool yraGalimasLocalPart(string localPart);
bool yraGalimasUnquotedLocalPart(string localPart);
bool yraGalimasQuotedLocalPart(string localPart);
bool arSpausdinamasSimbolis(char simbolis);
bool yraGalimasDomain(string domainPart);
bool yraGalimasTLD(string tld);
bool arFailoPletinys(string zodis);
bool arURL(string zodis);
#endif /* funkcijos_h */
