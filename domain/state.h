#ifndef INF112_STATE_H
#define INF112_STATE_H
#include <vector>
#include "eleitor.h"
#include "candidato.h"
#include "vereador.h"
#include "prefeito.h"

class State
{
private:
  std::vector<Eleitor *> _listaEleitor;
  std::vector<Candidato *> _listaVereador;
  std::vector<Candidato *> _listaPrefeito;
  Eleitor *_eleitorEdit;
  Candidato *_candidatoEdit;

public:
  State();
  ~State();
  std::vector<Eleitor *> getListaEleitor();
  void setListaEleitor(std::vector<Eleitor *> listaEleitor);
  void addEleitor(Eleitor *eleitor);
  Eleitor *buscaEleitor(int numTitulo);
  void deletaEleitor(int numTitulo);
  std::vector<Candidato *> getListaVereador();
  void setListaVereador(std::vector<Candidato *> listaVereador);
  void addVereador(Vereador *vereador);
  Candidato *buscaVereador(int numTitulo);
  void deletaVereador(int numTitulo);
  std::vector<Candidato *> getListaPrefeito();
  void setListaPrefeito(std::vector<Candidato *> listaPrefeito);
  void addPrefeito(Prefeito *prefeito);
  Candidato *buscaPrefeito(int numTitulo);
  void deletaPrefeito(int numTitulo);
  Eleitor *getEleitorEdit();
  void setEleitorEdit(Eleitor *eleitorEdit);
  bool checaExisteNumTitulo(int numTitulo);
  Candidato *getCandidatoEdit();
  void setCandidatoEdit(Candidato *candidatoEdit);
  bool checaExisteNumero(int numero);
};

#endif