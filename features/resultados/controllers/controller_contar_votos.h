#ifndef INF112_CONTROLLER_CONTAR_VOTOS_H
#define INF112_CONTROLLER_CONTAR_VOTOS_H
#include "state.h"
#include "global.h"

// Classe para controlar a contagem de votos de vereadores e prefeitos

class ControllerContarVotos
{
private:
  State *_state;

public:
  ControllerContarVotos(State *state);
  RetornoController contarVotosVereador();
  RetornoController contarVotosPrefeito();
};

#endif