#ifndef DATASTRUCTURES_H_INCLUDED
#define DATASTRUCTURES_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

#define left prev
#define right next

namespace dtk{  /// Darius The King ;)

void Errors(int e){

    if(e == 0){
        std::cout << "No elements to delete !" << std::endl;
    }else if(e == 1){
        std::cout << "Wrong parameter !" << std::endl;
    }else{
        std::cout << "Unknown error !" << std::endl;
    }
}

template <class T>
struct Node{    /// for  linked lists

    T data;
    Node *next;
};

template <class T>
struct DlNode{  /// for double linked lists & binary search trees

    T data;
    DlNode *prev;   /// *left (defined)
    DlNode *next;   /// *right (defined)
};

template <class T>
class LinkedList{
private:

    int elements;
    Node<T>* first;
    Node<T>* last;

public:

    T err;  /// A default return value in the case of accesing a wrong parameter (Example: l[7] in a list with 3 elements)

    LinkedList(){   /// CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;
    }

    LinkedList(const LinkedList& l){   /// COPY CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;

        Node<T>* temp = l.first;

        if(l.elements != 0){    /// if (l.elements == 0) is true, we do not need to do anything !
                /// Also: if (l.elements == 0) is true, temp = NULL, that means "temp->data" and "temp->next" does not exist, so the program would crash !

            this->in(temp->data, -1);   /// the argument "-1" puts the element at the end of the list (in O(1), that's because i'm a genius.. can't help it)

            while(temp->next != NULL){
                temp = temp->next;
                this->in(temp->data, -1);
            }
        }



        temp = NULL;
    }

    ~LinkedList(){  /// DESTRUCTOR

        while(first != NULL){
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
        delete first;
        delete last;
    }

    LinkedList& operator=(const LinkedList& l){

        this->empty();

        if(l.elements == 0){

            return *this;
        }

        Node<T>* temp = l.first;
        this->in(temp->data, -1);   /// the argument "-1" inserts the element at the end of the list (in O(1) - using a pointer to the end of the list...
                                                                                            /// ...than, we move the pointer (*last) to the newly created node)
        while(temp->next != NULL){
            temp = temp->next;
            this->in(temp->data, -1);
        }

        temp = NULL;

        return *this;
    }

    int length(){   /// returns the number of elements in the list
        return elements;
    }

    LinkedList& in(T item, int position){  /// inserts the specified item at specified position (-1 means at the end)

        if(position == 0){  /// Introducem elementul la inceput in complexitate O(1)

            Node<T>* temp = new Node<T>;
            temp->data = item;
            temp->next = first;
            first = temp;
            if(elements == 0){
                last = temp;
            }
            elements++;

        }else if((position == -1) || (position == elements)){ /// Introducem elementul la sfarsit in complexitate O(1)

            Node<T>* temp = new Node<T>;
            temp->data = item;
            temp->next = NULL;
            if(elements == 0){
                first = temp;
            }else{
                last->next = temp;
            }
            last = temp;
            elements++;

        }else if((position < -1) || (position >= elements)){  /// Error: "Wrong parameter !"

            Errors(1);

        }else{  /// Introducem elementul la pozitia specificata in complexitate O(n)

            Node<T>* temp = first;

            for(int i = 1; i < position; i++){
            /// Parcurgem lista pana la elementul de pe pozitia dorita
                temp = temp->next;
            }
            Node<T>* temp2 = new Node<T>;
            temp2->data = item;
            temp2->next = temp->next;
            temp->next = temp2;
            elements++;
        }
        return *this;
    }

    LinkedList& out(int position){ /// removes the element at specified position

        if(elements == 0){

            Errors(0);

        }else{

            if(position == -1){

                position = elements - 1;
            }

            if(position == 0){  /// Stergem primul element !

                Node<T>* temp = first;
                first = first->next;
                delete temp;

                if(elements == 1){

                    last = NULL;
                }

                elements--;

            }else{

                Node<T>* temp = first;

                for(int i = 1; i < position; i++){

                    temp = temp->next;
                }

                Node<T>* temp2 = temp;
                temp = temp->next;
                temp2->next = temp->next;
                delete temp;

                if(position == (elements - 1)){

                    last = temp2;
                }
                elements--;
            }
        }
        return *this;
    }

    LinkedList& empty(){

        int limit = this->elements;
        for(int i = 0; i < limit; i++){

            this->out(0);
        }
        return *this;
    }

    T& operator[](int position){  /// returns the element at specified position

        if(elements == 0){

            Errors(1);
            return err;

        }else if((position == -1) || (position == (elements - 1))){

            return last->data;

        }else if((position < -1) || (position >= elements)){  /// Error: "Wrong parameter !"

            Errors(1);
            return err;

        }else{

            Node<T>* temp = first;

            for(int i = 0; i < position; i++){
            /// Parcurgem lista pana la elementul de pe pozitia dorita
                temp = temp->next;
            }
            return temp->data;
        }
    }

    LinkedList& operator<<(T value){ /// removes the element with specified value (only the first one, in case it repeats)

        if(elements == 0){

            return *this;
        }

        if(first->data == value){  /// Stergem primul element !

            this->out(0);
            return *this;
        }

        if(elements > 1){

            Node<T>* temp = first;
            Node<T>* temp2 = first->next;

            for(int i = 1; i < elements; i++){

                if(temp2->data == value){

                    temp->next = temp2->next;
                    delete temp2;
                    elements--;

                    if(temp->next == NULL){
                        last = temp;
                    }

                    return *this;
                }

                temp = temp->next;
                temp2 = temp2->next;
            }
        }

        return *this;
    }

    LinkedList& operator>>(T item){    /// If the list is sorted, inserts an element to it's appropriate position.

        if(elements == 0){

            Node<T>* temp = new Node<T>;
            temp->data = item;
            temp->next = first;
            first = temp;
            last = temp;
            elements++;

        }else{

            if(item < last->data){

                if(item <= first->data){
                    this->in(item, 0);
                }else{

                    Node<T>* temp = first;
                    Node<T>* temp2 = first;

                    while(item > temp->data){
                        temp2 = temp;
                        temp = temp->next;
                    }
                    Node<T>* temp3 = new Node<T>;
                    temp3->data = item;
                    temp3->next = temp2->next;
                    temp2->next = temp3;
                    elements++;
                }
            }else{
                this->in(item, -1);
            }
        }
        return *this;
    }

    bool operator==(const LinkedList& l){

        if(this->elements != l.elements){

            return false;

        }else{  /// the lists have the same number of elements !

            if(this->elements < 2){

                if(this->elements == 0){    /// both lists are emplty !

                    return true;

                }else{  /// each list have only one element !

                    if(this->first->data == l.first->data){

                        return true;

                    }else{

                        return false;
                    }
                }

            }else{  /// We have at least 2 elements => first->next exist !

                if(this->first->data != l.first->data){

                    return false;
                }

                Node<T>* left = this->first;
                Node<T>* right = l.first;

                while(left->next != NULL){  /// since they have the same number of elements there is no need to check if (right->next != NULL).

                    left = left->next;
                    right = right->next;

                    if(left->data != right->data){

                        left = NULL;
                        right = NULL;

                        return false;
                    }
                }

                left = NULL;
                right = NULL;

                return true;
            }
        }
    }

    bool operator!=(const LinkedList& l){

        return !(*this == l);
    }

    bool operator<(const LinkedList& l){

        if((this->elements == 0) && (l.elements != 0)){

            return true;
        }

        if((this->elements != 0) && (l.elements == 0)){

            return false;
        }

        if((this->elements == 0) && (l.elements == 0)){

            return false;
        }

        /// If we got so far, it means that none of the two lists is empty !

        if(this->first->data != l.first->data){

            if(this->first->data < l.first->data){

                return true;

            }else{

                return false;
            }
        }

        /// If we got so far, it means that both lists start with the same element !

        if((this->first->next == NULL) && (l.first->next == NULL)){ /// the list are equal and they have only one element !

            return false;

        }else if((this->first->next == NULL) && (l.first->next != NULL)){   /// both lists start with the same element. The first has only one element but the second has more..

            return true;

        }else if((this->first->next != NULL) && (l.first->next == NULL)){   /// both lists start with the same element. The second has only one element but the first has more..

            return false;
        }

        /// If we got so far, it means that both lists have the same first element and at least 2 elements each. => first->next exist for both lists !

        Node<T>* left = this->first;
        Node<T>* right = l.first;

        while(left->next != NULL){

            if(right->next == NULL){    /// second list is shorter and the first list starts with the second list.

                left = NULL;
                right = NULL;

                return false;
            }

            left = left->next;
            right = right->next;

            if(left->data < right->data){

                left = NULL;
                right = NULL;

                return true;

            }else if((left->data > right->data)){

                left = NULL;
                right = NULL;

                return false;
            }
        }

        /// All the numbers are equal so far. If one of the list is longer, it is the biger one.

        if((left->next == NULL) && (left->next == NULL)){   /// the lists are equal.

            return false;
        }

        /// we allready checked whether the second list is shorter. (inside the while loop)
        /// we also checked whether they are equal (above), so, the only posibility left is for the second list to be longer.

        left = NULL;
        right = NULL;

        return true;
    }

    bool operator>(const LinkedList& l){

        if((this->elements == 0) && (l.elements != 0)){

            return false;
        }

        if((this->elements != 0) && (l.elements == 0)){

            return true;
        }

        if((this->elements == 0) && (l.elements == 0)){

            return false;
        }

        /// If we got so far, it means that none of the two lists is empty !

        if(this->first->data != l.first->data){

            if(this->first->data > l.first->data){

                return true;

            }else{

                return false;
            }
        }

        /// If we got so far, it means that both lists start with the same element !

        if((this->first->next == NULL) && (l.first->next == NULL)){ /// the list are equal and they have only one element !

            return false;

        }else if((this->first->next == NULL) && (l.first->next != NULL)){   /// both lists start with the same element. The first has only one element but the second has more..

            return false;

        }else if((this->first->next != NULL) && (l.first->next == NULL)){   /// both lists start with the same element. The second has only one element but the first has more..

            return true;
        }

        /// If we got so far, it means that both lists have the same first element and at least 2 elements each. => first->next exist for both lists !

        Node<T>* left = this->first;
        Node<T>* right = l.first;

        while(left->next != NULL){

            if(right->next == NULL){    /// second list is shorter and the first list starts with the second list.

                left = NULL;
                right = NULL;

                return true;
            }

            left = left->next;
            right = right->next;

            if(left->data > right->data){

                left = NULL;
                right = NULL;

                return true;

            }else if((left->data < right->data)){

                left = NULL;
                right = NULL;

                return false;
            }
        }

        /// All the numbers are equal so far. If one of the list is longer, it is the biger one.

        if((left->next == NULL) && (left->next == NULL)){   /// the lists are equal.

            return false;
        }

        /// we allready checked whether the second list is shorter. (inside the while loop)
        /// we also checked whether they are equal (above), so, the only posibility left is for the second list to be longer.

        left = NULL;
        right = NULL;

        return false;
    }

    bool operator<=(const LinkedList& l){

        return !(*this > l);
    }

    bool operator>=(const LinkedList& l){

        return !(*this < l);
    }

    LinkedList& operator+(const LinkedList& l){

        if(this->elements == 0){

            LinkedList<T> *supplement = new LinkedList<T>;
            *supplement = l;
            return *supplement;
        }

        if(l.elements == 0){

            LinkedList<T> *supplement = new LinkedList<T>;
            *supplement = *this;
            return *supplement;
        }

        LinkedList<T> *sum = new LinkedList<T>;
        *sum = *this;
        LinkedList<T> *supplement = new LinkedList<T>;
        *supplement = l;
        sum->last->next = supplement->first;
        sum->last = supplement->last;
        sum->elements += l.elements;

        return *sum;
    }

    LinkedList& operator+=(const LinkedList& l){

        if(this->elements == 0){

            *this = l;
            return *this;
        }

        if(l.elements == 0){

            return *this;
        }

        LinkedList<T> *supplement = new LinkedList<T>;
        *supplement = l;
        this->last->next = supplement->first;
        this->last = supplement->last;
        this->elements += l.elements;

        return *this;
    }

    LinkedList& operator-(const LinkedList& l){

        LinkedList *dif = new LinkedList;
        *dif = *this;

        if((l.elements == 0) || (dif->elements == 0)){

            return *dif;
        }

        LinkedList drop = l;

        for(int i = 0; i < l.elements; i++){

            *dif << (drop.first->data);
            drop.out(0);
        }
        return *dif;
    }

    LinkedList& operator-=(const LinkedList& l){

        if((l.elements == 0) || (this->elements == 0)){

            return *this;
        }

        LinkedList drop = l;

        for(int i = 0; i < l.elements; i++){

            *this << (drop.first->data);
            drop.out(0);
        }
        return *this;
    }

    LinkedList& fuse(const LinkedList& l){    /// Merge 2 lists together. If both lists are sorted, the resulting one will be sorted in O(n).

        if(elements == 0){  /// If *this is empty

            *this = l;
            return *this;

        }else if(l.elements == 0){

            return *this;

        }else{  /// None of the lists is empty !

            int limit = this->elements + l.elements;
            LinkedList<T> k = *this;
            Node<T> *temp = k.first;    /// LIST 1
            Node<T> *temp2 = l.first;   /// LIST 2
            this->empty();              /// RESULT

            for(int i = 0; i < limit; i++){

                if(temp->data < temp2->data){

                    this->in(temp->data, -1);

                    if(temp->next != NULL){

                        temp = temp->next;

                    }else{

                        while(temp2->next != NULL){

                            this->in(temp2->data, -1);
                            temp2 = temp2->next;
                            i++;
                        }

                        this->in(temp2->data, -1);   /// do{}while(); is not appropriate because of "temp2 = temp2->next;"
                        i++;
                    }

                }else{

                    this->in(temp2->data, -1);

                    if(temp2->next != NULL){

                        temp2 = temp2->next;

                    }else{

                        while(temp->next != NULL){

                            this->in(temp->data, -1);
                            temp = temp->next;
                            i++;
                        }

                        this->in(temp->data, -1);   /// do{}while(); is not appropriate because of "temp = temp->next;"
                        i++;
                    }
                }
            }

            return *this;
        }
    }

    LinkedList& sort(){ /// Sorts the list in O(n * log(n)) using std::sort !

        int nrOfEements = this->elements;

        T values[nrOfEements];

        for(int i = 0; i < nrOfEements; i++){

            values[i] = this->first->data;
            this->out(0);
        }

        std::sort(values, &values[nrOfEements]);

        for(int i = 0; i < nrOfEements; i++){

            this->in(values[i], -1);
        }

        this->elements = nrOfEements;

        return *this;
    }

    void print(){   /// Prints the list

        if(first == NULL){

            std::cout << "List is empty ! " << std::endl;
            return;
        }

        Node<T>* temp = first;
        std::cout << "List has " << elements << " elements: ";

        while(temp->next != NULL){

            std::cout << temp->data << "   ";
            temp = temp->next;
        }
        std::cout << temp->data << "." << std::endl;
    }

    void check(){

        /// std::cout << std::endl;
        this->print();
        if(this->elements > 0){
            std::cout << "first node address: " << first << " last node: (address: " << last << " | data: " << last->data << " | points to (should be 0) = " << last->next << ")" << std::endl;
        }else{
            std::cout << "first node address: " << first << " last node address: " << last << std::endl;
        }
    }
};

}   /// End of namespace

#undef left
#undef right
#endif /// DATASTRUCTURES_H_INCLUDED
