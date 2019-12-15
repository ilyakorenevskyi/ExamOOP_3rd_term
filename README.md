# ExamOOP_3rd_term
Кореневський Ілля К-28
Варіант 22
Використовуючи засоби ООП, описати користувачів програм та технічні проблеми, що у них
виникають. Для користувачів відоме ім’я, список програм, які використовує цей користувач та
середній час використання кожної з цих програм, історія попередніх проблем (час виникнення та
час виправлення). Для проблем відомий тип проблеми, список програм, в яких може виникнути
ця проблема, середній час виправлення проблеми. Кожна проблема може виникнути випадковим
чином під час використання відповідної програми, але шанси виникнення проблем також
залежать від типу користувача:
* Для деяких фіксована ймовірність виникнення для кожної проблеми;
* Для деяких ймовірність виникнення залежить від попередніх проблем цього ж типу у цього
користувача ;
* Для деяких ймовірність залежить від загального часу використання цієї програми.

Користувач випадковим чином вибирає одну з програм зі свого списку, намагається
використовувати її протягом випадкового часу з діапазону навколо середнього часу використання,
після завершення роботи вибирає наступну програму. Якщо виникають якісь проблеми –
користувач витрачає відповідний час на їх вирішення, і потім продовжує роботу з програмою до
виникнення нових проблем чи до завершення часу використання. (Таким чином, загальний час
роботи з програмою складається з часу використання та часу виправлення всіх проблем, які
виникли за час роботи. Час виправлення проблем не включається до часу використання – якщо
користувач планував працювати 10 годин, і витратив 7 годин на виправлення різних проблем, то
загальний час роботи буде 17 годин).
Реалізувати алгоритм, що для заданого списку користувачів та заданого періоду часу обчислює
список всіх проблем, що виникли у цих користувачів за цей період, та сумарний час, витрачений на
їх виправлення.
В інтерфейсі користувача реалізувати перегляд дерева всіх користувачів та програм, можливість
вибрати користувача чи програму і подивитись деталі (список програм, список дефектів).
Можливість вибрати користувачів, задати інтервал часу і подивитись список проблем та сумарний
час.
