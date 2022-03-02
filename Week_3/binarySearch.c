typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt{
    struct node* root;
} bt_t;

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int verifyValue(node_t node, int value){
    if (node.value == value){
        return 1;
    }
    if (node.left != NULL){
        if (node.left->value == value){
            return 1;
        }else if (verifyValue(*node.left, value)){
                return 1;
        }
    }
    if (node.right != NULL){
        if (node.right->value == value){
            return 1;
        }
        else if (verifyValue(*node.right, value)){
            return 1;
        }
    }
    return 0;
}
/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value){
    if(tree == NULL || tree->root == NULL){
        return 0;
    }
    return verifyValue(*tree->root, value);
}