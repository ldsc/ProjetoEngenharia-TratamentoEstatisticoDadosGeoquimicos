#include "CTesteGrubbs.h"

double CTesteGrubbs::vcritico[18][5] = 
{
{1.148, 1.153, 1.155, 1.155, 1.555},
{1.425, 1.463, 1.481, 1.492, 1.496},
{1.602, 1.672, 1.715, 1.749, 1.764},
{1.729, 1.822, 1.887, 1.944, 1.973},
{1.828, 1.938, 2.020, 2.097, 2.139},
{1.909, 2.032, 2.126, 2.221, 2.274},
{1.977, 2.110, 2.215, 2.323, 2.387},
{2.036, 2.176, 2.290, 2.410, 2.482},
{2.088, 2.234, 2.355, 2.485, 2.564},
{2.134, 2.285, 2.412, 2.550, 2.636},
{2.175, 2.331, 2.462, 2.607, 2.699},
{2.213, 2.371, 2.507, 2.659, 2.755},
{2.247, 2.409, 2.549, 2.705, 2.806},
{2.279, 2.443, 2.585, 2.747, 2.852},
{2.309, 2.475, 2.620, 2.785, 2.894},
{2.335, 2.504, 2.651, 2.821, 2.932},
{2.361, 2.532, 2.681, 2.854, 2.968},
{2.385, 2.557, 2.709, 2.884, 3.001}
};

void CTesteGrubbs::Ordenar()
{
  std::sort(dados.begin(),dados.end());
}

void CTesteGrubbs::LogTransform()
{
  for (int i = 0; i < dados.size(); i++) {
    dados[i] = std::log(dados[i]);
  }
}

double CTesteGrubbs::Tau()
{
  double media = Media();
  double desviopadrao = Desviopadrao();
  int n = dados.size() - 1;
  Ordenar();  
  if (resp == menorGrubbs) {
    tau = (media - dados[0]) / desviopadrao;
  }  
  if (resp = maiorGrubbs) {
    tau = (dados[n] - media) / desviopadrao;
  }  
  return tau;
}

void CTesteGrubbs::Entrada()
{
  std::cout << "\nTeste de Grubbs\n" << std::endl;
  std::cout << "O teste de Grubbs esta definido para um grupo de 3 ate 20 dados." << std::endl;
  CEstatistica::Entrada();
  
  if (dados.size() >= 3 and dados.size() <= 20)
    {
      std::cout << "Agora, entre com a significancia: "
	        << "\nPara alpha = 0.10.............................................................digite (0 + ENTER) : "
	        << "\nPara alpha = 0.05.............................................................digite (1 + ENTER) : "
	        << "\nPara alpha = 0.025............................................................digite (2 + ENTER) : "
	        << "\nPara alpha = 0.01.............................................................digite (3 + ENTER) : "
	        << "\nPara alpha = 0.005............................................................digite (4 + ENTER) : ";
      std::cin >> alpha; std::cin.get();
      
      std::cout << "\nPara testar o menor valor de observacao..........................................(digite 0 + ENTER)"
	        << "\nPara testar o maior valor de observacao..........................................(digite 1 + ENTER): ";
      std::cin >> resp; std::cin.get(); 
  }
  else
    {
      std::cout << "O teste de Grubbs nao esta definido para essa quantidade de dados" << std::endl; 
      exit(EXIT_FAILURE);      
    }
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app) ;
}

double CTesteGrubbs::Alpha()
{
  double aux;
  if (alpha == 0)
    aux = 0.10;
  if (alpha == 1)
    aux = 0.05;
  if (alpha == 2)
    aux = 0.025;
  if (alpha == 3)
    aux = 0.01;
  if (alpha == 4)
    aux = 0.005;
  return aux;
}

double CTesteGrubbs::ValorCritico()
{
  return vcritico[dados.size() - 3][alpha];
}

void CTesteGrubbs::Compara()
{
  LogTransform();
  double tau = Tau(); double valorcritico = ValorCritico(); 
  if (tau > valorcritico) {
    std::cout << "O valor testado com o nivel de significancia = " << Alpha() <<" e considerado outlier." << std::endl;
    fout << "O valor testado com o nivel de significancia = " << Alpha() <<" e considerado outlier." << std::endl;
    std::cout << "O valor do teste calculado e " << tau << std::endl;
    fout << "O valor do teste calculado e " << tau << std::endl;
    std::cout << "O valor critico tabelado e " << valorcritico << std::endl;
    fout << "O valor critico tabelado e " << valorcritico << std::endl;
  }
  else {
    std::cout << "O valor testado com o nivel de significancia = " << Alpha() << " nao e considerado outlier." << std::endl;
    fout << "O valor testado com o nivel de significancia = " << Alpha() << " nao e considerado outlier." << std::endl;
    std::cout << "O valor do teste calculado e " << tau << std::endl;
    fout << "O valor do teste calculado e " << tau << std::endl;
    std::cout << "O valor critico tabelado e " << valorcritico << std::endl;
    fout << "O valor critico tabelado e " << valorcritico << std::endl;
  }
  fout.close();
}
