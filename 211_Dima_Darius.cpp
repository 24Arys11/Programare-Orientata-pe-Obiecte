#include <iostream>
#include <stdio.h>  /// pentru scanf() - "stabilizeaza" functia getline !
#include <string>

using namespace std;

/*
Tema 8. Sa se defineasca clasa Contract care contine membrii privati
- nrContract (numar contract)
- anul (anul semnarii contractului de cumparare)
- beneficiar (numele cumparatorului/beneficiarului)
- furnizor (nume vanzator/ofertant/furnizor)
- valoare (valoarea totala a produsului)
Sa se deriveze clasa ContractInchiriere din Contract avand in plus ca membru privat
- perioada (perioada contractului exprimata in numar luni)
Definiti clasa Dosar care contine un vector de pointeri la obiecte de tip ContractInchiriere si un numar
de contracte de inchiriere.
Se citesc contractele din dosar, se afiseaza si se cere sa se calculeze valoarea incasata pentru fiecare
contract in functie de perioada, respectiv valoarea totala incasata
*/
void scanline(string &s){

    scanf(" ");
    getline(cin, s);
}

void storeInt(int &x){

    int number;

    string s;

    while(1){
        number = 0;
        scanline(s);

        int i = 0;
        while(s[i] != '\0'){    /// verificam daca stringul contine doar cifre.

            if(!((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9'))){

                cout << "Introduceti, va rog un integer:" << endl;
                break;

            }else{

                number = number * 10 + ((int)s[i] - 48);    /// pentru ca: '0' = 48, '1' = 49 ...
            }
            i++;
        }
        if(s[i] == '\0'){

            x = number;
            return;
        }
    }
}

void storeDouble(double &x){

    double number;
    double dotDivision;
    bool dotFound = 0;

    string s;

    while(1){
        number = 0;
        dotDivision = 1;
        scanline(s);

        int i = 0;
        while(s[i] != '\0'){    /// verificam daca stringul contine doar cifre.

            if(!((s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9') || (s[i] == '.'))){

                cout << "Introduceti, va rog un numar:" << endl;
                break;

            }else{

                if(s[i] == '.'){

                    if(dotFound == true){

                        cout << "Introduceti, va rog un numar:" << endl;
                        dotFound = false;
                        break;
                    }else{

                        dotFound = true;
                    }
                }

                if(dotFound == true){

                    dotDivision *= 10;
                }

                if(s[i] != '.'){
                    number = number * 10 + (double)((int)s[i] - 48);    /// pentru ca: '0' = 48, '1' = 49 ...
                }
            }
            i++;
        }
        if(s[i] == '\0'){

            x = (number * 10) / dotDivision;
            return;
        }
    }
}

class Contract{
protected:

    int *nrContract;     /// numar contract
    int *anul;           /// anul semnarii contractului de cumparare
    string *beneficiar;  /// numele cumparatorului/beneficiarului
    string *furnizor;    /// nume vanzator/ofertant/furnizor
    double *valoare;     /// valoarea totala a produsului

public:

    Contract(){         /// CONSTRUCTOR

        nrContract = new int;
        anul = new int;
        beneficiar = new string;
        furnizor = new string;
        valoare = new double;
    }

    ~Contract(){        /// DECONSTRUCTOR

        delete nrContract;
        delete anul;
        delete beneficiar;
        delete furnizor;
        delete valoare;
    }

};

class ContractInchiriere : protected Contract{
protected:

    int *perioada;       /// perioada contractului exprimata in numar luni

public:

    ContractInchiriere(){   /// CONSTRUCTOR

        perioada = new int;
    }

    ~ContractInchiriere(){  /// DECONSTRUCTOR

        delete perioada;
    }

    void completeaza(){

        cout << "Introduceti nrContract !" << endl;
        storeInt(*nrContract);
        cout << "Introduceti anul !" << endl;
        storeInt(*anul);
        cout << "Introduceti beneficiar !" << endl;
        scanline(*beneficiar);
        cout << "Introduceti furnizor !" << endl;
        scanline(*furnizor);
        cout << "Introduceti valoare !" << endl;
        storeDouble(*valoare);
        cout << "Introduceti perioada !" << endl;
        storeInt(*perioada);
    }

    double incasare(){

        return (*valoare) * (double)(*perioada);
    }

    void afisare(){

        cout << endl;
        cout << "Contractul nr. " << *nrContract << " a fost incheiat in " << *anul << "." << endl;
        cout << "Subsemnatul/subsemnata " << *beneficiar << " se angajeaza la plata sumei de " << *valoare << " lei pe luna, " << endl;
        cout << "pentru urmatoarele " << *perioada << " luni domnului/doamnei " << *furnizor << " reprezentand valoarea chiriei." << endl;
        cout << endl;
    }
};

class Dosar{
private:

    int cateContracte;
    ContractInchiriere *ci[100];

public:

    Dosar(int nrContracte){

        cateContracte = nrContracte;
        //*ci = new ContractInchiriere[nrContracte];

        for(int i = 0; i < nrContracte; i++){

            ci[i] = new ContractInchiriere;
        }
    }

    ~Dosar(){

        delete[] ci;
    }

    void citesteContracte(){

        for(int i = 0; i < cateContracte; i++){

            cout << "CONTRACT " << (i + 1) << ":" << endl;
            ci[i]->completeaza();
        }
    }

    void afiseazaContracte(){

        for(int i = 0; i < cateContracte; i++){

            cout << "CONTRACT " << (i + 1) << ":" << endl;
            ci[i]->afisare();
            cout << "Incasari: " << ci[i]->incasare() << endl;
        }
    }

    void totalIncasari(){

        double sum = 0;
        for(int i = 0; i < cateContracte; i++){

            sum += ci[i]->incasare();
        }
        cout << "Total incasari: " << sum << " !" << endl;
    }
};

///     Se citesc contractele din dosar, se afiseaza si se cere sa se calculeze valoarea incasata pentru fiecare
/// contract in functie de perioada, respectiv valoarea totala incasata

int main()
{
    int nrContracte;

    cout << "Numarul de contracte de inchiriere din dosar:" << endl;
    storeInt(nrContracte); /// Putem implementa o verificare sa vedem daca utilizatorul introduce string sau float sau altcv, dar pt asta negociem o marire de salariu :))

    Dosar file(nrContracte);

    file.citesteContracte();

    file.afiseazaContracte();

    cout << endl;

    file.totalIncasari();

    cout << endl;

    return 0;
}
