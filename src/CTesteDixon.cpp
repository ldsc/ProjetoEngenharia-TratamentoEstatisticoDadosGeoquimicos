#include "CTesteDixon.h"

double CTesteDixon::vcritico[23][3] = 

	 {//0.1   0.05   0.01  <-- Niveis de significancia
	 {0.886, 0.941, 0.988},
	 {0.679, 0.765, 0.889},
	 {0.557, 0.642, 0.780},
	 {0.482, 0.560, 0.698},
	 {0.434, 0.507, 0.637},
	 {0.479, 0.554, 0.683},
	 {0.441, 0.512, 0.635},
	 {0.409, 0.477, 0.597},
	 {0.517, 0.576, 0.679},
	 {0.490, 0.546, 0.642},
	 {0.467, 0.521, 0.615},
	 {0.492, 0.546, 0.641},
	 {0.472, 0.525, 0.616},
	 {0.454, 0.507, 0.595},
	 {0.438, 0.490, 0.577},
	 {0.424, 0.475, 0.561},
	 {0.412, 0.462, 0.547},
	 {0.401, 0.450, 0.535},
	 {0.391, 0.440, 0.524},
	 {0.382, 0.430, 0.514},
	 {0.374, 0.421, 0.505},
	 {0.367, 0.413, 0.497},
	 {0.360, 0.406, 0.489}
	 };

void CTesteDixon::Ordenar()
{
  std::sort(dados.begin(), dados.end());
}

double CTesteDixon::Zmaior()
{
  Ordenar();
  int n = dados.size() - 1;
  if (n + 1 >= 3 && n + 1 <= 7) {
    z_maior = (dados[n] - dados[n - 1])/(dados[n] - dados[0]);
  }
  else if (n + 1 >= 8 && n + 1 <= 12) {
    z_maior = (dados[n] - dados[n - 1])/(dados[n] - dados[1]);
  }
  else if (n + 1 <= 13 && n + 1 <= 25) {
    z_maior = (dados[n] - dados[n - 2])/(dados[n] - dados[2]);
  }
  else {
    std::cerr << "O teste de Dixon nao esta definido para mais de 25 observacoes!" << std::endl;
  }
  return z_maior;
}

double CTesteDixon::Zmenor()
{
  Ordenar();
  int n = dados.size() - 1;
  if (n + 1 >= 3 && n + 1 <= 7) {
    z_menor = (dados[1] - dados[0])/(dados[n] - dados[0]);
  }
  else if (n + 1 >= 8 && n + 1 <= 12) {
    z_menor = (dados[1] - dados[0])/(dados[n - 1] - dados[0]);
  }
  else if (n + 1 <= 13 && n + 1 <= 25) {
    z_menor = (dados[2] - dados[0])/(dados[n - 2] - dados[0]);
  }
  else {
    std::cerr << "O teste de Dixon nao esta definido para mais de 25 observacoes!" << std::endl;
  }    
  return z_menor;
}

double CTesteDixon::ValorCritico()
{
  return vcritico[dados.size() - 3][alpha];
}

double CTesteDixon::Alpha()
{
  double aux2;
  if (alpha == 0)
    aux2 = 0.10;
  else if (alpha == 1)
    aux2 = 0.05;
  else if (alpha == 2)
    aux2 = 0.01;
  return aux2;
}

void CTesteDixon::Compara()
{
  double valorcritico = ValorCritico();
  double zmenor = Zmenor();            
  double zmaior = Zmaior();             
  if (resp == maiorDixon) {
    if (zmaior > valorcritico) {
     std::cout << "O maior valor testado com um nivel de significancia de " << Alpha() << " e considerado um outlier" << std::endl;
     fout << "O maior valor testado com um nivel de significancia de " << Alpha() << " e considerado um outlier" << std::endl;
     std::cout << "O valor calculado e " << zmaior << std::endl;
     fout << "O valor calculado e " << zmaior << std::endl;
     std::cout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
     fout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
     std::cout << "O maior valor foi apagado: " << dados[dados.size() - 1] << std::endl;
     fout << "O maior valor foi apagado: " << dados[dados.size() - 1] << std::endl << std::endl;
     dados.pop_back();
    }
    else {
      std::cout << "O maior valor testado com um nivel de significancia de " << Alpha() << " nao e considerado um outlier" << std::endl;
      fout << "O maior valor testado com um nivel de significancia de " << Alpha() << " nao e considerado um outlier" << std::endl;
      std::cout << "O valor calculado e " << zmaior << std::endl;
      fout << "O valor calculado e " << zmaior << std::endl;
      std::cout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
      fout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
      std::cout << "O maior valor foi mantido: " << dados[dados.size() - 1] << std::endl;
      fout << "O maior valor foi mantido: " << dados[dados.size() - 1] << std::endl << std::endl;
    }
  }
  else if (resp == menorDixon) {
    if (zmenor > valorcritico) {
     std::cout << "O menor valor testado com um nivel de significancia de " << Alpha() << " e considerado um outlier" << std::endl;
     fout << "O menor valor testado com um nivel de significancia de " << Alpha() << " e considerado um outlier" << std::endl;
     std::cout << "O valor calculado e " << zmenor << std::endl;
     fout << "O valor calculado e " << zmenor << std::endl;
     std::cout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
     fout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
     std::cout << "O menor valor foi apagado: " << dados[0] << std::endl;
     fout << "O menor valor foi apagado: " << dados[0] << std::endl << std::endl;
     dados.erase(dados.begin());
    }
    else {
      std::cout << "O menor valor testado com um nivel de significancia de " << Alpha() << " nao e considerado um outlier" << std::endl;
      fout << "O menor valor testado com um nivel de significancia de " << Alpha() << " nao e considerado um outlier" << std::endl;
      std::cout << "O valor calculado e " << zmenor << std::endl;
      fout << "O valor calculado e " << zmenor << std::endl;
      std::cout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
      fout << "O valor critico tabelado para esse valor de significancia e " << valorcritico << std::endl;
      std::cout << "O menor valor foi mantido: " << dados[0] << std::endl;
      fout << "O menor valor foi mantido: " << dados[0] << std::endl << std::endl;
    }
  }
  std::cout << "Gostaria de realizar um novo teste? (s ou n): ";
  char auxiliar;
  std::cin >> auxiliar; 
  std::cin.get();
  
  if (auxiliar == 's' or auxiliar == 'S') {
    std::cout << "Para testar o menor valor de observacao........................................................(digite 0 + ENTER) "
              << "\nPara testar o maior valor de observacao........................................................(digite 1 + ENTER): ";
  std::cin >> resp;
  std::cin.get();
  Compara();
  }
  fout.close();
}

void CTesteDixon::Entrada()
{
  std::cout << "\nTeste de Dixon\n" << std::endl;
  std::cout << "Entre com o nivel de significancia " << std::endl;
  std::cout << "Para alpha = 0.10......................................................................digite (0 + ENTER)  \n"
	    << "Para alpha = 0.05......................................................................digite (1 + ENTER)  \n" 
	    << "Para alpha = 0.01......................................................................digite (2 + ENTER)  :";
  std::cin >> alpha; std::cin.get();  
  CEstatistica::Entrada();
  std::cout << "Para testar o menor valor de observacao................................................(digite 0 + ENTER) "
            << "\nPara testar o maior valor de observacao................................................(digite 1 + ENTER): ";
  std::cin >> resp; std::cin.get();
  std::cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  std::string nome; getline(std::cin, nome);
  fout.open(nome+".txt", std::ios::app) ;
}

