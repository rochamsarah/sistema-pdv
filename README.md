# 🛒 Sistema de PDV e Gestão de Hortifrúti

Este projeto consiste em um sistema de **Ponto de Venda (PDV)** desenvolvido em **Linguagem C**. Ele foi projetado para otimizar a gestão de estoque e o processo de vendas de um estabelecimento comercial, unindo lógica estruturada a uma preocupação com a experiência do usuário final (UX).

---

## 🚀 Funcionalidades Principais

O sistema foi construído focando em regras de negócio reais, permitindo um fluxo completo de operação:

- **Gestão de Inventário:** Cadastro de produtos com suporte a diferentes métricas (Unidade e Peso/Kg).
- **Persistência de Dados:** Implementação de leitura e escrita em arquivos `.txt`, garantindo que os dados cadastrados sejam preservados após o encerramento da aplicação.
- **Processamento de Vendas:** Interface para seleção de itens, cálculo automático de subtotal e fechamento de conta.
- **Módulo Financeiro:** Suporte a múltiplas formas de pagamento (PIX, Crédito, Débito e Dinheiro) com cálculo automatizado de troco.
- **Atualização de Estado:** Sistema de baixa automática de estoque após a confirmação de cada venda.

---

## 🛠️ Fundamentos Técnicos e Engenharia

Este projeto foi o marco da minha transição para a tecnologia, onde apliquei conceitos de **Engenharia de Software** e **Programação Orientada a Objetos (POO)**:

- **Engenharia de Requisitos:** Elaboração de documentação técnica completa, detalhando o fluxo do usuário e a viabilidade do projeto.
- **Estruturas de Dados:** Uso de `structs` para organização de objetos e manipulação de arrays para gestão de produtos.
- **Metodologias Ágeis:** O desenvolvimento foi pautado em conceitos de **SCRUM**, com foco em entregas funcionais e organização de backlog de funcionalidades.
- **Manipulação de Arquivos:** Implementação de lógica de Entrada/Saída (I/O) para armazenamento persistente em disco.

---

## 📈 Contexto de Desenvolvimento

Desenvolvido originalmente em 2024 como parte da minha formação em tecnologia, este projeto representa a consolidação da minha base lógica. 

Como **Designer há 12 anos** e atual graduanda em **Engenharia de Software na FPF Tech**, utilizei este sistema para explorar a interseção entre o design funcional e a robustez do código. Atualmente, sigo evoluindo esses conceitos para o ecossistema de **Ciência de Dados e Python**.

---

## 💻 Como Executar

1. Clone o repositório:
   ```bash
   git clone [https://github.com/rochamsarah/sistema-pdv.git](https://github.com/rochamsarah/sistema-pdv.git)
2. Compile o código:
   ```bash
   gcc main.c -o pdv
3. Execute o programa:
   ```bash
   ./pdv
