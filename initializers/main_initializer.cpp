#include "main_initializer.h"

MainInitializer::MainInitializer()
{
  _state = new State();
  _state->setListaEleitor({new Eleitor(111, "João Vitor", "Zona A", "Seção B")});
  _state->setListaVereador({new Vereador(112, "Reginaldo", "Zona A", "Seção B", 13, "PT", "Viçosa")});
  initializeCadastro();
  _menuInicial = new MenuInicial("Menu Inicial", _state, _menuCadastro);
}

MainInitializer::~MainInitializer()
{
  delete _menuInicial;
  delete _menuCadastro;
  delete _menuEleitor;
  delete _controllerEleitor;
  delete _menuEditarEleitor;
  delete _controllerDadosEleitor;
}

void MainInitializer::initializeCadastro()
{
  _controllerDadosEleitor = new ControllerDadosEleitor(_state);
  _menuEditarEleitor = new MenuEditarEleitor("Editar Eleitor", _state);
  _controllerEleitor = new ControllerEleitor(_state, _menuEditarEleitor, _controllerDadosEleitor);
  _controllerPrefeito = new ControllerCandidato<Prefeito>(_state, _menuEditarEleitor, _controllerDadosEleitor);
  _controllerVereador = new ControllerCandidato<Vereador>(_state, _menuEditarEleitor, _controllerDadosEleitor);
  _menuEleitor = new MenuEleitor("Menu do Eleitor", _state, _controllerEleitor);
  _menuVereador = new MenuCandidato<Vereador>("Menu do Vereador", _state, _controllerVereador);
  _menuPrefeito = new MenuCandidato<Prefeito>("Menu do Prefeito", _state, _controllerPrefeito);
  _menuEleitor = new MenuEleitor("Menu do Eleitor", _state, _controllerEleitor);
  _menuCadastro = new MenuCadastro("Menu de Cadastro", _state, _menuEleitor, _menuVereador, _menuPrefeito);
}

void MainInitializer::iniciar()
{
  _menuInicial->executar();
}