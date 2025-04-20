typedef struct{
 int hora_chegada[2];
 int min_chegada[2];
 int hora_saida[2];
 int min_saida[2];
} PontoEletronico;

void iniciaPontoEletronico(PontoEletronico *funcionario);
void registraPonto(PontoEletronico *funcionario, int hora, int min);
void imprimeTotalTrabalhadoDia(PontoEletronico funcionario);
