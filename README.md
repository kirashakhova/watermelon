**Watermelon Scene — Qt Project**

Программа создана на базе фреймворка Qt и включает графическую сцену для интерактивного добавления и управления объектами.  

**Описание**  
На сцене можно размещать два типа объектов:  
- Кнопка "Выход"  
- Программно нарисованный арбуз  

**Поведение объектов:**  
- Их можно перемещать, перетаскивая левой кнопкой мыши.  
- При нажатии правой кнопкой на арбуз он исчезает, а на сцене появляются 8 случайных долек.  
- Дольки также удаляются при нажатии правой кнопкой.  

Все объекты учитываются в общем счётчике на сцене.  

**Завершение работы:**  
Если на сцене окажется ровно 256 объектов, программа закроется.  
При другом количестве объектов появится предупреждение:  
"Отсюда не сбежать!"  

**Технологии:**  
- Язык: C++  
- Фреймворк: Qt 5/6  
- Инструменты: QGraphicsScene, QGraphicsItem, QPushButton, QGraphicsView, QMessageBox и другие.  

**Возможности:**  
- Добавление и удаление объектов с возможностью реакции на события.  
- Гибкая работа с графической сценой.  
- Поддержка интерактивного управления (drag & drop).  
- Пользовательский счётчик объектов.  

**Сборка:**  
Проект собирается с помощью Qt Creator:  
- Откройте .pro-файл или CMakeLists.txt.  
- Выберите подходящий kit (Qt 5/6 + компилятор).  
- Нажмите Build → Run.
