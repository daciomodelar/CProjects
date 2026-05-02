#include <stdio.h>
#include <string.h>

void main() {
	char _nome[20];
	int _idade;
	printf("Nome: ");
	scanf("%s", _nome);
	printf("Idade: ");
	scanf("%d", &_idade);

	printf("Seu nome é %s e você tem %d anos de idade\n", _nome, _idade);

}
