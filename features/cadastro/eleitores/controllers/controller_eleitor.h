#ifndef INF112_CONTROLLER_ELEITOR_H
#define INF112_CONTROLLER_ELEITOR_H
#include "state.h"
#include "global.h"
#include "menu_editar_eleitor.h"

class ControllerEleitor
{
private:
  State *_state;
  MenuEditarEleitor *_menuEditarEleitor;
  bool validaNumTitulo(int numTitulo);

public:
  ControllerEleitor(State *state, MenuEditarEleitor *menuEditarEleitor);
  RetornoController listEleitor();
  RetornoController addEleitor();
  RetornoController viewEleitor();
  RetornoController editEleitor();
  RetornoController deleteEleitor();
};

#endif