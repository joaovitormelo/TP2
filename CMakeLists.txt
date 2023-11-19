cmake_minimum_required(VERSION 3.0.0)
project(tp2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(sources
  main.cpp
  base/controller.h
  base/global.h
  base/global.cpp
  base/menu.h
  base/menu.cpp
  base/opcao_menu.h
  base/opcao_menu.cpp
  base/exception_invalid_format.h
  base/exception_invalid_format.cpp
  initializers/main_initializer.h
  initializers/main_initializer.cpp
  domain/eleitor.h
  domain/eleitor.cpp
  domain/candidato.h
  domain/candidato.cpp
  domain/vereador.h
  domain/vereador.cpp
  domain/prefeito.h
  domain/prefeito.cpp
  domain/state.h
  domain/state.cpp
  menus/menu_inicial.h
  menus/menu_inicial.cpp
  features/cadastro/menus/menu_cadastro.h
  features/cadastro/menus/menu_cadastro.cpp
  features/cadastro/controllers/controller_dados_eleitor.h
  features/cadastro/controllers/controller_dados_eleitor.cpp
  features/cadastro/eleitores/menus/menu_eleitor.h
  features/cadastro/eleitores/menus/menu_eleitor.cpp
  features/cadastro/eleitores/menus/menu_editar_eleitor.h
  features/cadastro/eleitores/menus/menu_editar_eleitor.cpp
  features/cadastro/eleitores/controllers/controller_eleitor.h
  features/cadastro/eleitores/controllers/controller_eleitor.cpp
  features/cadastro/candidatos/menus/menu_candidato.h
  features/cadastro/candidatos/menus/menu_candidato.cpp
  features/cadastro/candidatos/menus/menu_editar_candidato.h
  features/cadastro/candidatos/menus/menu_editar_candidato.cpp
  features/cadastro/candidatos/controllers/controller_candidato.h
  features/cadastro/candidatos/controllers/controller_candidato.cpp
  features/cadastro/candidatos/controllers/controller_dados_candidato.h
  features/cadastro/candidatos/controllers/controller_dados_candidato.cpp
  features/votacao/controllers/controller_votacao.h
  features/votacao/controllers/controller_votacao.cpp
  features/resultados/menus/menu_resultados.h
  features/resultados/menus/menu_resultados.cpp
  features/resultados/menus/menu_contar_votos.h
  features/resultados/menus/menu_contar_votos.cpp
  features/resultados/controllers/controller_resultados.h
  features/resultados/controllers/controller_resultados.cpp
  features/resultados/controllers/controller_contar_votos.h
  features/resultados/controllers/controller_contar_votos.cpp
)

set (dirs
  base
  initializers
  domain
  menus
  features/cadastro/menus
  features/cadastro/controllers
  features/cadastro/eleitores/menus
  features/cadastro/eleitores/controllers
  features/cadastro/candidatos/menus
  features/cadastro/candidatos/controllers
  features/votacao/controllers
  features/resultados/menus
  features/resultados/controllers
)

add_executable(tp2 ${sources})

target_include_directories(tp2 PRIVATE ${dirs})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
