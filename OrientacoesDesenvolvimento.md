# Projeto 1

- ENGENHARIA DE COMPUTAÇÃO (2021) - PUCPR
- Programação com Estruturas de Dados Avançadas (PEDA)
  - Prof: LUIZ AUGUSTO DE PAULA LIMA JUNIOR

- LABIRINTO USANDO PILHA
  - Aluno: Erick Lemmy dos Santos Oliveira


# Orientação
<p> 
A estrutura de dados PILHA pode ser usada para implementar isso.          
A ideia é partir de um ponto <code> E ("entrada") </code> e escolher arbitrariamente uma das suas conexões para a   
busca do ponto <code> S ("saída") </code>, armazenando o novo ponto a que se chegou na pilha.   
Assim, prossegue-se até que não seja mais possível partir para um novo caminho ou até que o ponto S   
seja atingido. No primeiro caso, deve-se retornar a um ponto anterior a partir do qual novos caminhos   
podem ser possíveis. Isto é feito retirando-se o último elemento da pilha.   
Este procedimento é repetido até voltar a um ponto a partir do qual caminhos não explorados podem ser   
tentados ou até voltar ao início (ponto E).     
Nesse caso, se não hover mais outras opções de caminho saindo de E, é porque S não existe.  
</p>

# Dica
<p>
calcule e mostre na tela o caminho de "E" a "S" <code>(marcando o caminho com asteriscos) </code>
O caractere "X" na matriz labirinto corresponde a uma "parede".            
Assim, se <code> labirinto[x][y] == 'X' (0≤x<20 e 0≤y<21) </code>, então esta posição não deve ser percorrida. 
</p>

# Exemplo de Entrada Orientado
~~~cpp
vector<string> labirinto = {
     "XXXXXXXXXXXXXXXXXXXXX",
     "X     X     X     X X",
     "XX XX XXXXX X X X   X",
     "X   X       XXX XXX X",
     "X X X XXXXXXX   X   X",
     "X X   X   X X X   X X",
     "X XXXXX X X   XXXXX X",
     "X X     X XXX  X    X",
     "X X X X X   XX XX XXX",
     "X X XXX X X     X   X",
     "E X X X X XXXXX XXX X",
     "X     X X   X X X   X",
     "X XXXXX XXX X XXX X X",
     "X X       X X   X X X",
     "X   XXX X X XXX X X X",
     "XXX X X X X X X X XXX",
     "X X   X X   X   X   X",
     "X XXX XXXXXXXXX XXX X",
     "X                 X X",
     "XXXXXXXXXXXXXXXXXXXSX"
}
