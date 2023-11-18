#ifndef INF112_MENU_EDITAR_ELEITOR_H
#define INF112_MENU_EDITAR_ELEITOR_H
#include "state.h"
#include "menu.h"
#include "controller_dados_eleitor.h"

// Menu com as opções de edição de eleitor

class MenuEditarEleitor : public Menu
{
private:
  State *_state;
  ControllerDadosEleitor *_controllerDadosEleitor;

protected:
  virtual void inicializarOpcoes();

public:
  MenuEditarEleitor(std::string label, State *state, ControllerDadosEleitor *controllerDadosEleitor);
};

#endif