#ifndef _ALUNO_HPP
#define _ALUNO_HPP

  void cadastrarAluno(long long int matricula, std::string nome, std::string endereco, std::string treino, long long int instrutor);
  void carregarValoresAlunos();
  void listaAluno();
  void buscaAluno(long long int mat);
  void verTreinoAluno(long long int matricula);
  void verInstrutorAluno(long long int matricula);
  void alterarTreinoAluno(long long int matricula, std::string novoTreino);
  void apagarAluno(long long int matricula);
  void atualizarArquivoAluno();

#endif