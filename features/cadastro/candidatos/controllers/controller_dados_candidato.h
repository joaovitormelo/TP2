#ifndef INF112_CONTROLLER_DADOS_CANDIDATO_H
#define INF112_CONTROLLER_DADOS_CANDIDATO_H
#include "state.h"
#include "global.h"

class ControllerDadosCandidato
{
private:
  State *_state;

public:
  ControllerDadosCandidato(State *state);
  bool validaNumero(int numero, bool isEdit);
};

#endif