#pragma once

class user{
    private:
        //! максимален размер на параметрите на user
        static const size_t MAX_PARAMATERS_LEN = 100;
        char* username;
        char* password;
        bool isAdmin;

        //! Провевява дало в името няма разтояния
        const bool isValidUsername(const char* name)const;
        //! Изтрива username и password
        void free();
        //! Помощна функция използвана от copy constructor и оператор =. Не изтрива динамична памер
        void copyFrom(const user&);

    public:
        user(const char* newUsernam , const char* newPassword , const bool isAdmin);
        //! default constructor  дава nullptr за стойност на username и password  и 0 за isAdmin
        user();
        user(const user& other);
        //! Конструктор който приема за името на текстови ффаил. Ако съществува такъв в data/users/... взима данните му и ги записва към класа
        user(const char* location);
        
        //! Деструктор извиква free()
        ~user();
        user& operator= (const user&);

        //! Поставвя нова стойнност на Username. Валидира прес isValidUsername()
        void setUsername(const char* newUsername);
        //! Поставя нова стойност на password няма ограничения
        void setPassword(const char* newPassword);  
        //! поставя нова стойност на isAdmin (true/false)
        void setIsAdmin(const bool newIsAdmin);
        //! Извиква всички set функции
        void setAll(const char* newUsername, const char* newPassword, const bool newIsAdmin);
        //! Връща указател към username
        const char* getUsername()const;
        //! Връща указател към password      
        const char* getPassword()const;
        //! Приема за параметър низ проверява дали съвпада с password
        const bool checkPassword(const char* input)const;
        //! Приема за параметър низ проверява дали съвпада с username
        const bool checkUsername(const char* input)const;
        //! Връща true/false на база дали user-a е админ
        const bool getIsAdmin()const;  
        //! Връща константата MAX_PARAMETER_LEN
        const size_t getMAX_PARAMETER_LEN()const; 

        //! Създава фаил в data/users/..  с име /username/ с информация за член данните му
        void createUserFile()const;
        //! Задава стойности за user от файл в data/users/".location"
        void importFile(const char* location);
        //! Връща адреса с фаила за информация на user  data/users/"usernameс"
        const char* getUserFileLocation()const;

};