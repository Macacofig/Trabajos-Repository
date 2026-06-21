// #include <bits/stdc++.h> // Linux

#include <iostream>
#include <vector>
#include <algorithm>

#include <type_traits> 

#include <string>
#include <sstream>

// using namespace std; -> carga todas las librerias
 
// Type aliases for faster typing
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;

// Overload for pairs
template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
// Overload for containers (except strings)
template<typename T_container,
    typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value,
    typename T_container::value_type>::type> std::ostream& operator<<(std::ostream& os, const T_container& v) {
    os << '{';
    std::string sep;
    for (const T& x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// Debug macro (disabled in submissions)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

// Fast I/O
void enable_fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

/*
Build from command line:
# Standard compilation
g++/clang++ -std=c++17 -O2 -o <bin> <cpp file>
# With warnings and debug info
g++/clang++ -std=c++17 -O2 -Wall -Wextra -g -DLOCAL -o <bin> <cpp file>
*/



void ordenar1(const std::vector<int>& vec)//no se crean copias y no se modifica la variable
{}
void ordenar2(std::vector<int> vec)//se crean copias 
{}
void ordenar3(std::vector<int>& vec)//no se crean copias y se modifica la variable
{}


int maxElement(int numeros[], int left, int right)
{
    if (left == right)
    {
        return numeros[left];
    }
    int mid = (left + right) / 2;
    int max1 = maxElement(numeros, left, mid);
    int max2 = maxElement(numeros, mid + 1, right);
    
    return std::max(max1, max2);
}

std::pair<int,int> maxMin(int numeros[], int left, int right)
{
    std::pair<int, int> resultado;
    if (left == right)
    {
        resultado.first = numeros[left];
        resultado.second = numeros[left];
        return  resultado;
    }
    if (right == left + 1)
    {
        if (numeros[left] < numeros[right])
        {
            resultado.first = numeros[left];
            resultado.second = numeros[right];
            return  resultado;
        }
        else
        {
            resultado.first = numeros[right];
            resultado.second = numeros[left];
            return  resultado;
        }
    }
    int mid = (left + right) / 2;

    std::pair<int, int> maxMin1 = maxMin(numeros, left, mid);
    std::pair<int, int> maxMin2 = maxMin(numeros, mid + 1, right);

    resultado.first = std::min(maxMin1.first, maxMin2.first);
    resultado.first = std::min(maxMin1.second, maxMin2.second);

    return resultado;
}

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

    void agregar(Nodo* raiz,int x)
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
        for (int i = tam/2; i >= 0; i--)
        {
            agregar(Arbol.getRaiz(), numeros[i]);
            if (j > tam/2)
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
    //enable_fast_io();
    /*
    int t;
    std::cin >> t;
    while (t--) {
        // Your solution here
    }*/

    int numeros[5] = { 4,2,3,1,5 };
    std::vector<int> vec = { 7,3,6,1,-100 };
    std::cout << findKthLargest(vec,2);

    return 0;
}

