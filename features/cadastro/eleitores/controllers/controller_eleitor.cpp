#include "controller_eleitor.h"
#include "iostream"
#include "string"

ControllerEleitor::ControllerEleitor(State *state, MenuEditarEleitor *menuEditarEleitor) : _state(state), _menuEditarEleitor(menuEditarEleitor) {}

RetornoController ControllerEleitor::listEleitor()
{
  std::cout << "Lista de Eleitores:" << std::endl;
  for (auto eleitor : _state->getListaEleitor())
    std::cout << "Nº TÍTULO: " << eleitor->getNumTitulo() << " NOME: " << eleitor->getNome() << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::addEleitor()
{
  int numTitulo;
  std::cout << "Cadastro de Eleitor:" << std::endl;
  std::cout << "Nº TÍTULO: ";
  numTitulo = readNumber<int>(
      [&](int numTitulo)
      { return true; });
}

RetornoController ControllerEleitor::viewEleitor()
{
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::editEleitor()
{
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::deleteEleitor()
{
  return RetornoController::Completo;
}