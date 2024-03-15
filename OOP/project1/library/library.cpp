void library::free(){
    delete []books;
}
void library::resize(){
    this->sizeOfLibrary = this->sizeOfLibrary*2;
    book* buffer = new book [this->sizeOfLibrary];
    for(int i = 0 ; i<numberOfBooks ; i++){
        buffer[i] = this->books[i];
    }
    free();
    this->books = buffer;
    buffer = nullptr;
}
const size_t library::getNumberOfBooks()const{
    return this->numberOfBooks;
}
const size_t library::getSizeOfLibrary()const{
    return this->sizeOfLibrary;
}
const book* library::getBookArr()const{
    return books;
}

void library::copyFrom(const library& other){
    this->numberOfBooks = other.getNumberOfBooks();
    this->sizeOfLibrary = other.getSizeOfLibrary();
    
    this->books = new book [ this->sizeOfLibrary ];
    this->books = other.books;
}

library::library(){
    this->books = new book [ this->DEFAULT_STARTING_LIB_SIZE ];
    this->numberOfBooks = 0;
    this->sizeOfLibrary = DEFAULT_STARTING_LIB_SIZE; 
}
library::~library(){
    free();
}
library::library(const library& other){
    copyFrom(other);
}
library& library::operator=(const library& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

void library::addBook(const book& newBook){
    
    if(this->numberOfBooks >= this->sizeOfLibrary){
        resize();
        this->books[numberOfBooks] = newBook;
        this->numberOfBooks++;

    }else{
        this->books[numberOfBooks] = newBook;
        this->numberOfBooks++;
    }
}

void library::removeBook(const unsigned int index){
    if( index>=this->numberOfBooks ){
        std::cout<<"book does not exist \n";
    }else{
        this->numberOfBooks--;
        removeFileDecision(index);
        for(int i = index; i < this->numberOfBooks; i++){
            this->books[i] = this->books[i+1];
            
        }
        std::cout<<"The book is unlisted"<<std::endl;
    }
}
void library::removeFileDecision(const unsigned int index){
    bool decision;
    std::cout<<"Do you want to remove: "<<books[index].getLocation() <<std::endl;
    std::cin>>decision;
    if(decision == true){
        this->books[index].removeFile();
    }else{
        std::cout<<"file not removed\n";
    }
}


void library::listBooks()const{
    for(size_t i = 0 ; i < this->numberOfBooks; i++){
        std::cout<<i+1<<". ";
        std::cout<<this->books[i].getTitle()<<", ";
        std::cout<<this->books[i].getAuthor()<<", ";
        //std::cout<<this->books[i].getLocation()<<", ";
        std::cout<<"rating: "<<books[i].getRating()<<", ";
        std::cout<<this->books[i].getIsbn();
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void library::rankingSort(const bool highestToLowest){
    if(highestToLowest == true){
        int remainingNumberOfBooks = this->numberOfBooks;
        while(remainingNumberOfBooks > 0){
            double highest = 0;
            size_t highestIndex;
            for(int i=0; i<remainingNumberOfBooks; i++){    
                if( this->books[i].getRating() > highest){
                    highest = this->books[i].getRating();
                    highestIndex = i;
                }
            }
            swapIndex(remainingNumberOfBooks-1 , highestIndex);
            remainingNumberOfBooks--;
        }  
    }else{
        int remainingNumberOfBooks = this->numberOfBooks;
        while(remainingNumberOfBooks > 0){
            double lowest = 5;
            size_t lowestIndex;
            for(int i=0; i<remainingNumberOfBooks; i++){    
                if( this->books[i].getRating() < lowest){
                    lowest = this->books[i].getRating();
                    lowestIndex = i;
                }
            }
            swapIndex(remainingNumberOfBooks-1 , lowestIndex);
            remainingNumberOfBooks--;
        } 
    }
}



void library::readBook(const unsigned int index)const{
    //std::cout<<numberOfBooks;
    if(index + 1 <= numberOfBooks){
        this->books[index].printBook();
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}
void library::readBookBySentences(const unsigned int index)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printBySentence();
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}
void library::readBookByCharactersInPage(const unsigned int index , const unsigned int symbolsInPage)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printByNcharacters(symbolsInPage);
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}

void library::readBookByPage(const unsigned int index , const unsigned int linesInPage)const{
    if(index + 1 <= numberOfBooks){
        this->books[index].printByPage(linesInPage);
    }else{
        std::cout<<"this book does not exist\n";//<<std::endl;
    }
}

const int library::validInputConverter(const int input , const unsigned int numberOfCommands)const{
    if(input >= 0 || input <= numberOfCommands){
        return input;
    }else{
        return -1;
    }
}

const int library::getInput()const{
    char input[MAX_INPUT_SIZE];
    std::cin>>input;
    const size_t inputLen = strlen(input); 
    int command=0;
    int pow = 1;
    for(int i=inputLen-1; i>=0; i--){
        if(input[i] != '0' && input[i] != '1' && input[i] != '2' &&
            input[i] != '3' && input[i] != '4' && input[i] != '5' &&
            input[i] != '6' && input[i] != '7' && input[i] != '8' &&
            input[i] != '9'){
                return -1;
        }
        if(input[i] == '0' ){
                command = command+0*pow;
        }
        if(input[i] == '1' ){
                command = command+1*pow;
        }
        if(input[i] == '2' ){
                command = command+2*pow;
        }
        if(input[i] == '3' ){
                command = command+3*pow;
        }
        if(input[i] == '4' ){
                command = command+4*pow;
        }
        if(input[i] == '5' ){
                command = command+5*pow;
        }
        if(input[i] == '6' ){
                command = command+6*pow;
        }
        if(input[i] == '7' ){
                command = command+7*pow;
        }
        if(input[i] == '8' ){
                command = command+8*pow;
        }
        if(input[i] == '9' ){
                command = command+9*pow;
        }
        pow = pow*10;
    }
    return command;
    
}

void library::printComandsForUser()const{
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Book list"<<std::endl;
    std::cout<<"2.Search"<<std::endl;
}
void library::printComandsForAdmin()const{
    std::cout<<"0.Exit"<<std::endl;
    std::cout<<"1.Book list"<<std::endl;
    std::cout<<"2.Search"<<std::endl;
    std::cout<<"3.Add book"<<std::endl;
}
void library::printBookProfileUser(const unsigned int index)const{
    std::cout<<"Title: "<<books[index].getTitle()<<std::endl;
    std::cout<<"Author: "<<books[index].getAuthor()<<std::endl;
    std::cout<<"Rating: "<<books[index].getRating()<<std::endl;
    std::cout<<"ISBN: "<<books[index].getIsbn()<<std::endl;
    std::cout<<std::endl;
    std::cout<<books[index].getDescription()<<std::endl;
  
    std::cout<<"0.Back"<<std::endl;
    std::cout<<"1.Read"<<std::endl;
    
}
void library::printBookProfileAdmin(const unsigned int index)const{
    std::cout<<"Title: "<<books[index].getTitle()<<std::endl;
    std::cout<<"Author: "<<books[index].getAuthor()<<std::endl;
    std::cout<<"Rating: "<<books[index].getRating()<<std::endl;
    std::cout<<"ISBN: "<<books[index].getIsbn()<<std::endl;
    std::cout<<"location: "<<books[index].getLocation()<<std::endl;
    std::cout<<std::endl;
    std::cout<<books[index].getDescription()<<std::endl;

    std::cout<<"0.Back"<<std::endl;
    std::cout<<"1.Read"<<std::endl;
    std::cout<<"2.Remove"<<std::endl;
}
void library::printReadingOptions()const{
    std::cout<<"1.Read (normaly..?)"<<std::endl;
    std::cout<<"2.Read sentence by sentency"<<std::endl;
    std::cout<<"3.Read by N amount of lines on a page"<<std::endl;
    std::cout<<"4.Read by N amount of symbols on a page"<<std::endl;
    std::cout<<"0.Back"<<std::endl;
}
void library::printListMenu()const{
    std::cout<<"1.List by ranking"<<std::endl;
    std::cout<<"2.List by title"<<std::endl;
    std::cout<<"3.List by author"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"0.Back"<<std::endl;
}
void library::menu(const user& person){
    if(person.getIsAdmin() == true){
        printComandsForAdmin();
        int input = getInput();
        int convInput = validInputConverter(input , 3);
        if( convInput == -1){
            std::cout<<"Invalid command!"<<std::endl;
        }else{
            if(convInput == 0){
                std::cout<<"Author: Rangel Plachkov";
                std::cout<<std::endl;
                std::cout<<"1MI0800061";
                return;
                
            }
            if(convInput == 1){
                listMenu(person);
            }
            if(convInput == 2){
                searchMenu(person);
            }
            if(convInput == 3){
                addBookMenu(person);
            }
        }
    }else{
        printComandsForUser();
        int input = getInput();
        int convInput = validInputConverter(input , 2);
        if( convInput == -1){
            std::cout<<"Invalid command!"<<std::endl;
        }else{
            if(convInput == 0){
                std::cout<<"Author: Rangel Plachkov";
                std::cout<<std::endl;
                std::cout<<"1MI0800061";
                return;
                
            }
            if(convInput == 1){
                listMenu(person);
            }
            if(convInput == 2){
                searchMenu(person);
            }
        }
    }
    menu(person);
}
void library::addBookMenu(const user& person){
    std::cout<<std::endl<<std::endl;
    std::cout<<"0.Back"<<std::endl;
    std::cout<<"1.Import from file"<<std::endl;
    std::cout<<"2.Write"<<std::endl;

    int input = getInput();
    int convInput = validInputConverter(input , 2);
    if(convInput == -1){
        std::cout<<"Invalid input!\n";
        addBookMenu(person);
    }
    if(convInput == 0){
        return;
    }
    if(convInput == 1){
        char location[MAX_INPUT_SIZE];
        std::cout<<"Location of the book: ";
        std::cin>>location;
        importBook(location);
    }
    if(convInput == 2){
        char title[MAX_INPUT_SIZE];
        char author[MAX_INPUT_SIZE];
        char ISNB [MAX_INPUT_SIZE];
        char location[MAX_INPUT_SIZE];
        char description[MAX_INPUT_SIZE];
        double rating;
        std::cout<<"Title: ";
        std::cin>>title;
        std::cout<<"Author: ";
        std::cin>>author;
        std::cout<<"ISNB: ";
        std::cin>>ISNB;
        std::cout<<"Location: ";
        std::cin>>location;
        std::cout<<"Rating: ";
        std::cin>>rating;
        std::cout<<"Description: ";
        std::cin>>description;
        book temp(title,author,location,description,rating,ISNB);
        addBook(temp);
        std::cout<<"Book added succsefuly"<<std::endl;
    }

}
void library::listMenu(const user& person){
    printListMenu();
    char input = getInput();
    int convInput = validInputConverter(input , 3);
    if( convInput == -1){
        std::cout<<"Invalid command:"<<std::endl;
        listMenu(person);
    }else{
        if(convInput == 0){
                return;
            }
            if(convInput == 1){
                bool highestToLowest;
                std::cout<<"Highest to lowest? (0/1) : \n";
                
                int input = getInput();
                input = validInputConverter(input , 1);
                if(input == -1){
                    std::cout<<"Invalid input"<<std::endl;
                    listMenu(person);
                }

                if(input == true){
                    rankingSort(true);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }else{
                    rankingSort(false);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();  
                    selectBookIndex(person);
                }
                
                
            }
            if(convInput == 2){
                bool AtoZ;
                std::cout<<"A to Z? (if 0 -> Z to A) (0/1) : \n";
                int input = getInput();
                input = validInputConverter(input ,1);
                if(input == -1){
                    std::cout<<"Invalid input"<<std::endl;
                    listMenu(person);
                }
                if(input == 1){
                    AtoZ = true;
                    titleSort(AtoZ);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }
                if(input == 0){
                    AtoZ = false;
                    titleSort(AtoZ);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }

                

            }
            if(convInput == 3){
                bool AtoZ;
                std::cout<<"A to Z? (if 0 -> Z to A) (0/1) : \n";
                int input = getInput();
                input = validInputConverter(input ,1);
                if(input == -1){
                    std::cout<<"Invalid input"<<std::endl;
                    listMenu(person);
                }
                if(input == 1){
                    AtoZ = true;
                    authorSort(AtoZ);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }
                if(input == 0){
                    AtoZ = false;
                    authorSort(AtoZ);
                    std::cout<<"0.Back"<<std::endl;
                    listBooks();
                    selectBookIndex(person);
                }
            }
    }
    //menu(person);
}

void library::selectBookIndex(const user& person){
    int input =validInputConverter( getInput() , numberOfBooks-1);
    if(input == 0){
        return;
    }
    if(person.getIsAdmin() == true){
        printBookProfileAdmin(input-1);
        int secInput = validInputConverter(getInput() , 2);
        if(input == -1){
            std::cout<<"Invalid input"<<std::endl;
            selectBookIndex(person);
        }
        if(input == 0){
            return;
        }
        if(secInput == 1){
            books[input-1].printBook();
        }
        if(secInput == 2){
            removeBook(input-1);
        }

    }else{
        printBookProfileUser(input-1);
        int secInput = validInputConverter(getInput() , 1);
        if(input == -1){
            std::cout<<"Invalid input"<<std::endl;
            selectBookIndex(person);
        }
        if(input == 0){
            return;
        }
        if(secInput == 1){
            readingMenu(person , input-1);
        }
    }
}
void library::readingMenu(const user& person ,const size_t bookIndex){
    printReadingOptions();
    int input = validInputConverter(getInput() , 4);
    if(input == -1){
        std::cout<<"Invalid input"<<std::endl;
        readingMenu(person,bookIndex);
    }
    if(input == 0){
        return;
    }
    if(input == 1){
        books[bookIndex].printBook();
    }
    if(input == 2){
        books[bookIndex].printBySentence();
    }
    if(input == 3){
        std::cout<<"Lines on page: ";
        int secInput = getInput();
        if(secInput == -1){
            std::cout<<"Invalid input"<<std::endl;
            readingMenu(person , bookIndex);
        }else{
            books[bookIndex].printByPage(secInput);
        }
    }
    if(input == 4){
        std::cout<<"Characters on page: ";
        int secInput = getInput();
        if(secInput == -1){
            std::cout<<"Invalid input"<<std::endl;
            readingMenu(person , bookIndex);
        }else{
            books[bookIndex].printByNcharacters(secInput);
        }
    }
}
void library::swapIndex(const size_t A ,const size_t B){
    if(A >= numberOfBooks || B >= numberOfBooks){
        std::cout<<"Invalid swap"<<std::endl;
        return;
    }
    const book temp = books[A];
    books[A] = books[B];
    books[B] = temp;
}

void library::titleSort(const bool AtoZ){
        /*
        double* stringValue = new double [ this->numberOfBooks +1  ];
        size_t highest = 0;

        for(int i=0; i<numberOfBooks;i++){
            stringValue[i] = 0;
            size_t bookLen = strlen( books[i].getTitle() );
            char* allLowercase = new char [ bookLen + 1];
            strcpy(allLowercase , books[i].getTitle() );
            for(int  j=0 ; j<bookLen + 1; j++){
                if(allLowercase[j] >= 'A' && allLowercase[j] <= 'Z'){
                    allLowercase[j] = allLowercase[j] + ('a' - 'A');
                }
                stringValue[i] = stringValue[i] + allLowercase[j] * pow(1000 , 0-j);

            }
            if(stringValue[i] > highest){
                highest = stringValue[i];
            }
            delete []allLowercase;
        }
        int remainingNumberOfBooks = this->numberOfBooks;

        while(remainingNumberOfBooks > 0){

            size_t  lowest = highest;
            size_t lowestIndex;
            for(int i=0; i<remainingNumberOfBooks; i++){   
                
                if( stringValue[i] <= lowest){
                    
                    lowest = stringValue[i];
                    lowestIndex = i;
                    
                }
                
            }
        
            swapIndex(remainingNumberOfBooks-1 , lowestIndex);
            remainingNumberOfBooks--;
        }
        delete []stringValue;
        
        if(AtoZ == true){
            int swaper = (numberOfBooks-1)/2;
            for(int i=0; i<swaper; i++){
                swapIndex(i,numberOfBooks-1-i);
            }
        }*/
    size_t maxStrLen = 0;
    char** allLowercase = new char* [ this->numberOfBooks + 1 ];
    for(int i=0; i <numberOfBooks; i++){
        size_t bookLen = strlen( books[i].getTitle() );
        if(maxStrLen < bookLen){
            maxStrLen = bookLen;
        }
        allLowercase[i] = new char[ bookLen + 1];
        strcpy(allLowercase[i] , books[i].getTitle());
        for(int  j=0 ; j<bookLen ; j++){
            if(allLowercase[i][j] >= 'A' && allLowercase[i][j] <= 'Z'){
                allLowercase[i][j] = allLowercase[i][j] + ('a' - 'A');
            }
        }
    }
    
    for (int i = 0 ; i<numberOfBooks; i++  ){
        size_t tempI = i;
        for(int j = i+1; j<numberOfBooks; j++){
            if(isLowerWord(allLowercase[tempI] , allLowercase[j]) == false){
                char* temp = new char[maxStrLen+1];
                strcpy(temp, allLowercase[tempI]);
                delete []allLowercase[tempI];
                allLowercase[tempI] = new char [maxStrLen + 1];
                strcpy(allLowercase[tempI],allLowercase[j]);
                delete []allLowercase[j];
                allLowercase[j] = new char[maxStrLen + 1];
                strcpy(allLowercase[j],temp);
                delete []temp;
                swapIndex(tempI,j);
                tempI = j;
            }
        }
    }
    for(int i=0;i<numberOfBooks;i++){
        delete []allLowercase[i];
    }
    delete []allLowercase;
    
    if(AtoZ == true){
        int swaper = (numberOfBooks-1)/2;
        for(int i=0; i<swaper; i++){
            swapIndex(i,numberOfBooks-1-i);
        }
    }

}
const bool library::isLowerWord(const char* a , const char* b)const {
    if( strcmp(a,b) > 0){
        //std::cout<<a<<"is higher than: "<<b<<std::endl;
        return true;
    }else{
        //std::cout<<a<<"is lower than: "<<b<<std::endl;
        return false;
    }
}
void library::authorSort(const bool AtoZ){
    
    size_t maxStrLen = 0;
    char** allLowercase = new char* [ this->numberOfBooks + 1 ];
    for(int i=0; i <numberOfBooks; i++){
        size_t bookLen = strlen( books[i].getAuthor() );
        if(maxStrLen < bookLen){
            maxStrLen = bookLen;
        }
        allLowercase[i] = new char[ bookLen + 1];
        strcpy(allLowercase[i] , books[i].getAuthor());
        for(int  j=0 ; j<bookLen ; j++){
            if(allLowercase[i][j] >= 'A' && allLowercase[i][j] <= 'Z'){
                allLowercase[i][j] = allLowercase[i][j] + ('a' - 'A');
            }
        }
    }
    /*
    for(int i=0;i<numberOfBooks;i++){
        std::cout<<allLowercase[i]<<std::endl;
    }
    */
    for (int i = 0 ; i<numberOfBooks; i++  ){
        size_t tempI = i;
        for(int j = i+1; j<numberOfBooks; j++){
            if(isLowerWord(allLowercase[tempI] , allLowercase[j]) == false){
                char* temp = new char[maxStrLen+1];
                strcpy(temp, allLowercase[tempI]);
                delete []allLowercase[tempI];
                allLowercase[tempI] = new char [maxStrLen + 1];
                strcpy(allLowercase[tempI],allLowercase[j]);
                delete []allLowercase[j];
                allLowercase[j] = new char[maxStrLen + 1];
                strcpy(allLowercase[j],temp);
                delete []temp;
                swapIndex(tempI,j);
                //std::cout<<i<<"<->"<<j<<"\n";
                tempI = j;
                
            }else{
                //std::cout<<"No change\n";
            }
        }
    }
    for(int i=0;i<numberOfBooks;i++){
        delete []allLowercase[i];
    }
    delete []allLowercase;
    
    if(AtoZ == true){
        int swaper = (numberOfBooks-1)/2;
        for(int i=0; i<swaper; i++){
            swapIndex(i,numberOfBooks-1-i);
        }
    }
}
const char* library::getInputString()const{
    char* input = new char[MAX_INPUT_SIZE];
    std::cin>>input;
    return input;///////////////////////////////////////////////////////////////////////////////////////
}
void library::searchMenu(const user& person){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"0.Back \n";
    std::cout<<"Search word: ";
    char* input; 
    //char* input = new char[MAX_INPUT_SIZE];
    //input = getInputString();
    strcpy( input , getInputString() );
    if( strlen( input ) <= 2 && input == "0\0"){
        //return;
    }else{
        book* isItListed = new book[ this->numberOfBooks ];
        size_t* indexMaper = new size_t[this->numberOfBooks];
        for(int i = 0;i<this->numberOfBooks;i++){
            indexMaper[i] = -1;
        }
        size_t numberOfListed = 0;
        for(int i = 0; i < this->numberOfBooks; i++){
            if( strcmp(input , books[i].getTitle() ) == 0){
                isItListed[numberOfListed] = books[i];
                indexMaper[numberOfListed] = i;
                numberOfListed++;
            }else{
                if( strcmp(input , books[i].getAuthor() ) == 0){
                    isItListed[numberOfListed] = books[i];
                    indexMaper[numberOfListed] = i;
                    numberOfListed++; 
                }else{
                    if( strcmp(input , books[i].getIsbn() ) == 0){
                        isItListed[numberOfListed] = books[i];
                        indexMaper[numberOfListed] = i;
                        numberOfListed++; 
                    }else{
                        if( strstr(books[i].getDescription() , input ) != nullptr){
                            isItListed[numberOfListed] = books[i];
                            indexMaper[numberOfListed] = i;
                            numberOfListed++; 
                        }
                    }
                }
            }
            /*
            if(isItListed[i].getTitle() != nullptr){
                indexMaper[numberOfListed-1] = i;
            }
            */
        }
        
        std::cout<<std::endl;
        if(numberOfListed == 0){
            std::cout<<"No matches\n\n";
            std::cout<<std::endl;
            delete []isItListed;
            delete []input;
            delete []indexMaper;
            
            return;
        }
        for(int i=0; i < numberOfListed ; i++){
            
            std::cout<<i+1<<". ";
            std::cout<<isItListed[i].getTitle()<<" ";
            std::cout<<isItListed[i].getAuthor()<<" ";
            std::cout<<isItListed[i].getRating()<<" ";
            std::cout<<isItListed[i].getIsbn()<<" ";
            std::cout<<std::endl;
        }
        int secInput = getInput();
        secInput = validInputConverter(secInput , numberOfListed-1);
        //std::cout<<numberOfListed<<std::endl;
        
            if(secInput == -1 || secInput>numberOfListed){
                std::cout<<"Invalid input\n";
                searchMenu(person);
            }else{
                if(secInput == 0){
                    delete []isItListed;
                    delete []input;
                    delete []indexMaper;
                    return;
                }else{
                    secInput--;
                    //std::cout<<indexMaper[secInput]<<"\n";
                    selectSearchedBookIndex(person , indexMaper[secInput]);
                }
            }
        delete []isItListed;
        delete []input;
        delete []indexMaper;
    }
}
void library::selectSearchedBookIndex(const user& person,const  size_t input){
    if(person.getIsAdmin() == true){
        printBookProfileAdmin(input);
        int secInput = validInputConverter(getInput() , 2);
        if(secInput == -1){
            std::cout<<"Invalid input\n"<<std::endl;
            selectBookIndex(person);
        }
        if(secInput == 0){
            return;
        }
        if(secInput == 1){
            readingMenu(person,input);
        }
        if(secInput == 2){
            removeBook(input);
        }
    }else{
        printBookProfileUser(input);
        int secInput = validInputConverter(getInput() , 1);
        if(secInput == -1){
            std::cout<<"Invalid input\n"<<std::endl;
            selectBookIndex(person);
        }
        if(secInput == 0){
            return;
        }
        if(secInput == 1){
            readingMenu(person , input);
        }
    }
}

void library::importBook(const char* bookLocation){
    char* descLocation = new char [ strlen(bookLocation) + 10];
    strcpy(descLocation, "data/");
    strcat(descLocation,bookLocation);
    std::ifstream iBook( descLocation);
    delete []descLocation;
    if(iBook.is_open() != true){
        std::cout<<"Cannot open file! \n";
        return;
    }
    char title[MAX_INPUT_SIZE];
    char author[MAX_INPUT_SIZE];
    char location[MAX_INPUT_SIZE];
    double rating;
    char isbn[MAX_INPUT_SIZE];
    char description[MAX_INPUT_SIZE];
    //iBook.read(author , get)
    iBook>>title;
    iBook>>author;
    iBook>>location;
    iBook>>rating;
    iBook>>isbn;
    iBook>>description;
    iBook.close();
    book newBook(title,author,location,description,rating,isbn);
    addBook(newBook);
}