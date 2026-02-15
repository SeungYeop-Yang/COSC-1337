#include <stdexcept>

class Sequence {
    int* items;
    int size, used;
public:

    friend BinaryTree* BinaryTree::BinaryTree(Sequence*, int, int);
    friend Node* MakeTree(Sequence*, int, int);

    Sequence(int n) : size(n), used(0) {
        items = new int[size];
    }
    ~Sequence() {
        delete[] items;
    }
    void insert(int x) {
        if (used < size) {
            items[used++] = x;
        }
    }
    int get(int i) const {
        if (i >= 0 && i < used) {
            return items[i];
        }
        throw std::out_of_range("Index out of range");
    }
    int length() const {
        return used;
    }
};

struct Node {
    int item;
    Node* left;
    Node* right;
}

class BinaryTree {
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(Sequence*, int, int);
};

BinaryTree::BinaryTree(Sequence* seq, int low=0, int high=0) {
    if (high == 0) {
        high = seq->used;
    }
    root = (low > high || low < 0 || high > seq->used) ? nullptr
    : MakeTree(seq, low, high);
}

Node* MakeTree(Sequence* seq, int low, int high)
{
    int mid = (low + high) / 2;
    Node* node = new Node;
    if (node != nullptr) {
        node->item = seq->items[mid];
        node->left = (mid <= low ? nullptr : MakeTree(seq, low, mid-1));
        node->right = (mid >= high ? nullptr : MakeTree(seq, mid+1, high));
    }
    return node;
}
