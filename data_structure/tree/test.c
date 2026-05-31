/* Testes para as funções de árvore */
/*** Compile and build: gcc test.c src/tree.c src/t_utils.c -Iinclude -o
 * build/test  ****/
/*** Execute: ./build/test ****/

#include "t_utils.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// Macro auxiliar para exibir resultado
#define TEST(nome, condicao)                                                   \
  do {                                                                         \
    if (condicao)                                                              \
      printf("✅ PASSOU: %s\n", nome);                                         \
    else                                                                       \
      printf("❌ FALHOU: %s\n", nome);                                         \
  } while (0)

int main() {

  printf("\n=============================\n");
  printf("TESTES - tree.c");
  printf("\n=============================\n");

  TNode *root = NULL;
  insert_node(&root, 10);
  TNode *node_10 = search_node(root, 10);
  TEST("Teste de apenas 1 nó: Nó 10 left NULL e right NULL",
       node_10 != NULL && 
       node_10->data == 10 && 
       node_10->left == NULL &&
       node_10->right == NULL);
  printf("\n");

  root = NULL;
  int data_values[] = {50, 30, 70, 80, 20, 40, 60, 10};
  int len = sizeof(data_values) / sizeof(data_values[0]);
  printf("Valores: ");
  for (int i = 0; i < len; i++) {
    int data = data_values[i];
    printf("%d ", data);
    insert_node(&root, data);
  }
  printf("\n");

  TNode *node_50 = search_node(root, 50);
  TEST("Nó 50 encontrado", node_50 != NULL && node_50->data == 50);
  int test_no_50_not_null = node_50 != NULL;
  int test_no_50_data_equal_50 = test_no_50_not_null ? node_50->data == 50 : 0;
  int test_no_50_left_data_equal_30 = test_no_50_not_null ? node_50->left != NULL && node_50->left->data == 30 : 0;
  int test_no_50_right_data_equal_70 = test_no_50_not_null ? node_50->right != NULL && node_50->right->data == 70 : 0;

  TEST("Filhos do nó 50: 30 left, 70 right",
      test_no_50_not_null &&
      test_no_50_data_equal_50 &&
      test_no_50_left_data_equal_30 &&
      test_no_50_right_data_equal_70);
  printf("\n");

  TNode *node_100_dont_searched = search_node(root, 100);
  TEST("Nó 100 não encontrado", node_100_dont_searched == NULL);
  printf("\n");

  printf("Níveis: ");
  print_tree(root, 2);
  printf("\n");

  remove_node(&root, 30);
  TNode *node_30_dont_searched = search_node(root, 30);
  TEST("Nó 30 removido", node_30_dont_searched == NULL);
  printf("\n");

  printf("Níveis: ");
  print_tree(root, 2);
  printf("\n");

  remove_node(&root, 50);
  TNode *node_50_dont_searched = search_node(root, 50);
  TEST("Nó 50 removido", node_50_dont_searched == NULL);
  printf("\n");

  printf("Níveis: ");
  print_tree(root, 2);
  printf("\n");

  printf("In-order: ");
  in_order(root);
  printf("\n");

  printf("Pre-order: ");
  pre_order(root);
  printf("\n");

  printf("Post-order: ");
  post_order(root);
  printf("\n");

  free_tree(root);

  printf("\n=============================\n");
  printf("FIM DOS TESTES - tree.c");
  printf("\n=============================\n\n");

  return 0;
}
