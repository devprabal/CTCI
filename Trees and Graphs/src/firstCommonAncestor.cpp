#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node* parent;
    int level;
    Node(){}
    Node(int data, Node* left, Node* right, Node* parent, int level){
        this->data = data;
        this->left = left;
        this->right = right;
        this->level = level;
        this->parent = parent;
    }
};
Node* firstCommonAncestor(Node* node1, Node* node2){
if(node1 == NULL || node2 == NULL)
    return NULL;
    else
    {
        while(node1->parent!= node2->parent){
            if(node1->parent->level < node2->parent->level)
                node2 = node2->parent;
            else
                node1 = node1->parent;
        }
        return node1->parent;
    }
    

}
int main(int argc, char const *argv[])
{
    // making a binary tree
    Node* root = new Node;
    root->data = 5;
    root->level = 0;
    root->left = new Node(12, NULL, NULL, root, 1);
    root->right = new Node(18, NULL, NULL, root, 1);
    Node* r12 = root->left;
    Node* r18 = root->right;
    r12->left = new Node(40, NULL, NULL, r12, 2);
    r12->right = new Node(36, NULL,NULL, r12, 2);
    r18->left = new Node(24, NULL, NULL, r18, 2);
    r18->right = new Node(38, NULL, NULL, r18, 2);
    Node* r40 = r12->left;
    Node* r36 = r12->right;
    r40->right = new Node(2, NULL, NULL, r40, 3);
    Node* r2 = r40->right;
    r36->left = new Node(6, NULL, NULL, r36, 3);
    Node* r6 = r36->left;
    r6->right = new Node(8, NULL, NULL, r6, 4);
    Node* r24 = r18->left;
    Node* r38 = r18->right;
    r38->left = new Node(49, NULL,NULL, r38, 3);
    Node* r49 = r38->left;
    r49->right = new Node(23, NULL, NULL, r49, 4);

    //checking function firstCommonAncestor()
    Node* ancestor = firstCommonAncestor(r24, r49);
    cout<<ancestor->data<<"\n";
    
    return 0;
}
