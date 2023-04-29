#ifndef _ALUNO_HPP
#define _ALUNO_HPP

  void cadastrarOnibus(int num_linha, string terminal, string itiner);
  void carregarValores();
  void listaOnibus();
  void buscaOnibusLinha(int num_linha);
  void buscaOnibusBairro(string bairro);
  void apagarOnibus(int linha);
  void atualizarArquivo_onibus();
  void listaReclamacoes();
  void cadastrarReclamacao();
  void listaOnibus();
  void alterarTerminal(int linha, string novo);
  void alterarItinerario(int linha, string novo);
  int perf();

#endif