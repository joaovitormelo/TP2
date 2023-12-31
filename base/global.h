#ifndef INF112_GLOBAL_H
#define INF112_GLOBAL_H
#include <iostream>
#include <functional>
#include <limits>
#include "exception_invalid_format.h"

enum RetornoController
{
  Voltar = 1,
  Sair = 2,
  Completo = 3,
};

void finalizarTela();

template <typename T>
T readNumber(std::function<bool(T)> extraValidation = NULL)
{
  T val;
  bool invalid;
  do
  {
    invalid = false;
    if (!(std::cin >> val))
    {
      std::cout << "Entrada inválida! Insira apenas valores numéricos!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      invalid = true;
    }
    else
    {
      if (extraValidation)
      {
        if (!extraValidation(val))
          invalid = true;
      }
    }
    if (invalid)
      std::cout << "Tente novamente: ";
  } while (invalid);
  return val;
}

void hold();

std::string readLine();

RetornoController voltar();

RetornoController sair();

std::string nextValLine(std::string line, int *pos, int *newPos, bool last = false);

#endif