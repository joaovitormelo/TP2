#ifndef INF112_MENU_CADASTRO_H
#define INF112_MENU_CADASTRO_H
#include "state.h"
#include "menu.h"
#include "menu_eleitor.h"

class MenuCadastro : public Menu
{
private:
  State *_state;
  MenuEleitor *_menuEleitor;

protected:
  virtual void inicializarOpcoes();

public:
  MenuCadastro(std::string label, State *state, MenuEleitor *menuEleitor);
};

#endif