#include "controller_candidato.h"
#include "vereador.h"
#include "prefeito.h"
#include "iostream"
#include "string"
#include <vector>
#include <typeinfo>

// Classe para controlar todas as operações com os candidatos (vereador ou prefeito)

template <typename T>
ControllerCandidato<T>::ControllerCandidato(State *state, MenuEditarEleitor *menuEditarEleitor, ControllerDadosEleitor *controllerDadosEleitor) : _state(state), _menuEditarEleitor(menuEditarEleitor), _controllerDadosEleitor(controllerDadosEleitor) {}

template <typename T>
RetornoController ControllerCandidato<T>::listCandidato()
{
  std::vector<Candidato *> listaCandidatos;
  std::cout << "Lista de ";
  if (typeid(T) == typeid(Vereador))
  {
    listaCandidatos = _state->getListaVereador();
    std::cout << "Vereadores" << std::endl;
  }
  else
  {
    listaCandidatos = _state->getListaPrefeito();
    std::cout << "Prefeitos:" << std::endl;
  }
  if (listaCandidatos.size())
  {
    for (auto candidato : listaCandidatos)
      std::cout << "Nº TÍTULO: " << candidato->getNumero() << " NOME: " << candidato->getNome() << std::endl;
  }
  else
    std::cout << "(Lista vazia)" << std::endl;
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::addCandidato()
{
  int numTitulo, numero = 1;
  std::string nome, zona, secao, nomePartido = "PT", cidade = "BH";
  std::cout << "Cadastro de ";
  if (typeid(T) == typeid(Vereador))
    std::cout << "Vereador:" << std::endl;
  else
    std::cout << "Prefeito:" << std::endl;
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
  if (typeid(T) == typeid(Vereador))
    _state->addVereador(new Vereador(numTitulo, nome, zona, secao, numero, nomePartido, cidade));
  else
    _state->addPrefeito(new Prefeito(numTitulo, nome, zona, secao, numero, nomePartido, cidade));
  std::cout << "Candidato adicionado!" << std::endl;
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::viewCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::editCandidato()
{
  return RetornoController::Completo;
}

template <typename T>
RetornoController ControllerCandidato<T>::deleteCandidato()
{
  return RetornoController::Completo;
}

template class ControllerCandidato<Vereador>;
template class ControllerCandidato<Prefeito>;