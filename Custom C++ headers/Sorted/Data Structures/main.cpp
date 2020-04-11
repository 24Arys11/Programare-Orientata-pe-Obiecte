#include "data_structures.h"
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace dtk;

void scanline(string &s){

    scanf(" ");
    getline(cin, s);
}

void storeInt(int &x){

    int number;
    bool negative = false;

    string s;

    while(1){
        number = 0;
        scanline(s);
        int i = 0;

        if(s[i] == '-'){

            negative = true;
            i++;
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

            if(negative == false){
                x = number;
            }else{
                x = -number;
            }
            return;
        }
    }
}

void storeDouble(double &x){

    double number;
    double dotDivision;
    bool dotFound = false;
    bool negative = false;

    string s;

    while(1){
        number = 0;
        dotDivision = 1;

        scanline(s);

        int i = 0;

        if(s[i] == '-'){

            negative = true;
            i++;
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

                if(negative == false){
                    x = number;
                }else{
                    x = -number;
                }
            }
            return;
        }
    }
}

void testList(){

    LinkedList<int> *l = new LinkedList<int>;
    LinkedList<int> *k = new LinkedList<int>;

    int nrOfOperations;
    int input;
    int input2;
    int item;
    int position;

    while(input != 0){

        cout << endl;
        cout << "INTEGER TYPE:" << endl;

        cout << "list l: ";
        l->check();
        cout << "list k: ";
        k->check();
        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false):" << endl;
        cout << "(l == k) = " << (*l == *k) << "; (l != k) = " << (*l != *k) << "; (l < k) = " << (*l < *k) << "; (l > k) = " << (*l > *k) << "; (l <= k) = " << (*l <= *k) << "; (l >= k) = " << (*l >= *k) << "." << endl;
        cout << endl;
        cout << " 1. print: l.length()                    6. l = k                     11. (l - k).check()" << endl;
        cout << " 2. l.in(T item, int position)           7. l << x                    12. l -= k" << endl;
        cout << " 3. l.out(int position)                  8. l >> x                    13. l.sort()" << endl;
        cout << " 4. l.empty()                            9. (l + k).check()           14. l.fuse(k)" << endl;
        cout << " 5. Afiseaza: l[x]                      10. l += k" << endl;
        cout << " 0. EXIT !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l->length() << endl;
            cout << "k.length() = " << k->length() << endl;

        }else if(input == 2){

            cout << "01. l.in(T item, int position)" << endl;
            cout << "02. k.in(T item, int position)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "item = ";
                        storeInt(item);
                        cout << "position = ";
                        storeInt(position);
                        l->in(item, position);
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "item = ";
                        storeInt(item);
                        cout << "position = ";
                        storeInt(position);
                        k->in(item, position);
                    }

                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }


        }else if(input == 3){

            cout << "01. l.out(int position)" << endl;
            cout << "02. k.out(int position)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "position = ";
                        storeInt(position);
                        l->out(position);
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "position = ";
                        storeInt(position);
                        k->out(position);

                    }

                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 4){

            cout << "01. l.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l->empty();
                    break;

                }else if(input2 == 2){

                    k->empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout<< "01. Afiseaza: l[x]" << endl;
            cout<< "02. Afiseaza: k[x]" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = ";
                    storeInt(position);
                    cout << "l[x] = " << (*l)[position] << endl;

                    break;

                }else if(input2 == 2){

                    cout << "x = ";
                    storeInt(position);
                    cout << "k[x] = " << (*k)[position] << endl;

                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 6){

            cout << "01. l = k" << endl;
            cout << "02. k = l" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    *l = *k;
                    break;

                }else if(input2 == 2){

                    *k = *l;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 7){

            cout << "01. l << x" << endl;
            cout << "02. k << x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeInt(item);
                        *l << item;

                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeInt(item);
                        *k << item;

                    }

                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 8){

            cout << "01. l >> x" << endl;
            cout << "02. k >> x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeInt(item);
                        *l >> item;
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeInt(item);
                        *k >> item;
                    }

                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "01. (l + k).check()" << endl;
            cout << "02. (k + l).check()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    (*l + *k).check();
                    break;

                }else if(input2 == 2){

                    (*k + *l).check();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 10){

            cout << "01. l += k" << endl;
            cout << "02. k += l" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    *l += *k;
                    break;

                }else if(input2 == 2){

                    *k += *l;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. (l - k).check()" << endl;
            cout << "02. (k - l).check()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    (*l - *k).check();
                    break;

                }else if(input2 == 2){

                    (*k - *l).check();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l -= k" << endl;
            cout << "02. k -= l" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    *l -= *k;
                    break;

                }else if(input2 == 2){

                    *k -= *l;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. l.sort()" << endl;
            cout << "02. k.sort()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l->sort();
                    break;

                }else if(input2 == 2){

                    k->sort();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.fuse(k)" << endl;
            cout << "02. k.fuse(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l->fuse(*k);
                    break;

                }else if(input2 == 2){

                    k->fuse(*l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete l;
    delete k;

    return;
}

int main(){

    int input;

    while(input != 0){

        cout << "LINKED-LIST DIAG:" << endl;
        cout << "1. Begin !" << endl;
        cout << "0. EXIT !" << endl;

        storeInt(input);

        if(input == 0){

            break;

        }else if(input == 1){

            testList();

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    /// Operatorul ">>" adauga elementele la locul lor (in ordine), daca lista este deja sortata.

    /// What you can do:

    /// l >> element; - baga un element intr-o lista sortata, la locul potrivit ! (lista ramane sortata)

    /// l << element; - Cauta si sterge elementul din lista. (indiferent de pozitia pe care se afla)

    /// l.print(); - afiseaza lista si spune cate elemente are.

    /// l.check(); - afiseaza lista si spune cate elemente are. afiseaza detalii despre primul element (adresa) si ultimul element (adresa, data, *next) (next trebuie sa fie 0, adica pointerul NULL, pt ca daca e ultumul, nu mai exista alt element dupa el)

    /// l.in(type item, int pozitie); - Adauga elementul "item" la pozitia "pozitie", numarand de la zero. (type trebuie sa fie tipul listei ! De ex. pentru "LinkedList <int> l;" e tip int)

    /// l.out(int pozitie); - Sterge elementul de pe pozitia "pozitie" din lista ! (numarand de la 0)
                        /// - Exista si un shortcut l.out(-1); sterge elementul de pe ultima pozitie, ca sa nu mai apelezi l.length()... NU merge cu alte numere negative sau invalide..

    /// l[2].data << endl; - l[n] Returneaza nodul de pe pozitia n; Putem accesa l[n].data sau l[n].next. La fel ca la vectori, n trebuie sa fie o pozitie valida (n < nr de elemente) !

    /// l.sortare(); - Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) ! merge si cu stringuri, orice tip de date. (inclusiv custom made, daca are operatorii de comparatie definiti).

    /// COMPARARE A 2 LISTE CU ELEM DE ACELASI TIP: (returneaza true sau false, adica 1 sau 0)
            /// l1 == l2    l1 != l2    l1 < l2     l1 > l2     l1 <= l2    l1 >= l2

    /// ATRIBUIRE l1 = l2;

    /// CONSTRUCTOR DE COPIERE: LinkedList <any type> l1 = l2; (l2 trebuie sa fie de acelasi tip). La initializare nu functioneaza operatorul de atribuire ! Este nevoie de constructor de copiere..



    return 0;
}
