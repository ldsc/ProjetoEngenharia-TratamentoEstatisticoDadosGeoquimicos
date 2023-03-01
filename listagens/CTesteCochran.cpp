#include "CTesteCochran.h"

using namespace std;

double CTesteCochran::vcritico5[10][9] =     ///< Tabela do valor critico para alpha = 0.05.
{                      
{0.9985, 0.9669, 0.9065, 0.8412, 0.7808, 0.7271, 0.6798, 0.6385, 0.6020},
{0.9750, 0.8709, 0.7679, 0.6838, 0.6161, 0.5612, 0.5157, 0.4775, 0.4450},
{0.9392, 0.7977, 0.6841, 0.5981, 0.5321, 0.4800, 0.4377, 0.4027, 0.3733},
{0.9057, 0.7457, 0.6287, 0.5441, 0.4803, 0.4307, 0.3910, 0.3584, 0.3311},
{0.8772, 0.7071, 0.5895, 0.5065, 0.4447, 0.3974, 0.3595, 0.3286, 0.3029},
{0.8534, 0.6771, 0.5598, 0.4783, 0.4184, 0.3726, 0.3362, 0.3067, 0.2823},
{0.8332, 0.6530, 0.5365, 0.4564, 0.3980, 0.3535, 0.3185, 0.2901, 0.2666},
{0.8159, 0.6333, 0.5175, 0.4387, 0.3817, 0.3384, 0.3043, 0.2768, 0.2541},
{0.8010, 0.6167, 0.5017, 0.4241, 0.3682, 0.3259, 0.2926, 0.2659, 0.2439},
{0.7880, 0.6025, 0.4884, 0.4118, 0.3568, 0.3154, 0.2829, 0.2568, 0.2353}
};
			    
double CTesteCochran::vcritico1[10][9] =     ///< Tabela do valor critico para alpha = 0.01
{
{0.9999, 0.9933, 0.9676, 0.9279, 0.8828, 0.8376, 0.7945, 0.7544, 0.7175}, 
{0.9950, 0.9423, 0.8643, 0.7885, 0.7218, 0.6644, 0.6152, 0.5727, 0.5358},
{0.9794, 0.8831, 0.7814, 0.6957, 0.6258, 0.5685, 0.5209, 0.4810, 0.4469},
{0.9586, 0.8335, 0.7212, 0.6329, 0.5635, 0.5080, 0.4627, 0.4251, 0.3934},
{0.9373, 0.7933, 0.6761, 0.5875, 0.5195, 0.4659, 0.4226, 0.3870, 0.3572},
{0.9172, 0.7606, 0.6410, 0.5531, 0.4866, 0.4347, 0.3932, 0.3592, 0.3308},
{0.8988, 0.7335, 0.6129, 0.5259, 0.4608, 0.4105, 0.3704, 0.3378, 0.3106},
{0.8823, 0.7107, 0.5897, 0.5037, 0.4401, 0.3911, 0.3522, 0.3207, 0.2945},
{0.8674, 0.6912, 0.5702, 0.4854, 0.4229, 0.3751, 0.3373, 0.3067, 0.2813},
{0.8539, 0.6743, 0.5536, 0.4697, 0.4084, 0.3616, 0.3248, 0.2950, 0.2704}
};			    

double CTesteCochran::C()
{
  c = *max_element(var.begin(), var.end())/accumulate(var.begin(), var.end(), 0.);
  return c;
}

double CTesteCochran::ValorCritico()
{
  if (alpha == 0)
    return vcritico5[est[0].dados.size() - 2][n - 2];
  if (alpha == 1)
    return vcritico1[est[0].dados.size() - 2][n - 2];
}

void CTesteCochran::Compara()
{
  double c2 = C();				
  double valorcritico = ValorCritico();		
 double numero = *max_element(var.begin(), var.end());
 auto it = find(var.begin(), var.end(), numero);
  if (c > valorcritico) {
    cout << "O grupo " << (it - var.begin() + 1) << " apresenta variancia nao homogenea com os demais grupos" << endl;
    fout << "O grupo " << (it - var.begin() + 1) << " apresenta variancia nao homogenea com os demais grupos" << endl;
    cout << "O valor de C calculado e " << c2 << endl;
    fout << "O valor de C calculado e " << c2 << endl;
    cout << "O valor critico tabelado para o nivel de significancia = " << Alpha() << " e " << valorcritico << endl;
    fout << "O valor critico tabelado para o nivel de significancia = " << Alpha() << " e " << valorcritico << endl;
  }
  else {
    cout << "O grupo " << (it - var.begin() + 1) << " apresenta variancia homogenea com os demais grupos" << endl;
    fout << "O grupo " << (it - var.begin() + 1) << " apresenta variancia homogenea com os demais grupos" << endl;
    cout << "O valor de C calculado e " << c2 << endl;
    fout << "O valor de C calculado e " << c2 << endl;
    cout << "O valor critico tabelado para o nivel de significancia = " << Alpha() << " e " << valorcritico << endl;
    fout << "O valor critico tabelado para o nivel de significancia = " << Alpha() << " e " << valorcritico << endl;
  }
  fout.close();
}

void CTesteCochran::Entrada()
{
  cout << "\tTeste de Cochran \n" << "\tAte 10 grupos de dados\n" << "\tAte 11 dados por grupo\n" << endl;
  cout << "Entre com o numero de grupos: "; cin >> n; cin.get();
  if (n <= 10) 
  {
  for (int i = 0; i < n; i++)
  {
    CEstatistica p1;
    cout << "Entre com os dados do grupo " << i + 1 << endl;
    p1.CEstatistica::Entrada();
    double variancia2 = p1.Variancia();
    cout << "A variancia do grupo e " << variancia2 << endl;
    var.push_back(variancia2);
    est.push_back(p1);
  }
  for (int i = 1; i < n; i++) 
  {
    if (est[i - 1].dados.size() != est[i].dados.size()) 
    {
      cerr << "O numero de dados de todos os grupos precisa ser igual\n";
      exit(EXIT_FAILURE);
    }
  }
  cout << "Agora, entre com o valor da significancia\n"
       << "Para alpha = 0.05............................................................digite (0 + ENTER) : \n"
       << "Para alpha = 0.01............................................................digite (1 + ENTER) : ";
  cin >> alpha; cin.get();
  }
  else
   {
     cout << "Entrada invalida.\n"
         << "O numero de grupos deve ser menor.\n"
         << "O programa aceita ate 10 grupos de dados" << endl;
	 est.clear(); var.clear(); Entrada();     
  } 
  cout << "Agora, entre com o nome do arquivo a ser salvo: ";
  string nome; getline(cin, nome);
  fout.open(nome+".txt", ios::app) ;
}

double CTesteCochran::Alpha()
{
  double aux;
  if (alpha == 0)
    aux = 0.05;
  else if (alpha == 1)
    aux = 0.01;
  return aux;
}
