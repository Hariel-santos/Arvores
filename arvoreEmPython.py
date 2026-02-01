class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

def inserir(no, valor):
    if no is None:
        return No(valor)
    
    elif valor < no.valor:
        no.esquerda = inserir(no.esquerda, valor)
        
    else:
        no.direita = inserir(no.direita, valor)

    return no

def em_ordem(no):
    if no:
        em_ordem(no.esquerda)
        print(no.valor, end=" ")
        em_ordem(no.direita)


raiz = None

while True:
    numAdd = int(input("informe o numero que deseja adicionar a arvore: "))
    raiz = inserir(raiz, numAdd)
    em_ordem(raiz)
    print()
