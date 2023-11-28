#include "CTesteDoerffel.h"

double CTesteDoerffel::vcritico[8] = {0.97, 0.84, 0.73, 0.64, 0.59, 0.54, 0.51, 0.49};

double CTesteDoerffel::Q()
{
  int n = dados.size();
  q = (valorSuspeito - ValorAdjacente())/Amplitudedados();
  return q;
}

void CTesteDoerffel::Compara()
{
  double que = Q();
  double valorcritico = ValorCritico();
  if (que > valorcritico) {
    std::cout << "O dado testado e considerado um outlier" << std::endl;
    fout << "O dado testado e considerado um outlier" << std::endl;
    std::cout << "O valor do teste calculado e " << que << std::endl;
    fout << "O valor do teste calculado e " << que << std::endl;
    std::cout << "O valor critico tabelado para alpha = 0.05 e n = " << dados.size() << " e " << valorcritico << std::endl;
    fout << "O valor critico tabelado para alpha = 0.05 e n = " << dados.size() << " e " << valorcritico << std::endl;
  }
  else {
    std::cout << "O dado testado nao e considerado um outlier" << std::endl;
    fout << "O dado testado nao e considerado um outlier" << std::endl;
    std::cout << "O valor do teste calculado e " << que << std::endl;
    fout << "O valor do teste calculado e " << que << std::endl;
    std::cout << "O valor critico tabelado para alpha = 0.05 e n = " << dados.size() << " e " << valorcritico << std::endl;
    fout << "O valor critico tabelado para alpha = 0.05 e n = " << dados.size() << " e " << valorcritico << std::endl;
  }
  fout.close();
}

double CTesteDoerffel::ValorCritico()
{
 return vcritico[dados.size() - 3];
}

void CTesteDoerffel::Entrada()
{
  std::cout << "\nTeste de Doerffel\n" << std::endl;
  std::cout << "O teste de Doerffel esta definido para um grupo de 3 ate 10 dados." << std::endl;
  CEstatistica::Entrada();
  if (dados.size() >= 3 and dados.size() <= 10)
  {
  std::cout << "Agora, entre com o valor suspeito de ser um outlier: ";
  std::cin >> valorSuspeito; std::cin.get();
  if(std::find(dados.begin(), dados.end(), valorSuspeito) != dados.end())
  {std::cout << "Entrada realizada com sucesso." << std::endl;} 
  else 
  {
   do {std::cout << "Esse valor suspeito nao se encontra nos dados.\n";
   std::cout << "Entre com um valor suspeito que esteja inserido nos dados: ";
   std::cin >> valorSuspeito; std::cin.get(); } while (std::find(dados.begin(), dados.end(), valorSuspeito) == dados.end());
  }
  }
  else
  {
   std::cout << "O teste de Doerffel nao esta definido para essa quantidade de dados" << std::endl; 
   exit(EXIT_FAILURE);    
  }
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app); 
} 

double CTesteDoerffel::ValorAdjacente()
{  
  for (int i = 0; i < dados.size(); i++) {
    if (std::abs(valorSuspeito - dados[i]) != 0) {
      dif.push_back(std::abs(valorSuspeito - dados[i]));
    }
  }
  auto it = min_element(dif.begin(), dif.end());
  valorAdjacente = dados[(it - dif.begin())];
  return valorAdjacente;
}
