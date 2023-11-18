#include "global.h"
#include "exception_invalid_format.h"

void finalizarTela()
{
  std::cout << "---------------------------------------\n";
}

void hold()
{
  std::cin.ignore();
  std::cout << "(Pressione ENTER)" << std::endl;
  std::cin.get();
}

std::string readLine()
{
  std::string val;
  std::cin.clear();
  std::getline(std::cin >> std::ws, val);
  return val;
}

RetornoController voltar()
{
  return RetornoController::Voltar;
}

RetornoController sair()
{
  return RetornoController::Sair;
}

std::string nextValLine(std::string line, int *pos, int *newPos, bool last)
{
  std::string val;
  *newPos = line.find(";", *pos);
  if (*newPos == std::string::npos)
  {
    if (!last)
      throw ExceptionInvalidFormat();
    else
      *newPos = line.size();
  }
  val = line.substr(*pos, *newPos - *pos);
  *pos = *newPos + 1;
  return val;
}