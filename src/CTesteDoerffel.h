#ifndef CTesteDoerffel_h
#define CTesteDoerffel_h

#include <algorithm>
#include <numeric>
#include <iostream>

#include "CTeste.h"
////////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CTesteDoerffel
/// @file CTesteDoerffel.h
/// @brief Classe representativa do teste de Doerffel.
////////////////////////////////////////////////////////////////////////
class CTesteDoerffel : public CTeste 
{
protected:  
  /// Valor suspeito de ser um outlier.
  double valorSuspeito; 		
    
  /// Valor adjacente ao dado suspeito de ser um outlier.
  double valorAdjacente;  
  
  /// Necessario para calcular o valor adjacente.
  std::vector<double> dif; 
  
  /// Estatistica calculada.
  double q; 		
  
  /// Vetor com os valores criticos.
  static double vcritico[8]; 	
  
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;  
  
public:
  /// Metodo que identifica o valor adjacente ao dado suspeito.
  /// @return valor adjacente ao valor suspeito.
  double ValorAdjacente(); 	
  
  /// Metodo que calcula a estatistica utilizada no teste de Doerffel.
  /// @return estatistica calculada.
  double Q(); 	
  
  /// Metodo que compara o valor calculado e o valor critico tabelado.
  void Compara(); 
  
  /// Metodo que retorna o valor critico.
  /// @return valor critico tabelado.
  double ValorCritico(); 
  
  /// Metodo de entrada, pede os dados iniciais.
  void Entrada(); 				

};
#endif
