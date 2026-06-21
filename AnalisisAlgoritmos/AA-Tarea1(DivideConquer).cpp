#include <iostream>
#include <vector>
#include <algorithm>

/*
Grupo: Analisis y Datos
Mateo Gael Figueroa Chavez
Ostin Lisandro Colque rivas
Nataly Ramirez Machicado

*/
// Obtener el k-simo numero mas grande de un array no ordenado, sin ordenar
int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] > pivot) { // para k-th largest
            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    std::swap(nums[i], nums[right]);
    return i;
}

int quickSelect(std::vector<int>& nums, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k)
            return nums[pivotIndex];

        if (pivotIndex > k)
            return quickSelect(nums, left, pivotIndex - 1, k);
        else
            return quickSelect(nums, pivotIndex + 1, right, k);
    }

    return -1;
}

int findKthLargest(std::vector<int>& nums, int k) {
    // k = 0 -> [mayor1, mayo2 ....
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
}

// llevar un array a un arbol el array es ordenado
struct Nodo {
private:
    int val;
    Nodo* left;
    Nodo* right;
public:
    Nodo(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
    int getVal()
    {
        return val;
    }
    Nodo*& getLeft()
    {
        return left;
    }
    Nodo*& getRight()
    {
        return right;
    }
};
struct Tree {

private:
    Nodo* Raiz;
public:
    Tree()
    {
        Raiz = NULL;
    }
    Nodo* getRaiz()
    {
        return Raiz;
    }

    void agregar(Nodo* raiz, int x)
    {
        if (Raiz = NULL)
        {
            Raiz = new Nodo(x);
        }
        else
        {
            if (Raiz->getVal() < x)
            {
                agregar(raiz->getLeft(), x);
            }
            if (Raiz->getVal() > x)
            {
                agregar(raiz->getRight(), x);
            }
        }
    }
    void ArrayATree(int numeros[], int tam)
    {
        Tree Arbol;
        int j = tam - 1;
        for (int i = tam / 2; i >= 0; i--)
        {
            agregar(Arbol.getRaiz(), numeros[i]);
            if (j > tam / 2)
            {
                agregar(Arbol.getRaiz(), numeros[j]);
                j--;
            }
        }
    }
};


// Simple conected list to Tree

struct ListNode
{
    int val;
    ListNode* next;
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// contar la cantidad de elementos que tiene la lista
int getSize(ListNode* head)
{
    int n = 0;
    while (head)
    {
        n++;
        head = head->next;
    }
    return n;
}


TreeNode* buildBST(ListNode*& head, int left, int right) {
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2; // medio de la lista

    TreeNode* leftChild = buildBST(head, left, mid - 1);// retrocediento del medio hasta el inicio

    TreeNode* root = new TreeNode(head->val);
    root->left = leftChild;

    head = head->next;

    root->right = buildBST(head, mid + 1, right); // avanzando del medio hasta el final

    return root;
}


// Metodo Main
TreeNode* sortedListToBST(ListNode* head) {
    int n = getSize(head);
    return buildBST(head, 0, n - 1);
}


int main() {

    int numeros[5] = { 4,2,3,1,5 };
    std::vector<int> vec = { 7,3,6,1,-100 };
    std::cout << findKthLargest(vec, 2);

    return 0;
}