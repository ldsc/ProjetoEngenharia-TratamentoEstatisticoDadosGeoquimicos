#ifndef CTesteCochran_h
#define CTesteCochran_h

#include <vector>
#include <numeric>
#include <algorithm>

#include "CTeste.h"

/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CTesteCochran
 * @file CTesteCochran.h
 * @brief Classe representativa do teste de Cochran.
 */


class CTesteCochran : public CTeste {
protected:
  /// Estatistica calculada do teste de Cochran, valor a ser comparado com o tabelado.
  double c;  
  
  /// Numero de grupos de dados.
  int n;  
  
  /// Valor da significancia.
  int alpha;   
  
  /// Vetor que guarda a variancia dos grupos.
  std::vector<double> var;  
  
  /// Vetor que guarda os dados de cada grupo.
  std::vector<CEstatistica> est;  
  
  /// Tabela do valor critico para alpha = 0.05.			    
  static double vcritico5[10][9];  
  
  /// Tabela do valor critico para alpha = 0.01			   
  static double vcritico1[10][9];     
  
  ///  Objeto associado ao arquivo de disco, onde os resultados sao inseridos.
  std::ofstream fout;			
  
public:
  
  /// Metodo que calcula a estatistica do teste.
  /// @return estatistica do teste.
  double C();    
  
  /// Metodo de entrada, pede os dados e informacoes adicionais.
  void Entrada(); 
  
  
  /// Metodo que retorna o valor critico tabelado.
  /// @return valor critico.
  double ValorCritico();    
  
  /// Metodo que compara o valor calculado e o valor critico tabelado.
  void Compara();                       
  
  
  /// Metodo que retorna o valor da significancia utilizada.
  /// @return valor da significancia.
  double Alpha();	
  
  
};
#endif
