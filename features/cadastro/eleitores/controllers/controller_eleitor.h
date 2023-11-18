#ifndef INF112_CONTROLLER_ELEITOR_H
#define INF112_CONTROLLER_ELEITOR_H
#include "state.h"
#include "global.h"
#include "menu_editar_eleitor.h"
#include "controller_dados_eleitor.h"

// Classe para controlar todas as operações com os eleitores

class ControllerEleitor
{
private:
  State *_state;
  MenuEditarEleitor *_menuEditarEleitor;
  ControllerDadosEleitor *_controllerDadosEleitor;

public:
  ControllerEleitor(State *state, MenuEditarEleitor *menuEditarEleitor, ControllerDadosEleitor *controllerDadosEleitor);
  RetornoController listEleitor();
  RetornoController addEleitor();
  RetornoController viewEleitor();
  RetornoController editEleitor();
  RetornoController deleteEleitor();
  RetornoController importEleitor();
  RetornoController exportEleitor();
};

#endif