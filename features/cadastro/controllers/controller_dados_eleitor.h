#ifndef INF112_CONTROLLER_DADOS_ELEITOR_H
#define INF112_CONTROLLER_DADOS_ELEITOR_H
#include "state.h"
#include "global.h"

class ControllerDadosEleitor
{
private:
  State *_state;
  bool validaNumTitulo(int numTitulo);

public:
  ControllerDadosEleitor(State *state);
  RetornoController editarNome();
  RetornoController editarNumTitulo();
  RetornoController editarZona();
  RetornoController editarSecao();
};

#endif