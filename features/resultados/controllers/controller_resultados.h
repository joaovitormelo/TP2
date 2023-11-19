#ifndef INF112_CONTROLLER_RESULTADOS_H
#define INF112_CONTROLLER_RESULTADOS_H
#include "global.h"
#include "state.h"
#include "menu_contar_votos.h"

// Classe para controlar a visualização dos resultados

class ControllerResultados
{
private:
  State *_state;
  MenuContarVotos *_menuContarVotos;

public:
  ControllerResultados(State *state, MenuContarVotos *menuContarVotos);
  RetornoController contarVotos();
  RetornoController mostrarEleitos();
};

#endif