int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* pilha[10000]; 
    int topo = -1;

    struct TreeNode* no = root;

    while (no!= NULL || topo >= 0) {
        while (no != NULL) {
            pilha[++topo] = no; 
            no = no->left;
        }
        no = pilha[topo--]; 
        // Visitei um nó, decremento o k
        k--;
        if (k == 0) {
            return no->val;
        }
        no = no->right;
    }
    return 0;
}