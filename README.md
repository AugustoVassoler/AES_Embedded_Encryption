# AES_Embedded_Encryption

Este repositório contém um projeto em C que utiliza o algoritmo AES para decodificar uma mensagem previamente codificada e valida o seu funcionamento por meio de testes unitários. O projeto foi desenvolvido para compilar e executar em um ambiente Windows utilizando o compilador GCC disponível no MinGW-w64, e utiliza a biblioteca **OpenSSL** para a implementação de criptografia e **CMocka** para testes unitários.

---

## Índice

1. [Descrição do Projeto](#descrição-do-projeto)
2. [Estrutura do Repositório](#estrutura-do-repositório)
3. [Bibliotecas Utilizadas](#bibliotecas-utilizadas)
4. [Passos para Compilação e Execução](#passos-para-compilação-e-execução)
5. [Execução de Testes Unitários](#execução-de-testes-unitários)
6. [Makefile](#makefile)
7. [Configuração Adicional](#configuração-adicional)

---

## Descrição do Projeto

Este projeto visa decodificar uma mensagem criptografada usando o **algoritmo AES em modo ECB** com uma chave de 128 bits. A chave de criptografia utilizada é `"thisisasecretkey"`, e a mensagem criptografada é fornecida no formato hexadecimal, sendo ela 'a57fd9725fb53c53d5bd0b56185da50f70ab9baea5a43523b76c03e3eb989a20'. O sistema lê a mensagem criptografada, realiza a decodificação e exibe o texto decodificado no terminal.

Além da decodificação, o projeto inclui um conjunto de **testes unitários** escritos com a biblioteca CMocka. Esses testes garantem que a função de decodificação opera corretamente e que o comportamento do módulo de criptografia é validado.

## Estrutura do Repositório

```plaintext
aes_decryption_project/
├── include/
│   └── aes_decrypt.h         # Cabeçalho da função de decodificação AES
├── src/
│   ├── main.c                # Arquivo principal para execução do programa
│   └── aes_decrypt.c         # Implementação da função de decodificação AES
├── tests/
│   └── test_aes_decrypt.c    # Testes unitários para a função de decodificação AES
├── Makefile                  # Arquivo Makefile para compilar e executar o projeto
├── README.md                 # Este arquivo README com instruções detalhadas
└── .gitignore                # Arquivo para ignorar arquivos temporários e binários
```

## Bibliotecas utilizadas

O projeto faz uso das seguintes bibliotecas:

- **OpenSSL:** Biblioteca usada para funções de criptografia AES, necessária para decodificar a mensagem.
- **CMocka:** Biblioteca de testes unitários para validar o comportamento e a robustez da função de decodificação.

## Instalação das bibliotecas

1. **OpenSSL:**
	- Baixe e instale o [OpenSSL](https://openssl-library.org/source/index.html).
	- Defina a variável de ambiente 'OPENSSL_DIR' para o diretório de instalação do OpenSSL.

2. **CMocka:**
	- Baixe e instale a [biblioteca CMocka](https://cmocka.org/)
	- Adicione o diretório 'lib' e 'include' do CMocka ao caminho de pesquisa do compilador no 'Makefile'ou configure a variável de ambiente 'CMOCKA_DIR'. 

---

## Passos para a compilação e execução

### Pré-requisitos
- **MinGW-w64:** Para compilar o código, instale o MinGW-w64 e adicione o diretório 'bin' ao PATH do Windows.
- **Make:** O comando 'make' está disponível via Git Bash ou diretamente no ambiente do MinGW-w64.

### Compilação
1. Abra o terminal e navegue até o diretório do projeto.
```bash
cd caminho/para/aes_decryption_project
```

2. Execute o comando make para compilar o código e os testes:
```bash
make
```
Isso irá gerar os executáveis 'main.exe' e 'tests.exe' no diretório raiz do projeto.

### Execução do programa principal
Para executar o programa principal, basta executar o arquivo .exe gerado:
```bash
.\main.exe
```
Esse comando executará a função de decodificação e exibirá a mensagem decodificada no terminal.

### Execução dos testes unitários
1. Compile os testes (já incluído no comando 'make').
2. Executar './tests.exe'.

Os testes unitários visam validar:
- O correto funcionamento da função de decodificação AES com a chave e input corretos.
- Casos limite e inputs inválidos que garantem a robustez da função.

## Makefile
Os alvos disponíveis são:
- **all:**    Compila o programa principal e os testes.
- **run:**    Compila e executa o programa principal, seguido da execução dos testes.
- **test:**   Executa os testes unitários.
- **run_all** Compila o projeto e executa o programa e os testes em sequência.
- **clean:**  Remove os executáveis ('main.exe' e 'tests.exe').

Para compilar o projeto e executar o programa e os testes em sequência, utilize:
```bash
make run_all
```
Para limpar os arquivos binários gerados:
```bash
make clean
```

## Configuração adicional
### Variáveis de ambiente
É importante atentar-se à correta configuração dos caminhos das bibliotecas OpenSSL e CMocka, descritos respectivamente nas variáveis 'OPENSSL_DIR' e 'CMOCKA_DIR'. Elas visam permitir que o projeto localize as bibliotecas de maneira genérica, sem a necessidade de modificação direta no Makefile.