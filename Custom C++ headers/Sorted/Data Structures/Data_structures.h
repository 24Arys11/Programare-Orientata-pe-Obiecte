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

struct Node{

    int data;
    Node *next;
};

class LinkedList{
private:

    int elements;
    Node* first;
    Node* last;

public:

    LinkedList(){   /// CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;
    }

    ~LinkedList(){  /// DESTRUCTOR

        while(first != NULL){
            Node* temp = first;
            first=first->next;
            delete[] temp;
        }
        delete[] first;
        delete[] last;
    }

    int length(){   /// returns the number of elements in the list
        return elements;
    }

    Node head(){    /// returns the address of the first node
        return *first;
    }

    void in(int number, int position){  /// inserts the specified number at specified position (-1 means at the end)

        if(position == 0){  /// Introducem elementul la inceput in complexitate O(1)

            Node* temp = new Node;
            temp->data = number;
            temp->next = first;
            first = temp;
            if(elements == 0){
                last = temp;
            }
            elements++;

        }else if((position == -1) || (position == elements)){ /// Introducem elementul la sfarsit in complexitate O(1)

            Node* temp = new Node;
            temp->data = number;
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

            Node* temp = new Node;
            temp = first;

            for(int i = 1; i < position; i++){
            /// Parcurgem lista pana la elementul de pe pozitia dorita
                temp = temp->next;
            }
            Node* temp2 = new Node;
            temp2->data = number;
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

                Node* temp = first;
                first = first->next;
                delete[] temp;
                elements--;

            }else{

                Node* temp = first;
                for(int i = 1; i < position; i++){
                    temp = temp->next;
                }
                Node* temp2 = temp;
                    temp = temp->next;
                    temp2->next = temp->next;
                delete[] temp;
                elements--;
            }
        }
    }

    Node show(int position){  /// returns the element at specified position

        if((position == -1) || (position == (elements - 1))){
            return *last;
        }else if((position < -1) || (position >= elements)){  /// Error: "Wrong parameter !"

            Errors(1);

        }else{

            Node* temp = new Node;
            temp = first;

            for(int i = 0; i < position; i++){
            /// Parcurgem lista pana la elementul de pe pozitia dorita
                temp = temp->next;
            }
            return *temp;
        }
    }

    void operator<<(int value){ /// removes the element with specified value (only the first one, in case it repeats)

        if(elements == 0){

            Errors(2);

        }else{

            if(first->data == value){  /// Stergem primul element !

                Node* temp = first;
                first = first->next;
                delete[] temp;
                elements--;

            }else if(elements == 1){

                Errors(2);
            }else{

                Node* temp = first;
                Node* temp2 = first->next;

                int i = 2; /// Contor. It starts at 2 because temp2 (first->next) is the 2nd element.
                while(temp2->data != value){

                    if(i == elements){
                        Errors(2);
                        return;
                    }
                    temp = temp->next;
                    temp2 = temp2->next;
                    i++;
                }

                temp->next = temp2->next;
                delete[] temp2;
                elements--;
            }
        }
    }

    void operator>>(int number){    /// If the list is sorted, inserts an alement to it's appropriate position

        if(elements == 0){

            Node* temp = new Node;
            temp->data = number;
            temp->next = first;
            first = temp;
            last = temp;
            elements++;

        }else{

            if(number < last->data){

                if(number < first->data){
                    this->in(number, 0);
                }else{

                    Node* temp = new Node;
                    Node* temp2 = new Node;
                    temp = first;

                    while(number > temp->data){
                        temp2 = temp;
                        temp = temp->next;
                    }
                    Node* temp3 = new Node;
                    temp3->data = number;
                    temp3->next = temp2->next;
                    temp2->next = temp3;
                    elements++;
                }
            }else{
                this->in(number, -1);
            }
        }
    }

    void print(){   /// Prints the list

        Node* temp = first;
        std::cout << "List has " << elements << " elements: ";
        while(temp->next != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data << "." << std::endl;
    }

    void sortare(){ /// Sorts the list in O(n^2) ! Need to improve time complexity !

        LinkedList* l = new LinkedList;
        int numberOfEements = elements;

        while(first != NULL){

            *l >> first->data;
            this->out(0);
        }

        first = l->first;
        elements = numberOfEements;
    }
};