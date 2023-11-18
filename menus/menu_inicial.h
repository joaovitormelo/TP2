#ifndef INF112_MENU_INICIAL_H
#define INF112_MENU_INICIAL_H
#include "menu.h"
#include "state.h"
#include "menu_cadastro.h"
#include "controller_votacao.h"

// Menu principal do programa

class MenuInicial : public Menu
{
private:
  State *_state;
  MenuCadastro *_menuCadastro;
  ControllerVotacao *_controllerVotacao;

protected:
  virtual void inicializarOpcoes();

public:
  MenuInicial(std::string label, State *state, MenuCadastro *menuCadastro, ControllerVotacao *controllerVotacao);
};

#endif