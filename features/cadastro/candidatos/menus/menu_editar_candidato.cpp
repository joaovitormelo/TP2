#include "menu_editar_candidato.h"
#include "vereador.h"
#include "prefeito.h"

template <typename T>
MenuEditarCandidato<T>::MenuEditarCandidato(std::string label, State *state, ControllerDadosEleitor *controllerDadosEleitor, ControllerDadosCandidato *ControllerDadosCandidato) : Menu(label), _state(state), _controllerDadosEleitor(controllerDadosEleitor), _controllerDadosCandidato(ControllerDadosCandidato)
{
  inicializarOpcoes();
}

template <typename T>
void MenuEditarCandidato<T>::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Nº Título", std::bind(&ControllerDadosEleitor::editarNumTitulo, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Nome", std::bind(&ControllerDadosEleitor::editarNome, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Zona", std::bind(&ControllerDadosEleitor::editarZona, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Seção", std::bind(&ControllerDadosEleitor::editarSecao, _controllerDadosEleitor)));
  _opcaoList.push_back(OpcaoMenu("Número", std::bind(&ControllerDadosCandidato::editarNumero, _controllerDadosCandidato)));
  _opcaoList.push_back(OpcaoMenu("Nome do Partido", std::bind(&ControllerDadosCandidato::editarNomePartido, _controllerDadosCandidato)));
  _opcaoList.push_back(OpcaoMenu("Cidade", std::bind(&ControllerDadosCandidato::editarCidade, _controllerDadosCandidato)));
  _opcaoList.push_back(OpcaoMenu("Finalizar", std::bind(voltar)));
}

template class MenuEditarCandidato<Vereador>;
template class MenuEditarCandidato<Prefeito>;