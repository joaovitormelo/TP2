#ifndef INF112_MENU_INICIAL_H
#define INF112_MENU_INICIAL_H
#include "menu.h"
#include "state.h"
#include "menu_cadastro.h"

class MenuInicial : public Menu
{
private:
  State *_state;
  MenuCadastro *_menuCadastro;

protected:
  virtual void inicializarOpcoes();

public:
  MenuInicial(std::string label, State *state, MenuCadastro *menuCadastro);
};

#endif