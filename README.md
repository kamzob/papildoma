# papildoma
## Užduoties formuluotė:

* Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: Vikipedijos straipsnis apie Vilnių (geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių, nereikia traukti straipsnio programiškai, užtenka nukopijuoti ir įkelti į apdorojamą failą). Tuomet realizacijos išoriniame faile išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
* Sukurkite failą su cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
* URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, tačiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/, https://vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt, vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir gražiai išvesti į failą. Repozitorija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.
## Kas padaryta?
Programa isrenka ir isspausdina zodzius, kurie tekste kartojasi daugiau nei viena karta, tam naudojamas ascoaityvus konteineris ``map<string, vector<int>> zodziuSarasas``, kuris saugo zodzius bei eilutes, kuriose tas zodis kartojasi. Taip pat programa geba atrinkti email adresus, URL ir viska isspausdina i faila ``rez.txt``.

# Naudojimo instrukcija
1. Parsisiųskite programą iš [versijų puslapio](https://github.com/kamzob/papildoma/tags), o jei kažkas neaišku, pridedu nuorodą: https://blog.hubspot.com/website/download-from-github. Jums reikia šių failų: **makefile, main.cpp, biblioteka.h, funkcijos.cpp, funkcijos.h**
2. Parsisiųskite ir įsidiekite C++ kompiliatorių (jei esate windows naudotojas pridedu nuorodą su žingsniais: https://medium.com/@samsorrahman/how-to-run-a-makefile-in-windows-b4d115d7c516)
3. Parsisiųskite (jei esate MacBook naudotojas) Xcode: https://www.youtube.com/watch?v=LBYj-xVvM1k, o visoms OS tinka Visual Studio: https://www.youtube.com/watch?v=DMWD7wfhgNY.
4. Tuomet jei naudojat MacBook, nueinate į ta aplanką, kuriame yra visi parsisiųsti failai, spaudžiate dešinį pelės klavišą ir Open in terminal: 
<img width="234" alt="Screenshot 2024-03-19 at 23 16 19" src="https://github.com/kamzob/ojektinis1/assets/149818908/9e516c7d-9673-4cc8-aea2-fd1eafef7e11">

5. Jei esat kitos OS naudotojai, tai nukopijuojat pathname, atsidarote terminalą, rašote cd ir įklijuojate kelią iki jūsų aplankalo.
6. Tada galit parašyti ls, spaudžiate enter ir turėtumėte matyti visus failus, esančius jūsų aplanke.
7. Instrukcija macbook (UNIX) naudotojams:
   
   Įrašykite į terminalą:  make pagrindine, spauskite enter
   
   Įrašykite į terminalą:  make funkcijos, spauskite enter
   
   Įrašykite į terminalą:  make prog, spauskite enter
    
   Įrašykite į terminalą:  ./prog, spauskite enter
   
8. Instrukcija Windows naudotojams:

   Įrašykite į terminalą:  mingw32-make pagrindine, spauskite enter

   Įrašykite į terminalą:  mingw32-make funkcijos, spauskite enter

   Įrašykite į terminalą:  mingw32-make prog, spauskite enter

   Įrašykite į terminalą:  ./prog, spauskite enter
