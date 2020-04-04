#include <string>
#include "Data_structures.h"

using namespace std;

int main()
{
    cout << "CITITI COMENTARIILE DIN main() PENTRU A VEDEA CE AR TREBUI SA FACA FIECARE FUNCTIE !" << endl;
    cout << "Test cu date de tip int:" << endl;
    LinkedList <int> l;

    l >> 1;
    l >> 5;
    l >> 3;
    l >> 2;
    l >> 4;

    /// Operatorul ">>" adauga elementele la locul lor (in ordine), daca lista este deja sortata.

    cout << "Am executat: l >> 1;    l >> 5;    l >> 3;    l >> 2;    l >> 4;" << endl;

    l.print();

    l.in(12, 2); /// Adauga elementul 12 la pozitia 2, numarand de la zero. (adica al treilea element din lista va fi 12)

    cout << "Am executat: l.in(12, 2);" << endl;

    l.print();

    cout << "Elem de pe pozitia 2 (am executat: \"l[2].data\") este: " << l[2].data << endl; /// Returneaza elementul de pe pozitia 2;

    l.sortare(); /// Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) !

    cout << "Am executat: l.sortare();" << endl;

    l.print();

    l << 12; /// Sterge elementul 12 din lista. (indiferent de pozitia pe care se afla)

    cout << "Am executat: l << 12;" << endl;

    l.print();

    l.out(2); /// Sterge elementul de pe pozitia 2 din lista ! (numarand de la 0)

    cout << "Am executat: l.out(2);" << endl;

    l.print();

    cout << endl;

    cout << "Test cu date de tip char:" << endl;
    LinkedList <char> k;

    k >> 'a';
    k >> 'e';
    k >> 'c';
    k >> 'b';
    k >> 'd';

    /// Operatorul ">>" adauga elementele la locul lor (in ordine), daca lista este deja sortata.

    cout << "Am executat: k >> 'a';    k >> 'e';    k >> 'c';    k >> 'b';    k >> 'd';" << endl;

    k.print();

    k.in('q', 2); /// Adauga elementul 'q' la pozitia 2, numarand de la zero. (adica al treilea element din lista va fi q)

    cout << "Am executat: k.in('q', 2);" << endl;

    k.print();

    cout << "Elem de pe pozitia 2 (am executat: \"k[2].data\") este: " << k[2].data << endl; /// Returneaza elementul de pe pozitia 2;

    k.sortare(); /// Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) !

    cout << "Am executat: k.sortare();" << endl;

    k.print();

    k << 'q'; /// Sterge elementul 'q' din lista. (indiferent de pozitia pe care se afla)

    cout << "Am executat: k << 'q';" << endl;

    k.print();

    k.out(2); /// Sterge elementul de pe pozitia 2 din lista ! (numarand de la 0)

    cout << "Am executat: k.out(2);" << endl;

    k.print();

    cout << endl;

    cout << "Test cu date de tip string:" << endl;
    LinkedList <string> s;

    s >> "abc";
    s >> "erl tm";
    s >> "cear";
    s >> "bdsada";
    s >> "dsadas";

    /// Operatorul ">>" adauga elementele la locul lor (in ordine), daca lista este deja sortata.

    cout << "Am executat: s >> \"abc\";    s >> \"erl tm\";    s >> \"cear\";    s >> \"bdsada\";    s >> \"dsadas\";" << endl;

    s.print();

    s.in("qtr py", 2); /// Adauga elementul "qtr py" la pozitia 2, numarand de la zero. (adica al treilea element din lista va fi "qtr py")

    cout << "Am executat: s.in(\"qtr py\", 2);" << endl;

    s.print();

    cout << "Elem de pe pozitia 2 (am executat: \"s[2].data\") este: " << s[2].data << endl; /// Returneaza elementul de pe pozitia 2;

    s.sortare(); /// Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) !

    cout << "Am executat: s.sortare();" << endl;

    s.print();

    s << "qtr py"; /// Sterge elementul "qtr py" din lista. (indiferent de pozitia pe care se afla)

    cout << "Am executat: s << \"qtr py\";" << endl;

    s.print();

    s.out(2); /// Sterge elementul de pe pozitia 2 din lista ! (numarand de la 0)

    cout << "Am executat: s.out(2);" << endl;

    s.print();

    return 0;
}
