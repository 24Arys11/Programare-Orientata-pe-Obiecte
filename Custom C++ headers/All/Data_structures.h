#include <iostream>

void Errors(int e){

    if(e == 0){
        std::cout << "No elements to delete !" << std::endl;
    }else if(e == 1){
        std::cout << "Wrong parameter !" << std::endl;
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

    LinkedList(){

        first = NULL;
        last = NULL;
        elements = 0;
    }

    ~LinkedList(){

        while(first != NULL){
            Node* temp = first;
            first=first->next;
            delete[] temp;
        }
        delete[] first;
        delete[] last;
    }

    int length(){
        return elements;
    }

    Node head(){
        return *first;
    }

    void in(int number, int position){

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

    void out(int position){

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

    Node operator<<(int position){

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

    void operator>>(int number){

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

    void print(){

        Node* temp = first;
        std::cout << "List has " << elements << " elements: ";
        while(temp->next != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data << "." << std::endl;
    }

    void sortare(){ /// Need to improve time complexity !

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
