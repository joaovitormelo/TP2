#ifndef INF112_MENU_CONTAR_VOTOS_H
#define INF112_MENU_CONTAR_VOTOS_H
#include "state.h"
#include "menu.h"
#include "controller_contar_votos.h"

// Menu com opções para contagem de votos (vereador ou prefeito)

class MenuContarVotos : public Menu
{
private:
  State *_state;
  ControllerContarVotos *_controllerContarVotos;

protected:
  virtual void inicializarOpcoes();

public:
  MenuContarVotos(std::string label, State *state, ControllerContarVotos *controllerContarVotos);
};

#endif