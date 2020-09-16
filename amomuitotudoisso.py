class Cliente:
    def __init__(self, *args, **kwarg):
        self.nome = kwarg.get("nome", "")
        self.idade = kwarg.get("idade", 0)
        

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

fila_normal = []
fila_pref = []
fila_espera = []
opcao = []
numero = 0

# péssimo (1), ruim (2), mediano (3), bom(4) e ótimo (5)
class Voto:
    def __init__(self, *args, **kwarg):
        self.pessimo = kwarg.get("pessimo",0)
        self.ruim = kwarg.get("ruim",0)
        self.mediano = kwarg.get("mediano",0)
        self.bom = kwarg.get("bom",0)
        self.otimo = kwarg.get("otimo",0)
    
    def votopessimo(self):
        self.pessimo = self.pessimo + 1

    def votoruim(self):
        self.ruim = self.ruim + 1

    def votomediano(self):
        self.mediano = self.mediano + 1

    def votobom(self):
        self.bom = self.bom + 1

    def votootimo(self):
        self.otimo = self.otimo + 1

# 
# opções
# 
opcao.append(Opcao(op_numero = 1, nome = "HAMBURGUER", tempo = 6, valor = 20))
opcao.append(Opcao(op_numero = 2, nome = "SUCO", tempo = 1, valor = 5))
opcao.append(Opcao(op_numero = 3, nome = "SOBREMESA", tempo = 1, valor = 10))
opcao.append(Opcao(op_numero = 4, nome = "HAMBURGUER+SUCO+SOBREMESA", tempo = 8, valor = 30))

voto = Voto()

def novo_cli(nome, idade):
    if idade <= 65:
        fila_normal.append(Cliente(nome = nome, idade = idade))
    else:
        fila_pref.append(Cliente(nome = nome, idade = idade))

  

def novo_pedido(opcoes, cliente):
    global numero
    numero = numero + 1
    totaltempo = 0
    valortotal = 0
    for i in opcoes:
        totaltempo = totaltempo + i.tempo
        valortotal = valortotal + i.valor
    

    fila_espera.append(Pedido(numero = numero, opcao = opcoes, tempot = totaltempo, vtotal = valortotal, cliente = cliente))

    if cliente.idade <= 65:
        fila_normal.remove(cliente)
    else:
        fila_pref.remove(cliente)


def printlistas():
    print ("###################################################")
    print ("lista fila preferencial")
    for i in fila_pref:
        print(" - Nome do CLiente : {0}".format(i.nome))


    print ("lista fila normal")
    for i in fila_normal:
        print(" - Nome do CLiente : {0}".format(i.nome))


    print ("lista espera")
    for i in fila_espera:
        print(" - Nome do CLiente : {0} - pedido numero: {1} - tempo: {2} - total: {3}".format(i.cliente.nome, i.numero, i.tempot, i.vtotal))
        
    print ("\n")


def chama():
    if (fila_pref):
        return fila_pref[0]
    else:
        return fila_normal[0]

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


printlistas()  # Printa as  filas

#
# NOVO pedido
#
davez = chama() # pega o primeiro da fila pref se não tiver pega o primeiro da normal
print ("+Fazendo Pedido para : {0}".format(davez.nome))
novo_pedido(opcoes = [opcao[0], opcao[1]], cliente = davez)
voto.votobom()

printlistas() # Printa as  filas

davez = chama()
print ("+Fazendo Pedido para : {0}".format(davez.nome))
novo_pedido(opcoes = [opcao[3]], cliente = davez)
voto.votootimo()

printlistas() # Printa as  filas

davez = chama()
print ("+Fazendo Pedido para : {0}".format(davez.nome))
novo_pedido(opcoes = [opcao[1], opcao[2], opcao[0]], cliente = davez)
voto.votobom()

printlistas() # Printa as  filas

print ("Os totais de Votos :\npéssimo {0}, ruim {1}, mediano {2}, bom {3} e ótimo {4}".format(voto.pessimo, voto.ruim, voto.mediano, voto.bom, voto.otimo))