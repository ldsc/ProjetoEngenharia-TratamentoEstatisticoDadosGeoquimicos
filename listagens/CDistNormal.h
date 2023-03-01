#ifndef CDistNormal_h
#define CDistNormal_h

#include <iostream>

#include "CEstatistica.h"

/**
 * @author Marcio Araujo
 * @author Tamires Soares
 * @author Thiago Rocha
 * @class CDistNormal
 * @file CDistNormal.h
 * @brief Classe representativa da distribuicao normal padrao.
 */

class CDistNormal : public CEstatistica {
protected:
  
   /// Area que representa a probabilidade acumulada.
  double area;  
  
  /// Abcissa da distribuicao normal.
  double x;    
  
  /// Ordenada da distribuicao normal.
  double y;                 
public:
  CDistNormal(): area(0.0), x(0.0), y(0.0){}; 
  
  /// Calcula y da distribuicao normal padrao, onde y e a funcao densidade de probabilidade da distribuicao normal padrao.
  /// y = f(x) = exp(-x*x/2)/sqrt(2*M_PI). 
  /// @param _x Abcissa da funcao densidade de probabilidade da distribuicao normal onde se deseja obter a ordenada.
  /// @return Ordenada da funcao densidade de probabilidade da distribuicao normal padrao.
  double F(double _x); 
  
  /// Aproximacao da funcao erro inversa por series de Taylor.
  /// Disponivel em: http://en.wikipedia.org/wiki/Error_function#Inverse_functions.
  /// @param x Parametro onde se deseja calcular a funcao erro inversa.
  /// @return Valor da funcao erro inversa em x.
  double ErfInv(double x);
  
  /// Calcula a area a esquerda do parametro _x utilizando a funcao erro.
  /// A area esquerda representa a probabilidade acumulada de ocorrencia para qualquer evento <= _x
  /// @param _x Abcissa onde se deseja obter a probabilidade acumulada.
  /// @return Valor da probabilidade acumulada.
  double Area(double _x);  
  
  /// O usuario entra com o valor da area e o metodo retorna a abcissa correspondente.
  /// @param _x Probabilidade acumulada.
  /// @return Abcissa correspondente a probabilidade acumulada _x.
  double InvArea(double _x); 
};
#endif
