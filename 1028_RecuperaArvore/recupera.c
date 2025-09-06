struct TreeNode* adicionaNo(int num) {
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = num;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct TreeNode* recoverFromPreorder(char * S){
    struct TreeNode* pilha[1001];
    int topo = -1, posicao = 0;
    int qtd = strlen(S);

    while (posicao < qtd) {
        int nivel = 0;
        while (S[posicao] == '-') {
            nivel++;
            posicao++;
        }

        int num = 0;
        while (S[posicao] >= '0' && S[posicao] <= '9') {
            num = num * 10 + (S[posicao] - '0');
            posicao++;
        } 

        struct TreeNode* no = adicionaNo(num);
        while (topo >= nivel) {
            topo--; 
        }
        if (topo != -1) {
            struct TreeNode* a = pilha[topo];
            if (a->left == NULL) {
                a->left = no;
            } else {
                a->right = no;
            }
        }
        topo++;
        pilha[topo] = no;
    }
    if (topo == -1) return NULL;
    return pilha[0];
}