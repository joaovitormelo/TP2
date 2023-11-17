#include "menu_editar_eleitor.h"

MenuEditarEleitor::MenuEditarEleitor(std::string label, State *state, ControllerDadosEleitor *controllerDadosEleitor) : Menu(label), _state(state), _controllerDadosEleitor(controllerDadosEleitor)
{
  inicializarOpcoes();
}

void MenuEditarEleitor::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Nº Título", std::bind(&ControllerDadosEleitor::editarNumTitulo, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Nome", std::bind(&ControllerDadosEleitor::editarNome, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Zona", std::bind(&ControllerDadosEleitor::editarZona, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Seção", std::bind(&ControllerDadosEleitor::editarSecao, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
}