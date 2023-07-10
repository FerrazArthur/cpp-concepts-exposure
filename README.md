# C++ RoadMap

Esse repositório contém códigos com exemplos e slides, criados para compreensão e apresentação dos conceitos fundamentos e ferramental disponibilizado pelo c++, apresentados pela [road map c++](https://roadmap.sh/).

## Objetivos ilustrados

O repositório acompanha [slides](Apresentacao.odp) utilizados para apresentação, onde as funções abaixo são referenciadas no decorrer do roadmap.

### Funções lambda e Prototipagem

[Uso de prototipagem e funções lambda vs funções tradicionais](lambda.cpp)

[Uso de funções lambda com retorno e parâmetros: ponteiro vs referência](pointerRef.cpp)

[Uso de referência para melhorar a legibilidade dos códigos](swapref.cpp)

### Tipagem de dados

#### Verificações em tempo de execução -> performance reduzida

[Uso de alocação dinamica com ponteiro void e typecast: c vs c++](dinamtype.cpp)

[Uso de alocação dinamica com ponteiro any e tratamento de exceção](dinamc%2B%2B17.cpp)

[Uso de RTTI pra prevenir downcasting de ponteiros e slicing](rtii.cpp)

#### Verificações em tempo de compilação -> 'verbosidade' reduzida

[Uso da palavra chave auto para reduzir complexidade de loops](autoverb.cpp)

### Ponteiros Inteligêntes

[Uso de ponteiro tipo unique](uniqptr.cpp)

[Uso do ponteiro tipo shared](sharedptr.cpp)

[Uso do ponteiro tipo weak](weakptr.cpp)

[Uso de valores apontados por ponteiro weak](weakptruse.cpp)

### Boas práticas

[Implementação da regra do cinco](ruleof5.cpp)

[Uso de classes bases com construtor copia/movimentação implícitos implica em slicing](slicing.cpp)

[Como impedir slicing em polimorfismo](slicingPrevent.cpp)
