#include "menu_candidato.h"
#include "vereador.h"
#include "prefeito.h"

template <typename T>
MenuCandidato<T>::MenuCandidato(std::string label, State *state, ControllerCandidato<T> *controllerCandidato) : Menu(label), _state(state), _controllerCandidato(controllerCandidato)
{
  inicializarOpcoes();
}

template <typename T>
void MenuCandidato<T>::inicializarOpcoes()
{
  _opcaoList.push_back(OpcaoMenu("Listar", std::bind(&ControllerCandidato<T>::listCandidato, _controllerCandidato)));
  _opcaoList.push_back(OpcaoMenu("Adicionar", std::bind(&ControllerCandidato<T>::addCandidato, _controllerCandidato)));
  _opcaoList.push_back(OpcaoMenu("Visualizar", std::bind(&ControllerCandidato<T>::viewCandidato, _controllerCandidato)));
  _opcaoList.push_back(OpcaoMenu("Editar", std::bind(&ControllerCandidato<T>::editCandidato, _controllerCandidato)));
  _opcaoList.push_back(OpcaoMenu("Excluir", std::bind(&ControllerCandidato<T>::deleteCandidato, _controllerCandidato)));
  _opcaoList.push_back(OpcaoMenu("Voltar", std::bind(voltar)));
  _opcaoList.push_back(OpcaoMenu("Sair do programa", std::bind(sair)));
}

template class MenuCandidato<Vereador>;
template class MenuCandidato<Prefeito>;