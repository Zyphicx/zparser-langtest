#include <stdio.h>
#include "parserdefs.h"

void printTree(int indent, ParseNode *tree);

int main(int argc, char *argv[]){
    setupGrammar("grammarFile");
    
    if(argc <= 1)
        fprintf(stderr, "You need to input more than one argument\n");

    ParseNode *node = parseFile(argv[1]);
    

    printTree(0, node);

    deleteGrammar();

    return 0;
}

void printTree(int indent, ParseNode *tree){
	printf("%s:\n", tree->name);

	int i;
	for(i = 0; i < tree->childAmount; i++){
		ParseChild child = tree->children[i];

		int j;
		for(j = 0; j < indent; j++)
			printf("  ");

		if(child.type == CHILD_TOKEN){
			printf("%s\n", child.val.token->value);
		}
		else{
			printTree(indent + 1, child.val.node);
		}
	}	
}

int token_is_symbol(char *s, TokenType *t){
	*t = 0;
	switch(*s){
		case '+': *t = PLUS;		break;
		case '-': *t = MINUS;		break;
		case '*': *t = STAR; 		break;
		case '/': *t = SLASH;		break;
		case '^': *t = CARET;		break;
		case '=': *t = EQUALS;		break;
		case '(': *t = L_PAREN;		break;
		case ')': *t = R_PAREN;		break;
		default:	                return 0;
	}

    return 1;
}
