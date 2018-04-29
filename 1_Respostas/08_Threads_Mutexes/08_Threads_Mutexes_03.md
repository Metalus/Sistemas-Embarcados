1. Apresente as características e utilidades das seguintes funções:

(a) `popen()`

Semelhante ao system, porém cria uma pipe entre o comando chamado, uma stream

(b) `pclose()`

Usado para encerrar um stream aberto com o popen

(c) `fileno()`

Obtém descrição do stream usado no popen

2. Quais são as vantagens e desvantagens em utilizar:

(a) `popen()?`

Vantagem: Mantém uma stream de dados entre os processos
Desvantagem: Não cria uma nova imagem e pode travar o processo

(b) `exec()?`

Vantagem: Cria uma nova imagem do processo e não trava o processo pai.
Desvantagem: Não mantém comunicação pipe entre os processos.