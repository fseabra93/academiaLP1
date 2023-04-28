#include <iostream>
using namespace std;

int perf(){
  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Usuário (cliente)\n";
  cout << "2 - Gerente\n";
  //cout << "3 - Administrador\n";
  cout << "-> :";
  int pf; 
  cin >> pf;

  return pf;
}