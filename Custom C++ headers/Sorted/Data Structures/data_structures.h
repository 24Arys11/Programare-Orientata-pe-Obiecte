#include <iostream>

void Errors(int e){

    if(e == 0){
        std::cout << "No elements to delete !" << std::endl;
    }else if(e == 1){
        std::cout << "Wrong parameter !" << std::endl;
    }else if(e == 2){
        std::cout << "Element not found !" << std::endl;
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
struct DlNode{  /// for double linked lists (urmeaza...)

    T data;
    DlNode *prev;
    DlNode *next;
};

template <class T>
class LinkedList{
private:

    int elements;
    Node<T>* first;
    Node<T>* last;

public:

    LinkedList(){   /// CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;
    }

    LinkedList(const LinkedList& l){   /// COPY CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;

        Node<T>* temp = new Node<T>;
        temp = l.first;
        this->in(temp->data, -1);   /// the argument "-1" puts the element at the end of the list (in O(1), that's because i'm a genius.. can't help it)

        while(temp->next != NULL){
            temp = temp->next;
            this->in(temp->data, -1);
        }

        temp = NULL;
        delete temp;
    }

    ~LinkedList(){  /// DESTRUCTOR

        while(first != NULL){
            Node<T>* temp = new Node<T>;
            temp = first;
            first = first->next;
            delete temp;
        }
        delete first;
        delete last;
    }

    LinkedList& operator=(const LinkedList& l){

        if(this->elements > 0){  /// If the list is not empty, make it empty !

            LinkedList<T>* temporary = new LinkedList<T>;

            temporary->first = this->first;
            temporary->elements = this->elements;

            delete temporary;

            this->first = NULL;
            this->last = NULL;
            this->elements = 0;
        }

        Node<T>* temp = new Node<T>;
        temp = l.first;
        this->in(temp->data, -1);   /// the argument "-1" puts the element at the end of the list (in O(1), that's because i'm a genius.. can't help it)

        while(temp->next != NULL){
            temp = temp->next;
            this->in(temp->data, -1);
        }

        temp = NULL;
        delete temp;
    }

    int length(){   /// returns the number of elements in the list
        return elements;
    }

    Node<T> head(){    /// returns the address of the first node
        return *first;
    }

    void in(T item, int position){  /// inserts the specified item at specified position (-1 means at the end)

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

            Node<T>* temp = new Node<T>;
            temp = first;

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
    }

    void out(int position){ /// removes the element at specified position

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
    }

    Node<T> operator[](int position){  /// returns the element at specified position

        if((position == -1) || (position == (elements - 1))){
            return *last;
        }else if((position < -1) || (position >= elements)){  /// Error: "Wrong parameter !"

            Errors(1);

        }else{

            Node<T>* temp = new Node<T>;
            temp = first;

            for(int i = 0; i < position; i++){
            /// Parcurgem lista pana la elementul de pe pozitia dorita
                temp = temp->next;
            }
            return *temp;
        }
    }

    void operator<<(T value){ /// removes the element with specified value (only the first one, in case it repeats)

        if(elements == 0){

            Errors(2);

        }else{

            if(first->data == value){  /// Stergem primul element !

                Node<T>* temp = first;
                first = first->next;
                delete temp;
                elements--;

            }else if(elements == 1){

                Errors(2);
            }else{

                Node<T>* temp = first;
                Node<T>* temp2 = first->next;

                int i = 2; /// Contor. It starts at 2 because temp2 (first->next) is the 2nd element.
                while((temp2->data != value) && (temp2->next != NULL)){

                    if(i >= elements){
                        Errors(2);
                        return;
                    }
                    temp = temp2;
                    temp2 = temp2->next;
                    i++;
                }

                temp->next = temp2->next;
                delete temp2;
                if(temp->next == NULL){
                    last = temp;
                }
                elements--;
            }
        }
    }

    void operator>>(T item){    /// If the list is sorted, inserts an alement to it's appropriate position

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

                    Node<T>* temp = new Node<T>;
                    Node<T>* temp2 = new Node<T>;
                    temp = first;
                    temp2 = first;

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

                Node<T>* left = new Node<T>;
                left = this->first;
                Node<T>* right = new Node<T>;
                right = l.first;

                while(left->next != NULL){  /// since they have the same number of elements there is no need to check if (right->next != NULL).

                    left = left->next;
                    right = right->next;

                    if(left->data != right->data){

                        left = NULL;
                        right = NULL;
                        delete left;
                        delete right;
                        return false;
                    }
                }

                left = NULL;
                right = NULL;
                delete left;
                delete right;
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

        Node<T>* left = new Node<T>;
        left = this->first;
        Node<T>* right = new Node<T>;
        right = l.first;

        while(left->next != NULL){

            if(right->next == NULL){    /// second list is shorter and the first list starts with the second list.

                left = NULL;
                right = NULL;
                delete left;
                delete right;

                return false;
            }

            left = left->next;
            right = right->next;

            if(left->data < right->data){

                left = NULL;
                right = NULL;
                delete left;
                delete right;

                return true;

            }else if((left->data > right->data)){

                left = NULL;
                right = NULL;
                delete left;
                delete right;

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
        delete left;
        delete right;

        return true;
    }

    bool operator>(const LinkedList& l){

        if((this->elements == 0) && (l.elements != 0)){

            return false;
        }

        if((this->elements != 0) && (l.elements == 0)){

            return true;
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

        Node<T>* left = new Node<T>;
        left = this->first;
        Node<T>* right = new Node<T>;
        right = l.first;

        while(left->next != NULL){

            if(right->next == NULL){    /// second list is shorter and the first list starts with the second list.

                left = NULL;
                right = NULL;
                delete left;
                delete right;

                return true;
            }

            left = left->next;
            right = right->next;

            if(left->data > right->data){

                left = NULL;
                right = NULL;
                delete left;
                delete right;

                return true;

            }else if((left->data < right->data)){

                left = NULL;
                right = NULL;
                delete left;
                delete right;

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
        delete left;
        delete right;

        return false;
    }

    bool operator<=(const LinkedList& l){

        return !(*this > l);
    }

    bool operator>=(const LinkedList& l){

        return !(*this < l);
    }

    void sortare(){ /// Sorts the list in O(n^2) ! Need to improve time complexity !

        LinkedList* l = new LinkedList;
        int nrOfEements = elements;

        while(first != NULL){

            *l >> first->data;
            this->out(0);
        }

        first = l->first;
        elements = nrOfEements;
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

        std::cout << "first node: " << first << std::endl;
        this->print();
        if(this->elements > 0){
            std::cout << "first node: " << first << " last node: (" << last << " | " << last->data << " | " << last->next << ")" << std::endl;
        }else{
            std::cout << "first node: " << first << " last node: (" << last << " | ? | ?)" << std::endl;
        }
    }
};
