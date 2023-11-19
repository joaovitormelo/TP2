#include "controller_resultados.h"
#include "candidato.h"

// Classe para controlar a visualização dos resultados

ControllerResultados::ControllerResultados(State *state, MenuContarVotos *menuContarVotos) : _state(state), _menuContarVotos(menuContarVotos) {}

RetornoController ControllerResultados::contarVotos()
{
  _menuContarVotos->executar();
  return RetornoController::Completo;
}

RetornoController ControllerResultados::mostrarEleitos()
{
  std::cout << "Prefeito eleito:" << std::endl;
  std::vector<Candidato *> listaPrefeitos = _state->getListaPrefeito();
  Candidato::sortCandidatoList(listaPrefeitos);
  std::cout
      << "NÚMERO: " << listaPrefeitos[0]->getNumero() << " | NOME: " << listaPrefeitos[0]->getNome() << " | VOTOS: " << listaPrefeitos[0]->getTotalVotos() << std::endl;

  std::cout << "Vereadores eleitos:" << std::endl;
  std::vector<Candidato *> listaVereadores = _state->getListaVereador();
  Candidato::sortCandidatoList(listaVereadores);
  for (int i = 0; i < 10 && i < listaVereadores.size(); i++)
    std::cout
        << "NÚMERO: " << listaVereadores[i]->getNumero() << " | NOME: " << listaVereadores[i]->getNome() << " | VOTOS: " << listaVereadores[i]->getTotalVotos() << std::endl;

  return RetornoController::Completo;
}