#ifndef CDistChiQuadrado_h
#define CDistChiQuadrado_h


///////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CDistChiQuadrado
/// @file CDistChiQuadrado.h
/// @brief Classe representativa da distribuicao Chi-Quadrado.
///////////////////////////////////////////////////////////////////////

class CDistChiQuadrado
{
protected:
  
  /// Tabela direita.
  static double dir[30][6];
  
  /// Tabela esquerda.
  static double esq[30][7];
public:
  
  /// Retorna elemento da tabela direita.
  /// @param _x Linha da tabela direita.
  /// @param _y Coluna da tabela direita.
  /// @return valor critico.
  double Direita(int _x, int _y);
  
  /// Retorna elemento da tabela esquerda.
  /// @param x Linha da tabela esquerda.
  /// @param y Coluna da tabela esquerda.
  /// @return valor critico.
  double Esquerda(int x, int y);
};


#endif
