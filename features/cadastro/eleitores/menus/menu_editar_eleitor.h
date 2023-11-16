#ifndef INF112_MENU_EDITAR_ELEITOR_H
#define INF112_MENU_EDITAR_ELEITOR_H
#include "state.h"
#include "menu.h"

class MenuEditarEleitor : public Menu
{
private:
  State *_state;

protected:
  virtual void inicializarOpcoes();

public:
  MenuEditarEleitor(std::string label, State *state);
};

#endif