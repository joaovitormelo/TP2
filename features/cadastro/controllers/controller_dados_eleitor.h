#ifndef INF112_CONTROLLER_DADOS_ELEITOR_H
#define INF112_CONTROLLER_DADOS_ELEITOR_H
#include "state.h"
#include "global.h"

class ControllerDadosEleitor
{
private:
  State *_state;

public:
  ControllerDadosEleitor(State *state);
  RetornoController editarNome();
  RetornoController editarNumTitulo();
  RetornoController editarZona();
  RetornoController editarSecao();
  bool validaNumTitulo(int numTitulo, bool isEdit);
};

#endif