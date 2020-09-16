class Cliente:
    def __init__(self, *args, **kwarg):
        self.nome = kwarg.get("nome", "")
        self.idade = kwarg.get("idade", 0)
        self.n_pedido = kwarg.get("n_pedido", {})


class Pedido:
    def __init__(self, *args, **kwarg):
        self.numero = kwarg.get("numero", 0)
        self.opcao = kwarg.get("opcao", {})
        self.tempot = kwarg.get("tempot", 0)
        self.vtotal = kwarg.get("vtotal", 0)
        self.cliente = kwarg.get("cliente", {})

class Opcao:
    def __init__(self, *args, **kwarg):
        self.op_numero = kwarg.get("op_numero", 0)
        self.nome = kwarg.get("nome", "")
        self.tempo = kwarg.get("tempo", 0)
        self.valor = kwarg.get("valor", 0)


# class Espera:
#     def __init__(self, *args, **kwarg):
#         self.nome = kwarg.get("nome", "")
#         self.tempo = kwarg.get("tempo", 0)
#         self.numero = kwarg.get("numero", 0)


fila_normal = []
fila_pref = []

fila_espera = []

opcao = []

numero = 0



# 
# opções
# 
opcao.append(Opcao(op_numero = 1, nome = "HAMBURGUER", tempo = 6, valor = 20))
opcao.append(Opcao(op_numero = 2, nome = "SUCO", tempo = 1, valor = 5))
opcao.append(Opcao(op_numero = 3, nome = "SOBREMESA", tempo = 1, valor = 10))
opcao.append(Opcao(op_numero = 4, nome = "HAMBURGUER+SUCO+SOBREMESA", tempo = 8, valor = 30))

def novo_cli(nome, idade, **n_pedido):
    if idade <= 65:
        fila_normal.append(Cliente(nome = nome, idade = idade, n_pedido = n_pedido.get("n_pedido", None)))
    else:
        fila_pref.append(Cliente(nome = nome, idade = idade, n_pedido = n_pedido.get("n_pedido", None)))

  

def novo_pedido(opcoes, cliente):
    global numero
    numero = numero + 1
    totaltempo = 0
    valortotal = 0
    for i in opcoes:
        totaltempo = totaltempo + i.tempo
        valortotal = valortotal + i.valor
    
    Cliente.n_pedido = numero
    fila_espera.append(Pedido(numero = numero, opcao = opcoes, tempot = totaltempo, vtotal = valortotal, cliente = cliente))

    if cliente.idade <= 65:
        fila_normal.remove(cliente)
    else:
        fila_pref.remove(cliente)


def printlistas():
    print ("\n")
    print ("###################################################")
    print ("lista fila preferencial")
    for i in fila_pref:
        print(" - Nome do CLiente : {0}".format(i.nome))

    # print ("\n")

    print ("lista fila normal")
    for i in fila_normal:
        print(" - Nome do CLiente : {0}".format(i.nome))

    # print ("\n")

    print ("lista espera")
    for i in fila_espera:
        print(" - Nome do CLiente : {0} - pedido numero: {1} - tempo: {2} - total: {3}".format(i.cliente.nome, i.numero, i.tempot, i.vtotal))
        
    print ("\n")





# 
# entrada de dados e processamentos
# 

#
# NOVO CLIENTE
#
novo_cli(nome = "Marcelo", idade = 49)
novo_cli(nome = "Eitor", idade =  18)
novo_cli(nome = "Maria", idade =  68)
novo_cli(nome = "Sidney", idade =  69)

#
# lista filas
#
printlistas()

#
# NOVO pedido
#
novo_pedido(opcoes = [opcao[0], opcao[1]], cliente = fila_pref[0])

printlistas()

novo_pedido(opcoes = [opcao[3]], cliente = fila_pref[0])

printlistas()