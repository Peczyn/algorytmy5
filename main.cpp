#include <iostream>
#include <algorithm>
using namespace std;


class BST
{
public:
     int val;
     BST* left;
     BST* right;
     BST* parent;

     BST();
     BST(int);


    static BST* Insert(BST* root, int);
    static BST* Delete(BST* root, int);

    static void printTreePreOrder(BST* node);
    static void printTreePostOrder(BST* node);
    static void printTreeInOrder(BST* node);

    static BST* min(BST* root);
    static BST* max(BST* root);

    int height(BST* root,int h);

    static BST* inOrderSuccessor(BST* root, int value);
    static BST* inOrderPredeccessor(BST* root, int value);
};

BST::BST(): val(0), right(nullptr), left(nullptr){}
BST::BST(int value): val(value), right(nullptr), left(nullptr) {}

BST* BST::Insert(BST *root, int value) {
    if(!root)
    {
        return new BST(value);
    }
    else if(value < root->val)
    {
        root->left = Insert(root->left, value);
        root->left->parent = root;
    }
    else
    {
        root->right = Insert(root->right, value);
        root->right->parent = root;
    }
    return root;
}
BST* BST::Delete(BST *root, int value) { //z jakiegos powodu wywalalo mi errora przy starym kodzie wiec zmodyfikowalem ta funkcje
    if (value < root->val) {
        root->left = Delete(root->left, value);
    } else if (value > root->val) {
        root->right = Delete(root->right, value);
    } else {
        // Węzeł do usunięcia został znaleziony

        // Przypadek 1: Brak lub jedno dziecko
        if (root->left == nullptr) {
            BST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BST* temp = root->left;
            delete root;
            return temp;
        }

        // Przypadek 2: Dwa dzieci - znalezienie najmniejszego węzła w prawym poddrzewie
        BST* temp = BST::min(root->right);

        // Skopiowanie wartości najmniejszego węzła do bieżącego węzła
        root->val = temp->val;

        // Usunięcie najmniejszego węzła w prawym poddrzewie
        root->right = Delete(root->right, temp->val);
    }

    return root;
}


void BST::printTreePreOrder(BST *node) {
    if(!node)
    {
        return;
    }
    cout << node->val << '\t';
    printTreePreOrder(node->left);
    printTreePreOrder(node->right);
}
void BST::printTreePostOrder(BST *node) {
    if(!node)
    {
        return;
    }
    printTreePostOrder(node->left);
    printTreePostOrder(node->right);
    cout << node->val << '\t';
}
void BST::printTreeInOrder(BST *node) {
    if(!node)
    {
        return;
    }
    printTreeInOrder(node->left);
    cout << node->val << '\t';
    printTreeInOrder(node->right);

}

BST *BST::max(BST *root) {
    if(!root->right)
    {
        return root;
    }
    return max(root->right);
}
BST *BST::min(BST *root) {
    if(!root->left)
    {
        return root;
    }
    return min(root->left);
}

int BST::height(BST *root, int h) {
    if(!root)
    {
        return h;
    }
    return ::max(height(root->left,h),height(root->right,h))+1;
}

BST *BST::inOrderSuccessor(BST *root, int value) {
    if(root->val == value)
    {
        cout << "Successor: " << root->right->val;
        return root->right;
    }
    else if(root->val > value)
    {
        inOrderSuccessor(root->left,value);
    }
    else
    {
        inOrderSuccessor(root->right,value);
    }
    return nullptr;
}
BST *BST::inOrderPredeccessor(BST *root, int value) {
    if(root->val == value)
    {
        cout << "Successor: " << root->left->val;
        return root->left;
    }
    else if(root->val > value)
    {
        inOrderPredeccessor(root->left,value);
    }
    else
    {
        inOrderPredeccessor(root->right,value);
    }
    return nullptr;
}



//int main() {
//    BST *root = NULL;
//    root = BST::Insert(root,22);
//    root = BST::Insert(root,12);
//    root = BST::Insert(root,30);
//    root = BST::Insert(root,8);
//    root = BST::Insert(root,20);
//    root = BST::Insert(root,25);
//    root = BST::Insert(root,40);
//
//
////    BST::printTreePostOrder(root);
////    BST::printTreePreOrder(root);
////    BST::printTreeInOrder(root);
//
////    BST* max = BST::max(root);
////    BST* min = BST::min(root);
//
////    cout << root->height(root,0);
//
////    root->inOrderPredeccessor(root,12);
////    root->inOrderSuccessor(root,12);
//
//
//    return 0;
//}

//Tak powinno wygladac drzewko po implementacji
/*
            22
    12              30
8       20      25      40

1. Napisz trzy funkcję do przechodzenia drzewa BST i wypisz wynik:
    a. PreOrder,
    b. PostOrder,
    c. InOrder.
2. Napisz funkcję, która znajdzie w strukturze drzewa:
    a. Minimum,
    b. Maksimum.
3. Napisz funkcje, która obliczy wysokość drzewa,
4. Napisz funkcję, która znajdzie:
    a. Następnika podanego węzła,
    b. Poprzednika podanego węzła.
5. Napisz funkcję, która:
    a. Wstawi podany element w odpowiednie miejsce drzewa,
    b. Usunie podany element.
*/