## Clase 05

### Objetivos

* Discutir los problemas del contest de la anterior clase
* Ver más ejemplos de fuerza bruta

### Solucionario del contest

### [G - Easy Tape Programming](https://codeforces.com/contest/239/problem/B)

#### Resumen del enunciado

Dado

$$s_1s_2 \cdots s_n \quad \mid s_i \in \{<, >, 1, 2, \cdots, 9\}$$

Recibirás `q` consultas de la forma `l r`. En cada consulta debes simular la
ejecución de 

$$ s_l \cdots s_r $$

e imprimir la cantidad de veces que se imprimio cada dígito (`0-9`)

Para simular la ejecución de la secuencia $s_l \cdots s_r$ usted comienza en la
posicion `l` en la direccion derecha. Ahora:

* Si la sentencia actual es un dígito. Imprímelo y muevete en tu dirección
  actual. Luego, reduce el número de la anterior sentencia en 1. Si este se
vuelve negativo, eliminalo de la secuencia.
* Si la sentencia actual es `<` o `>` cambia la dirección hacia la izquida
  o derecha respectivamente. Luego, muevete en tu dirección actual. Si la
sentencia en tu posición actual es `<` o `>`, elimina la sentencia de tu
anterior posición.

* Si tu posición actual no esta en `[l, r]`. Termina la simulación.

#### Límites

 $$1 \leq n, q \leq 100 $$

#### Solución

En el peor de los casos (una consulta de al forma `>99...99<`) la simulación
se hara en `O(n)`

Luego, bastará simular la ejecución de cada consulta siguiendo la descripción
del enunciado para obtener una solución en `O(q n)`

**Nota:** Tener cuidado, las consultas son independientes entre sí.

[Implementación](https://codeforces.com/contest/239/submission/48684436)

### [H - Restoring Increasing Sequence](https://codeforces.com/contest/490/problem/E)

#### Resumen del enunciado

Se tiene una secuencia $a_1, a_2, \cdots a_n$ donde algunos dígitos han sido
reemplazados por `?`. Ahora, deberás reemplazar los `?` por dígitos de tal
forma que 

$$a_1 < a_2 < \cdots < a_n$$

e imprimir dicha secuencia (si hay multiples respuestas, imprime alguna válida)
o indicar que es imposible formar tal secuencia. Tener en cuenta que los
números formados no pueden tener `0` como primer dígito.

#### Límites

$$n < 10 ^ 5$$
$$1 < a_i < 10 ^ 8$$

#### Solución

Si ya tengo formado el número $a_i$. Para formar $a_{i + 1}$ puedo intentar
formar un número mayor que $a_i$ lo menor posible.

Si $a_{i + 1} > a_i$ y ambos tienen la misma cantidad de dígitos. Entonces
ambos tendrán la forma:
$$a_i = \overline{xmy}$$
$$a_{i + 1} = \overline{xnz}$$

Y $n > m$ y $z$ puede tomar cualquier forma.

Luego, para hacer $a_{i + 1}$ lo más pequeño posible, nos conviene hacer $n = m + 1$ y hacer que `z` sea tan pequeño como sea
posible (para lo cual nos conviene completar con `0`s los `?` en `z`). 

Así, simplemente cada `?` en $a_{i + 1}$ puedo tomarlo como la posición de `n`
e intentar formar $a_{i + 1}$ y al final tomar el menor $a_{i + 1}$ formado (Si
no logro formar ningun $a_{i + 1}$ entonces no hay respuesta). Como $a_i$ tiene
a lo mucho `8` digitos. Entonces, en `O(8 * 8) = O(1)` podemos formar todas las
posibilidades de $a_{i + 1}$.

Finalmente, puedo agrupar los números dados por su cantidad de dígitos. Ir completando
los `?` con lo anterior descrito. Juntar todas las secuencia y comprobar si se
forma una respuesta válida en `O(n)`.

[Implementación](https://codeforces.com/contest/490/submission/48590505)

### [I - Divisors](https://codeforces.com/contest/448/problem/E)

#### Resumen del enunciado

Sea:

$$D(x) = \{ \text{Los divisores de x ordenados de menor a mayor} \} $$

$$f_0(x) = \{x\}$$
$$f_k(x) = \bigcup_{d \in D(X)} f_{k -1}(d)$$

Recibirás un `x, d` y deberás imprimir los primos $10 ^ 5$ términos de $f_k(x)$

#### Límites

$$1 \leq X \leq 10 ^ {12}$$
$$0 \leq k \leq 10 ^ {18}$$

#### Solución

Notemos que:
$$f_k(p) = \{1\} \times k \quad  \bigcup \quad \{p\} \quad \mid p \text{ es primo }$$
$$f_k(1) = \{1\}$$

Luego, notemos que bastará simular la recurrencia anterior mientras mantenemos
un contador de cuantos números ya hemos imprimido (lo cual nos indicará cuando 
detenernos)

Ahora, necesitamos tener un vector con los divisores que necesitaremos de
manera rápida. Para ello podemos fijar una constante, por ejemplo 

$$ \text{MX}= 10 ^ 5 $$

Preprocesar todos los divisores de los números $< \text{MX}$ en `O(MX log MX)`
y aquellos $x \geq \text{MX}$ en $\text{O(}\sqrt{x} \text{)}$ (Se explicará esto en clase).

Consiguiendo así una solución en $\text{O(} \sqrt{x} + \text{MX} \log \text{MX}  \text{)}$

[Implementación](https://codeforces.com/contest/448/submission/48651120)
