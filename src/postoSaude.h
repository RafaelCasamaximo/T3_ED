#ifndef __POSTOSAUDE_H
#define __POSTOSAUDE_H

typedef void* PostoSaude;

//Função responsável para criar PostoSaude. Retorna um pointer instanciado.
PostoSaude criaPostoSaude(float x, float y);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void postoSaudeSetX(PostoSaude posto, float x);
void postoSaudeSetY(PostoSaude posto, float y);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
float postoSaudeGetX(PostoSaude posto);
float postoSaudeGetY(PostoSaude posto);

#endif
