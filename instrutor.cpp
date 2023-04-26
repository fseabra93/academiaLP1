#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

struct Instrutor{
  string nome;
  string funcao;
};

map<long long int, Instrutor> instrutores;

void carregarValoresInstrutor(){
  fstream arquivoCriar;
  arquivoCriar.open("instrutor.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  fstream arquivoler;
  arquivoler.open("instrutor.txt", ios::in);
  string linha;
  vector<string> vetor;
  
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }

  arquivoler.close();
  
  for(int i = 0; i< vetor.size(); i+=3){
    long long int matricula = stoll(vetor[i]);
    instrutores[matricula].nome = vetor[i+1];
    instrutores[matricula].funcao = vetor[i+2];
  }
}

/* Cadastrar um novo instrutor */
void cadastrarInstrutor(long long int matricula, string nome, string funcao){
  fstream arquivo;
  arquivo.open("instrutor.txt", ios::out | ios::app); //Abre um arquivo (escrita)
  arquivo << matricula << endl;
  instrutores[matricula].nome = nome;
  arquivo << nome << endl;
  instrutores[matricula].funcao = funcao;
  arquivo << funcao << endl;
  arquivo.close();
  cout << "Instrutor cadastrado!!!\n";
  
}

/* Listar um instrutor */
void listaInstrutor(){
  cout << "\n####  Lista de Instrutores   ####\n\n";
  cout << "*************************\n";
  for(auto i : instrutores){
    cout << "Matricula: "<< i.first << endl;
    cout << "Nome: "<< i.second.nome << endl;
    cout << "Função: "<< i.second.funcao << endl;
    cout << "*************************\n";
  }
}

/* Buscar um instrutor */
void buscaInstrutor(long long int mat){
  cout << "\n####  Buscando Instrutores..   ####\n";
  for(auto i : instrutores){
    if(i.first == mat){
      cout << "\n*************************\n";
      cout << "Matricula do instrutor: " << i.first;
      cout << "\nNome do instrutor: " << i.second.nome;
      cout << "\nFormação do instrutor: " << i.second.funcao << endl;
      cout << "*************************\n";
      cout << endl;
    }   
  }
}

bool existeInstrutor(long long int mat){
  for(auto i : instrutores){
    if(i.first == mat){
      return true;
    }   
  }
  return false;
}

void atualizarArquivoInstrutor(){
  fstream arquivo;
  arquivo.open("instrutores.txt", ios::out);
  
  for(auto i : instrutores){
    arquivo << i.first << endl;
    arquivo << i.second.nome << endl;
    arquivo << i.second.funcao << endl;
    
  }
}

void apagarInstrutor(long long int matricula){
  for(auto i : instrutores){
    if(i.first == matricula){
      instrutores.erase(matricula);
      atualizarArquivoInstrutor();
      cout << "instrutor excluido com sucesso" << endl;
      return;
    }   
  }
  cout << "instrutor não encontrado!!!" << endl;
}





