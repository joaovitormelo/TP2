#include "controller_votacao.h"

// Classe para controlar o processo de votação dos candidatos

ControllerVotacao::ControllerVotacao(State *state, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *controllerDadosCandidato) : _state(state), _controllerDadosEleitor(controllerDadosEleitor), _controllerDadosCandidato(controllerDadosCandidato) {}

void ControllerVotacao::votaVereador(Eleitor *eleitor)
{
  int numero;
  std::cout << ">>> Informe o número do seu candidato para vereador: ";
  numero = readNumber<int>(
      [&](int numero)
      {
        if (!_state->checaExisteNumero(numero))
        {
          std::cout << "Candidato não existente!" << std::endl;
          return false;
        }
        Candidato *candidato = _state->buscaVereador(numero);
        if (!candidato)
        {
          std::cout << "O nº informado é de um candidato a prefeito!" << std::endl;
          return false;
        }
        return true;
      });
  Vereador *vereador = dynamic_cast<Vereador *>(_state->buscaVereador(numero));
  eleitor->votaVereador(vereador);
  vereador->setTotalVotos(vereador->getTotalVotos() + 1);
  std::cout << "Voto registrado!" << std::endl;
  std::cout << vereador->getTotalVotos() << std::endl;
}

void ControllerVotacao::votaPrefeito(Eleitor *eleitor)
{
  int numero;
  std::cout << ">>> Informe o número do seu candidato para prefeito: ";
  numero = readNumber<int>(
      [&](int numero)
      {
        if (!_state->checaExisteNumero(numero))
        {
          std::cout << "Candidato não existente!" << std::endl;
          return false;
        }
        Candidato *candidato = _state->buscaPrefeito(numero);
        if (!candidato)
        {
          std::cout << "O nº informado é de um candidato a vereador!" << std::endl;
          return false;
        }
        return true;
      });
  Prefeito *prefeito = dynamic_cast<Prefeito *>(_state->buscaPrefeito(numero));
  eleitor->votaPrefeito(prefeito);
  prefeito->setTotalVotos(prefeito->getTotalVotos() + 1);
  std::cout << "Voto registrado!" << std::endl;
  std::cout << prefeito->getTotalVotos() << std::endl;
}

RetornoController ControllerVotacao::realizaVotacao()
{
  int numTitulo, numero;
  std::cout << "Votação" << std::endl;
  std::cout << "Bem-vindo ao processo de votação!" << std::endl;
  std::cout << "Para sair, insira '-1' como Nº Título." << std::endl;
  while (1)
  {
    std::cout << ">>> Informe o Nº Título do eleitor: ";
    numTitulo = readNumber<int>(
        [&](int numTitulo)
        {
          if (numTitulo == -1)
            return true;
          if (!_state->checaExisteNumTitulo(numTitulo))
          {
            std::cout << "Eleitor não existente!" << std::endl;
            return false;
          }
          return true;
        });
    if (numTitulo == -1)
      break;
    Eleitor *eleitor = _state->buscaEleitorVotacao(numTitulo);
    if (eleitor->getVotoVereador())
    {
      std::cout << "Eleitor já votou!" << std::endl;
      continue;
    }
    votaVereador(eleitor);
    votaPrefeito(eleitor);
  }
  std::cout << "Processo de votação finalizado!" << std::endl;
  return RetornoController::Completo;
}