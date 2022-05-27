<h1>Minhas anotações sobre:</h1>
<h2>Implementações de tabla hash.</h2>
Esse arquivo tem finalidade de anotações sobre implemtações<br>
<br>

<h2>Conceito</h2>
<p>tabelas hash tem como finalidade fornecer uma estrutura que tenha complexidade <i>O(1)</i> já que nas outras estruturas
nos melhores dos casos temos uma complexidade de <i>O(n)</i> em operações de busca, e tendo em base um vetor(<i>array</i>)
 caso nós soubermos em que posição do vetor está o dado que queremos temos uma estrutura de dados com complexidade <i>O(1)</i>
</p>
<p>A idéia é bem simples, dado um valor (<i>key</i>) nós aplicamos alguma função matematica que nos retorne um valor, 
tal que esse valor irá ser nossa posição do vetor como por exemplo:<br>

-> Dado um vetor com 100 posições ( vetor[100] ) e nos é fornecido o valor 15, assim aplicamos o que chamamos de função de 
hash que nos retorna um valor de 0 a 100 (valor que vai ser a posição em vetor[] no qual iremos armazenar o valor) em 
forma matematica temos:</p>
```
f(x) = x * 2 

assim, aplicando o valor 15:

f(15)= 15 *2 = 30
```
<p>agora sempre que quisermos verificar se temos o valor 15 na nossa lista de hash para realizarmos a busca e simples, basta:

- Aplicar a formula de hash e termos o local no vetor que o valor está
- verificar se o valor está na posição, se sim, temos na tabela, se não o valor não está</p>


***Na sua teoria a tabela hash possui sim, a propriedade de: para cada valor inserido ter um valor unico para o tal, contudo
pode haver colisões(2 valores diferentes que na função de hash retornam o mesmo valor) e por isso nao temos que um valor
terá sua posição como absoluta, assim com algoritmos podemos realocar esse valor para posições vazias***