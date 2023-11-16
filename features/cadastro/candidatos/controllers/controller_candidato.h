#ifndef INF112_CONTROLLER_CANDIDATO_H
#define INF112_CONTROLLER_CANDIDATO_H
#include "state.h"
#include "global.h"
#include "menu_editar_eleitor.h"
#include "controller_dados_eleitor.h"

// Classe para controlar todas as operações com os candidatos (vereador ou prefeito)

template <typename T>
class ControllerCandidato
{
private:
  State *_state;
  MenuEditarEleitor *_menuEditarEleitor;
  ControllerDadosEleitor *_controllerDadosEleitor;

public:
  ControllerCandidato(State *state, MenuEditarEleitor *menuEditarEleitor, ControllerDadosEleitor *controllerDadosEleitor);
  RetornoController listCandidato();
  RetornoController addCandidato();
  RetornoController viewCandidato();
  RetornoController editCandidato();
  RetornoController deleteCandidato();
};

#endif