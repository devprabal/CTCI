# include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
/**
 * METHOD 1
 * O(n log n) time 
 * because we compute height at each node
 * height computation at each node takes us down the tree log n
 **/

int height(Node* root){
    if (root == nullptr)
        return -1;
    else
        return max(height(root->left),height(root->right))+1;
    
}
bool checkBalanced(Node* root){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    else{
        int leftHeight = 1+ height(root->left);
        int rightHeight = 1+ height(root->right);
        int rootHeight = max(leftHeight, rightHeight);
        int heightDiff = leftHeight - rightHeight;
        if ((abs(leftHeight - rightHeight)) > 1)
            return false;
        else
            return true;
    }
}

/**
 * METHOD 2
 * modify Method 1 so that function height() also checks if a node in balanced or not.
 * This requires height() to send an error message 
 * This can be INT_MIN value because -1 is already used to signal height of NULL node
 * takes O(n) time and O(H) space where H is the height of tree, H may not be log n.
 **/

int checkHeight(Node* root){
    if(root == nullptr)
        return -1;
    else{
        int leftHeight = checkHeight(root->left);
        if(leftHeight == INT8_MIN)
            return INT8_MIN;
        int rightHeight = checkHeight(root->right);
        if (rightHeight == INT8_MIN)
            return INT8_MIN;
        int rootHeight = max(leftHeight, rightHeight)+1;
        int heightDiff = leftHeight - rightHeight;
        if(abs(heightDiff)>1)
            return INT8_MIN;
        else
            return rootHeight;
    }
    
}

bool checkBalanced_method2(Node* root){
    if(checkHeight(root)!=INT8_MIN)
        return true;
    else
        return false;
}


int main(){
    Node* root = new Node;
    root->data = 8;
    root->left = new Node;
    root->left->data = 4;
    root->left->left  = nullptr;
    root->left->right = nullptr;
    root->right = nullptr;
    Node* node4 = root->left;
    node4->left = new Node;
    node4->left->data = 3;
    node4->left->left = nullptr;
    node4->left->right = nullptr;
    cout<<(checkBalanced(root)?"true\n":"false\n");
    cout<<(checkBalanced_method2(root)?"true\n":"false\n");
    return 0;
}