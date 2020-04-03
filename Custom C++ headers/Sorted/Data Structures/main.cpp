#include "Data_structures.h"

using namespace std;

int main()
{
    LinkedList l;

    l >> 1;
    l >> 5;
    l >> 3;
    l >> 2;
    l >> 4;

    /// Operatorul ">>" adauga numerele la locul lor (in ordine), daca lista este deja sortata.

    l.print();

    l.in(12, 2); /// Adauga numarul 12 la pozitia 2, numarand de la zero. (adica al treilea numar din lista va fi 2)

    l.print();

    cout << l[2].data << endl; /// Returneaza elementul de pe pozitia 2;

    l.sortare(); /// Sorteaza lista in complexitate O(n^2). E de proba deocamdata. O sa o imbunatatesc la O(n*log(n)) !

    l.print();

    l << 12; /// Sterge elementul 12 din lista. (indiferent de pozitia pe care se afla)

    l.print();

    l.out(2); /// Sterge elementul de pe pozitia 2 din lista ! (numarand de la 0)

    l.print();

    return 0;
}
