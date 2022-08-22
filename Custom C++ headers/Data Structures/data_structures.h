#ifndef DATASTRUCTURES_H_INCLUDED
#define DATASTRUCTURES_H_INCLUDED

#include <iostream>
#include <string>       /// for printing the AVL Tree in a fancy way..

namespace dtk{  /// Darius The King ;)

template<class T>
class LList;
template<class T>
class AVL;
template<class T>
class UnWGraph;
//template<class T>
//class WGraph;
//template<class T>
//class NNetwork;

void Errors(int e){

    /// ERRORS 0 - 99 -> Linked List
    if(e == 0){
        std::cout << "No elements to delete !" << std::endl;
    }else if(e == 1){
        std::cout << "Accessing out of bounds parameter !" << std::endl;
    /// ERRORS 100 - 199 -> AVL Tree
    }else if(e == 100){
        std::cout << "The tree is empty !" << std::endl;
    /// ERRORS 200 - 299 -> UnWGraph
    }else if(e == 200){
        std::cout << "Impossible to sort ! The Graph needs to be directed !" << std::endl;
    }else if(e == 201){
        std::cout << "Impossible to sort ! The Graph contains cycles" << std::endl;
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
struct AVLnode{  /// for binary search trees (ballanced AVL)

    T data;
    unsigned char height; /// We store the hight to improve time efficiency. Usually, the imballance doesn't spread up to the root.
                        /// 1 byte - Since the tree is ballanced, hight = log(n) ! If the hight > 255 you're not gonna be able to store 2^255 nodes in any computer !
    AVLnode *left;      /// 4 bytes
    AVLnode *right;     /// 4 bytes
                        /// No parent node for space efficiency. We will use a stack, instead.   [With parent node: 4 bytes * n | With stack: 4 bytes * log(n)]
};

template <class T>
class LList{
private:

    int elements;
    Node<T>* first;
    Node<T>* last;

public:

    T err;  /// A default return value in the case of accesing a wrong parameter (Example: l[7] in a list with 3 elements)

    LList(){   /// CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;
    }

    LList(const LList& l){   /// COPY CONSTRUCTOR

        first = NULL;
        last = NULL;
        elements = 0;

        Node<T>* temp = l.first;

        if(l.elements != 0){    /// if (l.elements == 0) is true, we do not need to do anything !
                /// Also: if (l.elements == 0) is true, temp = NULL, that means "temp->data" and "temp->next" does not exist, so the program would crash !

            this->in(temp->data, -1);   /// the argument "-1" puts the element at the end of the list (in O(1))

            while(temp->next != NULL){
                temp = temp->next;
                this->in(temp->data, -1);
            }
        }
        temp = NULL;
    }

    LList(const T* arr, int nrOfElements, int startIndex = 0){   /// CONSTRUCT a Linked List from an array of the same type !

        first = NULL;
        last = NULL;
        elements = 0;

        int endIndex = startIndex + nrOfElements;

        for(int i = startIndex; i < endIndex; i++){

            this->qpush(arr[i]);
        }
    }

    explicit LList(AVL<T>& tree){  /// Type cast an AVL into a Linked List

        first = NULL;
        last = NULL;
        elements = 0;

        tree.assign(*this);
    }

    ~LList(){  /// DESTRUCTOR

        while(first != NULL){

            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
    }

    LList& operator=(const LList& l){

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

    void store(T* arr) const {     /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        if(this->elements == 0){

            arr = NULL;
            return;
        }

        Node<T>* temp = this->first;

        for(int i = 0; i < this->elements; i++){

            arr[i] = temp->data;
            temp = temp->next;
        }
        return;
    }

    void assign(AVL<T>& tree) const {

        tree.empty();
        if(this->elements == 0){

            return;
        }

        Node<T>* temp = this->first;

        for(int i = 0; i < this->elements; i++){

            tree >> temp->data;
            temp = temp->next;
        }
        return;
    }

    int length() const {   /// returns the number of elements in the list
        return elements;
    }

    LList& in(T item, int position){  /// inserts the specified item at specified position (-1 means at the end)

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

    LList& out(int position){ /// removes the element at specified position

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

    LList& operator>>(T item){    /// If the list is sorted, inserts an element to it's appropriate position.

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

    LList& operator<<(T item){ /// removes the specified element (only the first one, in case it repeats)

        if(elements == 0){

            return *this;
        }

        if(first->data == item){  /// Stergem primul element !

            this->out(0);
            return *this;
        }

        if(elements > 1){

            Node<T>* temp = first;
            Node<T>* temp2 = first->next;

            for(int i = 1; i < elements; i++){

                if(temp2->data == item){

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

    bool operator==(const LList& l) const {

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

    bool operator!=(const LList& l) const {

        return !(*this == l);
    }

    bool operator<(const LList& l) const {

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

    bool operator>(const LList& l) const {

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

    bool operator<=(const LList& l) const {

        return !(*this > l);
    }

    bool operator>=(const LList& l) const {

        return !(*this < l);
    }

    LList& fuse(const LList& l){    /// Merge 2 lists together. If both lists are sorted, the resulting one will be sorted in O(n).

        if(elements == 0){  /// If *this is empty

            *this = l;
            return *this;

        }else if(l.elements == 0){

            return *this;

        }
        /// None of the lists is empty !

        int limit = this->elements + l.elements;
        LList<T> k = *this;
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

    LList& expand(const LList& l){

        if(this->elements == 0){

            *this = l;
            return *this;
        }

        if(l.elements == 0){

            return *this;
        }

        LList<T> supplement = l;
        while(supplement.length() != 0){

            this->qpush(supplement.top());
            supplement.pop();
        }

        return *this;
    }

    LList& eject(const LList& l){

        if((l.elements == 0) || (this->elements == 0)){

            return *this;
        }

        LList drop = l;

        for(int i = 0; i < l.elements; i++){

            *this << (drop.top());
            drop.pop();
        }
        return *this;
    }

    LList& empty(){

        while(first != NULL){

            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }

        this->elements = 0;
        this->last = NULL;

        return *this;
    }

    LList& sort(){ /// Sorts the list in O(n * log(n)) using the AVL !

        AVL<T> avl = AVL<T>(*this);     /// We are casting the list into an AVL, and than back into a list !
        *this = LList<T>(avl);

        return *this;
    }

    LList& qpush(T item){

        this->in(item, -1);
        return *this;
    }

    LList& push(T item){

        this->in(item, 0);
        return *this;
    }

    LList& pop(){

        this->out(0);
        return *this;
    }

    T& top(){

        if(elements == 0){

            Errors(1);
            return err;
        }

        return this->first->data;
    }

    void print() const {   /// Prints the list

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

    void check() const {

        /// std::cout << std::endl;
        this->print();
        if(this->elements > 0){
            std::cout << "first node address: " << first << " last node: (address: " << last << " | data: " << last->data << " | points to (should be 0) = " << last->next << ")" << std::endl;
        }else{
            std::cout << "first node address: " << first << " last node address: " << last << std::endl;
        }
    }
};

template <class T>
class AVL{
private:

    int elements;
    AVLnode<T>* root;

    AVLnode<T>* getNewNode(T item){     /// Utility function

        AVLnode<T>* newNode = new AVLnode<T>;
        newNode->data = item;
        newNode->left = newNode->right = NULL;
        newNode->height = 0;

        return newNode;
    }

    short int height(AVLnode<T>* &node){  /// Utility function

        if(node == NULL){

            return -1;
        }

        short int left;
        short int right;

        if(node->left == NULL){

            left = -1;
        }else{

            left = node->left->height;
        }

        if(node->right == NULL){

            right = -1;
        }else{

            right = node->right->height;
        }

        if(left > right){

            node->height = left + 1;
        }else{

            node->height = right + 1;
        }
        return node->height;
    }

    void ballance(LList<AVLnode<T>*> &S){

        while(S.length() != 0){

            if((height((S.top())->left) - height((S.top())->right)) > 1){   /// Left heavy
                                                                            ///     |     A |
                S.push((S.top())->left);                                    ///     |    /  |
                if(height((S.top())->left) > height((S.top())->right)){     ///     |   B   |
                                                                            ///     |  /    |
                    rightRotate(S);     ///  |    A  |                              | C     |
                }else{                  ///  |   /   |
                                        ///  |  B    |
                    leftRightRotate(S); ///  |   \   |
                }                       ///  |    C  |
            }else if((height((S.top())->right) - height((S.top())->left)) > 1){ /// Right heavy
                                                                                ///      | A     |
                S.push((S.top())->right);                                       ///      |  \    |
                if(height((S.top())->right) > height((S.top())->left)){         ///      |   B   |
                                                                                ///      |    \  |
                    leftRotate(S);      /// |  A    |                                    |     C |
                }else{                  /// |   \   |
                                        /// |    B  |
                    rightLeftRotate(S); /// |   /   |
                }                       /// |  C    |
            }else{

                S.pop();
            }
        }
    }

    void remove(LList<AVLnode<T>*> &S){   /// Utility function

        /// We need to remove S.top(), and use the rest of the stack to ballance the tree

        AVLnode<T>* node = S.top();
        AVLnode<T>* parent;

        /// Case 1: No child
        if(node->left == NULL && node->right == NULL){

            S.pop();
            if(S.length() != 0){
                parent = S.top();

                if(parent->left == node){

                    parent->left = NULL;
                }else{

                    parent->right = NULL;
                }
                delete node;
                ballance(S);
            }else{

                delete node;
                this->root = NULL;
            }

        /// Case 2: Right child (left NULL)
        }else if(node->left == NULL){

            S.pop();
            if(S.length() != 0){
                parent = S.top();

                if(parent->left == node){

                    parent->left = node->right;
                }else{

                    parent->right = node->right;
                }
                delete node;
                ballance(S);
            }else{

                this->root = root->right;
                delete node;
            }

        /// Case 3: Left child (right NULL)
        }else if(node->right == NULL){

            S.pop();
            if(S.length() != 0){
                parent = S.top();

                if(parent->left == node){

                    parent->left = node->left;
                }else{

                    parent->right = node->left;
                }
                delete node;
                ballance(S);
            }else{

                this->root = root->left;
                delete node;
            }

        /// Case 4: Both childs
        }else{

            /// We swap the node with the node value with minimum value in it's right !
            AVLnode<T>* current = node->right;

            while(current != NULL){

                S.push(current);
                current = current->left;
            }
            current = S.top();
            node->data = current->data;

            S.pop();
            parent = S.top();

            /// Case 4.1: current has no child
            if(current->right == NULL){

                if(parent->left == current){

                    parent->left = current->right;
                }else{

                    parent->right = current->right;
                }
                delete current;
                ballance(S);

            /// Case 4.2: current has a right child
            }else{

                if(parent->left == current){

                    parent->left = current->right;
                }else{

                    parent->right = current->right;
                }
                delete current;
                ballance(S);
            }
        }
    }

    void leftRotate(LList<AVLnode<T>*> &S){

        ///   X               X         |
        ///   |               |         |
        ///   A               B         |
        ///  / \            /   \       |
        /// al  B     =>   A     C      |
        ///    / \        / \   / \     |
        ///   bl  C      al bl cl  cr   |
        ///      / \                    |
        ///     cl  cr                  |

        AVLnode<T>* B = S.top();
        S.pop();
        AVLnode<T>* A = S.top();
        S.pop();

        if(S.length() == 0){    /// means A is the root ! X doesn't exist !

            this->root = B;
        }else{      /// X exist ! X becomes the parent of B !

            AVLnode<T>* X = S.top();

            if(X->left == A){

                X->left = B;
            }else{

                X->right = B;
            }
        }
        A->right = B->left;
        B->left = A;
        height(A);
        height(B);   /// height works in O(1). Only looks at the height of the childrens !
        S.push(B);

        /// We never had to touch C, so if it is NULL, there is no problem !
    }

    void rightRotate(LList<AVLnode<T>*> &S){

        ///       X              X         |
        ///       |              |         |
        ///       A              B         |
        ///      / \           /   \       |
        ///     B   ar   =>   C     A      |
        ///    / \           / \   / \     |
        ///   C   br        cl cr br  ar   |
        ///  / \                           |
        /// cl  cr                         |

        AVLnode<T>* B = S.top();
        S.pop();
        AVLnode<T>* A = S.top();
        S.pop();

        if(S.length() == 0){    /// means A is the root ! X doesn't exist !

            this->root = B;
        }else{      /// X exist ! X becomes the parent of B !

            AVLnode<T>* X = S.top();

            if(X->left == A){

                X->left = B;
            }else{

                X->right = B;
            }
        }
        A->left = B->right;
        B->right = A;
        height(A);
        height(B);   /// height works in O(1). Only looks at the height of the childrens !
        S.push(B);

        /// We never had to touch C, so if it is NULL, there is no problem !
    }

    void leftRightRotate(LList<AVLnode<T>*> &S){

        S.push((S.top())->right);
        leftRotate(S);
        rightRotate(S);
    }

    void rightLeftRotate(LList<AVLnode<T>*> &S){

        S.push((S.top())->left);
        rightRotate(S);
        leftRotate(S);
    }

    void preorder(AVLnode<T>* &node, LList<T>& l){

        if(node == NULL){

            return;
        }
        l.qpush(node->data);
        preorder(node->left, l);
        preorder(node->right, l);
    }

    void inorder(AVLnode<T>* &node, LList<T>& l){

        if(node == NULL){

            return;
        }
        inorder(node->left, l);
        l.qpush(node->data);
        inorder(node->right, l);
    }

    void postorder(AVLnode<T>* &node, LList<T>& l){

        if(node == NULL){

            return;
        }
        postorder(node->left, l);
        postorder(node->right, l);
        l.qpush(node->data);
    }

public:

    T err;  /// A default return value in the case of an error (Example: t.min() when t is an empty tree)

    AVL(){  /// CONSTRUCTOR

        root = NULL;
        elements = 0;
    }

    AVL(const AVL& t){  /// COPY CONSTRUCTOR

        root = NULL;
        elements = 0;

        this->expand(t);
    }

    explicit AVL(LList<T>& l){  /// Type cast a Linked List into an AVL

        root = NULL;
        elements = 0;

        l.assign(*this);
    }

    ~AVL(){  /// DECONSTRUCTOR

        this->empty();
    }

    AVL& operator=(const AVL& t){

        this->empty();

        this->expand(t);

        return *this;
    }

    void assign(LList<T>& l){

        l.empty();
        this->inorder(this->root, l);
    }

    int length() const {   /// returns the number of elements in the tree

        return elements;
    }

    AVL& empty(){

        if(root == NULL){

            return *this;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(root);

        AVLnode<T>* current;
        AVLnode<T>* arr[this->elements];    /// stores the pointers to the nodes to be deleted later.   Time complexity is O(n).
        int i = 0;
        while(Q.length() > 0){

            current = Q.top();
            arr[i] = current;       /// by using "*this << current->data" instead, would have resulted in O(n*log(n)) time complexity !

            if(current->left != NULL){
                Q.qpush(current->left);
            }

            if(current->right != NULL){
                Q.qpush(current->right);
            }

            Q.pop();
            i++;
        }

        for(int i = 0; i < this->elements; i++){

            delete arr[i];
        }

        this->root = NULL;
        this->elements = 0;

        return *this;
    }

    bool search(T item) const {    /// Search element

        if(this->root == NULL){

            return false;
        }

        AVLnode<T>* node = this->root;
        while(node != NULL){

            if(node->data == item){

                return true;
            }
            if(item > node->data){

                node = node->right;
            }else{

                node = node->left;
            }
        }
        return false;
    }

    T& operator[](T item){    /// Find element

        if(this->root == NULL){

            return err;
        }

        AVLnode<T>* node = this->root;
        while(node != NULL){

            if(node->data == item){

                return node->data;
            }
            if(item > node->data){

                node = node->right;
            }else{

                node = node->left;
            }
        }
        return err;
    }

    AVL& operator>>(T item){    /// Insert element

        AVLnode<T>* newBorn = getNewNode(item);
        if(this->root == NULL){

            this->root = newBorn;
            elements++;
            return *this;
        }

        AVLnode<T>* temp = this->root;
        LList<AVLnode<T>*> S; /// Stack to store the parents !

        while(temp != NULL){

            S.push(temp);
            if(item > temp->data){

                temp = temp->right;
                if(temp == NULL){
                    (S.top())->right = newBorn;
                }
            }else{

                temp = temp->left;
                if(temp == NULL){
                    (S.top())->left = newBorn;
                }
            }
        }
        elements++;

        ballance(S);

        return *this;
    }

    AVL& operator<<(T item){    /// Delete element

        if(this->root == NULL){

            return *this;
        }

        AVLnode<T>* temp = this->root;
        LList<AVLnode<T>*> S; /// Stack to store the parents !

        while(temp != NULL){

            S.push(temp);
            if(item > temp->data){

                temp = temp->right;
                if(temp == NULL){
                    return *this;
                }
            }else if(item < temp->data){

                temp = temp->left;
                if(temp == NULL){
                    return *this;
                }
            }else{  /// We need to remove S.top(), and use the rest of the stack to ballance the tree

                remove(S);
                this->elements--;
                break;
            }
        }

        return *this;
    }

    bool operator==(const AVL& tree){

        if((this->elements == 0) && (tree.elements == 0)){

            return true;
        }

        if(this->elements != tree.elements){

            return false;
        }

        /// Since we passed the previous checks, the trees are not empty and they have the same number of elements !

        AVL<T> t = tree;

        T l[this->elements];
        T k[this->elements];

        this->srd(l);
        t.srd(k);

        for(int i = 0; i < this->elements; i++){

            if(l[i] != k[i]){
                return false;
            }
        }

        return true;
    }

    bool operator!=(const AVL& t){

        return !(*this == t);
    }

    /// Overloading the following operators "<", ">", "<=" and ">=" makes no sense ! (suppose we have tree1: 1-2-3 and tree2: 2-2-2. Wich is bigger ?)

    AVL& expand(const AVL& t){

        if(t.root == NULL){

            return *this;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(t.root);

        AVLnode<T>* current;
        int i = 0;
        while(Q.length() > 0){

            current = Q.top();
            *this >> current->data;

            if(current->left != NULL){
                Q.qpush(current->left);
            }

            if(current->right != NULL){
                Q.qpush(current->right);
            }

            Q.pop();
            i++;
        }
        return *this;
    }

    AVL& eject(const AVL& t){

        if((t.root == NULL) || (this->root == NULL)){

            return *this;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(t.root);

        AVLnode<T>* current;
        int i = 0;
        while(Q.length() > 0){

            current = Q.top();
            *this << current->data;

            if(current->left != NULL){
                Q.qpush(current->left);
            }

            if(current->right != NULL){
                Q.qpush(current->right);
            }

            Q.pop();
            i++;
        }
        return *this;
    }

    T& min(){

        if(root == NULL){

            Errors(100);
            return err;
        }

        AVLnode<T>* current = root;

        while(current->left != NULL){

            current = current->left;
        }

        return current->data;
    }

    T& max(){

        if(root == NULL){

            Errors(100);
            return err;
        }

        AVLnode<T>* current = root;

        while(current->right != NULL){

            current = current->right;
        }

        return current->data;
    }

    /// BFS. Level order
    void bfs(T *arr){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        if(root == NULL){

            return;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(root);

        AVLnode<T>* current;
        int i = 0;
        while(Q.length() > 0){

            current = Q.top();
            arr[i] = current->data;

            if(current->left != NULL){
                Q.qpush(current->left);
            }

            if(current->right != NULL){
                Q.qpush(current->right);
            }

            Q.pop();
            i++;
        }
    }

    /// BFS. Level order - Stores the references in the array !
    void referencesBfs(T* *arr){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        if(root == NULL){

            return;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(root);

        AVLnode<T>* current;
        int i = 0;
        while(Q.length() > 0){

            current = Q.top();
            arr[i] = &current->data;

            if(current->left != NULL){
                Q.qpush(current->left);
            }

            if(current->right != NULL){
                Q.qpush(current->right);
            }

            Q.pop();
            i++;
        }
    }

    /// DFS. Preorder:   EN: <ROOT> <LEFT> <RIGHT>         RO: <RADACINA> <STANGA> <DREAPTA>
    void rsd(T *arr){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        LList<T> l;
        this->preorder(this->root, l);
        l.store(arr);
    }

    /// DFS. Inorder:    EN: <LEFT> <ROOT> <RIGHT>         RO: <STANGA> <RADACINA> <DREAPTA>
    void srd(T *arr){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        LList<T> l;
        this->inorder(this->root, l);
        l.store(arr);
    }

    /// DFS. Postorder:  EN: <LEFT> <RIGHT> <ROOT>         RO: <STANGA> <DREAPTA> <RADACINA>
    void sdr(T *arr){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the length() function for that...

        LList<T> l;
        this->postorder(this->root, l);
        l.store(arr);
    }

    void print(std::string (*f)(std::string, int) = [](std::string s, int){return (" " + s);}){   /// Prints (draws) the tree !

        if(root == NULL){

            return;
        }

        LList<AVLnode<T>* > Q;
        Q.qpush(root);

        AVLnode<T>* current;

        int k = 2;
        int counter = 2;
        int level = height(root);

        while(Q.length() > 0){

            current = Q.top();

            if(current != NULL){

                std::cout << f(std::to_string(current->data), level);

            }else{

                std::cout << f("", level);
            }

            if(current != NULL){

                if(current->left != NULL){

                    Q.qpush(current->left);

                }else{

                    Q.qpush(NULL);
                }

                if(current->right != NULL){

                    Q.qpush(current->right);

                }else{

                    Q.qpush(NULL);
                }
            }else{

                Q.qpush(NULL);
                Q.qpush(NULL);
            }

            Q.pop();

            if(counter == k){

                k = k * 2;
                level--;
                std::cout << std::endl;

            }
            counter++;
            if(level < 0){
                break;
            }
        }
    }
};

template <class T>
class UnWGraphNode{

    friend class UnWGraph<T>;

private:

    T data;
    AVL<UnWGraphNode<T>* > *neighbors;

    bool seen;

    void addNeighbor(UnWGraphNode<T>* n){

        *this->neighbors >> n;
    }

    bool removeNeighbor(UnWGraphNode<T>* n){

        int elements = this->neighbors->length();
        *this->neighbors << n;  /// After removal, this->neighbors->length() should have one less element !

        if(elements == this->neighbors->length()){

            return false;   /// Failure means that "n" wasn't in the AVL ("n" is not a neighbor) so there was nothing to remove !
        }

        return true;
    }

public:

    UnWGraphNode(){         /// CONSTRUCTOR

        this->neighbors = new AVL<UnWGraphNode<T>* >;
        this->neighbors->err = NULL;
    }

    UnWGraphNode(T value){  /// CONSTRUCTOR WITH INITIALIZATION

        this->data = value;
        this->neighbors = new AVL<UnWGraphNode<T>* >;
        this->neighbors->err = NULL;
    }

    UnWGraphNode(const UnWGraphNode<T>& V){  /// COPY CONSTRUCTOR

        this->data = V.data;
        this->neighbors = new AVL<UnWGraphNode<T>* >(*V.neighbors);
        this->neighbors->err = NULL;
    }

    UnWGraphNode& operator=(UnWGraphNode<T>& V){

        this->data = V.data;

        return *this;
    }

    ~UnWGraphNode(){        /// DESTRUCTOR

        delete neighbors;
    }

    bool operator==(const UnWGraphNode& v) const {

        return (this->data == v.data);
    }

    bool operator!=(const UnWGraphNode& v) const {

        return (this->data != v.data);
    }

    bool operator<(const UnWGraphNode& v) const {

        return (this->data < v.data);
    }

    bool operator>(const UnWGraphNode& v) const {

        return (this->data > v.data);
    }

    bool operator<=(const UnWGraphNode& v) const {

        return (this->data <= v.data);
    }

    bool operator>=(const UnWGraphNode& v) const {

        return (this->data >= v.data);
    }

    int deg(){

        return this->neighbors->length();
    }
};

template <class T>
class UnWGraph{
private:

    AVL<UnWGraphNode<T> > *vertices;
    /// order (number of vertices) = vertices->length()
    int noOfEdges;   /// size (number of edges)
    bool directed;
    UnWGraphNode<T> err;

    UnWGraphNode<T>& getNode(T data){  /// returns the vertex with the specified data in the graph

        UnWGraphNode<T> temp(data);
        return (*this->vertices)[temp];
    }

    bool hasCmpCycleDi(T vertex, LList<T>& l){

        int noOfVertices = this->order();
        if(noOfVertices == 0){
            return false;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        for(int i = 0; i < noOfVertices; i++){

            allVertices[i]->seen = false;
        }

        LList<UnWGraphNode<T>* > S;  /// Search Stack
        AVL<UnWGraphNode<T>* > copyS;

        UnWGraphNode<T>* current = &this->getNode(vertex);

        S.push(current);
        copyS >> current;

        LList<UnWGraphNode<T>* > copyNeighbors;

        while(S.length() != 0){

            current = S.top();
            copyS << S.top();
            S.pop();

            if(current->seen == false){

                current->seen = true;
                l.qpush(current->data);
            }

            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    S.push(copyNeighbors.top());
                    copyS >> copyNeighbors.top();

                }else{  ///copyNeighbors.top() has been seen ! If it is in the stack, we have a cycle !

                    if(copyS.search(copyNeighbors.top())){

                        return true;
                    }
                }
                copyNeighbors.pop();
            }
        }
        return false;
    }
    /// BETA VERSION !!!

    bool hasCmpCycleUndi(T vertex, LList<T>& l){

        int noOfVertices = this->order();
        if(noOfVertices == 0){
            return false;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        for(int i = 0; i < noOfVertices; i++){

            allVertices[i]->seen = false;
        }

        LList<UnWGraphNode<T>* > S;  /// Search Stack
        AVL<UnWGraphNode<T>* > copyS;

        UnWGraphNode<T>* current = &this->getNode(vertex);
        UnWGraphNode<T>* parent = NULL;

        S.push(current);
        copyS >> current;

        LList<UnWGraphNode<T>* > copyNeighbors;

        while(S.length() != 0){

            current = S.top();
            copyS << current;
            S.pop();

            if(current->seen == false){

                current->seen = true;
                l.qpush(current->data);
            }

            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    S.push(copyNeighbors.top());
                    copyS >> copyNeighbors.top();

                }else{  ///copyNeighbors.top() has been seen ! If it is in the stack and it is not the parent, we have a cycle !

                    if((copyS.search(copyNeighbors.top()) == true) && (copyNeighbors.top() != parent)){

                        return true;
                    }
                }
                parent = current;
                copyNeighbors.pop();
            }
        }
        return false;
    }
    /// BETA VERSION !!!

    bool hasCmpCycleUtil(T vertex, LList<T>& l){

        if(this->directed == true){

            return hasCmpCycleDi(vertex, l);
        }
        return hasCmpCycleUndi(vertex, l);
    }

public:

    void setErr(T value){

        this->err.data = value;
        this->vertices->err = err;
    }

    void setDirected(){

        if(this->directed == true){

            return;
        }

        this->directed = true;
        noOfEdges = 2 * noOfEdges;
    }

    UnWGraph(){   /// CONSTRUCTOR

        this->vertices = new AVL<UnWGraphNode<T> >;
        noOfEdges = 0;
        this->directed = false;
    }

    UnWGraph(const UnWGraph<T>& G){   /// COPY CONSTRUCTOR

        /// Initialization
        this->vertices = new AVL<UnWGraphNode<T> >;
        noOfEdges = 0;
        this->directed = true;	/// Edge insertion works differently depending on this parameter

        /// Inserting vertices...
        int noOfVertices = G.vertices->length();
        UnWGraphNode<T>* copyVertices[noOfVertices];
        G.vertices->referencesBfs(copyVertices);

        for(int i = 0; i < noOfVertices; i++){

            *this >> copyVertices[i]->data;
        }

        /// Inserting edges...
        LList<UnWGraphNode<T>* > copyNeighbors;

        for(int i = 0; i < noOfVertices; i++){

            copyVertices[i]->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                this->insertEdge(copyVertices[i]->data, copyNeighbors.top()->data);
                copyNeighbors.pop();
            }
        }

        /// Fix directed parameter
        this->directed = G.directed;
        this->noOfEdges = G.noOfEdges;
    }

    UnWGraph& operator=(const UnWGraph<T>& G){

        /// Initialization
        this->empty();
        this->directed = true;	/// Edge insertion works differently depending on this parameter

        /// Inserting vertices...
        int noOfVertices = G.vertices->length();
        UnWGraphNode<T>* copyVertices[noOfVertices];
        G.vertices->referencesBfs(copyVertices);

        for(int i = 0; i < noOfVertices; i++){

            *this >> copyVertices[i]->data;
        }

        /// Inserting edges...
        LList<UnWGraphNode<T>* > copyNeighbors;

        for(int i = 0; i < noOfVertices; i++){

            copyVertices[i]->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                this->insertEdge(copyVertices[i]->data, copyNeighbors.top()->data);
                copyNeighbors.pop();
            }
        }

        /// Fix directed parameter
        this->directed = G.directed;
        this->noOfEdges = G.noOfEdges;
        return *this;
    }

    ~UnWGraph(){   /// DESTRUCTOR

        delete vertices;
    }

    int order() const {   /// returns the number of vertices in the graph

        return this->vertices->length();
    }

    int size() const {   /// returns the number of edges in the graph

        return this->noOfEdges;
    }

    int deg(T data){

        return this->getNode(data).deg();
    }

    void neighbors(T data, LList<T>& l){

        l.empty();
        int degree = this->getNode(data).deg();

        if(degree == 0){
			return;
		}

		UnWGraphNode<T>* allNeighbors[degree];
        this->getNode(data).neighbors->bfs(allNeighbors);       /// The array allNeighbors contains references to for each vertex in the graph !

        for(int i = 0; i < degree; i++){

            l.qpush(allNeighbors[i]->data);
        }
        return;
    }

    void neighbors(T data, T *arr){  /// Well, it's not idiot proof ! It needs a right sized array ! But you have the deg() function for that...

        int degree = this->getNode(data).deg();

        if(degree == 0){
			return;
		}

		UnWGraphNode<T>* allNeighbors[degree];
        this->getNode(data)->neighbors->bfs(allNeighbors);  /// The array allNeighbors contains references to for each vertex in the graph !

        int index = 0;
        for(int i = 0; i < degree; i++){

            arr[index] = allNeighbors[i]->data;
            index++;
        }
        return;
    }

    UnWGraph& operator>>(T data){  /// inserts a vertex with the specified data in it

        UnWGraphNode<T> temp(data);
        *this->vertices >> temp;

        return *this;
    }

    UnWGraph& operator<<(T data){  /// removes the vertex with the specified data in it

        /// Find the node in the vertices AVL tree !
        UnWGraphNode<T> toBeDeleted = this->getNode(data);

        /// STEP 1: Remove all the edges leading to the "toBeDeleted" node !

        UnWGraphNode<T>* copyNeighbors[toBeDeleted.deg()];
        toBeDeleted.neighbors->bfs(copyNeighbors);      /// The array copyNeighbors contains all the neighbors of the "toBeDeleted" node !

        for(int i = 0; i < toBeDeleted.deg(); i++){

            this->removeEdge(toBeDeleted.data, copyNeighbors[i]->data);  /// Removes all the edges leading to the "toBeDeleted" node !
        }

        if(this->directed == true){

            UnWGraphNode<T> allVertices[this->order()];
            this->vertices->bfs(allVertices);       /// The array allVertices contains all the vertices in the graph !

            for(int i = 0; i < this->order(); i++){

                this->removeEdge(allVertices[i].data, toBeDeleted.data);
                /// If you try to remove an element that does't exist from the AVL, nothing happends !
            }
        }
        /// STEP 2: Deleting the vertex

        *this->vertices << toBeDeleted;

        return *this;
    }

    UnWGraph& insertEdge(T vertex, T neighbor){  /// inserts a vertex with the specified data in it

        if(this->directed == true){

            this->noOfEdges++;

            this->getNode(vertex).addNeighbor(&this->getNode(neighbor));
            return *this;
        }

        this->noOfEdges++;

        this->getNode(vertex).addNeighbor(&this->getNode(neighbor));
        this->getNode(neighbor).addNeighbor(&this->getNode(vertex));
        return *this;
    }

    UnWGraph& removeEdge(T vertex, T neighbor){  /// removes the vertex with the specified data in it

        bool success;

        if(this->directed == true){


            success = this->getNode(vertex).removeNeighbor(&this->getNode(neighbor));   /// Failure means that "&(*this)[neighbor]" is not a neighbor so there was nothing to remove !

            if(success == true){
                this->noOfEdges--;
            }

            return *this;
        }

        success = this->getNode(vertex).removeNeighbor(&this->getNode(neighbor));   /// Failure means that "&(*this)[neighbor]" is not a neighbor so there was nothing to remove !
        this->getNode(neighbor).removeNeighbor(&this->getNode(vertex));             /// No need to check both of them. In an undirected graph, if there is an edge from A to B there is also an edge from B to A.

        if(success == true){
            this->noOfEdges--;
        }

        return *this;
    }

	void bfs(T vertex, T *arr, bool automatic = true){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the order() function for that...

		int noOfVertices = this->order();
		if(noOfVertices == 0){
			return;
		}

		UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        if(automatic == true){

            for(int i = 0; i < noOfVertices; i++){

                allVertices[i]->seen = false;
            }
        }

		LList<UnWGraphNode<T>* > Q;  /// Search Queue
		Q.qpush(&this->getNode(vertex));

		int index = 0;
		UnWGraphNode<T>* current;

		while(Q.length() != 0){

			current = Q.top();
			Q.pop();

			if(current->seen == false){

				current->seen = true;
				arr[index] = current->data;
				index++;
			}

			LList<UnWGraphNode<T>* > copyNeighbors;
            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    Q.qpush(copyNeighbors.top());
                }
                copyNeighbors.pop();
            }
		}
	}

	void dfs(T vertex, T *arr, bool automatic = true){   /// Well, it's not idiot proof ! It needs a right sized array ! But you have the order() function for that...

		int noOfVertices = this->order();
		if(noOfVertices == 0){
			return;
		}

		UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        if(automatic == true){

            for(int i = 0; i < noOfVertices; i++){

                allVertices[i]->seen = false;
            }
        }

		LList<UnWGraphNode<T>* > S;  /// Search Stack
        S.push(&(*this)[vertex]);

		int index = 0;
		UnWGraphNode<T>* current;

		while(S.length() != 0){

			current = S.top();
			S.pop();

			if(current->seen == false){

				current->seen = true;
				arr[index] = current->data;
				index++;
			}

			LList<UnWGraphNode<T>* > copyNeighbors;
            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    S.push(copyNeighbors.top());
                }
                copyNeighbors.pop();
            }
		}
	}

    void bfs(T vertex, LList<T>& l, bool automatic = true){

        l.empty();
        int noOfVertices = this->order();
        if(noOfVertices == 0){
            return;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        if(automatic == true){

            for(int i = 0; i < noOfVertices; i++){

                allVertices[i]->seen = false;
            }
        }

        LList<UnWGraphNode<T>* > Q;  /// Search Queue
        Q.qpush(&this->getNode(vertex));

        UnWGraphNode<T>* current;

        while(Q.length() != 0){

            current = Q.top();
            Q.pop();

            if(current->seen == false){

                current->seen = true;
                l.qpush(current->data);
            }

            LList<UnWGraphNode<T>* > copyNeighbors;
            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    Q.qpush(copyNeighbors.top());
                }
                copyNeighbors.pop();
            }
        }
    }

    void dfs(T vertex, LList<T>& l, bool automatic = true){

        l.empty();
        int noOfVertices = this->order();
        if(noOfVertices == 0){
            return;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        if(automatic == true){

            for(int i = 0; i < noOfVertices; i++){

                allVertices[i]->seen = false;
            }
        }

        LList<UnWGraphNode<T>* > S;  /// Search Stack
        S.push(&this->getNode(vertex));

        UnWGraphNode<T>* current;

        while(S.length() != 0){

            current = S.top();
            S.pop();

            if(current->seen == false){

                current->seen = true;
                l.qpush(current->data);
            }

            LList<UnWGraphNode<T>* > copyNeighbors;
            current->neighbors->assign(copyNeighbors);      /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                if(copyNeighbors.top()->seen == false){

                    S.push(copyNeighbors.top());
                }
                copyNeighbors.pop();
            }
        }
    }

    void topSort(LList<T>& l){     /// topological sorting

        if(this->directed == false){

            Errors(200);

            return;
        }

        if(this->order() == 0){

            return;
        }

        if(this->hasCycle() == true){

            Errors(201);

            return;
        }

        /// If we passed the previous tests, we have a directed acyclic graph with at least one node !

        int noOfVertices = this->order();
		UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references for each vertex in the graph !!
        int noOfVisited = 0;

		for(int i = 0; i < noOfVertices; i++){

			allVertices[i]->seen = false;
		}

		LList<T> lastDfs;

        while(noOfVisited < noOfVertices){

            for(int i = 0; i < noOfVertices; i++){

                if(allVertices[i]->seen == false){

                    this->dfs(allVertices[i]->data, lastDfs, false);
                    break;
                }
            }
            noOfVisited += lastDfs.length();

            while(lastDfs.length() != 0){

                l.push(lastDfs.top());
                lastDfs.pop();
            }
        }

        return;
    }
    /// BETA VERSION !!!

    int regular() const {       /// Checks if a graph is regular. Returns k if it is k regular or "-1" if it is't.

        int noOfVertices = this->order();
        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains all the vertices in the graph !

        if(noOfVertices == 0){

            return -1;
        }

        int k = allVertices[0]->deg();

        for(int i = 1; i < noOfVertices; i++){

            if(allVertices[i]->deg() != k){

                return -1;
            }
        }

        return k;
    }

    int connectedCmp(){

        int noOfVertices = this->order();

        if(noOfVertices == 0){
            return 0;
        }

        AVL<UnWGraphNode<T> > allVertices;
        allVertices = *this->vertices;

        int connectedComponents = 0;

        LList<T> seenVertices;

        UnWGraphNode<T> temp;

        while(allVertices.length() != 0){

            connectedComponents++;
            this->bfs(allVertices.min().data, seenVertices);    /// Automatically marks the visited vertices.

            while(seenVertices.length() != 0){

                temp.data = seenVertices.top();
                allVertices << temp;
                seenVertices.pop();
            }
        }

        return connectedComponents;
    }

    int kosaraju(){     /// returns the number of strongly connected components (components that are connected by more than one edge)

        return 3;
    }
    /// UNFINISHED BUSINESS !!!

    bool hasCmpCycle(T vertex){

        LList<T> l;
        return hasCmpCycleUtil(vertex, l);
    }

    bool hasCycle(){

        int noOfVertices = this->order();

        if(noOfVertices == 0){
            return false;
        }

        AVL<UnWGraphNode<T> > allVertices;
        allVertices = *this->vertices;

        /// int connectedComponents = 0;

        LList<T> seenVertices;
        bool answer;

        UnWGraphNode<T> temp;

        while(allVertices.length() != 0){

            answer = this->hasCmpCycleUtil(allVertices.min().data, seenVertices);    /// Automatically marks the visited vertices.

            if(answer == true){

                return true;
            }

            while(seenVertices.length() != 0){

                temp.data = seenVertices.top();
                allVertices << temp;
                seenVertices.pop();
            }
        }

        return false;
    }

    bool isSimple(){

        return true;
    }
    /// UNFINISHED BUSINESS !!!

    bool isBipartite(){

        return true;
    }
    /// UNFINISHED BUSINESS !!!

    void replace(T oldData, T newData){

        UnWGraphNode<T>* oldNode = &this->getNode(oldData);
        int degree = oldNode->deg();

        UnWGraphNode<T>* allNeighbors[degree];
        oldNode->neighbors->bfs(allNeighbors);  /// The array allNeighbors contains references to for each vertex in the graph !

        /// Undirected Graph

        if(this->directed == false){

            (*this) >> newData;

            if(degree == 0){

                (*this) << oldData;
                return;
            }

            for(int i = 0; i < degree; i++){

                insertEdge(allNeighbors[i]->data, newData);
            }
            (*this) << oldData;
            return;
        }

        /// Directed Graph

        (*this) >> newData;
        int noOfVertices = this->order();

        if(noOfVertices == 1){

            (*this) << oldData;
            return;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        for(int i = 0; i < noOfVertices; i++){  /// Drawing edges to the new Node.

            while(allVertices[i]->neighbors->search(oldNode) == true){  /// Could be multiple edges (Graph might not be simple)

                this->insertEdge(allVertices[i]->data, newData);
                this->removeEdge(allVertices[i]->data, oldData);
            }
        }

        for(int i = 0; i < degree; i++){

            insertEdge(allNeighbors[i]->data, newData);
        }

        (*this) << oldData;
        return;
    }

    bool operator==(const UnWGraph<T>& G) const {  /// checks whether the two graphs are isomorphic

        return false;
    }
    /// UNFINISHED BUSINESS !!!

    bool operator!=(const UnWGraph<T>& G) const {  /// checks whether the two graphs are not isomorphic

        return !(*this == G);
    }

    bool operator<(const UnWGraph<T>& G) const {  /// checks whether *this is a subgraph of G but not isomorphic

        return false;
    }
    /// UNFINISHED BUSINESS !!!

    bool operator>(const UnWGraph<T>& G) const {  /// checks whether G is a subgraph of *this but not isomorphic

        return (G < *this);
    }

    bool operator<=(const UnWGraph<T>& G) const {  /// checks whether *this is a subgraph of G, or if they're isomorphic

        if(*this == G){
            return true;
        }

        return (*this < G);
    }

    bool operator>=(const UnWGraph<T>& G) const {  /// checks whether G is a subgraph of *this, or if they're isomorphic

        if(*this == G){
            return true;
        }

        return (G < *this);
    }

    UnWGraph& clear(){  /// removes all edges

        int noOfVertices = this->order();
        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains pointers to all the vertices in the graph !

        for(int i = 0; i < noOfVertices; i++){

            allVertices[i]->neighbors->empty();
        }

        this->noOfEdges = 0;

        return *this;
    }

    UnWGraph& empty(){  /// removes all vertices

        this->vertices->empty();
        this->noOfEdges = 0;

        return *this;
    }

    UnWGraph& complete(){  /// removes all vertices

        this->clear();

        int noOfVertices = this->order();

        if(noOfVertices < 2){

            return *this;
        }

        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains pointers to all the vertices in the graph !

        bool initialState = this->directed;
        this->directed = false;     /// insertEdge works differently in directed and undirected graphs !

        for(int i = 0; i < noOfVertices; i++){

            for(int j = i + 1; j < noOfVertices; j++){

                this->insertEdge(allVertices[i]->data, allVertices[j]->data);
            }
        }

        if(initialState == true){

            this->setDirected();
        }

        return *this;
    }

    UnWGraph& rebirth(){

        this->empty();
        this->directed = false;

        return *this;
    }

    void print(){

        int noOfVertices = this->order();
        UnWGraphNode<T>* allVertices[noOfVertices];
        this->vertices->referencesBfs(allVertices);       /// The array allVertices contains references to for each vertex in the graph !

        LList<UnWGraphNode<T>* > copyNeighbors;

        for(int i = 0; i < noOfVertices; i++){

            std::cout << allVertices[i]->data << ":";
            allVertices[i]->neighbors->assign(copyNeighbors);   /// The Linked List copyNeighbors contains all the neighbors of the current node !

            while(copyNeighbors.length() != 0){

                std::cout << " [" << copyNeighbors.top()->data << "]";
                copyNeighbors.pop();
            }
            std::cout << std::endl;
        }

        return;
    }
};

bool WEIGHT_CMP;    /// Changes how comparison operators work on WEdge structure
                    /// false: compare by neighbor address; true: compare by weight

template <class T>
struct WEdge{

    ///friend class WGraphNode<T>;

private:

    UnWGraphNode<T>* neighbor;
    int weight;

public:

    bool operator==(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight == E.weight);
        }

        return (this->neighbor == E.neighbor);
    }

    bool operator!=(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight != E.weight);
        }

        return (this->neighbor != E.neighbor);
    }

    bool operator<(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight < E.weight);
        }

        return (this->neighbor < E.neighbor);
    }

    bool operator>(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight > E.weight);
        }

        return (this->neighbor > E.neighbor);
    }

    bool operator<=(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight <= E.weight);
        }

        return (this->neighbor <= E.neighbor);
    }

    bool operator>=(const WEdge& E){

        if(WEIGHT_CMP == true){

            return (this->weight >= E.weight);
        }

        return (this->neighbor >= E.neighbor);
    }
};

}   /// End of namespace

#endif /// DATASTRUCTURES_H_INCLUDED
