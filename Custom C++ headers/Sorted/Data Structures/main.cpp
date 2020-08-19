/// Code Blocks

#include "data_structures.h"
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace dtk;    /// Darius The King...

string fit(string s, int level){

    if(s.length() > 5)
    s.erase(s.begin()+5, s.end());

    int spaceAround = 0;

    for(int i = 0; i < level; i++){

        spaceAround = spaceAround * 2 + 3;
    }

    if(s.length() == 0)
        s = " NULL ";
    else if(s.length() == 1)
        s = "   " + s + "  ";
    else if(s.length() == 2)
        s = "  " + s + "  ";
    else if(s.length() == 3)
        s = "  " + s + " ";
    else if(s.length() == 4)
        s = " " + s + " ";
    else if(s.length() == 5)
        s = " " + s;

    for(int i = 0; i < spaceAround; i++){

        s = " " + s + " ";
    }
    return s;
}

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

        if((s[i] == '\0') && (negative == true)){

            i--;
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

        if((s[i] == '\0') && (negative == true)){

            i--;
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

void testListInteger(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    LList<int> l;
    LList<int> *k = new LList<int>;

    l.err = -1;
    k->err = -1;

    int nrOfOperations;
    int input = 1;
    int input2;
    int item;
    int position;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "INTEGER TYPE:" << endl;

        cout << "list l: ";
        l.check();
        cout << "list k: ";
        k->check();
        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false):" << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << "; (l < k) = " << (l < *k) << "; (l > k) = " << (l > *k) << "; (l <= k) = " << (l <= *k) << "; (l >= k) = " << (l >= *k) << "." << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.push(x)" << endl;
        cout << " 2. l.in(T item, int position)            8. l >> x                      15. l.qpush(x)" << endl;
        cout << " 3. l.out(int position)                   9. l.err = x                   16. l.top()" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.pop()" << endl;
        cout << " 5. Afiseaza: l[x]                       11. l.fuse(k)" << endl;
        cout << " 6. l = k                                12. l.eject(k)" << endl;
        cout << " 0. BACK !                               13. l.sort()                    18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
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
                        l.in(item, position);
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
                        l.out(position);
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

                    l.empty();
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
                    cout << "l[x] = " << l[position] << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        l << item;

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
                        l >> item;
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

            cout << "l.err = " << endl;
            storeInt(item);
            l.err = item;
            cout << "k.err = " << endl;
            storeInt(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.fuse(k)" << endl;
            cout << "02. k.fuse(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.fuse(*k);
                    break;

                }else if(input2 == 2){

                    k->fuse(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
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

                    l.sort();
                    break;

                }else if(input2 == 2){

                    k->sort();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.push(x)" << endl;
            cout << "02. k.push(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    l.push(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k->push(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.qpush(x)" << endl;
            cout << "02. k.qpush(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    l.qpush(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k->qpush(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "l.top() = " << l.top() << endl;
            cout << "k.top() = " << k->top() << endl;

        }else if(input == 17){

            cout << "01. l.pop()" << endl;
            cout << "02. k.pop()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.pop();
                    break;

                }else if(input2 == 2){

                    k->pop();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din lista (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x intr-o lista sortata la pozitia corespunzatoare." << endl;
            cout << "        Daca lista nu este sortata, x va fi plasat inainte de primul element > x" << endl;
            cout << " l.in(T item, int position) - insereaza elementul \"item\" in lista, la pozitia \"pozitie\"" << endl;
            cout << "                            (Shortcut: pozitie = -1 <=> ultima pozitie)" << endl;
            cout << " l.out(int position) - scoate elementul de la pozitia \"position\" din lista (Shortcut: -1)" << endl;
            cout << " l.empty() - goleste lista !     l.sort() - sorteaza lista     l.check() - l.print(), dar cu mai multe detalii." << endl;
            cout << " l.fuse(k) - combina listele l si k in l. (l ramane sortata daca l si k erau sortate anterior)" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l.qpush(x) - in(item, -1)   |   l.push(x) - in(item, 0)   |   l.pop() - out(0)   |   l.top() - return l[0]" << endl;
            cout << " [qpush+pop+top - folosim lista precum o coada]; [push+pop+top - folosim lista precum o stiva]" << endl;
            cout << " Afiseaza: l[x] - returneaza elementul de la pozitia x din lista. (Shortcut: l[-1], returneaza ultimul element)" << endl;
            cout << " Daca x nu e un parametru valid returneaza l.err (variabila publica, de tip T)" << endl;
            cout << " LISTA ARE SI ALTE FUNCTIONALITATI, PRECUM ABILITATEA DE A FACE CAST EXPLICIT IN AVL<T>," << endl;
            cout << " ABILITATEA DE A FORMA O LISTA FOLOSIND UN VECTOR (ARRAY) CU ELEMENTE DE ACELASI TIP" << endl;
            cout << " COPIINDU-L PARTIAL SAU INTEGRAL. SAU DE A SCRIE UN AVL DAT CA PARAMETRU LA FUNCTIA \"assign(AVL<T>&)\"" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testListDouble(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    LList<double> l;
    LList<double> *k = new LList<double>;

    l.err = -1.3;
    k->err = -1.3;

    int nrOfOperations;
    int input = 1;
    int input2;
    double item;
    int position;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "DOUBLE TYPE:" << endl;

        cout << "list l: ";
        l.check();
        cout << "list k: ";
        k->check();
        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false):" << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << "; (l < k) = " << (l < *k) << "; (l > k) = " << (l > *k) << "; (l <= k) = " << (l <= *k) << "; (l >= k) = " << (l >= *k) << "." << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.push(x)" << endl;
        cout << " 2. l.in(T item, int position)            8. l >> x                      15. l.qpush(x)" << endl;
        cout << " 3. l.out(int position)                   9. l.err = x                   16. l.top()" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.pop()" << endl;
        cout << " 5. Afiseaza: l[x]                       11. l.fuse(k)" << endl;
        cout << " 6. l = k                                12. l.eject(k)" << endl;
        cout << " 0. BACK !                               13. l.sort()                    18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
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
                        storeDouble(item);
                        cout << "position = ";
                        storeInt(position);
                        l.in(item, position);
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "item = ";
                        storeDouble(item);
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
                        l.out(position);
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

                    l.empty();
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
                    cout << "l[x] = " << l[position] << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        storeDouble(item);
                        l << item;

                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeDouble(item);
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
                        storeDouble(item);
                        l >> item;
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeDouble(item);
                        *k >> item;
                    }

                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "l.err = " << endl;
            storeDouble(item);
            l.err = item;
            cout << "k.err = " << endl;
            storeDouble(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.fuse(k)" << endl;
            cout << "02. k.fuse(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.fuse(*k);
                    break;

                }else if(input2 == 2){

                    k->fuse(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
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

                    l.sort();
                    break;

                }else if(input2 == 2){

                    k->sort();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.push(x)" << endl;
            cout << "02. k.push(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    l.push(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k->push(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.qpush(x)" << endl;
            cout << "02. k.qpush(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    l.qpush(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k->qpush(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "l.top() = " << l.top() << endl;
            cout << "k.top() = " << k->top() << endl;

        }else if(input == 17){

            cout << "01. l.pop()" << endl;
            cout << "02. k.pop()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.pop();
                    break;

                }else if(input2 == 2){

                    k->pop();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din lista (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x intr-o lista sortata la pozitia corespunzatoare." << endl;
            cout << "        Daca lista nu este sortata, x va fi plasat inainte de primul element > x" << endl;
            cout << " l.in(T item, int position) - insereaza elementul \"item\" in lista, la pozitia \"pozitie\"" << endl;
            cout << "                            (Shortcut: pozitie = -1 <=> ultima pozitie)" << endl;
            cout << " l.out(int position) - scoate elementul de la pozitia \"position\" din lista (Shortcut: -1)" << endl;
            cout << " l.empty() - goleste lista !     l.sort() - sorteaza lista     l.check() - l.print(), dar cu mai multe detalii." << endl;
            cout << " l.fuse(k) - combina listele l si k in l. (l ramane sortata daca l si k erau sortate anterior)" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l.qpush(x) - in(item, -1)   |   l.push(x) - in(item, 0)   |   l.pop() - out(0)   |   l.top() - return l[0]" << endl;
            cout << " [qpush+pop+top - folosim lista precum o coada]; [push+pop+top - folosim lista precum o stiva]" << endl;
            cout << " Afiseaza: l[x] - returneaza elementul de la pozitia x din lista. (Shortcut: l[-1], returneaza ultimul element)" << endl;
            cout << " Daca x nu e un parametru valid returneaza l.err (variabila publica, de tip T)" << endl;
            cout << " LISTA ARE SI ALTE FUNCTIONALITATI, PRECUM ABILITATEA DE A FACE CAST EXPLICIT IN AVL<T>," << endl;
            cout << " ABILITATEA DE A FORMA O LISTA FOLOSIND UN VECTOR (ARRAY) CU ELEMENTE DE ACELASI TIP" << endl;
            cout << " COPIINDU-L PARTIAL SAU INTEGRAL. SAU DE A SCRIE UN AVL DAT CA PARAMETRU LA FUNCTIA \"assign(AVL<T>&)\"" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testListString(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    LList<string> l;
    LList<string> *k = new LList<string>;

    l.err = "err";
    k->err = "err";

    int nrOfOperations;
    int input = 1;
    int input2;
    string item;
    int position;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "STRING TYPE:" << endl;

        cout << "list l: ";
        l.check();
        cout << "list k: ";
        k->check();
        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false):" << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << "; (l < k) = " << (l < *k) << "; (l > k) = " << (l > *k) << "; (l <= k) = " << (l <= *k) << "; (l >= k) = " << (l >= *k) << "." << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.push(x)" << endl;
        cout << " 2. l.in(T item, int position)            8. l >> x                      15. l.qpush(x)" << endl;
        cout << " 3. l.out(int position)                   9. l.err = x                   16. l.top()" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.pop()" << endl;
        cout << " 5. Afiseaza: l[x]                       11. l.fuse(k)" << endl;
        cout << " 6. l = k                                12. l.eject(k)" << endl;
        cout << " 0. BACK !                               13. l.sort()                    18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
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
                        scanline(item);
                        cout << "position = ";
                        storeInt(position);
                        l.in(item, position);
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "item = ";
                        scanline(item);
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
                        l.out(position);
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

                    l.empty();
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
                    cout << "l[x] = " << l[position] << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        scanline(item);
                        l << item;

                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        scanline(item);
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
                        scanline(item);
                        l >> item;
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        scanline(item);
                        *k >> item;
                    }

                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "l.err = " << endl;
            scanline(item);
            l.err = item;
            cout << "k.err = " << endl;
            scanline(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.fuse(k)" << endl;
            cout << "02. k.fuse(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.fuse(*k);
                    break;

                }else if(input2 == 2){

                    k->fuse(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
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

                    l.sort();
                    break;

                }else if(input2 == 2){

                    k->sort();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.push(x)" << endl;
            cout << "02. k.push(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    l.push(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k->push(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.qpush(x)" << endl;
            cout << "02. k.qpush(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    l.qpush(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k->qpush(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "l.top() = " << l.top() << endl;
            cout << "k.top() = " << k->top() << endl;

        }else if(input == 17){

            cout << "01. l.pop()" << endl;
            cout << "02. k.pop()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.pop();
                    break;

                }else if(input2 == 2){

                    k->pop();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din lista (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x intr-o lista sortata la pozitia corespunzatoare." << endl;
            cout << "        Daca lista nu este sortata, x va fi plasat inainte de primul element > x" << endl;
            cout << " l.in(T item, int position) - insereaza elementul \"item\" in lista, la pozitia \"pozitie\"" << endl;
            cout << "                            (Shortcut: pozitie = -1 <=> ultima pozitie)" << endl;
            cout << " l.out(int position) - scoate elementul de la pozitia \"position\" din lista (Shortcut: -1)" << endl;
            cout << " l.empty() - goleste lista !     l.sort() - sorteaza lista     l.check() - l.print(), dar cu mai multe detalii." << endl;
            cout << " l.fuse(k) - combina listele l si k in l. (l ramane sortata daca l si k erau sortate anterior)" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l.qpush(x) - in(item, -1)   |   l.push(x) - in(item, 0)   |   l.pop() - out(0)   |   l.top() - return l[0]" << endl;
            cout << " [qpush+pop+top - folosim lista precum o coada]; [push+pop+top - folosim lista precum o stiva]" << endl;
            cout << " Afiseaza: l[x] - returneaza elementul de la pozitia x din lista. (Shortcut: l[-1], returneaza ultimul element)" << endl;
            cout << " Daca x nu e un parametru valid returneaza l.err (variabila publica, de tip T)" << endl;
            cout << " LISTA ARE SI ALTE FUNCTIONALITATI, PRECUM ABILITATEA DE A FACE CAST EXPLICIT IN AVL<T>," << endl;
            cout << " ABILITATEA DE A FORMA O LISTA FOLOSIND UN VECTOR (ARRAY) CU ELEMENTE DE ACELASI TIP" << endl;
            cout << " COPIINDU-L PARTIAL SAU INTEGRAL. SAU DE A SCRIE UN AVL DAT CA PARAMETRU LA FUNCTIA \"assign(AVL<T>&)\"" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testAVLInteger(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    AVL<int> l;
    AVL<int> *k = new AVL<int> ;

    l.err = -1;
    k->err = -1;

    /// pentru a printa parcurgerile BFS, RSD, SRD, SDR care se stocheaza in vectori,
    /// deoarece poate vrem sa facem altceva in loc sa le printam pe ecran..
    int v[1000];

    bool lDraw = true;
    bool kDraw = false;

    int nrOfOperations;
    int input = 1;
    int input2;
    int item;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "INTEGER TYPE:" << endl;

        if(lDraw == true){

            l.print(fit);
            cout << endl;
        }else{

            cout << "l DRAWING: OFF" << endl;
        }

        l.bfs(v);
        cout << "l.bfs(v): ";

        for(int i = 0; i < l.length(); i++){

            cout << v[i] << " ";
        }

        cout << endl;

        if(kDraw == true){

            k->print(fit);
            cout << endl;
        }else{

            cout << "k DRAWING: OFF" << endl;
        }

        k->bfs(v);
        cout << "k.bfs(v): ";

        for(int i = 0; i < k->length(); i++){

            cout << v[i] << " ";
        }
        cout << endl;

        cout << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << ";" << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.bfs(v)" << endl;
        cout << " 2. l DRAWING: ";
        if(lDraw == true){ cout << "ON ";}else{cout << "OFF";}
        cout << "                        8. l >> x                      15. l.rsd(v)" << endl;
        cout << " 3. k DRAWING: ";
        if(kDraw == true){ cout << "ON ";}else{cout << "OFF";}
        cout << "                        9. l.err = x                   16. l.srd(v)" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.sdr(v)" << endl;
        cout << " 5. l.search(x)                          11. l.eject(k)" << endl;
        cout << " 6. l = k                                12. l.min" << endl;
        cout << " 0. BACK !                               13. l.max                       18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
            cout << "k.length() = " << k->length() << endl;

        }else if(input == 2){

            lDraw = !lDraw;

        }else if(input == 3){

            kDraw = !kDraw;

        }else if(input == 4){

            cout << "01. l.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.empty();
                    break;

                }else if(input2 == 2){

                    k->empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout<< "01. l.search(x)" << endl;
            cout<< "02. k.search(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = ";
                    storeInt(item);
                    cout << "l.search(x) = " << l.search(item) << endl;

                    break;

                }else if(input2 == 2){

                    cout << "x = ";
                    storeInt(item);
                    cout << "k.search(x) = " << k->search(item) << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        l << item;
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
                        l >> item;
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

            cout << "l.err = " << endl;
            storeInt(item);
            l.err = item;
            cout << "k.err = " << endl;
            storeInt(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.min()" << endl;
            cout << "02. k.min()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.min() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->min() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. l.max()" << endl;
            cout << "02. k.max()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.max() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->max() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.bfs(v)   /// v - array of int" << endl;
            cout << "02. k.bfs(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.bfs(v);
                    cout << "l.bfs(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->bfs(v);
                    cout << "k.bfs(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.rsd(v)   /// v - array of int" << endl;
            cout << "02. k.rsd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.rsd(v);
                    cout << "l.rsd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->rsd(v);
                    cout << "k.rsd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. l.srd(v)   /// v - array of int" << endl;
            cout << "02. k.srd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.srd(v);
                    cout << "l.srd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->srd(v);
                    cout << "k.srd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. l.sdr(v)   /// v - array of int" << endl;
            cout << "02. k.sdr(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.sdr(v);
                    cout << "l.sdr(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->sdr(v);
                    cout << "k.sdr(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din AVL (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x in AVL" << endl;
            cout << " l.print(string (*f)(string, int)) = Deseneaza arborele ! It's a masterpiece !" << endl;
            cout << " l.length() - returneaza numarul de elemente" << endl;
            cout << " l.empty() - goleste arborele !" << endl;
            cout << " l[x] - cauta elementul x in AVL si returneaza true sau false" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l = k - copiaza arborele k in l !" << endl;
            cout << " l.expand(k) - adauga elementele lui k in l" << endl;
            cout << " l.eject(k) - scoate elementele lui k din l" << endl;
            cout << " Parcurgerile: l.bfs(v), l.rsd(v), l.srd(v) si l.sdr(v) stocheaza rezultatul in vectorul v" << endl;
            cout << " Astfel pot fi folosite pentru numeroase aplicatii, nu doar pt printarea in consola." << endl;
            cout << " l.min() - returneaza minimul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " l.max() - returneaza maximul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " " << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testAVLDouble(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    AVL<double> l;
    AVL<double> *k = new AVL<double> ;

    l.err = -1.03;
    k->err = -1.03;

    /// pentru a printa parcurgerile BFS, RSD, SRD, SDR care se stocheaza in vectori,
    /// deoarece poate vrem sa facem altceva in loc sa le printam pe ecran..
    double v[1000];

    bool lDraw = true;
    bool kDraw = false;

    int nrOfOperations;
    int input = 1;
    int input2;
    double item;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "DOUBLE TYPE:" << endl;

        if(lDraw == true){

            l.print(fit);
            cout << endl;
        }else{

            cout << "l DRAWING: OFF" << endl;
        }

        l.bfs(v);
        cout << "l.bfs(v): ";

        for(int i = 0; i < l.length(); i++){

            cout << v[i] << " ";
        }

        cout << endl;

        if(kDraw == true){

            k->print(fit);
            cout << endl;
        }else{

            cout << "k DRAWING: OFF" << endl;
        }

        k->bfs(v);
        cout << "k.bfs(v): ";

        for(int i = 0; i < k->length(); i++){

            cout << v[i] << " ";
        }
        cout << endl;

        cout << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << ";" << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.bfs(v)" << endl;
        cout << " 2. l DRAWING: ";
        if(lDraw == true){ cout << "ON ";}else{cout << "OFF";}
        cout << "                        8. l >> x                      15. l.rsd(v)" << endl;
        cout << " 3. k DRAWING: ";
        if(kDraw == true){ cout << "ON ";}else{cout << "OFF";}
        cout << "                        9. l.err = x                   16. l.srd(v)" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.sdr(v)" << endl;
        cout << " 5. l.search(x)                          11. l.eject(k)" << endl;
        cout << " 6. l = k                                12. l.min" << endl;
        cout << " 0. BACK !                               13. l.max                       18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
            cout << "k.length() = " << k->length() << endl;

        }else if(input == 2){

            lDraw = !lDraw;

        }else if(input == 3){

            kDraw = !kDraw;

        }else if(input == 4){

            cout << "01. l.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.empty();
                    break;

                }else if(input2 == 2){

                    k->empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout<< "01. l.search(x)" << endl;
            cout<< "02. k.search(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = ";
                    storeDouble(item);
                    cout << "l.search(x) = " << l.search(item) << endl;

                    break;

                }else if(input2 == 2){

                    cout << "x = ";
                    storeDouble(item);
                    cout << "k.search(x) = " << k->search(item) << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        storeDouble(item);
                        l << item;
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeDouble(item);
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
                        storeDouble(item);
                        l >> item;
                    }
                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        storeDouble(item);
                        *k >> item;
                    }
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "l.err = " << endl;
            storeDouble(item);
            l.err = item;
            cout << "k.err = " << endl;
            storeDouble(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.min()" << endl;
            cout << "02. k.min()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.min() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->min() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. l.max()" << endl;
            cout << "02. k.max()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.max() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->max() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.bfs(v)   /// v - array of int" << endl;
            cout << "02. k.bfs(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.bfs(v);
                    cout << "l.bfs(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->bfs(v);
                    cout << "k.bfs(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.rsd(v)   /// v - array of int" << endl;
            cout << "02. k.rsd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.rsd(v);
                    cout << "l.rsd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->rsd(v);
                    cout << "k.rsd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. l.srd(v)   /// v - array of int" << endl;
            cout << "02. k.srd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.srd(v);
                    cout << "l.srd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->srd(v);
                    cout << "k.srd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. l.sdr(v)   /// v - array of int" << endl;
            cout << "02. k.sdr(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.sdr(v);
                    cout << "l.sdr(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->sdr(v);
                    cout << "k.sdr(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din AVL (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x in AVL" << endl;
            cout << " l.print(string (*f)(string, int)) = Deseneaza arborele ! It's a masterpiece !" << endl;
            cout << " l.length() - returneaza numarul de elemente" << endl;
            cout << " l.empty() - goleste arborele !" << endl;
            cout << " l[x] - cauta elementul x in AVL si returneaza true sau false" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l = k - copiaza arborele k in l !" << endl;
            cout << " l.expand(k) - adauga elementele lui k in l" << endl;
            cout << " l.eject(k) - scoate elementele lui k din l" << endl;
            cout << " Parcurgerile: l.bfs(v), l.rsd(v), l.srd(v) si l.sdr(v) stocheaza rezultatul in vectorul v" << endl;
            cout << " Astfel pot fi folosite pentru numeroase aplicatii, nu doar pt printarea in consola." << endl;
            cout << " l.min() - returneaza minimul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " l.max() - returneaza maximul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " " << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testAVLString(){

    /// Sometimes we'll use pointers, sometimes we don't. Just to mix things up...
    AVL<string> l;
    AVL<string> *k = new AVL<string> ;

    l.err = "err";
    k->err = "err";

    /// pentru a printa parcurgerile BFS, RSD, SRD, SDR care se stocheaza in vectori,
    /// deoarece poate vrem sa facem altceva in loc sa le printam pe ecran..
    string v[1000];

    bool lDraw = true;
    bool kDraw = false;

    int nrOfOperations;
    int input = 1;
    int input2;
    string item;
    string useless;

    while(input != 0){

        cout << endl;
        cout << "STRING TYPE:" << endl;

        cout << "DRAWING: Unavailable" << endl;

        l.bfs(v);
        cout << "l.bfs(v): ";

        for(int i = 0; i < l.length(); i++){

            cout << v[i] << " ";
        }

        cout << endl;

        cout << "DRAWING: Unavailable" << endl;

        k->bfs(v);
        cout << "k.bfs(v): ";

        for(int i = 0; i < k->length(); i++){

            cout << v[i] << " ";
        }
        cout << endl;

        cout << endl;
        cout << "(l == k) = " << (l == *k) << "; (l != k) = " << (l != *k) << ";" << endl;
        cout << endl;
        cout << " 1. print: l.length()                     7. l << x                      14. l.bfs(v)" << endl;
        cout << " 2. DRAWING: Unavailable                  8. l >> x                      15. l.rsd(v)" << endl;
        cout << " 3. DRAWING: Unavailable                  9. l.err = x                   16. l.srd(v)" << endl;
        cout << " 4. l.empty()                            10. l.expand(k)                 17. l.sdr(v)" << endl;
        cout << " 5. l.search(x)                          11. l.eject(k)" << endl;
        cout << " 6. l = k                                12. l.min" << endl;
        cout << " 0. BACK !                               13. l.max                       18. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "l.length() = " << l.length() << endl;
            cout << "k.length() = " << k->length() << endl;

        }else if(input == 2){

            lDraw = !lDraw;

        }else if(input == 3){

            kDraw = !kDraw;

        }else if(input == 4){

            cout << "01. l.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.empty();
                    break;

                }else if(input2 == 2){

                    k->empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout<< "01. l.search(x)" << endl;
            cout<< "02. k.search(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = ";
                    scanline(item);
                    cout << "l.search(x) = " << l.search(item) << endl;

                    break;

                }else if(input2 == 2){

                    cout << "x = ";
                    scanline(item);
                    cout << "k.search(x) = " << k->search(item) << endl;

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

                    l = *k;
                    break;

                }else if(input2 == 2){

                    *k = l;
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
                        scanline(item);
                        l << item;
                    }

                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        scanline(item);
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
                        scanline(item);
                        l >> item;
                    }
                    break;

                }else if(input2 == 2){

                    cout << "De cate ori executati operatia ?" << endl;

                    storeInt(nrOfOperations);

                    for(int i = 0; i < nrOfOperations; i++){    /// Daca nrOfOperations <= 0, nu se executa niciodata

                        cout << "x = ";
                        scanline(item);
                        *k >> item;
                    }
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "l.err = " << endl;
            scanline(item);
            l.err = item;
            cout << "k.err = " << endl;
            scanline(item);
            k->err = item;

        }else if(input == 10){

            cout << "01. l.expand(k)" << endl;
            cout << "02. k.expand(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.expand(*k);
                    break;

                }else if(input2 == 2){

                    k->expand(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 11){

            cout << "01. l.eject(k)" << endl;
            cout << "02. k.eject(l)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.eject(*k);
                    break;

                }else if(input2 == 2){

                    k->eject(l);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. l.min()" << endl;
            cout << "02. k.min()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.min() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->min() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. l.max()" << endl;
            cout << "02. k.max()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << l.max() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k->max() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. l.bfs(v)   /// v - array of int" << endl;
            cout << "02. k.bfs(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.bfs(v);
                    cout << "l.bfs(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->bfs(v);
                    cout << "k.bfs(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. l.rsd(v)   /// v - array of int" << endl;
            cout << "02. k.rsd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.rsd(v);
                    cout << "l.rsd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->rsd(v);
                    cout << "k.rsd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. l.srd(v)   /// v - array of int" << endl;
            cout << "02. k.srd(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.srd(v);
                    cout << "l.srd(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->srd(v);
                    cout << "k.srd(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. l.sdr(v)   /// v - array of int" << endl;
            cout << "02. k.sdr(v)   ///   creat anterior" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    l.sdr(v);
                    cout << "l.sdr(v): ";

                    for(int i = 0; i < l.length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else if(input2 == 2){

                    k->sdr(v);
                    cout << "k.sdr(v): ";

                    for(int i = 0; i < k->length(); i++){

                        cout << v[i] << " ";
                    }
                    cout << endl;
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << " l << x - scoate elementul x din AVL (daca este dublura, il scoate doar pe primul)" << endl;
            cout << " l >> x - insereaza elementul x in AVL" << endl;
            cout << " l.print(string (*f)(string, int)) = Deseneaza arborele ! It's a masterpiece !" << endl;
            cout << " l.length() - returneaza numarul de elemente" << endl;
            cout << " l.empty() - goleste arborele !" << endl;
            cout << " l[x] - cauta elementul x in AVL si returneaza true sau false" << endl;
            cout << " l.err = x - seteaza variabila de returnat in caz de eroare (o masura de siguranta)"<< endl;
            cout << " l = k - copiaza arborele k in l !" << endl;
            cout << " l.expand(k) - adauga elementele lui k in l" << endl;
            cout << " l.eject(k) - scoate elementele lui k din l" << endl;
            cout << " Parcurgerile: l.bfs(v), l.rsd(v), l.srd(v) si l.sdr(v) stocheaza rezultatul in vectorul v" << endl;
            cout << " Astfel pot fi folosite pentru numeroase aplicatii, nu doar pt printarea in consola." << endl;
            cout << " l.min() - returneaza minimul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " l.max() - returneaza maximul sau returneaza valoarea err, daca arborele este gol" << endl;
            cout << " " << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    delete k;   /// k is a pointer, l is not !

    return;
}

void testGraphInteger(){

    UnWGraph<int> g;
    UnWGraph<int> k;

    g.setErr(-1);
    k.setErr(-1);

    ///int nrOfOperations;
    int input = 1;
    int input2;
    int item;
    int item2;
    string useless;

    bool gShow = true;
    bool kShow = false;

    LList<int> l;

    while(input != 0){

        cout << endl;
        cout << "INTEGER TYPE:" << endl;

        if(gShow == true){

            cout << endl;
            g.print();
        }

        if(kShow == true){

            cout << endl;
            k.print();
        }

        cout << endl;
        cout << "g.order = " << g.order() << "; g.size = " << g.size() << "; k.order = " << k.order() << "; k.seize = " << k.size() << "." << endl;

        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false): [NOT WORKING YET !]" << endl;
        cout << "(g == k) = " << (g == k) << "; (g != k) = " << (g != k) << "; (g < k) = " << (g < k) << "; (g > k) = " << (g > k) << "; (g <= k) = " << (g <= k) << "; (g >= k) = " << (g >= k) << "." << endl;
        cout << endl;
        cout << " 1. g.order()                        10. g.setErr(x)                      20. g.regular()" << endl;
        cout << " 2. g.size()                         11. g.setDirected()                  21. g.isSimple()" << endl;
        cout << " 3. g.clear()                        12. g >> x                           22. g.isBipartite()" << endl;
        cout << " 4. g.empty()                        13. g << x                           23. g.hasCycle()" << endl;
        cout << " 5. g.rebirth()                      14. g.insertEdge(x1, x2)             24. g.hasCmpCycle(x)" << endl;
        cout << " 6. g.complete()                     15. g.removeEdge(x1, x2)             25. g.connectedCmp()" << endl;
        cout << " 7. g.deg(x)                         16. g.replace(x1, x2)                26. g.kosaraju()" << endl;
        cout << " 8. g.neighbors(x, list/array)       17. g.bfs(x, list/array)             27. g: ";
        if(gShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 9. g = k                            18. g.dfs(x, list/array)             28. k: ";
        if(kShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 0. BACK !                           19. g.topSort(list/array)            29. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "g.order() = " << g.order() << endl;
            cout << "k.order() = " << k.order() << endl;

        }else if(input == 2){

            cout << "g.size() = " << g.size() << endl;
            cout << "k.size() = " << k.size() << endl;

        }else if(input == 3){

            cout << "01. g.clear()" << endl;
            cout << "02. k.clear()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.clear();
                    break;

                }else if(input2 == 2){

                    k.clear();
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 4){

            cout << "01. g.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.empty();
                    break;

                }else if(input2 == 2){

                    k.empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout << "01. g.rebirth()" << endl;
            cout << "02. k.rebirth()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.rebirth();
                    break;

                }else if(input2 == 2){

                    k.rebirth();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 6){

            cout << "01. g.complete()" << endl;
            cout << "02. k.complete()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.complete();
                    break;

                }else if(input2 == 2){

                    k.complete();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 7){

            cout << "01. g.deg(x)" << endl;
            cout << "02. k.deg(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g.deg(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k.deg(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 8){

            cout << "01. g.neighbors(x, list/array)" << endl;
            cout << "02. k.neighbors(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g.neighbors(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k.neighbors(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "01. g = k" << endl;
            cout << "02. k = g" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g = k;
                    break;

                }else if(input2 == 2){

                    k = g;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 10){

            cout << "g.setErr(x); x = " << endl;
            storeInt(item);
            g.setErr(item);
            cout << "k.setErr(x); x = " << endl;
            storeInt(item);
            k.setErr(item);

        }else if(input == 11){

            cout << "01. g.setDirected()" << endl;
            cout << "02. k.setDirected()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.setDirected();
                    break;

                }else if(input2 == 2){

                    k.setDirected();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. g >> x" << endl;
            cout << "02. k >> x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g >> item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k >> item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. g << x" << endl;
            cout << "02. k << x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g << item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k << item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. g.insertEdge(x1, x2)" << endl;
            cout << "02. k.insertEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    g.insertEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    k.insertEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. g.removeEdge(x1, x2)" << endl;
            cout << "02. k.removeEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    g.removeEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    k.removeEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. g.replace(x1, x2)" << endl;
            cout << "02. k.replace(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    g.replace(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeInt(item);
                    cout << "x2 = " << endl;
                    storeInt(item2);
                    k.replace(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. g.bfs(x, list/array)" << endl;
            cout << "02. k.bfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g.bfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k.bfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << "01. g.dfs(x, list/array)" << endl;
            cout << "02. k.dfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    g.dfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    k.dfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 19){

            cout << "01. g.topSort(list/array)" << endl;
            cout << "02. k.topSort(list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.topSort(l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    k.topSort(l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 20){

            cout << "01. g.regular()" << endl;
            cout << "02. k.regular()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.regular() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.regular() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 21){

            cout << "01. g.isSimple()" << endl;
            cout << "02. k.isSimple()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isSimple() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isSimple() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 22){

            cout << "01. g.isBipartite()" << endl;
            cout << "02. k.isBipartite()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isBipartite() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isBipartite() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 23){

            cout << "01. g.hasCycle()" << endl;
            cout << "02. k.hasCycle()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.hasCycle() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.hasCycle() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 24){

            cout << "01. g.hasCmpCycle(x)" << endl;
            cout << "02. k.hasCmpCycle(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeInt(item);
                    cout << g.hasCmpCycle(item) << endl;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeInt(item);
                    cout << k.hasCmpCycle(item) << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 25){

            cout << "01. g.connectedCmp()" << endl;
            cout << "02. k.connectedCmp()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.connectedCmp() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.connectedCmp() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 26){

            cout << "01. g.kosaraju()" << endl;
            cout << "02. k.kosaraju()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.kosaraju() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.kosaraju() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 27){

            gShow = !gShow;

        }else if(input == 28){

            kShow = !kShow;

        }else if(input == 29){

            cout << "Operators \"==\", \"!=\", \"<\", \">\", \"<=\" and \">=\" checks whether the two graphs are isomorphic or/and" << endl;
            cout << " one graph is a subgraph of the other ! g.order() - returns nr of vertices ! g.size() - returns nr of edges !" << endl;
            cout << " g.setDirected() sets the Graph as directed ! g.regular() - returns k if g is k regular or \"-1\" otherwise" << endl;
            cout << " g.clear() - removes all edges ! g.isSimple() - checks if g is a simple graph ! g.empty() - removes all vertices" << endl;
            cout << " g.isBipartite() - checks if g is a bipartite graph ! g.rebirth() - removes all vertices and resets status to undirected" << endl;
            cout << " g.hasCycle() - checks if g has a cycle ! g.complete() - completes the grapg with every possible edge !" << endl;
            cout << " g.hasCmpCycle(x) - checks if g has a cycle in the connected component containing x vertex !" << endl;
            cout << " g >> x - inserts vertex x into g ! g << x - removes vertex x from g !  g.topSort(list/array) - topological sorting !" << endl;
            cout << " g.setErr(x) - sets a parrameter to return in case of an error ! g.deg(x) returns the degree of x vertex !" << endl;
            cout << " g.replace(x1, x2) - replace x1 with x2 (keeps the neighbors) g.connectedCmp() - returns nr of connected components !" << endl;
            cout << " g.kosaraju() - returns nr of strongly connected components ! g.neighbors(x, list/array) - stores the neighbors of" << endl;
            cout << " x in a list or an array ! g.bfs(x, list/array) - stores a bfs traversal starting from node x in a list or an array !" << endl;
            cout << " g.dfs(x, list/array) - stores a dfs traversal starting from node x in a list or an array !" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    return;
}

void testGraphDouble(){

    UnWGraph<double> g;
    UnWGraph<double> k;

    g.setErr(-1.0385);
    k.setErr(-1.0385);

    ///int nrOfOperations;
    int input = 1;
    int input2;
    double item;
    double item2;
    string useless;

    bool gShow = true;
    bool kShow = false;

    LList<double> l;

    while(input != 0){

        cout << endl;
        cout << "DOUBLE TYPE:" << endl;

        if(gShow == true){

            cout << endl;
            g.print();
        }

        if(kShow == true){

            cout << endl;
            k.print();
        }

        cout << endl;
        cout << "g.order = " << g.order() << "; g.size = " << g.size() << "; k.order = " << k.order() << "; k.seize = " << k.size() << "." << endl;

        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false): [NOT WORKING YET !]" << endl;
        cout << "(g == k) = " << (g == k) << "; (g != k) = " << (g != k) << "; (g < k) = " << (g < k) << "; (g > k) = " << (g > k) << "; (g <= k) = " << (g <= k) << "; (g >= k) = " << (g >= k) << "." << endl;
        cout << endl;
        cout << " 1. g.order()                        10. g.setErr(x)                      19. g.topSort(list/array)" << endl;
        cout << " 2. g.size()                         11. g.setDirected()                  20. g.regular()" << endl;
        cout << " 3. g.clear()                        12. g >> x                           21. g.isSimple()" << endl;
        cout << " 4. g.empty()                        13. g << x                           22. g.isBipartite()" << endl;
        cout << " 5. g.rebirth()                      14. g.insertEdge(x1, x2)             23. g.hasCycle()" << endl;
        cout << " 6. g.complete()                     15. g.removeEdge(x1, x2)             24. g.hasCmpCycle(x)" << endl;
        cout << " 7. g.deg(x)                         16. g.replace(x1, x2)                25. g.connectedCmp()" << endl;
        cout << " 8. g.neighbors(x, list/array)       17. g.bfs(x, list/array)             27. g: ";
        if(gShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 9. g = k                            18. g.dfs(x, list/array)             28. k: ";
        if(kShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 0. BACK !                           19. g.topSort(list/array)            29. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "g.order() = " << g.order() << endl;
            cout << "k.order() = " << k.order() << endl;

        }else if(input == 2){

            cout << "g.size() = " << g.size() << endl;
            cout << "k.size() = " << k.size() << endl;

        }else if(input == 3){

            cout << "01. g.clear()" << endl;
            cout << "02. k.clear()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.clear();
                    break;

                }else if(input2 == 2){

                    k.clear();
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 4){

            cout << "01. g.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.empty();
                    break;

                }else if(input2 == 2){

                    k.empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout << "01. g.rebirth()" << endl;
            cout << "02. k.rebirth()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.rebirth();
                    break;

                }else if(input2 == 2){

                    k.rebirth();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 6){

            cout << "01. g.complete()" << endl;
            cout << "02. k.complete()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.complete();
                    break;

                }else if(input2 == 2){

                    k.complete();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 7){

            cout << "01. g.deg(x)" << endl;
            cout << "02. k.deg(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g.deg(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k.deg(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 8){

            cout << "01. g.neighbors(x, list/array)" << endl;
            cout << "02. k.neighbors(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g.neighbors(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k.neighbors(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "01. g = k" << endl;
            cout << "02. k = g" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g = k;
                    break;

                }else if(input2 == 2){

                    k = g;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 10){

            cout << "g.setErr(x); x = " << endl;
            storeDouble(item);
            g.setErr(item);
            cout << "k.setErr(x); x = " << endl;
            storeDouble(item);
            k.setErr(item);

        }else if(input == 11){

            cout << "01. g.setDirected()" << endl;
            cout << "02. k.setDirected()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.setDirected();
                    break;

                }else if(input2 == 2){

                    k.setDirected();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. g >> x" << endl;
            cout << "02. k >> x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g >> item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k >> item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. g << x" << endl;
            cout << "02. k << x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g << item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k << item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. g.insertEdge(x1, x2)" << endl;
            cout << "02. k.insertEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    g.insertEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    k.insertEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. g.removeEdge(x1, x2)" << endl;
            cout << "02. k.removeEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    g.removeEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    k.removeEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. g.replace(x1, x2)" << endl;
            cout << "02. k.replace(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    g.replace(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    storeDouble(item);
                    cout << "x2 = " << endl;
                    storeDouble(item2);
                    k.replace(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. g.bfs(x, list/array)" << endl;
            cout << "02. k.bfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g.bfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k.bfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << "01. g.dfs(x, list/array)" << endl;
            cout << "02. k.dfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    g.dfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    k.dfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 19){

            cout << "01. g.topSort(list/array)" << endl;
            cout << "02. k.topSort(list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.topSort(l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    k.topSort(l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 20){

            cout << "01. g.regular()" << endl;
            cout << "02. k.regular()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.regular() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.regular() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 21){

            cout << "01. g.isSimple()" << endl;
            cout << "02. k.isSimple()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isSimple() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isSimple() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 22){

            cout << "01. g.isBipartite()" << endl;
            cout << "02. k.isBipartite()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isBipartite() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isBipartite() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 23){

            cout << "01. g.hasCycle()" << endl;
            cout << "02. k.hasCycle()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.hasCycle() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.hasCycle() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 24){

            cout << "01. g.hasCmpCycle(x)" << endl;
            cout << "02. k.hasCmpCycle(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    storeDouble(item);
                    cout << g.hasCmpCycle(item) << endl;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    storeDouble(item);
                    cout << k.hasCmpCycle(item) << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 25){

            cout << "01. g.connectedCmp()" << endl;
            cout << "02. k.connectedCmp()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.connectedCmp() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.connectedCmp() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 26){

            cout << "01. g.kosaraju()" << endl;
            cout << "02. k.kosaraju()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.kosaraju() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.kosaraju() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 27){

            gShow = !gShow;

        }else if(input == 28){

            kShow = !kShow;

        }else if(input == 29){

            cout << "Operators \"==\", \"!=\", \"<\", \">\", \"<=\" and \">=\" checks whether the two graphs are isomorphic or/and" << endl;
            cout << " one graph is a subgraph of the other ! g.order() - returns nr of vertices ! g.size() - returns nr of edges !" << endl;
            cout << " g.setDirected() sets the Graph as directed ! g.regular() - returns k if g is k regular or \"-1\" otherwise" << endl;
            cout << " g.clear() - removes all edges ! g.isSimple() - checks if g is a simple graph ! g.empty() - removes all vertices" << endl;
            cout << " g.isBipartite() - checks if g is a bipartite graph ! g.rebirth() - removes all vertices and resets status to undirected" << endl;
            cout << " g.hasCycle() - checks if g has a cycle ! g.complete() - completes the grapg with every possible edge !" << endl;
            cout << " g.hasCmpCycle(x) - checks if g has a cycle in the connected component containing x vertex !" << endl;
            cout << " g >> x - inserts vertex x into g ! g << x - removes vertex x from g !  g.topSort(list/array) - topological sorting !" << endl;
            cout << " g.setErr(x) - sets a parrameter to return in case of an error ! g.deg(x) returns the degree of x vertex !" << endl;
            cout << " g.replace(x1, x2) - replace x1 with x2 (keeps the neighbors) g.connectedCmp() - returns nr of connected components !" << endl;
            cout << " g.kosaraju() - returns nr of strongly connected components ! g.neighbors(x, list/array) - stores the neighbors of" << endl;
            cout << " x in a list or an array ! g.bfs(x, list/array) - stores a bfs traversal starting from node x in a list or an array !" << endl;
            cout << " g.dfs(x, list/array) - stores a dfs traversal starting from node x in a list or an array !" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    return;
}

void testGraphString(){

    UnWGraph<string> g;
    UnWGraph<string> k;

    g.setErr("Custom error message !");
    k.setErr("Custom error message !");

    ///int nrOfOperations;
    int input = 1;
    int input2;
    string item;
    string item2;
    string useless;

    bool gShow = true;
    bool kShow = false;

    LList<string> l;

    while(input != 0){

        cout << endl;
        cout << "STRING TYPE:" << endl;

        if(gShow == true){

            cout << endl;
            g.print();
        }

        if(kShow == true){

            cout << endl;
            k.print();
        }

        cout << endl;
        cout << "g.order = " << g.order() << "; g.size = " << g.size() << "; k.order = " << k.order() << "; k.seize = " << k.size() << "." << endl;

        cout << endl;
        cout << "Lexicografic comparations: (1 - true; 0 - false): [NOT WORKING YET !]" << endl;
        cout << "(g == k) = " << (g == k) << "; (g != k) = " << (g != k) << "; (g < k) = " << (g < k) << "; (g > k) = " << (g > k) << "; (g <= k) = " << (g <= k) << "; (g >= k) = " << (g >= k) << "." << endl;
        cout << endl;
        cout << " 1. g.order()                        10. g.setErr(x)                      19. g.topSort(list/array)" << endl;
        cout << " 2. g.size()                         11. g.setDirected()                  20. g.regular()" << endl;
        cout << " 3. g.clear()                        12. g >> x                           21. g.isSimple()" << endl;
        cout << " 4. g.empty()                        13. g << x                           22. g.isBipartite()" << endl;
        cout << " 5. g.rebirth()                      14. g.insertEdge(x1, x2)             23. g.hasCycle()" << endl;
        cout << " 6. g.complete()                     15. g.removeEdge(x1, x2)             24. g.hasCmpCycle(x)" << endl;
        cout << " 7. g.deg(x)                         16. g.replace(x1, x2)                25. g.connectedCmp()" << endl;
        cout << " 8. g.neighbors(x, list/array)       17. g.bfs(x, list/array)             27. g: ";
        if(gShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 9. g = k                            18. g.dfs(x, list/array)             28. k: ";
        if(kShow == true){ cout << "SHOW ";}else{cout << "HIDE";}
        cout << endl;
        cout << " 0. BACK !                           19. g.topSort(list/array)            29. HELP !" << endl;

        storeInt(input);
        cout << endl;

        if(input == 0){

            break;

        }else if(input == 1){

            cout << "g.order() = " << g.order() << endl;
            cout << "k.order() = " << k.order() << endl;

        }else if(input == 2){

            cout << "g.size() = " << g.size() << endl;
            cout << "k.size() = " << k.size() << endl;

        }else if(input == 3){

            cout << "01. g.clear()" << endl;
            cout << "02. k.clear()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.clear();
                    break;

                }else if(input2 == 2){

                    k.clear();
                    break;

                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 4){

            cout << "01. g.empty()" << endl;
            cout << "02. k.empty()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.empty();
                    break;

                }else if(input2 == 2){

                    k.empty();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 5){

            cout << "01. g.rebirth()" << endl;
            cout << "02. k.rebirth()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.rebirth();
                    break;

                }else if(input2 == 2){

                    k.rebirth();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 6){

            cout << "01. g.complete()" << endl;
            cout << "02. k.complete()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.complete();
                    break;

                }else if(input2 == 2){

                    k.complete();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 7){

            cout << "01. g.deg(x)" << endl;
            cout << "02. k.deg(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g.deg(item);
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k.deg(item);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 8){

            cout << "01. g.neighbors(x, list/array)" << endl;
            cout << "02. k.neighbors(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g.neighbors(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k.neighbors(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 9){

            cout << "01. g = k" << endl;
            cout << "02. k = g" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g = k;
                    break;

                }else if(input2 == 2){

                    k = g;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 10){

            cout << "g.setErr(x); x = " << endl;
            scanline(item);
            g.setErr(item);
            cout << "k.setErr(x); x = " << endl;
            scanline(item);
            k.setErr(item);

        }else if(input == 11){

            cout << "01. g.setDirected()" << endl;
            cout << "02. k.setDirected()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.setDirected();
                    break;

                }else if(input2 == 2){

                    k.setDirected();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 12){

            cout << "01. g >> x" << endl;
            cout << "02. k >> x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g >> item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k >> item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 13){

            cout << "01. g << x" << endl;
            cout << "02. k << x" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g << item;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k << item;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 14){

            cout << "01. g.insertEdge(x1, x2)" << endl;
            cout << "02. k.insertEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    g.insertEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    k.insertEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 15){

            cout << "01. g.removeEdge(x1, x2)" << endl;
            cout << "02. k.removeEdge(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    g.removeEdge(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    k.removeEdge(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 16){

            cout << "01. g.replace(x1, x2)" << endl;
            cout << "02. k.replace(x1, x2)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    g.replace(item, item2);
                    break;

                }else if(input2 == 2){

                    cout << "x1 = " << endl;
                    scanline(item);
                    cout << "x2 = " << endl;
                    scanline(item2);
                    k.replace(item, item2);
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 17){

            cout << "01. g.bfs(x, list/array)" << endl;
            cout << "02. k.bfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g.bfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k.bfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 18){

            cout << "01. g.dfs(x, list/array)" << endl;
            cout << "02. k.dfs(x, list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    g.dfs(item, l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    k.dfs(item, l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 19){

            cout << "01. g.topSort(list/array)" << endl;
            cout << "02. k.topSort(list/array)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    g.topSort(l);
                    l.print();
                    break;

                }else if(input2 == 2){

                    k.topSort(l);
                    l.print();
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 20){

            cout << "01. g.regular()" << endl;
            cout << "02. k.regular()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.regular() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.regular() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 21){

            cout << "01. g.isSimple()" << endl;
            cout << "02. k.isSimple()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isSimple() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isSimple() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 22){

            cout << "01. g.isBipartite()" << endl;
            cout << "02. k.isBipartite()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.isBipartite() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.isBipartite() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 23){

            cout << "01. g.hasCycle()" << endl;
            cout << "02. k.hasCycle()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.hasCycle() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.hasCycle() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 24){

            cout << "01. g.hasCmpCycle(x)" << endl;
            cout << "02. k.hasCmpCycle(x)" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << "x = " << endl;
                    scanline(item);
                    cout << g.hasCmpCycle(item) << endl;
                    break;

                }else if(input2 == 2){

                    cout << "x = " << endl;
                    scanline(item);
                    cout << k.hasCmpCycle(item) << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 25){

            cout << "01. g.connectedCmp()" << endl;
            cout << "02. k.connectedCmp()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.connectedCmp() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.connectedCmp() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 26){

            cout << "01. g.kosaraju()" << endl;
            cout << "02. k.kosaraju()" << endl;

            while(1){

                storeInt(input2);
                if(input2 == 1){

                    cout << g.kosaraju() << endl;
                    break;

                }else if(input2 == 2){

                    cout << k.kosaraju() << endl;
                    break;
                }else{

                    cout << "It's a binary choice.. Alege 1 sau 2 !" << endl;
                }
            }

        }else if(input == 27){

            gShow = !gShow;

        }else if(input == 28){

            kShow = !kShow;

        }else if(input == 29){

            cout << "Operators \"==\", \"!=\", \"<\", \">\", \"<=\" and \">=\" checks whether the two graphs are isomorphic or/and" << endl;
            cout << " one graph is a subgraph of the other ! g.order() - returns nr of vertices ! g.size() - returns nr of edges !" << endl;
            cout << " g.setDirected() sets the Graph as directed ! g.regular() - returns k if g is k regular or \"-1\" otherwise" << endl;
            cout << " g.clear() - removes all edges ! g.isSimple() - checks if g is a simple graph ! g.empty() - removes all vertices" << endl;
            cout << " g.isBipartite() - checks if g is a bipartite graph ! g.rebirth() - removes all vertices and resets status to undirected" << endl;
            cout << " g.hasCycle() - checks if g has a cycle ! g.complete() - completes the grapg with every possible edge !" << endl;
            cout << " g.hasCmpCycle(x) - checks if g has a cycle in the connected component containing x vertex !" << endl;
            cout << " g >> x - inserts vertex x into g ! g << x - removes vertex x from g !  g.topSort(list/array) - topological sorting !" << endl;
            cout << " g.setErr(x) - sets a parrameter to return in case of an error ! g.deg(x) returns the degree of x vertex !" << endl;
            cout << " g.replace(x1, x2) - replace x1 with x2 (keeps the neighbors) g.connectedCmp() - returns nr of connected components !" << endl;
            cout << " g.kosaraju() - returns nr of strongly connected components ! g.neighbors(x, list/array) - stores the neighbors of" << endl;
            cout << " x in a list or an array ! g.bfs(x, list/array) - stores a bfs traversal starting from node x in a list or an array !" << endl;
            cout << " g.dfs(x, list/array) - stores a dfs traversal starting from node x in a list or an array !" << endl;
            cout << endl;
            cout << "Give an input to continue..." << endl;

            scanline(useless);

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    return;
}

void testList(){

    int input = 1;

    while(input != 0){

        cout << "LINKED LIST DIAG:" << endl;
        cout << "01. Test Linked List with integer values" << endl;
        cout << "02. Test Linked List with double values" << endl;
        cout << "03. Test Linked List with string values" << endl;
        cout << " 0. BACK !" << endl;

        storeInt(input);

        if(input == 0){

            break;

        }else if(input == 1){

            testListInteger();

        }else if(input == 2){

            testListDouble();

        }else if(input == 3){

            testListString();

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }
}

void testAVL(){

    int input = 1;

    while(input != 0){

        cout << "AVL DIAG:" << endl;
        cout << "01. Test AVL Tree with integer values" << endl;
        cout << "02. Test AVL Tree with double values" << endl;
        cout << "03. Test AVL Tree with string values" << endl;
        cout << " 0. BACK !" << endl;

        storeInt(input);

        if(input == 0){

            break;

        }else if(input == 1){

            testAVLInteger();

        }else if(input == 2){

            testAVLDouble();

        }else if(input == 3){

            testAVLString();

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }
}

void testGraph(){

    int input = 1;

    while(input != 0){

        cout << "GRAPH DIAG:" << endl;
        cout << "01. Test Graph with integer values" << endl;
        cout << "02. Test Graph with double values" << endl;
        cout << "03. Test Graph with string values" << endl;
        cout << " 0. BACK !" << endl;

        storeInt(input);

        if(input == 0){

            break;

        }else if(input == 1){

            testGraphInteger();

        }else if(input == 2){

            testGraphDouble();

        }else if(input == 3){

            testGraphString();

        }else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }
}

int main(){

    int input = 1;

    while(input != 0){

        cout << "DATA STRUCTURES DIAG:" << endl;
        cout << "01. Test Linked List" << endl;
        cout << "02. Test Binary Search Tree (AVL)" << endl;
        cout << "03. Test Graph" << endl;
        ///cout << "04. Test Neural Network" << endl;
        cout << " 0. EXIT !" << endl;

        storeInt(input);

        if(input == 0){

            break;

        }else if(input == 1){

            testList();

        }else if(input == 2){

            testAVL();

        }else if(input == 3){

            testGraph();

        }/*else if(input == 4){

            testNNetwork();

        }*/else{

            cout << "Invalid input ! Please try again !" << endl;
        }
    }

    ///                     LINKED-LISTS:       DONE !

    ///                     AVL-TREES:          DONE !

    ///                     GRAPHS:             COMMING SOON - SORT OF..

    ///                     NEURAL NETWORKS:    COMMING NOT-SO-SOON..


    return 0;
}

/// Commentariu dupa main() pentru a vedea nr total de linii dupa ce dau collapse (-) la functia main... It's motivating ! :D
