/** binary tree representation */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TNode *create_node(int data) {
  TNode *new_node = (TNode *)malloc(sizeof(TNode));
  if (new_node == NULL) {
    perror("malloc failed");
    return NULL;
  }
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(TNode **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }
  if (data > (*root)->data) {
    insert_node(&(*root)->right, data);
  } else {
    insert_node(&(*root)->left, data);
  }
}

//Os nós são visitados antes dos filhos, ou seja, 
//a raiz é processada primeiro, seguida pela subárvore esquerda e depois pela subárvore direita.
void pre_order(TNode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

//Os nós são visitados em ordem, ou seja, a subárvore esquerda é processada primeiro, 
//seguida pela raiz e depois pela subárvore direita.
void in_order(TNode *root) {
  if (root != NULL) {
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
  }
}

//Os nós são visitados após os filhos, ou seja, a subárvore esquerda é processada primeiro,
//seguida pela subárvore direita e depois pela raiz.
void post_order(TNode *root) {
  if (root != NULL) {
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
  }
}

TNode *search_node(TNode *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }
  if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

void remove_node(TNode **root, int data) {
  if (*root == NULL) {
    return;
  }
  if (data < (*root)->data) {
    remove_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    remove_node(&(*root)->right, data);
  } else {// Nesse ponto encontramos o nó a ser removido
    // Node with only one child or no child
    if ((*root)->left == NULL) {
      TNode *temp = (*root)->right;
      free(*root);
      *root = temp;
    } else if ((*root)->right == NULL) {
      TNode *temp = (*root)->left;
      free(*root);
      *root = temp;
    } else {
      // Node with two children: Get the inorder successor
      TNode *temp = (*root)->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      (*root)->data = temp->data; // Copy the inorder successor's content to this node
      remove_node(&(*root)->right, temp->data); // Delete the inorder successor
    }
  }
}

void free_tree(TNode *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    printf("Liberando nó com valor: %d\n", root->data);
    free(root);
  }
}
