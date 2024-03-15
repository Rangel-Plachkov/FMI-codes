#pragma once

class book{
    private:
        char* title;
        char* author;
        char* location;
        char* description;
        double rating;
        char* isbn;
        static const unsigned int LINES_BETWEEN_PAGES = 3;
        static const unsigned int MAX_SYMBOLS_IN_LINE = 1024;
        static const size_t MAX_SYMBOLS_IN_PARAM = 100;

        //! Освобождава динамичната памет от класа
        void free();

        //! Функция взимаща за параметър doble  и връща double ,който е валидно число за рейтинг (Ако е над 5 -> 5  , ако е под 0 -> 0) Всички останали се връща подаденото число 
        const double  validRatingConverter(const double rate)const;
        //! Проверява дали ISBN  е валиден. Връща false ако има символи които не са цифри или има дължина над 13
        const bool validIsbn(const char* checkIsbn)const;
        //! Функция взимаща за параметър фаилов поток и връща размера му запазваща позицията на get() указателя
        const size_t getFileSize(std::ifstream& iFile)const;
        //! Помощна функция която принтира константен брой редове мехду страници
        void newPageSpacer()const;
        //! Проверява дали даденият символ е символ с който се завършва изречение ( . , ! , ?)
        const bool isEndSymbol(const char symbol)const;
        
        //!Помощна функция за оператор = и copy constructor. Не освобождава динамична памет.
        void copyFrom(const book& other);
        //void removeFile();
    public:

        book& operator=(const book& other);


        book(const book& other);
        
        book(const char* newTitle , const char* newAuthor, const char* newLocation , const char* newDescription, double newRating, const char* newIsbn);
        //! default constroctor  дава стойност на всички член данни nullptr
        book();
        //! destructor извиква free()
        ~book();

        //! Задава нова стойност на title  няма ограничения
        void setTitle(const char* newTitle);
        //! Задава нова стойност на author  няма ограничения
        void setAuthor(const char* newAuthor);
        //! Задава нова стойност на location  няма ограничения
        void setLocation(const char* newLocation);
        //! Задава нова стойност на description  няма ограничения
        void setDescription(const char* newDescription);
        //! Задава нова стойност на rating  преминава през validRatingConventor()
        void setRating(const double newRating);
        //! Задава нова стойност на ISBN  преминава през validIsbn() ако е false задава стойност на члед данната nulltpr
        void setIsbn(const char* newIsbn);
        //! Връща указател към title
        const char* getTitle()const;
        //! Връща указател към author
        const char* getAuthor()const;
        //! Връща указател към location
        const char* getLocation()const;
        //! Връща указател към description
        const char* getDescription()const;
        //! Връща double към rating
        const double getRating()const;
        //! Връща указател към ISBN
        const char* getIsbn()const;

        //! Ако съществува фаил на location го изтрива
        void removeFile();

        //! Принтира съдържанието на книга
        void printBook()const;
        //! Принтира съдържанието на книга като на всеки linesInPage реда поставя newPageSpacer()
        void printByPage(const unsigned int linesInPage)const;
        //! Принтира съдържанието на книга като на всеки symbolsInPage символа поставя newPageSpacer()
        void printByNcharacters(const unsigned int symbolsInPage)const;
        //! Принтира съдържанието на книга като на всяко ивречение поставя newPageSpacer(). Ако извечението завършва с многоточние или стрингове  от типа "..?" , ".!" "1?." изчаква да свършат
        void printBySentence()const;

        //! Създава фаил с член данните на книга в data/books/...
        void createBookInfoFile()const;

        
};