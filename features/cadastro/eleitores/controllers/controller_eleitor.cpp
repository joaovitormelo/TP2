#include "controller_eleitor.h"
#include "iostream"
#include "string"
#include "eleitor.h"

// Classe para controlar todas as operações com os eleitores

ControllerEleitor::ControllerEleitor(State *state, MenuEditarEleitor *menuEditarEleitor, ControllerDadosEleitor *controllerDadosEleitor) : _state(state), _menuEditarEleitor(menuEditarEleitor), _controllerDadosEleitor(controllerDadosEleitor) {}

RetornoController ControllerEleitor::listEleitor()
{
  std::cout << "Lista de Eleitores: " << std::endl;
  if (_state->getListaEleitor().size())
  {
    for (auto eleitor : _state->getListaEleitor())
      std::cout << "Nº TÍTULO: " << eleitor->getNumTitulo() << " NOME: " << eleitor->getNome() << std::endl;
  }
  else
    std::cout << "(Lista vazia)" << std::endl;
  hold();
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
      { return _controllerDadosEleitor->validaNumTitulo(numTitulo, false); });
  std::cout << "Nome: ";
  nome = readLine();
  std::cout << "Zona: ";
  zona = readLine();
  std::cout << "Seção: ";
  secao = readLine();
  _state->addEleitor(new Eleitor(numTitulo, nome, zona, secao));
  std::cout << "Eleitor adicionado!" << std::endl;
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::viewEleitor()
{
  int numTitulo;
  std::cout << "Informe o Nº Título: ";
  numTitulo = readNumber<int>();
  Eleitor *eleitor = _state->buscaEleitor(numTitulo);
  if (eleitor)
  {
    std::cout << "Dados do Eleitor:" << std::endl;
    std::cout << "Nº Titulo: " << eleitor->getNumTitulo() << std::endl;
    std::cout << "Nome: " << eleitor->getNome() << std::endl;
    std::cout << "Zona: " << eleitor->getZona() << std::endl;
    std::cout << "Seção: " << eleitor->getSecao() << std::endl;
    hold();
  }
  else
  {
    std::cout << "Eleitor não encontrado!" << std::endl;
  }
  return RetornoController::Completo;
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
    std::cout << "Edições finalizadas!" << std::endl;
  }
  else
  {
    std::cout << "Eleitor não encontrado!" << std::endl;
  }
  return RetornoController::Completo;
}

RetornoController ControllerEleitor::deleteEleitor()
{
  int numTitulo;
  std::cout << "Informe o Nº Título: ";
  numTitulo = readNumber<int>();
  Eleitor *eleitor = _state->buscaEleitor(numTitulo);
  if (eleitor)
  {
    _state->deletaEleitor(numTitulo);
    std::cout << "Eleitor deletado!" << std::endl;
  }
  else
  {
    std::cout << "Eleitor não encontrado!" << std::endl;
  }
  return RetornoController::Completo;
}