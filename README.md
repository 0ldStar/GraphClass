# Задание 1

Спроектировать и реализовать шаблонный класс для коллекции «Простой граф» и
использовать коллекцию для решения задач для неориентированных, ориентированных и
взвешенных графов.

## Разработать АТД «Простой граф».

### Интерфейс АТД «Простой граф» включает операции:

- Конструктор ( ) по умолчанию: создает пустой L - граф с нулевым числом вершин и
  ребер
- Конструктор (V, D, F) создает граф с V вершинами, без ребер, типа D (ориентированный / неориентированный), формы
  представления F (L- граф/M-граф)
- Конструктор (V, E, D, F) создает граф с V вершинами, с E случайными ребрами, типа
  D (ориентированный / неориентированный), формы представления F (L- граф/M-граф)
- Конструктор (G) - конструктор копирования создает объект – копию графа G
- Деструктор ( ) уничтожает внутренние структуры графа
- V ( ) - возвращает число вершин в графе,
- E ( ) - возвращает число ребер в графе,
- Directed ( ) - возвращает тип графа (ориентированный / неориентированный)
- Dense ( ) - возвращает форму представления графа (L- граф / M- граф),
- K ( ) - возвращает коэффициент насыщенности графа,
- ToListGraph ( ) преобразует граф к L- графу,
- ToMatrixGraph ( ) преобразует граф к M- графу,
- InsertV ( ) добавляет вершину к графу и возвращает адрес дескриптора вновь созданной вершины,
- DeleteV (v) - удаляет вершину из графа, заданную адресом дескриптора v,
- InsertE(v1, v2) - добавляет ребро (v1, v2) к графу, соединяющую вершины, заданные
  адресами дескрипторов v1 и v2, и возвращает адрес дескриптора вновь созданного ребра - e,
- DeleteE (v1, v2) удаляет ребро, соединяющее вершины, заданные адресами дескрипторов v1 и v2,
- GetEdge (v1, v2) возвращает адрес дескриптора ребра соединяющего вершины, заданные дескрипторами v1 и v2,

## Разработать ассоциированные с графом типы:

### АТД «Дескриптор вершины графа»

#### Дескриптор вершины содержит поля:

- name – имя вершины,
- data – данные, связанные с вершиной,
- index – индекс вершины в структуре графа или -1,

#### Интерфейс АТД «Дескриптор вершины графа» включает операции:

- Конструктор ():поле name не определено, поле data не определено,
- Конструктор (name, data): name - имя вершины, data - данные, связанные с вершиной,
- GetName ( ) - возвращает имя вершины,
- GetData ( ) - возвращает данные, связанные с вершиной,
- SetName (name ) – задает имя вершины,
- SetData (data) – записывает данные data в дескриптор вершины.

### АТД «Дескриптор ребра графа»

Дескриптор ребра содержит поля:

- v1 - дескриптор вершины, из которой исходит ребро,
- v2 - дескриптор вершины, в которую входит ребро,
- w - вес ребра,
- data - данные, связанные с ребром,

#### Интерфейс АТД «Дескриптор ребра графа» включает операции:

- Конструктор (v1, v2): v1 - дескриптор вершины, из которой исходит ребро, v2 - дескриптор вершины, в которую входит
  ребро,
- Конструктор (v1, v2, w): v1 - дескриптор вершины, из которой исходит ребро, v2 - дескриптор вершины, в которую входит
  ребро, w - вес ребра,
- Конструктор (v1, v2, w, data): v1 - дескриптор вершины, из которой исходит ребро, v2 - дескриптор вершины, в которую
  входит ребро, w - вес ребра, data - данные, связанные с ребром
- v1( ) - возвращает дескриптор вершины, из которой исходит ребро,
- v2( ) - возвращает дескриптор вершины, в которую входит ребро,
- GetW ( ) - возвращает вес ребра,
- SetW (w) - изменение веса ребра,
- GetData ( ) - возвращает данные, связанные с ребром,
- SetData (data) - изменение данных, связанных с ребром.

### АТД «Итератор вершин графа»

#### Интерфейс АТД «Итератор вершин графа» включает операции:

- Конструктор ( ) - создает итератор вершин графа,
- beg ( ) - возвращает итератор, установленный на первую вершину графа,
- end ( ) - возвращает итератор, соответствующий окончанию переходов итератора,
- operator ++ - переход к следующей вершине графа,
- operator * - возвращает дескриптор вершины графа, на которую указывает итератор.

### АТД «Итератор ребер графа»

#### Интерфейс АТД «Итератор ребер графа» включает операции:

- Конструктор ( ) - создает итератор ребер графа,
- beg ( ) - возвращает итератор, установленный на первое ребро графа,
- end ( ) - возвращает итератор, соответствующий окончанию переходов итератора,
- operator ++ - переход к следующему ребру графа,
- operator * - возвращает дескриптор ребра графа, на которое указывает итератор.

### АТД «Итератор исходящих ребер вершины»

#### Интерфейс АТД «Итератор исходящих ребер вершины» включает операции:

- Конструктор (v) - создает итератор исходящих ребер графа для вершины, заданной дескриптором v,
- beg ( ) - возвращает итератор, установленный на первое исходящее ребро вершины,
- end ( ) - возвращает итератор, соответствующий окончанию переходов итератора,
- operator ++ - переход к следующему исходящему ребру,
- operator * - возвращает дескриптор исходящего ребра вершины, на которое указывает итератор.

# Задание 2

Спроектировать и реализовать шаблонный класс для АТД «Задача для невзвешенного
графа» в соответствии с вариантом и использовать для решения задачи на
неориентированном или ориентированном графе. Для программирования графа
использовать разработанный в задании 1

#### Интерфейс АТД «Задача для невзвешенного графа» включает операции:

- Конструктор (g) - создает объект задачи 1, ассоциированный с графом g, и выполняет
  решение задачи для графа g,
- Конструктор (DATA) - конструктор копирования создает копию объекта – задачи DATA,
- Деструктор ( ) - уничтожает внутренние структуры объекта задачи,
- Set (g) – связывает объект задачи с графом g и выполняет решение задачи 1 для графа g,
- Restart ( ) – повторно выполняет решение задачи 1 для графа g,
- Result ( ) – возвращает результат решения задачи 1
- формирования двудольного неориентированного графа с раскраской в два цвета

# Задание 3

Спроектировать и реализовать шаблонный класс для АТД « Задача для взвешенного
графа»» в соответствии с вариантом и использовать для решения задачи на взвешенном
графе. Для программирования графа использовать разработанный в задании 1

#### Интерфейс АТД «Задача для взвешенного графа»» включает операции:

- Конструктор (g) - создает объект задачи 3, ассоциированный с графом g, и выполняет
  решение задачи для графа g,
- Конструктор (DATA) - конструктор копирования создает копию объекта – задачи DATA,
- Деструктор ( ) - уничтожает внутренние структуры объекта задачи,
- Set (g) – связывает объект задачи с графом g и выполняет решение задачи 3 для графа g,
- Restart ( ) – повторно выполняет решение задачи 3 для графа g,
- Result( ) – возвращает результат решения задачи 3
- определение диаметра и пути, соответствующего диаметру, на основе алгоритма Флойда