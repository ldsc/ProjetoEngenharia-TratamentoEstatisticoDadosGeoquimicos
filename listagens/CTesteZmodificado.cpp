#include <iostream>
#include <algorithm>
#include "CTesteZmodificado.h"

void CTesteZmodificado::Z()
{
  double x4 = Mad();
  for (int i = 0; i < dados.size(); i++) {
    zmod.push_back((0.6745*desvio[i])/x4);
  }
}

void CTesteZmodificado::DesvioAbs()
{
  double x5 = Mediana();
  for (int i = 0; i < dados.size(); i++) {
    double dabs = dados[i] - x5;
    desvio.push_back(dabs);
    desvioAbsoluto.push_back(std::abs(dabs));
  }
}
 
double CTesteZmodificado::Mad()
{
  std::sort(desvioAbsoluto.begin(), desvioAbsoluto.end()); 
  int n = desvioAbsoluto.size() - 1;
  if (desvioAbsoluto.size()%2 == 0) {
    mad = (desvioAbsoluto[n/2] + desvioAbsoluto[(n/2) + 1])/2;
  }
  else {
    mad = desvioAbsoluto[(n + 1)/2];
  }
  return mad;
}
 
void CTesteZmodificado::Compara()
{
  DesvioAbs();
  Z();
  for (int i = 0; i < dados.size(); i++) {
    if (zmod[i] > 3) {
      std::cout << "Considera-se como outlier o seguinte dado: " << dados[i] << ", que tem como Zmod: " << zmod[i] << std::endl;
      fout << "Considera-se como outlier o seguinte dado: " << dados[i] << ", que tem como Zmod: " << zmod[i] << std::endl;
    }
  }
  fout.close();
}
 
void CTesteZmodificado::Entrada()
{
  std::cout << "\nTeste Z modificado\n" << std::endl;
  CEstatistica::Entrada();
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app) ;
}
