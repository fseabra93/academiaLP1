#ifndef _ALUNO_HPP
#define _ALUNO_HPP

  void cadastrarOnibus(int num_linha, string terminal, string itiner);
  void carregarValoresOnibus();
  void listaOnibus();
  void buscaOnibus(int num_linha);
  void verTreinoAluno(long long int matricula);
  void verInstrutorAluno(long long int matricula);
  void alterarTreinoAluno(long long int matricula, std::string novoTreino);
  void apagarAluno(long long int matricula);
  void atualizarArquivoAluno();

#endif