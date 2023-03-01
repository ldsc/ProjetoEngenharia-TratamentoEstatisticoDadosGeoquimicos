#ifndef CDistTStudent_h
#define CDistTStudent_h

///////////////////////////////////////////////////////////////////////
/// @author Marcio Araujo
/// @author Tamires Soares
/// @author Thiago Rocha
/// @class CDistTStudent
/// @file CDistTStudent.h
/// @brief Classe representativa da distribuicao t de Student.
///////////////////////////////////////////////////////////////////////


class CDistTStudent
{
protected:
  
  /// Tabela unicaudal.
  static double unicaudal[30][6];
  
  /// Tabela bicaudal.
  static double bicaudal[30][7];
public:
  
  /// Retorna elemento da tabela unicaudal.
  /// @param _x Linha da tabela unicaudal.
  /// @param _y Coluna da tabela unicaudal.
  /// @return valor critico do teste de hipotese com desvio padrao desconhecido nos casos unicaudais.
  double uniStudent(int _x, int _y);
  
  /// Retorna elemento da tabela bicaudal.
  /// @param x Linha da tabela bicaudal.
  /// @param y Coluna da tabela bicaudal.
  /// @return valor critico do teste de hipotese com desvio padrao desconhecido no caso bicaudal.
  double biStudent(int x, int y);
};


#endif
