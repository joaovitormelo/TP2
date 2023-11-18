#include "controller_dados_eleitor.h"

// Classe para controlar a manipulação de dados do eleitor

ControllerDadosEleitor::ControllerDadosEleitor(State *state) : _state(state) {}

bool ControllerDadosEleitor::validaNumTitulo(int numTitulo, bool isEdit)
{
  if (isEdit)
    if (_state->getEleitorEdit()->getNumTitulo() == numTitulo)
      return true;
  if (_state->checaExisteNumTitulo(numTitulo))
  {
    std::cout << "Nº Título já cadastrado!" << std::endl;
    return false;
  }
  return true;
}

RetornoController ControllerDadosEleitor::editarNumTitulo()
{
  int numTitulo;
  std::cout << "Valor atual: " << _state->getEleitorEdit()->getNumTitulo() << std::endl;
  std::cout << "Novo valor: ";
  numTitulo = readNumber<int>(
      [&](int numTitulo)
      {
        return validaNumTitulo(numTitulo, true);
      });
  _state->getEleitorEdit()->setNumTitulo(numTitulo);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerDadosEleitor::editarNome()
{
  std::string nome;
  std::cout << "Valor atual: " << _state->getEleitorEdit()->getNome() << std::endl;
  std::cout << "Novo valor: ";
  nome = readLine();
  _state->getEleitorEdit()->setNome(nome);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerDadosEleitor::editarSecao()
{
  std::string secao;
  std::cout << "Valor atual: " << _state->getEleitorEdit()->getSecao() << std::endl;
  std::cout << "Novo valor: ";
  secao = readLine();
  _state->getEleitorEdit()->setSecao(secao);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerDadosEleitor::editarZona()
{
  std::string zona;
  std::cout << "Valor atual: " << _state->getEleitorEdit()->getZona() << std::endl;
  std::cout << "Novo valor: ";
  zona = readLine();
  _state->getEleitorEdit()->setZona(zona);
  finalizarTela();
  std::cout << "Valor editado!" << std::endl;
  return RetornoController::Completo;
}