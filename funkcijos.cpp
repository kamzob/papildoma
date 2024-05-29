//
//  funkcijos.cpp
//  egzaminas
//
//  Created by Kamilė Zobėlaitė on 2024-05-25.
//

#include "funkcijos.h"

void skaityti(string pavadinimas, map<string, vector<int>>& zodziuSarasas, vector<string>& email, vector<string>& URL)
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
    int kelinta = 0;        // kelinta eilute
    vector<string> zodziai;
    while(failas){
        if(!failas.eof()){
            getline(failas,eilute);
            kelinta++;
            if(!eilute.empty()){
                istringstream iss(eilute);
                string zodis;
                while (iss>>zodis) {
                    if(arEmail(zodis))
                    {
                        email.push_back(zodis);
                    }
                    else if (arURL(zodis))
                    {
                        URL.push_back(zodis);
                    }
                    else{
                        transform(zodis.begin(), zodis.end(), zodis.begin(), ::tolower);
                        string rezultatas;
                        rezultatas = pasalinti_ne_zodziu_simbolius(zodis);
                        kuriamMAP(rezultatas, kelinta, zodziuSarasas);
                    }

                }
            }
            
        }
        else break;
    }
    spausdinti(zodziuSarasas, email, URL);
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
void kuriamMAP(string& zodis, int& eilNr, map<string, vector<int>>& zodziuSarasas)
{
    if(zodis.empty())
        return;
    auto it = zodziuSarasas.find(zodis);
    if(it==zodziuSarasas.end())
    {
        vector<int> eilutes;
        eilutes.push_back(eilNr);
        zodziuSarasas.insert(pair<string, vector<int>>(zodis,eilutes));
        zodziuSarasas[zodis]=eilutes;
    }
    else it->second.push_back(eilNr);
    
}
void spausdinti(map<string, vector<int>> &zodziuSarasas, vector<string> &email, vector<string> &URL)
{
    ofstream fr("rez.txt");
    try {
     if (!fr)
         throw runtime_error("Rezultatu failas neegzistuoja arba nepasiekiamas.");
    } catch(const std::exception& e) {
        cerr << "Klaida: " << e.what() << endl;
     return;
 }
    fr << left << setw(25) << "Zodis" << setw(25) << "Pasikartojimai" << "Eilutes" << endl;
    fr << string(75, '-') << endl;

    for(const auto& pair: zodziuSarasas) {
        if(pair.second.size() > 1) {
            fr << left << setw(25) << pair.first << setw(25) << pair.second.size();
            for (const auto& eil : pair.second) {
                fr  << eil << " ";
            }
            fr << endl;
        }
    }
    fr << "Email: " << endl;
    for(auto e: email)
    {
        fr << e << endl;
    }
    fr << "URL: " << endl;
    for(auto u: URL)
    {
        fr << u << endl;
    }
    fr.close();
}
bool arEmail(string email)
{
    size_t etaVieta = email.find('@');
        if (etaVieta == string::npos || etaVieta == 0 || etaVieta == email.size() - 1) {
            return false;
        }

        string localPart = email.substr(0, etaVieta);
        string domainPart = email.substr(etaVieta + 1);
    return yraGalimasLocalPart(localPart) && yraGalimasDomain(domainPart);
    
}
bool yraGalimasLocalPart(string localPart) {
    if (localPart.size() > 64) {
        return false;
    }
    if (localPart.front() == '.' || localPart.back() == '.') {
            return false;
        }
        for (size_t i = 0; i < localPart.size(); ++i) {
            char c = localPart[i];
            if (!(isalnum(c) || arSpausdinamasSimbolis(c)|| (c == '.' && i > 0 && i < localPart.size() - 1 && localPart[i-1] != '.'))) {
                return false;
            }
        }
        return true;
}
bool yraGalimasTLD(string tld)
{
    for (char c : tld) {
        if (!isalpha(c)) { // Tikrina, ar simbolis yra raidė
            return false;
        }
    }
    return true;
}
bool yraGalimasDomain(string domainPart)
{
    if (domainPart.empty() || domainPart.size() > 255)
    {
            return false;
    }
    if (domainPart.front() == '.' || domainPart.back() == '.')
    {
            return false;
    }
    size_t paskutinis_tsk = 0;
    for(size_t i = domainPart.size()-1; i > 0; i--)
    {
        if (domainPart[i] == '.') {
            paskutinis_tsk = i;
            break;
        }
    }
    string TLD = domainPart.substr(paskutinis_tsk+1);
    if(!yraGalimasTLD(TLD))
    {
        return false;
    }
    if (paskutinis_tsk == 0) {
            return false; // Jei paskutinio taško nerasta, domenas neturi TLD ir todėl yra netinkamas
        }
    
    
    size_t labelStart = 0;  // subdomeno pradzia
    bool allNumericLabel = true;  // ar subdomenas tik is skaiciu nes taip buti negali
    bool prevCharWasDot = false;  // ar bv taskas pries tai
    for (size_t i = 0; i <= domainPart.size(); ++i) {
        if (i == domainPart.size() || domainPart[i] == '.') {
            size_t labelLength = i - labelStart;
            if (labelLength == 0 || labelLength > 63) {
                return false;
            }
            if (domainPart[labelStart] == '-' || domainPart[i - 1] == '-') {
                return false;
            }
            for (size_t j = labelStart; j < i; ++j) {
                char c = domainPart[j];
                if (!isalnum(c) && c != '-') {
                    return false;
                }
                if (!isdigit(c)) {
                allNumericLabel = false;
                                }
            }
            labelStart = i + 1;
        }
            if (domainPart[i] == '.' && prevCharWasDot) {
                return false; // Tikrinama, ar nėra dviejų iš eilės einančių taškų
            }
            prevCharWasDot = (domainPart[i] == '.');
        }

    return !allNumericLabel;
}

bool arSpausdinamasSimbolis(char simbolis)
{
    string spausdinamisimboliai = "!#$%&'*+-/=?^_`{|}~";
    return spausdinamisimboliai.find(simbolis) != std::string::npos;
}
bool arFailoPletinys(string zodis)
{
    set<string> pletiniai = {".txt", ".pdf", ".doc", ".docx", ".xls", ".xlsx", ".png", ".jpg", ".jpeg", ".gif", ".zip", ".rar"};
    for (const string& pletinys : pletiniai)
    {
        if (zodis.size() >= pletinys.size() && zodis.compare(zodis.size() - pletinys.size(), pletinys.size(), pletinys) == 0)
        {
            return true;
        }
    }
    return false;
}

bool arURL(string zodis)
{
    if(arFailoPletinys(zodis)||arEmail(zodis))
    {
        return false;
    }
    if (zodis.front() == '.' ||zodis.back()=='.'||zodis.find('.') == string::npos || zodis.back()==',')
    {
        return false;
    }
    set<string> galimiTLD = {".com", ".org", ".net", ".int", ".edu", ".gov", ".mil", ".lt", ".ai", ".io", ".co", ".us", ".arpa"};
    
    for (const string& pletinys : galimiTLD)
    {
        if (zodis.size() >= pletinys.size() && zodis.compare(zodis.size() - pletinys.size(), pletinys.size(), pletinys) == 0)
        {
            return true;
        }
    }
   if(zodis.find("https://") != string::npos || zodis.find("www.") != string::npos || zodis.find("http://"))
   {
       return true;
   }
    return false;

    
}
