#include <iostream>
#include "aluno.hpp" //importa o arquivo de cabeçalho do instrutor
#include "instrutor.hpp" //importa o arquivo de cabeçalho do instrutor

using namespace std;

int main(int argc, char *argv[]){

  //imprimir o título

  string titulo = "### Sistema Gerenciador de Transportes Coletivos ###";
  int tam_titulo = titulo.length();

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl;
  
  cout << "### Sistema Gerenciador de transportes coletivos ###\n";

  for (int i=0; i<tam_titulo; i++){
    cout << "#";
  } cout << endl;
  
  /* Escolhendo o perfil (aluno, instrutor ou admin */
  
  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Usuário (cliente)\n";
  cout << "2 - Gerente\n";
  //cout << "3 - Administrador\n";
  cout << "-> :";
  int perfil; 
  cin >> perfil;
  
  /* Lê o arquivo aluno.txt e carrega os dados no sistema */
  carregarValoresAlunos();
  /* Lê o arquivo instrutor.txt e carrega os dados no sistema */
  carregarValoresInstrutor();
  
  /* Menu de opções para o perfil Aluno */
  if(perfil == 1){
    while(true){
      cout << "\n#####   Usuário (cliente)   #####\n\n";
      cout << "1 - Ver ônibus cadastrados (nome da linha e bairro)\n";
      cout << "2 - Buscar um ônibus por seu bairro (terminal)\n";
      cout << "3 - Ver o itinerário de um ônibus (busque pelo nome da linha)\n";
      cout << "4 - Fazer uma reclamação (a reclamação será anônima)\n";
      int opt;
      cin >> opt;
      
      /* Busca o treino do aluno por sua matricula */
      if(opt == 1){
        cout << "\n####  Ver treino   ####\n";
        cout << "Digite sua matricula: ";
        long long int matricula;
        cin >> matricula;
        verTreinoAluno(matricula); //Chama a função em aluno.cpp
      }

      /* Busca o instrutor do aluno com a matricula do aluno */
      else if(opt == 2){
        cout << "Digite sua matricula: ";
        long long int matricula;
        cin >> matricula;
        verInstrutorAluno(matricula); //Chama a função em aluno.cpp
      }
      
      /* Sai do while(true) */
      else{
        break;
      }
    } 
  }

  /* Menu de opções para o perfil instrutor */
  else if(perfil == 2){
    while(true){
      cout << "\n#####   Perfil instrutor   #####\n\n";
      cout << "1 - Listar alunos\n";
      cout << "2 - ver treino de aluno\n";
      cout << "3 - alterar treino de aluno\n";
      cout << "4 - Sair\n";

      int opt;
      cin >> opt;


      /* Lista todos os alunos */
      if(opt == 1){
        listaAluno(); //Chama a função em aluno.cpp
      }
      
      /* Busca o treino de um aluno por sua matricula */
      else if(opt == 2){
        cout << "\n####  Ver treino   ####\n";
        cout << "Digite a matricula do aluno: ";
        long long int matricula;
        cin >> matricula;
        verTreinoAluno(matricula); //Chama a função em aluno.cpp
      }

      /* Altera o  treino do aluno */
      else if(opt == 3){
        cout << "Digite a matricula do aluno: ";
        long long int matricula;
        string treino;
        cin >> matricula;
        cin.ignore();
        cout << "\nDigite o novo treino: \n";
        getline(cin, treino);
        alterarTreinoAluno(matricula, treino); //Chama a função em aluno.cpp
      }
      
      /* Sai do while(true) */
      else{
        break;
      }
    }
  }

  /* Menu de opções para o perfil admin */
  else if(perfil == 3){
    while(true){
      cout << "\n#####   Perfil administrador   #####\n\n";
      cout << "1 - Cadastrar alunos\n";
      cout << "2 - Cadastrat instrutor\n";
      cout << "3 - Listar alunos\n";
      cout << "4 - Listar instrutores\n";
      cout << "5 - Excluir alunos\n";
      cout << "6 - Excluir instrutores\n";
      cout << "7 - Sair\n";

      int opt;
      cin >> opt;

      /* Cadastrar um novo aluno */
      if(opt == 1){
        string nome, treino, end;
        long long int inst, mat;
        cout << "\n#####   Cadastrar aluno   #####\n";
        cout << "Matricula: ";
        cin >> mat;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Treino: ";
        getline(cin, treino);
        cout << "Endereço: ";
        getline(cin, end);
        cout << "Instrutor: ";
        cin >> inst;
        cadastrarAluno(mat, nome, end, treino, inst); //Chama a função em aluno.cpp
      }

      /* Cadastrar um novo instrutor */
      else if(opt == 2){
        string nome, funcao;
        long long int mat;
        cout << "\n#####   Cadastrar instrutor   #####\n";
        cout << "Matricula: ";
        cin >> mat;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Função: ";
        getline(cin, funcao);
        cadastrarInstrutor(mat, nome, funcao); //Chama a função em instrutor.cpp
      } 

      /* Listar todos os alunos cadastrados */
      else if(opt == 3){
        listaAluno(); //Chama a função em aluno.cpp
      }

      /* Listar todos os instrutores cadastrados */
      else if(opt == 4){
        listaInstrutor(); //Chama a função em instrutor.cpp
      }

      /* Apaga um aluno por sua matricula */
      else if(opt == 5){
        cout << "Digite a matricula do aluno: ";
        long long int matricula;
        cin >> matricula;
        apagarAluno(matricula); //Chama a função em aluno.cpp
      }

      /* Apaga um instrutor por sua matricula */
      else if(opt == 6){
        cout << "Digite a matricula do Instrutor: ";
        long long int matricula;
        cin >> matricula;
        apagarInstrutor(matricula); //Chama a função em instrutor.cpp
      }

      /* Sai do while(true) */
      else{
        break;
      }
    }
  }

  /* Caso o perfil não exista */
  else{
      cout << "Perfil não localizado\n"<< endl;
    }
  
  return 0; 
}