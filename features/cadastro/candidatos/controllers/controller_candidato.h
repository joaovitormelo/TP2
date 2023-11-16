#ifndef INF112_CONTROLLER_CANDIDATO_H
#define INF112_CONTROLLER_CANDIDATO_H
#include "state.h"
#include "global.h"
#include "menu_editar_eleitor.h"

template <typename T>
class ControllerCandidato
{
private:
  State *_state;
  MenuEditarEleitor *_menuEditarEleitor;
  bool validaNumTitulo(int numTitulo);

public:
  ControllerCandidato(State *state, MenuEditarEleitor *menuEditarEleitor);
  RetornoController listCandidato();
  RetornoController addCandidato();
  RetornoController viewCandidato();
  RetornoController editCandidato();
  RetornoController deleteCandidato();
};

#endif