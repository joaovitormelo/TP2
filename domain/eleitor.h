#ifndef INF112_ELEITOR_H
#define INF112_ELEITOR_H
#include <string>
#include <fstream>
class Vereador;
class Prefeito;

class Eleitor
{
private:
  int _numTitulo;
  std::string _nome;
  std::string _zona;
  std::string _secao;
  Vereador *_votoVereador;
  Prefeito *_votoPrefeito;

public:
  Eleitor(int numTitulo, std::string nome, std::string zona, std::string secao);
  int getNumTitulo();
  void setNumTitulo(int numTitulo);
  std::string getNome();
  void setNome(std::string nome);
  std::string getZona();
  void setZona(std::string zona);
  std::string getSecao();
  void setSecao(std::string secao);
  static Eleitor *fromString(std::string line);
  Vereador *getVotoVereador();
  void votaVereador(Vereador *vereador);
  Prefeito *getVotoPrefeito();
  void votaPrefeito(Prefeito *prefeito);
};

#endif