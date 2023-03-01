#ifndef CEstatistica_h
#define CEstatistica_h

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CEstatistica
 * @file CEstatistica.h
 * @brief Classe representativa dos metodos estatisticos basicos.
 */

class CEstatistica {
public:
   /// Vetor que amazena os dados medidos.
  std::vector<double> dados;   
  
  /// Media dos dados.
  double media;
  
  /// Variancia dos dados.
  double variancia;
  
  /// Desvio padrao dos dados.
  double desviopadrao;
  
  /// Amplitude dos dados. Amplitude = maximo valor - minimo valor.
  double amplitude;
  
  /// Mediana dos dados. Valor que divide a amostra em duas partes iguais.
  double mediana;
  ///
public:
  /// Metodo que retorna a amplitude dos dados.
  /// @return amplitude dos dados.
  double Amplitudedados();
  
  /// Metodo que retorna a media dos dados.
  /// @return media dos dados.
  double Media();
  
  /// Metodo que retorna a mediana dos dados.
  /// @return madiana dos dados.
  double Mediana(); 
  
  /// Metodo que retorna a variancia dos dados.
  /// @return variancia dos dados.
  double Variancia();
  
  /// Metodo que retorna o desvio padrao dos dados.
  /// @return desvio padrao dos dados.
  double Desviopadrao();
  
  /// Metodo de entrada, pede dados e informacoes adicionais.
  void Entrada();
};


#endif

