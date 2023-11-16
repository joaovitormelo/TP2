#ifndef INF112_STATE_H
#define INF112_STATE_H
#include <vector>
#include "eleitor.h"
#include "vereador.h"
#include "prefeito.h"

class State
{
private:
  std::vector<Eleitor *> _listaEleitor;
  std::vector<Vereador *> _listaVereador;
  std::vector<Prefeito *> _listaPrefeito;
  Eleitor *_eleitorEdit;

public:
  State();
  ~State();
  std::vector<Eleitor *> getListaEleitor();
  void setListaEleitor(std::vector<Eleitor *> listaEleitor);
  std::vector<Vereador *> getListaVereador();
  void setListaVereador(std::vector<Vereador *> listaVereador);
  std::vector<Prefeito *> getListaPrefeito();
  void setListaPrefeito(std::vector<Prefeito *> listaPrefeito);
  Eleitor *getEleitorEdit();
  void setEleitorEdit(Eleitor *eleitorEdit);
  bool checaExisteNumTitulo(int numTitulo);
};

#endif