#include "controller_contar_votos.h"
#include <vector>
#include "candidato.h"

// Classe para controlar a contagem de votos de vereadores e prefeitos

ControllerContarVotos::ControllerContarVotos(State *state) : _state(state) {}

RetornoController ControllerContarVotos::contarVotosVereador()
{
  std::vector<Candidato *> listaVereadores = _state->getListaVereador();
  Candidato::sortCandidatoList(listaVereadores);
  for (auto vereador : listaVereadores)
    std::cout
        << "NÚMERO: " << vereador->getNumero() << " | NOME: " << vereador->getNome() << " | VOTOS: " << vereador->getTotalVotos() << std::endl;
  hold();
  return RetornoController::Completo;
}

RetornoController ControllerContarVotos::contarVotosPrefeito()
{
  std::vector<Candidato *> listaPrefeitos = _state->getListaPrefeito();
  Candidato::sortCandidatoList(listaPrefeitos);
  for (auto prefeito : listaPrefeitos)
    std::cout
        << "NÚMERO: " << prefeito->getNumero() << " | NOME: " << prefeito->getNome() << " | VOTOS: " << prefeito->getTotalVotos() << std::endl;
  hold();
  return RetornoController::Completo;
}