# Datastructures in C++

- C++ header file that implements a handfull of usefull datastructures as templated Classes: a Linked List, an AVL tree and I'm working on a Graph (not ready yet).

- Each data structure has about 15-25 methods (without counting the overloaded operators for comparison) that serves for sorting the data structure, to make use of common algorithms on the data structure. We may even explicitly cast a Linked List into an AVL and vice-versa.

- You will also find friendly comments in the code to understand what's going on. An example:

```cpp
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
```

- The main.cpp implements a versatile API used to test the data structures. Here is a labeled screenshoot: <br>
<img src="https://github.com/24Arys11/Programare-Orientata-pe-Obiecte/blob/master/Custom%20C%2B%2B%20headers/Sorted/Data%20Structures/Screenshot.jpg" alt="Screenshot" width="800"/>
