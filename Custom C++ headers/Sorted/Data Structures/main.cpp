#include "data_structures.h"

using namespace std;

int main()
{
    cout << "CITITI COMENTARIILE DIN main() PENTRU A VEDEA CE AR TREBUI SA FACA FIECARE FUNCTIE !" << endl;
    cout << "Test cu date de tip int:" << endl;
    LinkedList <int> l; /// merge schimbat tipul din int in char, string, orice..

    l >> 1;    l >> 2;    l >> 2;    l >> 1;    l >> 3;

    /// Operatorul ">>" adauga elementele la locul lor (in ordine), daca lista este deja sortata.

    cout << "Am executat: l >> 1;    l >> 2;    l >> 2;    l >> 1;    l >> 3;" << endl;

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

    cout << "Test cu date de tip string:" << endl;
    LinkedList <string> s;

    s >> "abc";
    s >> "erl tm";
    s >> "cear";

    s.print();

    s.in("qtr py", 2); /// Adauga elementul "qtr py" la pozitia 2, numarand de la zero. (adica al treilea element din lista va fi "qtr py")

    s.print();

    s.sortare(); /// Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) !

    s.print();

    cout << endl;

    LinkedList <int> m;

    m >> 5;
    m >> 8;
    m >> 5;
    m >> 9;

    l.print();
    m.print();

    cout << "(l < m) = " << (l < m) << endl;

    l = m;

    l.print();
    m.print();

    cout << endl;

    m.check();

    cout << endl;

    return 0;
}
