#ifndef INF112_CONTROLLER_CANDIDATO_H
#define INF112_CONTROLLER_CANDIDATO_H
#include "state.h"
#include "global.h"
#include "menu_editar_candidato.h"
#include "controller_dados_eleitor.h"
#include "controller_dados_candidato.h"

// Classe para controlar todas as operações com os candidatos (vereador ou prefeito)

template <typename T>
class ControllerCandidato
{
private:
  State *_state;
  MenuEditarCandidato<T> *_menuEditarCandidato;
  ControllerDadosEleitor *_controllerDadosEleitor;
  ControllerDadosCandidato *_controllerDadosCandidato;

public:
  ControllerCandidato(State *state, MenuEditarCandidato<T> *menuEditarCandidato, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *controllerDadosCandidato);
  RetornoController listCandidato();
  RetornoController addCandidato();
  RetornoController viewCandidato();
  RetornoController editCandidato();
  RetornoController deleteCandidato();
  RetornoController importCandidato();
  RetornoController exportCandidato();
};

#endif