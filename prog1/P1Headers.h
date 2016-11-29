

struct node{
  struct node* leftChild;
  struct node* rightChild;
  char* key;
};
typedef struct node* nodeptr;
typedef struct node node;

unsigned int heightT(nodeptr node);
unsigned int countLeaf(nodeptr node);
unsigned int strNum(nodeptr node);
nodeptr createNode(char* inpNode);
nodeptr  insert(nodeptr prnt, char* inpStr);

