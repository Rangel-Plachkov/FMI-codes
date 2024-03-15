#pragma once

#include"book/book.h"
#include"book/book.cpp"

class library{
    private:
        book* books;
        
        size_t numberOfBooks;
        size_t sizeOfLibrary;

        //! констранта която задава стартовият размер на библиотека
        static const size_t DEFAULT_STARTING_LIB_SIZE = 16;
        //! Максимален размер на input
        static const size_t MAX_INPUT_SIZE = 100;


        //! Освобождава динамичанта памет
        void free();
        //! Угвоява размера на library
        void resize();
        //! Помощна фукнция използвана от оператор = и copy constructor
        void copyFrom(const library& other);
        //! Фукнция с избор от user дали да изтие фаил на книга при премахването на книгата от листа
        void removeFileDecision(const unsigned int index);

//        const int validInputConverter(const char* input , const unsigned int numberOfCommands)const;

        //! Разеня индекса на две книги
        void swapIndex(const size_t A,const size_t B);
        //! Алгоритъм който сортира книгите по rankig. Приема bool който определядали да е от най-малкиято д0 най-големият или обратното
        void rankingSort(const bool highestToLowest);
        //! Соритра книгите по азбучен ред спрямо Title ,като взима параметър определящ дали да е от A -> Z или Z -> A
        void titleSort(const bool AtoZ);
        //! Соритра книгите по азбучен ред спрямо Author ,като взима параметър определящ дали да е от A -> Z или Z -> A
        void authorSort(const bool AtoZ);
        //! Помощна функция която определя дали дадена дума е преди друга спрямо азбучният ред
        const bool isLowerWord(const char* a, const char* b)const;
        
        
        //! Функцияе която едиствено принтира командите за user(не админ) в главното меню
        void printComandsForUser()const;
        //! Функцияе която едиствено принтира командите за админ в главното меню
        void printComandsForAdmin()const;
        //! Функцияе която едиствено принтира командите за админ в в менюто на специфична книга
        void printBookProfileAdmin(const unsigned int index)const;
        //! Функцияе която едиствено принтира командите за user(не админ) на специфична книга
        void printBookProfileUser(const unsigned int index)const;
        //! Функцияе която едиствено принтира командите опции за четене на книга
        void printReadingOptions()const;
        //! Функцияе която едиствено принтира командите опции за извъждане на списък от книга
        void printListMenu()const;

        //! Проверява дали input > numberOfComanda ако да връща -1 ,ако не връща input
        const int validInputConverter(const int input , const unsigned int numberOfCommands)const;
        //! Взима cin input като го конвентира в integer след това. Ако има символи които не са цифри връща -1
        const int getInput()const;
        //! Взима cin input и го връша (Указател към string)
        const char* getInputString()const;

        //! Менюто за извеждане на книги по списък. Взима членданна user да определи дали е админ или не.
        void listMenu(const user& person);
        //! Менюто за книга . Взима членданна user да определи дали е админ или не.
        void selectBookIndex(const user& person);
        //! Менюто идентично на selectBookIndex() но използвано от SearchMenu() . Взима членданна user да определи дали е админ или не.
        void selectSearchedBookIndex(const user& person, const size_t input);
        //! Менюто за методи на четене на книга . Взима членданна user да определи дали е админ или не въпреки че не се използва никъде.
        void readingMenu(const user& person ,const size_t boolIndex);
        //! Менюто за добавяне на книга . Може да се достигне само от admin
        void addBookMenu(const user& person);
        //! Менюто за търсене на книга по input. Ако има пълно съвпадение на title,author,isbn или частично на destription извежда поджодящите книги в лист. Взима членданна user да определи дали е админ или не.
        void searchMenu(const user& person);

        //! извежда книга на позиция index
        void readBook(const unsigned int index)const;
         //! извежда книга на позиция index като всяко изречение е на нова страница
        void readBookBySentences(const unsigned int index)const;
         //! извежда книга на позиция index. Всеки symbolsInPage на брой символа извежда на нова страница
        void readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const;
         //! извежда книга на позиция index. На всеки linesInPage реда извежда нова страница
        void readBookByPage(const unsigned int index , const unsigned int linesInPage)const;

    public:
        //! default constructor  дава стойнсоти nullptr.
        library();
        library(const library& other);
        //! Деструктор извиква free() 
        ~library();
        library& operator=(const library& other);

        //! Всръща броят на книгите в библиотека
        const size_t getNumberOfBooks()const;
         //! Връща размерът на библиотеката
        const size_t getSizeOfLibrary()const; 
         //! връща указател към масива с книги
        const book* getBookArr()const;

         //! Добавя нова кника към листа с книги. Ако библиотеката има прекалено малък размер извиква resize()
        void addBook(const book& newBook);
         //! Премахва книга от листа. Пита потребителя дали иска и да изтрие фаила на книгата
        void removeBook(const unsigned int index);
         //! Вкарва книга от фаилс с информация за нея
        void importBook(const char* bookLocation);
        
        //! Принтира книгите подредени по индекса им в books[index]
        void listBooks()const;

        //! Главното меню с Interface. Изисква параметър user да се знае дали е admin или не
        void menu(const user& person);
        

};