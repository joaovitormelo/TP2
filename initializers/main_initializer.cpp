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
  delete _menuVereador;
  delete _menuPrefeito;
  delete _controllerEleitor;
  delete _controllerVereador;
  delete _controllerPrefeito;
  delete _menuEditarVereador;
  delete _menuEditarPrefeito;
  delete _menuEditarEleitor;
  delete _controllerDadosEleitor;
  delete _controllerDadosCandidato;
}

void MainInitializer::initializeCadastro()
{
  _controllerDadosEleitor = new ControllerDadosEleitor(_state);
  _controllerDadosCandidato = new ControllerDadosCandidato(_state);
  _menuEditarVereador = new MenuEditarCandidato<Vereador>("Editar Vereador", _state, _controllerDadosEleitor, _controllerDadosCandidato);
  _menuEditarPrefeito = new MenuEditarCandidato<Prefeito>("Editar Prefeito", _state, _controllerDadosEleitor, _controllerDadosCandidato);
  _menuEditarEleitor = new MenuEditarEleitor("Editar Eleitor", _state, _controllerDadosEleitor);
  _controllerEleitor = new ControllerEleitor(_state, _menuEditarEleitor, _controllerDadosEleitor);
  _controllerPrefeito = new ControllerCandidato<Prefeito>(_state, _menuEditarPrefeito, _controllerDadosEleitor, _controllerDadosCandidato);
  _controllerVereador = new ControllerCandidato<Vereador>(_state, _menuEditarVereador, _controllerDadosEleitor, _controllerDadosCandidato);
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