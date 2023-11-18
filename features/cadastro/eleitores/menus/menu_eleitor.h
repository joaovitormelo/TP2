#ifndef INF112_MENU_ELEITOR_H
#define INF112_MENU_ELEITOR_H
#include "state.h"
#include "menu.h"
#include "controller_eleitor.h"

// Menu com as ações possíveis para o cadastro dos eleitores

class MenuEleitor : public Menu
{
private:
  State *_state;
  ControllerEleitor *_controllerEleitor;

protected:
  virtual void inicializarOpcoes();

public:
  MenuEleitor(std::string label, State *state, ControllerEleitor *controllerEleitor);
};

#endif