class Cliente:
    def __init__(self, *args, **kwarg):
        self.nome = kwarg.get("nome", "")
        self.idade = kwarg.get("idade", 0)
        self.pedido = kwarg.get("pedido", {})


class Pedido:
    def __init__(self, *args, **kwarg):
        self.numero = kwarg.get("numero", 0)
        self.opcao = kwarg.get("opcao", {})
        self.tempo = kwarg.get("tempo", 0)
        self.vtotal = kwarg.get("vtotal", 0)

class Opcao:
    def __init__(self, *args, **kwarg):
        self.op_numero = kwarg.get("op_numero", 0)
        self.nome = kwarg.get("nome", "")
        self.tempo = kwarg.get("tempo", 0)
        self.vtotal = kwarg.get("valor", 0)


# class Espera:
#     def __init__(self, *args, **kwarg):
#         self.nome = kwarg.get("nome", "")
#         self.tempo = kwarg.get("tempo", 0)
#         self.numero = kwarg.get("numero", 0)


fila_espera_normal = []
fila_espera_pref = []
fila_normal = []
fila_pref = []
opcao = []

# 
# opções
# 
opcao.append(Opcao(op_numero = 1, nome = "HAMBURGUER", tempo = 6, valor = 20))
opcao.append(Opcao(op_numero = 2, nome = "SUCO", tempo = 1, valor = 5))
opcao.append(Opcao(op_numero = 3, nome = "SOBREMESA", tempo = 1, valor = 10))
opcao.append(Opcao(op_numero = 4, nome = "HAMBURGUER+SUCO+SOBREMESA", tempo = 8, valor = 30))

def novo_cli(name, idade, **npedido):
    if idade <= 65:
        fila_normal.append(Cliente(name = name, idade = idade, npedido = npedido.get("npedido", None)))
    else:
        fila_pref.append(Cliente(name = name, idade = idade, npedido = npedido.get("npedido", None)))

  

def novo_pedido(op_numero, name):
    # numero = 0
    








# 
# entrada de dados e processamentos
# 
novo_cli(name = "Marcelo", idade = 49)
novo_cli(name = "Eitor", idade =  18)
novo_cli(name = "Maria", idade =  68)


