#include "controller_eleitor.h"
#include "iostream"
#include "string"
#include "eleitor.h"

ControllerEleitor::ControllerEleitor(State *state, MenuEditarEleitor *menuEditarEleitor) : _state(state), _menuEditarEleitor(menuEditarEleitor) {}

bool ControllerEleitor::validaNumTitulo(int numTitulo)
{
  if (_state->checaExisteNumTitulo(numTitulo))
  {
    std::cout << "Nº já cadastrado!" << std::endl;
    return false;
  }
  return true;
}

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
  std::string nome, zona, secao;
  std::cout << "Cadastro de Eleitor:" << std::endl;
  std::cout << "Nº Título: ";
  numTitulo = readNumber<int>(
      [&](int numTitulo)
      { return validaNumTitulo(numTitulo); });
  std::cout << "Nome: ";
  nome = readLine();
  std::cout << "Zona: ";
  zona = readLine();
  std::cout << "Seção: ";
  secao = readLine();
  _state->addEleitor(new Eleitor(numTitulo, nome, zona, secao));
  std::cout << "Eleitor adicionado!";
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::viewEleitor()
{
}

RetornoController ControllerEleitor::editEleitor()
{
  int numTitulo;
  std::cout << "Informe o Nº Título: ";
  numTitulo = readNumber<int>();
  Eleitor *eleitor = _state->buscaEleitor(numTitulo);
  if (eleitor)
  {
    _state->setEleitorEdit(eleitor);
    _menuEditarEleitor->executar();
  }
  else
  {
    std::cout << "Eleitor não encontrado!";
  }
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::deleteEleitor()
{
  return RetornoController::Completo;
}