#ifndef CTesteGrubbs_h
#define CTesteGrubbs_h
#include <algorithm>
#include <iostream>
#include <cmath>
#include "CTeste.h"

////////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteGrubbs
/// @file CTesteGrubbs.h
/// @brief Classe representativa do teste de Grubbs.
////////////////////////////////////////////////////////////////////////

enum ETipoTesteGrubbs {menorGrubbs, maiorGrubbs};

class CTesteGrubbs : public CTeste {
protected:
  
  /// Identifica o nivel de significancia.
  int alpha; 				
  
  /// Estatistica do teste.
  double tau;		
  
  /// Identifica se o usuario quer testar o maior ou menor elemento.
  int resp;				
  
  /// Matriz com os valores criticos.
  static double vcritico[18][5];		
  
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;   		
public:
  
  /// Metodo que ordena os dados de forma crescente.
  void Ordenar(); 			
  
  /// Metodo que transforma vetor de dados no logaritmo natural do vetor de dados.
  void LogTransform(); 			
  
  /// Metodo que calcula e retorna a estatistica do teste.
  /// @return estatistica do teste.
  double Tau(); 		
  
  /// Metodo que compara o valor calculado e o valor critico tabelado.
  void Compara(); 	
  
  /// Metodo que retorna o valor critico tabelado.
  /// @return valor critico tabelado.
  double ValorCritico(); 
  
  /// Metodo de entrada. Pede os dados e informacoes adicionais.
  void Entrada(); 
  
  /// Metodo que retorna o valor da significancia.
  /// @return valor da significancia.
  double Alpha(); 			
   
};
#endif
