#include "main_initializer.h"

// Classe para inicializar, destruir e prover instâncias de todos os componentes do sistema

MainInitializer::MainInitializer()
{
  _state = new State();
  Vereador *reginaldo = new Vereador(119, "Reginaldo", "A", "B", 13, "PT", "Divinópolis");
  Vereador *cristiano = new Vereador(120, "Cristiano", "A", "B", 14, "PT", "Divinópolis");
  Prefeito *jose = new Prefeito(121, "José", "A", "B", 15, "PSTD", "California");
  Prefeito *andre = new Prefeito(122, "André", "A", "B", 16, "PT", "California");
  _state->setListaVereador({reginaldo, cristiano});
  _state->setListaPrefeito({jose, andre});
  reginaldo->votaVereador(reginaldo);
  reginaldo->votaPrefeito(jose);
  cristiano->votaVereador(reginaldo);
  cristiano->votaPrefeito(jose);
  jose->votaVereador(cristiano);
  jose->votaPrefeito(jose);
  andre->votaVereador(reginaldo);
  andre->votaPrefeito(andre);
  reginaldo->setTotalVotos(3);
  cristiano->setTotalVotos(1);
  jose->setTotalVotos(3);
  andre->setTotalVotos(1);

  initializeCadastro();
  initializeResultados();
  _controllerVotacao = new ControllerVotacao(_state, _controllerDadosEleitor, _controllerDadosCandidato);
  _menuInicial = new MenuInicial("Menu Inicial", _state, _menuCadastro, _controllerVotacao, _menuResultados);
}

MainInitializer::~MainInitializer()
{
  delete _menuInicial;
  destroyCadastro();
  destroyResultados();
  delete _controllerVotacao;
  delete _state;
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

void MainInitializer::initializeResultados()
{
  _controllerContarVotos = new ControllerContarVotos(_state);
  _menuContarVotos = new MenuContarVotos("Contagem de votos", _state, _controllerContarVotos);
  _controllerResultados = new ControllerResultados(_state, _menuContarVotos);
  _menuResultados = new MenuResultados("Menu Resultados", _state, _controllerResultados);
}

void MainInitializer::destroyCadastro()
{
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

void MainInitializer::destroyResultados()
{
  delete _menuResultados;
  delete _controllerResultados;
  delete _menuContarVotos;
  delete _controllerContarVotos;
}

void MainInitializer::iniciar()
{
  _menuInicial->executar();
}