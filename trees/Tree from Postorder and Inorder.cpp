/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node* solution(int in[], int post[],int is,int ie,int &postIndex)
    {
      if(is>ie)
      return NULL;
      
      Node*root = new Node(post[postIndex--]);
      
      int Index;
      
      for(int i=is;i<=ie;i++)
      {
          if(in[i]==root->data)
          {
              Index=i;
              break;
          }
      }
      
      
      root->right = solution(in,post,Index+1,ie,postIndex);
      root->left = solution(in,post,is,Index-1,postIndex);
      
      return root;
      
    }
    
    
    Node* buildTree(int in[],int post[], int n)
    {
        // Code here
        int postIndex=n-1;
       return solution(in,post,0,n-1,postIndex);
    }
