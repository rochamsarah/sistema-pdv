# sistema-pdv
Projeto realizado em linguagem C para sistema de PDV, como parte de projeto para obtenção de nota no curso de Análise e Desenvolvimento de Sistemas. O sistema possui opções de controle de estoque, desde cadastro a exibição de produtos, realização de vendas e formas de pagamento.

Sobre o funcionamento, passo a passo:

Ao iniciar a aplicação, o usuário se depara com a tela de menu principal, onde deverá escolher entre as 4 opções ou a opção 0 para sair da aplicação, digitando o número correspondente.

Digitando a opção 1, a seguinte tela irá fazer as seguintes solicitações: inserir nome do produto, sem acentuações, preço, onde deve-se separar as casas decimais com uma vírgula, e a quantidade. Em relação à quantidade, pode-se inserir tanto por unidades quanto por peso disponível, seguindo o mesmo critério de separação das casas decimais com uma vírgula. Após informar a quantidade, o produto será cadastrado e em seguida o usuário deve informar digitando um “s” se deseja inserir outro produto ou “n” se quiser encerrar o cadastro. Caso digite “n” a aplicação voltará para o Menu Principal.

Ao escolher a opção 2 no Menu Principal, o usuário poderá visualizar o estoque cadastrado.

Para realizar uma venda, o usuário deve escolher a opção 3 no Menu Principal. Assim que escolher, a aplicação exibirá os itens disponíveis em
estoque, onde cada item é indicado com uma numeração ao lado. O usuário, no momento da venda, irá selecionar o número correspondente ao item que deseja vender, em seguida irá informar a quantidade, seja em kg ou unidade, conforme exemplo abaixo. Assim que for informada a quantidade do produto, a aplicação exibirá um subtotal proporcional ao peso ou por unidade e em seguida perguntará se deseja adicionar outro item. Em caso de venda por unidade, basta informar um número inteiro, conforme mostra no exemplo com o item “Laranja”.

Caso o usuário já tenha inserido todos os produtos, basta digitar a opção 0 (zero) para finalizar a compra, onde então é exibido o total geral dos produtos e é solicitado que informe a forma de pagamento. Se informado uma das opções, PIX, débito ou crédito, a aplicação informará para realizar o pagamento através da maquininha, e caso seja selecionada a opção de pagamento em dinheiro, o usuário deverá colocar o valor dado em dinheiro pelo cliente e em seguida a própria aplicação informará a quantidade de troco e em seguida irá finalizar a venda.

Um detalhe importante é que, após a venda ser concluída, o estoque irá atualizar automaticamente.

Temos em seguida a última opção do Menu Principal, ao digitar 4, onde o usuário pode atualizar o estoque informando uma quantidade extra que deseja incluir para somar com o estoque já existente. Para isso, deve-se atentar para digitar o nome do produto exatamente conforme foi cadastrado, sem acentuações. Em seguida informar a quantidade que deseja somar com o estoque já existente.
