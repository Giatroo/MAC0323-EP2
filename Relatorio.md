# Relatório do EP2 de Estrutura de Dados 2

Para esse relatório, alguns textos em Português e Inglês serão utilizados, para compararmos uma língua latina e ânglo-saxônica.

Além disso, vamos utilizar o valor $k$ do enunciado para também verificar se percebemos mudanças nos grafos de alguns desses textos.

## Detalhes da implementação

Antes de analisar o texto, é importante dizer algumas decisões de implementação.

Todas as palavras retiradas do texto passam por um pre-processaento antes de serem inseridas no grafo. O algoritmo faz os seguintes processos:
* Os caracteres que são letras do alfabeto americano (A-Za-z) são todas passadas para mínusculo;
* Os seguintes caracteres são removidos da palavra: `.\"!-:,_'’—?)(;*#1234567890$@%&*[]+/ `;
* Finalmente se o caracter é não ASCII, também o removemos. O que significa que acentos são removidos.

## Os Lusiadas

Inicialmente, vamos utilizar o clássico de Camões com $k=0$ para verificarmos como um texto em língua português se comporta.

**Número de vértices:** 9303
**Número de arestas:** 10963
**Número de componentes:** 3824
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 3449
**Tamanho médio das componentes:** 3.43279
**Grau médio:** 2.35687
**Densidade:** 1.17844

**Observações sobre os dados:** rapidamente que mais de um terço dos vértices se localizam todos numa mesma componente conexa. Esse número provavelmente não é ainda maior porque o português possui muitas palavras com acentos, hífen e outros caracteres que são removidos no pré-procesamento. Assim, acabamos criando algumas palavras que ficarão isoladas no grafo como *fazei-vos*, que se torna *fazeivos* e não se parece com nada. 

Nossa conclusão é que o português possui palavra muito parecidas e que derivam umas das outras. Entretanto, vemos que o grafo não é muito denso, o número de arestas é pouca coisa a mais que o número de vértices. Isso significa que, por mais que tenhamos aquela enorme componente incluindo a maioria das palavras, as palavras não possuem tantos vizinhos no grafo, como confirma também o grau médio de aproximadamente 2.

Vamos agora aumentar o $k$ e ver que como esses dados vão mudando.

### $k=3$

Pouco mudou:

**Número de vértices:** 9187
**Número de arestas:** 9585
**Número de componentes:** 3828
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 3329
**Tamanho médio das componentes:** 3.39995
**Grau médio:** 2.08664
**Densidade:** 1.04332

**Observações sobre os dados:** vemos que o número de vértices caiu muito pouco, mas o número de arestas caiu relativamente muito, quase 10%. Isso teve um impacto direto no grau médio e na densidade, que diminuíram bastante. Disso, temos efidências de que são as palavras pequenas que possuem os maiores graus.

Vamos agora retirar as palavras de quatro letras e comparar:

### $k=4$

**Número de vértices:** 8941
**Número de arestas:** 8300 
**Número de componentes:** 3845 
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 3041 
**Tamanho médio das componentes:** 3.32536
**Grau médio:** 1.85662
**Densidade:** 0.928308

**Observações sobre os dados:** vemos que as mudanças foram muito maiores, o número de vértices caiu bastante e o número de arestas caiu ainda mais, assim como o tamanho daquela grande componente. Vemos também que as palavras com quatro letras também figuram entre as que possuem vários vizinhos.

### $k=5$

**Número de vértices:** 8253
**Número de arestas:** 5900 
**Número de componentes:** 3921 
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 2010 
**Tamanho médio das componentes:** 3.10482
**Grau médio:** 1.42978
**Densidade:** 0.714892

**Observações sobre os dados:**  Vemos que agora sim aquela grande componente foi teve vários de seus vértices removidos e o número de arestas caiu massivamente.

### $k=6$

**Número de vértices:** 6808
**Número de arestas:** 3404
**Número de componentes:** 3901 
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 84 
**Tamanho médio das componentes:** 2.74519
**Grau médio:** 1
**Densidade:** 0.5

**Observações sobre os dados:** Vemos agora que aquela componente grande foi completamente desimada, assim como o número de arestas do grafo. Vemos que o grafo está se tornando extremamente esparso, mostrando que de fato são as palavras pequenas que possuem grande conectividade. Algo curioso é que o número de componentes, entretanto, diminuiu, mas isso é por causa do número de vértices que também diminuiu.

Vamos, por fim, verificar para $k=7$

### $k=7$

**Número de vértices:** 5204
**Número de arestas:** 2078
**Número de componentes:** 3366 
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 21
**Tamanho médio das componentes:** 2.54605
**Grau médio:** 0.798616
**Densidade:** 0.399308

**Observações sobre os dados:** Vemos que agora as palavras restantes mal se conectam, pois a maior componente tem apenas 21 vértices. Chegamos ao ponto que apenas praticamente aquelas palavras estranhas mencionadas no começo passaram a restar.

Para k maiores que isso, não vale muito a pena colocar no relatório.

### Página do Depto de Computação do IME

O arquivo `dcc.txt` possui uma concatenação de todas as palavras que aparecem no site: `ime.usp.br/dcc` e nos subdiretórios que podemos encontrar no acesso à direita. Ou seja:

* Sobre o DCC
* Histórico
* Prêmios
* Docentes visitantes
* Ensino
* Graduação
* Pós-Graduação
* Vestibulando
* Pesquisa
* Publicações
* Núcleos de Apoio à Pesquisa
* Extensão
* Empresas de alunos e ex-alunos
* CCSL
* Mídia e Eventos
* DCC na mídia
* Notícias
* Eventos
* Organização
* Docentes
* Docentes por Área de Pesquisa
* Administração
* Conselho do Departamento
* Ramais

### $k=0$

**Número de vértices:** 4005 
**Número de arestas:** 3128
**Número de componentes:** 2547 
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 598
**Tamanho médio das componentes:** 2.57244
**Grau médio:** 1.56205
**Densidade:** 0.781024

**Observações sobre os dados:** Vemos novamente que o grafo é bastante esparso, com vários vértices completamente isolados e com uma componente principal com vários dele. Nesse grafo temos ainda mais daqueles casos isolados pois a página do DCC tem muitos sites, muitos nomes em inglês e por ai vai. Vemos também que o grau médio é bem menor do que no grafo anterior.

Vamos analisar agora o que acontece com $k=3$ até $k=5$.

### $k=3$

**Número de vértices:** 3866
**Número de arestas:** 1665 
**Número de componentes:** 2560
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 432
**Tamanho médio das componentes:** 2.51016
**Grau médio:** 0.861355
**Densidade:** 0.430678

**Observações sobre os dados:** Notamos que a densidade e o grau médio já caíram muito assim como o tamanho daquela grande componente. 

### $k=4$

**Número de vértices:** 3692
**Número de arestas:** 1359
**Número de componentes:** 2564
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 110
**Tamanho médio das componentes:** 2.43994
**Grau médio:** 0.736186
**Densidade:** 0.368093

**Observações sobre os dados:** Vemos que a grande componente já está bem pequena e que a enorme maioria do grafo já são vértices isolados. A densidade já é quase aquela que obtemos com $k=7$ para a obra de Camões. Por isso, façamos apenas mais um teste para $k=5$.

### $k=5$

**Número de vértices:** 3379
**Número de arestas:** 1041
**Número de componentes:** 2493
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 43
**Tamanho médio das componentes:** 2.3554
**Grau médio:** 0.616159
**Densidade:** 0.308079

**Observações sobre os dados:** agora tivemos uma queda menor no número de vértices, mas o número de arestas continuou a cair, assim como o tamanho da maior componente.

## Manual do Ubuntu

Agora vamos analisar um texto em inglês, o manual do Ubuntu. As palavras em inglês possuem menos variantes igual no português, que possui gênero e número com uma mudança de apenas uma letra.

Comecemos com $k=0$:

### $k=0$

**Número de vértices:** 4427
**Número de arestas:** 3430
**Número de componentes:** 2743
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 793 
**Tamanho médio das componentes:** 2.61393
**Grau médio:** 1.54958
**Densidade:** 0.774791

**Observações sobre os dados:** A primeira observação cabível não aparece nos dados em si, mas tem a ver com o tempo para criarmos o grafo. Enquanto os Lusiadas levaram cerca de 17 segundos para carregar 55447 palavras e gerar um grafo com 9303 vértices, o manual do Ubuntu levou aproximadamente apenas 5 segundos para carregar 50816 e gerar um graf com apenas 4427.

Ou seja, vemos que no manual do Ubuntu temos muito mais palavras repetidas ou strings que acabam se tornando nulas por removemos todos os caracteres daquela string (como `1.`, `16.04` etc.).

Por fim, falando do grafo em si, temos um resultado bastante interessante: o número de arestas já é menor que o número de vértices, assim como no grafo anterior. Além disso, um resultado interessante é que temos um total e 2743 componentes de 4427 vértices. Ou seja, um grafo esparcíssimo. E, além disso, o tamanho da maior componente é 793. Somando esses vértices, temos `2743 + 793 = 3536`, logo temos cerca de `4427-3536 = 891` vértices apenas que não estão nem na grande componente conexa e nem isolados.

Com certeza isso é muito interessante. 

Vamos passar agora para outros $k$.

### $k=3$

**Número de vértices:** 4293
**Número de arestas:** 2114
**Número de componentes:** 2763
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 587 
**Tamanho médio das componentes:** 2.55375
**Grau médio:** 0.984859
**Densidade:** 0.49243

**Observações sobre os dados:** Vemos que pouquíssimos vértices foram removidos, mas mais de um terço das arestas foram removidas. Ou seja, vemos que, assim como no português, o inglês também possui uma conectividade entre as palavras pequenas. Isso também se mostra verdadeiro pois foram 134 vértices removidos e 206 vértices a menos na grande componente. Ou seja, _muitas_ das grandes palavras atuavam como vértices de corte nesse grafo.

### $k=4$

**Número de vértices:** 4082
**Número de arestas:** 1706
**Número de componentes:** 2776
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 339 
**Tamanho médio das componentes:** 2.47046
**Grau médio:** 0.835865
**Densidade:** 0.417932

**Observações sobre os dados:** Vemos novamente que não muitos vértices foram removidos, mas muitas arestas acabaram removidas, assim como o número de vértices na grande componente. Vemos já que o grafo está ainda mais esparso, com a densidade abaixo de meio.

### $k=5$

**Número de vértices:** 3641
**Número de arestas:** 1136
**Número de componentes:** 2727
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 23 
**Tamanho médio das componentes:** 2.33517
**Grau médio:** 0.624004
**Densidade:** 0.312002

**Observações sobre os dados:** Agora tivemos um pouco mais de vértices sendo removidos, mas o número de arestas caiu ainda mais, assim como a grande componente já está em apenas 23 vértices, confirmando que de fato são as palavras com até 5 letras são as mais conexas. 

Vamos agora pular para $k=8$ para vermos se o número de vértices começa a cair um pouco mais.

### $k=8$

**Número de vértices:** 1934
**Número de arestas:** 319
**Número de componentes:** 1648
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 7 
**Tamanho médio das componentes:** 2.17354
**Grau médio:** 0.329886
**Densidade:** 0.164943

**Observações sobre os dados:** Vemos que o número de vértices caiu ainda muito pouco (dado que $k$ cresceu bastante), mas o número de aréstas já está baixíssimo, podemos ver dado a densidade. 

Aumentemos ainda mais o $k$.

### $k=12$

**Número de vértices:** 930
**Número de arestas:** 110
**Número de componentes:** 830
**Tamanho da menor componente:** 2
**Tamanho da maior componente:** 7 
**Tamanho médio das componentes:** 2.12048
**Grau médio:** 0.236559
**Densidade:** 0.11828

**Observações sobre os dados:** Vemos agora sim que vários vértices foram removidos e poucas das arestas comparativas foram removidas (a densidade não caiu tanto). Além disso, é muito interessante esse valor de $k$ pois ele é já muito grande e vemos que ainda assim quase um quarto dos vértices do grafo original se mantêm mesmo após removermos todas as palavras com até 12 letras. 

Dessa forma, vemos, como imaginado, por se tratar de um manual de um sistema operacional, que existem muitas palavras muito grandes como sites, que não vão se conectar com qualquer outra palavra.

## Autor

Lucas Paiolla Forastiere - 11221911