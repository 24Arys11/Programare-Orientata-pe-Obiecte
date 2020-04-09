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

        if(s[i] == '-'){

            cout << "Numarul trebuie sa fie pozitiv !" << endl;
        }

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
    bool dotFound = false;

    string s;

    while(1){
        number = 0;
        dotDivision = 1;

        scanline(s);

        int i = 0;

        if(s[i] == '-'){

            cout << "Numarul trebuie sa fie pozitiv !" << endl;
        }

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

            if(dotFound == true){

                x = (number * 10) / dotDivision;

            }else{

                x = number;
            }
            return;
        }
    }
}

class Contract{
private:

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

    Contract(int nrContract, int anul, string beneficiar, string furnizor, double valoare){         /// CONSTRUCTOR PARAMETRIZAT

        this->nrContract = new int(nrContract);
        this->anul = new int(anul);
        this->beneficiar = new string(beneficiar);
        this->furnizor = new string(furnizor);
        this->valoare = new double(valoare);
    }

    Contract(Contract& c){         /// CONSTRUCTOR DE COPIERE

        this->nrContract = new int;
        this->nrContract = c.nrContract;
        this->anul = new int;
        this->anul = c.anul;
        this->beneficiar = new string;
        this->beneficiar = c.beneficiar;
        this->furnizor = new string;
        this->furnizor = c.furnizor;
        this->valoare = new double;
        this->valoare = c.valoare;
    }

    ~Contract(){        /// DECONSTRUCTOR

        delete nrContract;
        delete anul;
        delete beneficiar;
        delete furnizor;
        delete valoare;
    }

    Contract& operator=(Contract& c){

        this->nrContract = new int;
        this->nrContract = c.nrContract;
        this->anul = new int;
        this->anul = c.anul;
        this->beneficiar = new string;
        this->beneficiar = c.beneficiar;
        this->furnizor = new string;
        this->furnizor = c.furnizor;
        this->valoare = new double;
        this->valoare = c.valoare;
    }

    virtual double incasare() = 0;  /// aceasta functie trebuie neaaparat suprascrisa in clasa derivata "ContractInchiriere"

    friend class ContractInchiriere;
    friend class Dosar;
};

class ContractInchiriere : public Contract{
private:

    int *perioada;       /// perioada contractului exprimata in numar luni

public:

    static int haiSaLeNumaram;

    ContractInchiriere(){   /// CONSTRUCTOR

        haiSaLeNumaram++;
        perioada = new int;
    }

    ContractInchiriere(int perioada){   /// CONSTRUCTOR PARAMETRIZAT

        haiSaLeNumaram++;
        this->perioada = new int(perioada);
    }

    ContractInchiriere(ContractInchiriere& c){   /// CONSTRUCTOR DE COPIERE

        haiSaLeNumaram++;
        /// De celelalte variabile se ocupa constructorul de copiere din clasa pe care o mostenim !
        this->perioada = new int;
        this->perioada = c.perioada;
    }

    ~ContractInchiriere(){  /// DECONSTRUCTOR

        --haiSaLeNumaram;
        /// De celelalte variabile se ocupa constructorul de copiere din clasa pe care o mostenim !
        delete perioada;
    }

    ContractInchiriere& operator=(ContractInchiriere& c){

        //this->nrContract = new int;
        this->nrContract = c.nrContract;
        //this->anul = new int;
        this->anul = c.anul;
        //this->beneficiar = new string;
        this->beneficiar = c.beneficiar;
        //this->furnizor = new string;
        this->furnizor = c.furnizor;
        //this->valoare = new double;
        this->valoare = c.valoare;
        //this->perioada = new int;
        this->perioada = c.perioada;
    }

    void operator>>(int input){     /// Mi se pare aiurea ca ni se cere sa supraincarcam acesti operatori pe astfel de clase. Nu e un mod natural de a rezolva problema.
                                /// E hack-ish.. si alt programator nu va sti sa foloseasca acesti operatori intuitiv pe clasele astea. Ii supraincarc doar pentru
                                /// ca asa e cerinta, dar nu mi se pare ca are sens. Pe un graf, sau un linked list ar fi fost potrivit.

        if((input == 2) || (input == 1)){           /// Practic, 1 inseamna ca introducem tot. 2 - introducem doar nr de contract.. Nu are sens pt ceea ce vom face,
            cout << "Introduceti numarul contractului !" << endl; /// deoarece de fiecare data vom introduce tot, dar m-as simti vinovat sa ignor complet valoarea inputului..
            storeInt(*nrContract);
        }
        if((input == 3) || (input == 1)){
            cout << "Introduceti anul !" << endl;
            storeInt(*anul);
        }
        if((input == 4) || (input == 1)){
            cout << "Introduceti beneficiar !" << endl;
            scanline(*beneficiar);
        }
        if((input == 5) || (input == 1)){
            cout << "Introduceti furnizor !" << endl;
            scanline(*furnizor);
        }
        if((input == 6) || (input == 1)){
            cout << "Introduceti valoare !" << endl;
            storeDouble(*valoare);
        }
        if((input == 7) || (input == 1)){
            cout << "Introduceti perioada !" << endl;
            storeInt(*perioada);
        }
    }

    double incasare(){

        return (*valoare) * (double)(*perioada);
    }

    void operator<<(int input){

        for(int i = 0; i < input; i++){     /// Inputul corespunde numarului de exemplare (de cate ori printam poezia..

            cout << endl;
            cout << "Copia nr. " << (i + 1) << endl;
            cout << "Contractul nr. " << *nrContract << " a fost incheiat in " << *anul << "." << endl;
            cout << "Subsemnatul/subsemnata " << *beneficiar << " se angajeaza la plata sumei de " << *valoare << " lei pe luna, " << endl;
            cout << "pentru urmatoarele " << *perioada << " luni domnului/doamnei " << *furnizor << " reprezentand valoarea chiriei." << endl;
        }
    }

    friend class Dosar;
};

int ContractInchiriere::haiSaLeNumaram = 0;

class Dosar{
private:

    int cateContracte;
    ContractInchiriere *ci[100];

public:

    Dosar(){    /// CONSTRUCTOR

        cout << "Ati creat un dosar gol ! Puteti folosi functia \"initializare()\" pentru a specifica numarul de contracte !" << endl;
    }

    Dosar(int nrContracte){ /// CONSTRUCTOR PARAMETRIZAT

        cateContracte = nrContracte;

        for(int i = 0; i < nrContracte; i++){

            ci[i] = new ContractInchiriere;
        }
    }

    Dosar(Dosar& d){ /// CONSTRUCTOR DE COPIERE

        this->cateContracte = d.cateContracte;

        for(int i = 0; i < cateContracte; i++){

            ci[i] = new ContractInchiriere;

            ci[i]->nrContract = d.ci[i]->nrContract;
            ci[i]->anul = d.ci[i]->anul;
            ci[i]->beneficiar = d.ci[i]->beneficiar;
            ci[i]->furnizor = d.ci[i]->furnizor;
            ci[i]->valoare = d.ci[i]->valoare;
            ci[i]->perioada = d.ci[i]->perioada;
        }
    }

    ~Dosar(){   /// DECONSTRUCTOR

        delete[] ci;
    }

    void initializare(int nrContracte){

        cateContracte = nrContracte;

        for(int i = 0; i < nrContracte; i++){

            ci[i] = new ContractInchiriere;
        }
    }

    Dosar& operator=(Dosar& d){

        this->cateContracte = d.cateContracte;

        for(int i = 0; i < cateContracte; i++){

            ci[i] = new ContractInchiriere;

            ci[i]->nrContract = d.ci[i]->nrContract;
            ci[i]->anul = d.ci[i]->anul;
            ci[i]->beneficiar = d.ci[i]->beneficiar;
            ci[i]->furnizor = d.ci[i]->furnizor;
            ci[i]->valoare = d.ci[i]->valoare;
            ci[i]->perioada = d.ci[i]->perioada;
        }
    }

    void operator>>(int input){

        for(int i = 0; i < cateContracte; i++){

            cout << endl;
            cout << "CONTRACT " << (i + 1) << ":" << endl;
            *ci[i] >> input; /// folosim inputul pentru a alege ce variabila sa citim din contracte (1 = citim tot)
        }
    }       /// Daca am fi folosit inputul pentru a alege cate contracte vrem sa introducem, mai aveam nevoie de o variabila in plus in
            /// aceasta clasa, fata de cele din enunt pentru a memora pozitia la care am introdus ultima data, ca sa nu suprascriem contractele..

    void operator<<(int input){

        for(int i = 0; i < cateContracte; i++){

            cout << "CONTRACT " << (i + 1) << ":" << endl;
            *ci[i] << input;     /// folosim inputul pentru a afisa contractele (input = nr de copii)
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

    Dosar file(nrContracte);    /// verificam ca merge constructorul parametrizat

    file >> 1;  /// introducem contractele in dosar.

    Dosar g(file); /// verificam ca merge constructorul de copiere

    cout << endl;
    cout << "Atentie, urmatorul dosar pe care il vom crea se va supara ca nu il vom initializa si urmeaza sa ne atentioneze !" << endl;
    cout << "Domnule dosar, aveti onoarea:" << endl;
    cout << endl;

    Dosar h;

    cout << endl;
    cout << "Multumim, domnule dosar ! Acum, sa continuam.." << endl;
    cout << endl;

    h = g;      /// verificam ca merge operatorul "="

    h << 1; /// afisam contractele din h.

    /// h e copia lui g, iar g e copia lui file.
    /// daca merge h, inseamna ca merge si operatorul "=", si constructorul normal, si constructorul de copiere, si constructorul parametrizat..
    /// si operatorii ">>" respectiv "<<"..

    cout << endl;

    h.totalIncasari();

    cout << endl;

    cout << "Exista " << ContractInchiriere::haiSaLeNumaram << " contracte de inchiriere numarate cu variabila statica :D" << endl << endl;

    cout << "EXPLICATIE: Am creat 2 copii ale fisierului, deci trebuie sa avem de 3 ori mai multe contracte in sistem decat ati introdus !" << endl;

    return 0;
}
