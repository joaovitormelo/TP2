#ifndef INF112_CONTROLLER_VOTACAO_H
#define INF112_CONTROLLER_VOTACAO_H
#include "state.h"
#include "global.h"
#include "candidato.h"
#include "eleitor.h"
#include "prefeito.h"
#include "controller_dados_eleitor.h"
#include "controller_dados_candidato.h"

// Classe para controlar o processo de votação dos candidatos

class ControllerVotacao
{
private:
  State *_state;
  ControllerDadosEleitor *_controllerDadosEleitor;
  ControllerDadosCandidato *_controllerDadosCandidato;
  void votaVereador(Eleitor *eleitor);
  void votaPrefeito(Eleitor *eleitor);

public:
  ControllerVotacao(State *state, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *controllerDadosCandidato);
  RetornoController realizaVotacao();
};

#endif