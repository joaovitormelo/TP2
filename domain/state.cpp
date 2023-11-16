#include "state.h"

State::State() {}

State::~State()
{
  for (auto eleitor : _listaEleitor)
    delete eleitor;
  for (auto vereador : _listaVereador)
    delete vereador;
  for (auto prefeito : _listaPrefeito)
    delete prefeito;
}

std::vector<Eleitor *> State::getListaEleitor()
{
  return _listaEleitor;
}

void State::setListaEleitor(std::vector<Eleitor *> listaEleitor)
{
  _listaEleitor = listaEleitor;
}

void State::addEleitor(Eleitor *eleitor)
{
  _listaEleitor.push_back(eleitor);
}

Eleitor *State::buscaEleitor(int numTitulo)
{
  for (auto eleitor : _listaEleitor)
    if (eleitor->getNumTitulo() == numTitulo)
      return eleitor;
  return nullptr;
}

std::vector<Vereador *> State::getListaVereador()
{
  return _listaVereador;
}

void State::setListaVereador(std::vector<Vereador *> listaVereador)
{
  _listaVereador = listaVereador;
}

std::vector<Prefeito *> State::getListaPrefeito()
{
  return _listaPrefeito;
}

void State::setListaPrefeito(std::vector<Prefeito *> listaPrefeito)
{
  _listaPrefeito = listaPrefeito;
}

Eleitor *State::getEleitorEdit()
{
  return _eleitorEdit;
}

void State::setEleitorEdit(Eleitor *editEleitor)
{
  _eleitorEdit = editEleitor;
}

bool State::checaExisteNumTitulo(int numTitulo)
{
  for (auto eleitor : _listaEleitor)
    if (eleitor->getNumTitulo() == numTitulo)
      return true;
  for (auto vereador : _listaVereador)
    if (vereador->getNumTitulo() == numTitulo)
      return true;
  for (auto prefeito : _listaPrefeito)
    if (prefeito->getNumTitulo() == numTitulo)
      return true;
  return false;
}