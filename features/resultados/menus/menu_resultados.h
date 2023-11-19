#ifndef INF112_MENU_RESULTADOS_H
#define INF112_MENU_RESULTADOS_H
#include "state.h"
#include "menu.h"
#include "controller_resultados.h"

// Menu com ações para visualização dos resultados

class MenuResultados : public Menu
{
private:
  State *_state;
  ControllerResultados *_controllerResultados;

protected:
  virtual void inicializarOpcoes();

public:
  MenuResultados(std::string label, State *state, ControllerResultados *controllerResultados);
};

#endif