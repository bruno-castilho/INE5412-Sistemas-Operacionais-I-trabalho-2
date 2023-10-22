# INE5412-Sistemas-Operacionais-I-trabalho-2

## Descrição
O presente trabalho tem por objetivo escrever um programa para simular o comportamento
de algoritmos de subsituição de páginas, usados pelos mecanismos de paginação dos sistemas
operacionais modernos. O programa deve simular os seguintes algoritmos de substituição de
páginas:
• FIFO (First In, First Out)
• OPT (Algoritmo ótimo)
• LRU (Least Recently Used)
O programa deve receber como parâmetro o número de quadros (frames) disponíveis na
memória RAM (usando os parâmetros argc/argv na main) e ler da entrada padrão (stdin – usando
cin por exemplo) a sequência de referência às páginas (uma referência por linha), conforme
exemplo abaixo:

```
./simulador 4 < referencias.txt
ou
cat referencias.txt | ./simulador 4
```

No exemplo acima, a memória RAM tem 4 quadros e o arquivo referencias.txt contém as
referências de acesso para as páginas, sendo uma por linha. A entrada deve ser finalizada quando for
encontrado um caracter vazio indicando final de arquivo (usar !feof(stdin) para parar o laço de
entrada).

A saída da simulação deve ter o número de quadros, o número de acesso a memória e o
número de falta de páginas verificado para cada algoritmo, de acordo com o exemplo a seguir:
```
4 quadros
30 refs
FIFO: 17 PFs
LRU: 15 PFs
OPT: 11 PFs
```

## Instalação
### Opção 1: Bare Metal
   **Passo 1: Verifique se o GCC 11.4.0 já está instalado**
    
   ```bash
   gcc --version
   ```
   
   **Passo 2: Atualize os repositórios do sistema**
    
   ```bash
   sudo apt update
   ```
   
   **Passo 3: Adicione o repositório Toolchain**
    
   ```bash
   sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
   ```
 
   **Passo 4 : Instale o GCC 11**
   
    
   ```bash
   sudo apt install -y gcc-11
   ```
    
    
   **Passo 5 : Verifique a instalação**
   
   ```bash
   gcc --version
   ```
   
### Opção 2: Docker
   **Passo 1: Baixe o script de instalação do Docker**
    
   ```bash
   curl -fsSL https://get.docker.com -o get-docker.sh
   ```
   
   **Passo 2: Execute o script**
   
   ```bash
    sudo sh ./get-docker.sh --dry-run
   ```
   **Passo 3: Verifique se a instalação foi bem sucedida executando a imagem hello-world**
   
   ```bash
    sudo docker run hello-world
   ```
   

## Compilação
### Opção 1: Bare Metal
  **Na pasta raiz do projeto, execute**
  ```bash
    make
  ```

### Opção 2: Docker
  **Na pasta raiz do projeto, execute**
   ```bash
    docker build -t page-eplacement .
   ```
## Execução
### Opção 1: Bare Metal
**Na pasta raiz do projeto, execute**
   ```bash
    ./main 4 < data/vsim-belady.txt
   ```
### Opção 2: Docker
**Na pasta raiz do projeto, execute**
   ```bash
    docker run -v ./data:/data page-eplacement ./main 4 < vsim-belady.txt
   ```
