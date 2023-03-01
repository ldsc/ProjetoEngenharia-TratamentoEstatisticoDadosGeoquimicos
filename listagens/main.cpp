#include <iostream>
#include "CRegressaoLinear.h"
#include "CGnuplot.h"
#include "CTesteCochran.h"
#include "CTesteZmodificado.h"
#include "CTesteDixon.h"
#include "CTesteGrubbs.h"
#include "CTesteDoerffel.h"
#include "CTesteHipoteseDPconhecido.h"
#include "CTesteHipoteseDPdesconhecido.h"

int main()
{
  bool repeat = false;
  std::cout << "\n====================================================================\n";
  std::cout << "\n>>>>>>>>>>>>>>>>  Estatistica de Dados Geoquimicos  <<<<<<<<<<<<<<<<\n";
  std::cout << "\n  Teste de Hipotese | Identificacao de Outliers | Regressao Linear  \n";
  std::cout << "\n Autores: Marcio L. C. Araujo - Tamires S. Soares - Thiago R. Gomes \n";
  std::cout << "\n====================================================================\n";
  std::cout << "\n\nPara realizar Teste de Hipotese.................................................................digite 0 + ENTER\n"
 	  << "Para realizar Testes para Identificacao de Outliers.............................................digite 1 + ENTER\n"
	  << "Para realizar Regressao Linear..................................................................digite 2 + ENTER: ";
  int resp1;
  std::cin >> resp1;
  std::cin.get();
  
  if (resp1 == 0) {
    do {
      std::cout << "\n--------------------------------------------------------\n"
                << "O Teste de Hipotese pode ser realizado de duas formas:\n"
		<< "  1) Quando o Desvio Padrao da Populacao e Desconhecido.\n"
		<< "  2) Quando o Desvio Padrao da Populacao e Conhecido."
		<< "\n--------------------------------------------------------\n"
		<< "\nPara realizar um Teste de Hipotese com o Desvio Padrao da Populacao Desconhecido................digite 0 + ENTER:\n"
		<< "Para realizar um Teste de Hipotese com o Desvio Padrao da Populacao Conhecido...................digite 1 + ENTER:  ";
  int resp2; 
  std::cin >> resp2;
  std::cin.get();
  CTesteHipotese* teste = 0;
  
  switch (resp2) {
    case 0:
      teste = new CTesteHipoteseDPdesconhecido;
      teste->Entrada();
      teste->Compara();
      repeat = false;
      delete teste;
      teste = 0;
      break;
    case 1:
      teste = new CTesteHipoteseDPconhecido;
      teste->Entrada();
      teste->Compara();
      repeat = false;
      delete teste;
      teste = 0;
      break;
    default:
      std::cerr << "Entrada invalida." << std::endl;
      repeat = true;
      break;
  }
    }
    while (repeat == true);
  }
  else if (resp1 == 1) {
    do {
      std::cout << "O teste de identificacao de Outliers pode ser realizado por varios metodos diferentes.\n\n"
	        << "Teste de Dixon........................................................digite 0 + ENTER: \n"
	 	<< "Teste de Cochran......................................................digite 1 + ENTER: \n"
	 	<< "Teste de Grubbs.......................................................digite 2 + ENTER: \n"
	 	<< "Teste Z Modificado....................................................digite 3 + ENTER: \n"
	 	<< "Teste de Doerffel.....................................................digite 4 + ENTER: ";
      int resp3; std::cin >> resp3; std::cin.get();
      CTeste* obj = 0;
      switch (resp3) {
	case 0:
	  obj = new CTesteDixon;
	  obj->Entrada();
	  obj->Compara();
	  repeat = false;
	  delete obj;
	  obj = 0;
	  break;
	case 1:
	  std::cout << "\nO teste de Cochran e realizado para testar a homogeneidade da variancia de varios grupos de dados.\n" << std::endl;
          obj = new CTesteCochran;
	  obj->Entrada();
	  obj->Compara();
	  repeat = false;
	  delete obj;
	  obj = 0;
	  break;
	case 2:
	  obj = new CTesteGrubbs;
	  obj->Entrada();
	  obj->Compara();
	  repeat = false;
	  delete obj;
	  obj = 0;
	  break;
	 case 3:
	   obj = new CTesteZmodificado;
	   obj->Entrada();
	   obj->Compara();
	   repeat = false;
	   delete obj;
	   obj = 0;
	   break;
	 case 4:
	   obj = new CTesteDoerffel;
	   obj->Entrada();
	   obj->Compara();
	   repeat = false;
	   delete obj;
	   obj = 0;
	   break;
	 default:
	   std::cerr << "Entrada invalida." << std::endl;
	   repeat = true;
	   break;
      }
    }
    while (repeat == true);
  }
  else if (resp1 == 2) {
    std::cout << "\nRegressao Linear\n" << std::endl;
    CRegressaoLinear obj;
    obj.Entrada();
    obj.Correlacao();
    obj.ExibirEquacao();
    obj.Plotar();
    obj.Salvar();
  }
  else {
    std::cerr << "Entrada invalida." << std::endl;
    main();
  }
  std::cout << "\nDeseja sair do programa? s ou n: ";
  char sair; std::cin >> sair; std::cin.get();
  if (sair == 's' or sair == 'S')
    return 0;
  else
    main();
}