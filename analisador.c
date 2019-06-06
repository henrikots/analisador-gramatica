#include<stdio.h>
#include<stdlib.h>

/*
 * S -> aBc$
 * B -> bB | e
 *
 */
char lookahead;

int  match(char t, char palavra[], int *pos){
	if (lookahead == t){
		lookahead= palavra[++(*pos)];
		return(1);
	}
	return(0);  
}

int S(char palavra[], int *pos){
	if (T(palavra, pos) && K(palavra, pos)){
	   	return(1);
	}
	return(0);
}

int K(char palavra[], int *pos){
	if(lookahead == '+'){
		if(match('+', palavra, pos) && 
					T(palavra, pos) && 
					K(palavra, pos)){
			return(1);				
		}
	} else if(lookahead == '-'){
		if(match('-', palavra, pos) && 
					T(palavra, pos) && 
					K(palavra, pos)){
			return(1);				
		}
	} else {
		return(0);
	}
}

int B(char palavra[], int *pos){
	if (lookahead == 'b'){
		if (match('b', palavra, pos) &&
		    B(palavra, pos)          )
	   	return(1);
	} else return(1);
}

void trataErro(int pos){
	printf("\n\nERRO DE SINTAXE na posi??o %d\n\n", pos);
	/* Faca um tratamento melhor */
}

int main(){
	char palavra[]= "abbbcc$";
	int  pos=0;
	
	lookahead= palavra[0];
	if (S(palavra, &pos))
	    printf("\nPalavra %s reconhecida\n", palavra);
	else 
	    trataErro(pos);
	system("PAUSE");
	return(0);
	
}

