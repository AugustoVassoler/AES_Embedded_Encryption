# Compilador e flags
CC = gcc
CFLAGS = -Iinclude -I$(OPENSSL_DIR)/include -I$(CMOCKA_DIR)/include
LDFLAGS = -L$(OPENSSL_DIR)/lib -lcrypto -lssl -L$(CMOCKA_DIR)/lib -lcmocka

# Diretorios e arquivos
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

# Arquivos fonte
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/aes_decrypt.c
TEST_FILES = $(TEST_DIR)/test_aes_decrypt.c

# Executaveis
MAIN_EXEC = $(BIN_DIR)/main.exe
TEST_EXEC = $(BIN_DIR)/tests.exe

# Alvo padrao
all: $(MAIN_EXEC) $(TEST_EXEC)

# Compilacao do programa principal
$(MAIN_EXEC): $(SRC_FILES) | $(BIN_DIR)
	@echo "Compilando o programa principal..."
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(MAIN_EXEC) $(LDFLAGS)
	@echo "Programa principal compilado: $(MAIN_EXEC)"

# Compilacao dos testes unitarios
$(TEST_EXEC): $(SRC_FILES) $(TEST_FILES) | $(BIN_DIR)
	@echo "Compilando os testes unitários..."
	$(CC) $(CFLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST_EXEC) $(LDFLAGS)
	@echo "Testes unitários compilados: $(TEST_EXEC)"

# Diretorio para binarios
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Alvo para executar o programa principal
run: $(MAIN_EXEC)
	@echo "Executando o programa principal..."
	$(MAIN_EXEC)

# Alvo para executar os testes unitarios
test: $(TEST_EXEC)
	$(TEST_EXEC)

# Alvo para compilar e executar o programa e os testes em sequencia
run_all: all
	$(MAIN_EXEC)
	@echo "Executando os testes unitários..."
	$(TEST_EXEC)

# Limpeza dos binários
clean:
	@echo "Removendo arquivos binários..."
	rm -rf $(BIN_DIR)/*.exe
	@echo "Arquivos binários removidos."