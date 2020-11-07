#ifndef __POSTOSAUDE_H
#define __POSTOSAUDE_H

typedef void* PostoSaude;

PostoSaude criaPostoSaude(float x, float y);

void postoSaudeSetX(PostoSaude posto, float x);
void postoSaudeSetY(PostoSaude posto, float y);

float postoSaudeGetX(PostoSaude posto);
float postoSaudeGetY(PostoSaude posto);

#endif