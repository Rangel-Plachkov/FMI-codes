#include<iostream>
#include<cstring>
#include<fstream>

void book::free(){
    delete []this->title;
    delete []this->author;
    delete []this->location;
    delete []this->description;
    delete []this->isbn;
}
const double book::validRatingConverter(const double rate)const {
    if(rate >= 1 && rate <= 5){
        return rate;
    }else{
        if(rate < 1){
            return 1;
        }
        if(rate > 5){
            return 5;
        }
    }
    return 1;
}
const bool book::validIsbn(const char* checkIsbn)const{
    
    const size_t strLen = strlen(checkIsbn);
    if(strLen > 13){
        return false;
    }
    for(int i = 0; i<strLen; i++){
        if(checkIsbn[i] == '0' || checkIsbn[i] == '1' || checkIsbn[i] == '2' ||
            checkIsbn[i] == '3' || checkIsbn[i] == '4' || checkIsbn[i] == '5' ||
            checkIsbn[i] == '6' || checkIsbn[i] == '7' || checkIsbn[i] == '8' ||
            checkIsbn[i] == '9'){
                
        }else{
            return false;
        }
    }
    return true;
}
const size_t book::getFileSize(std::ifstream& iFile)const{
    size_t currentPosition = iFile.tellg();
	iFile.seekg(0, std::ios::end);
	size_t result = iFile.tellg();
	iFile.seekg(currentPosition);
	return result;     
}
void book::removeFile(){
    remove( getLocation() );
    std::cout<<"Removed "<<getLocation()<<std::endl;
}

void book::copyFrom(const book& other){
    this->title = new char[ sizeof( other.getTitle() ) + 1];
    strcpy(this-> title, other.getTitle() );

    this->author = new char[ sizeof( other.getAuthor() ) + 1];
    strcpy(this->author , other.getAuthor() );

    this->location = new char[ sizeof( other.getLocation() ) + 1];
    strcpy(this->location , other.getLocation() );

    this->description = new char[ sizeof( other.getDescription() ) + 1];
    strcpy(this->description , other.getDescription() );

    setRating( other.getRating() );

    this->isbn = new char [ sizeof( other.getIsbn() ) +1  ];
    strcpy(this->isbn , other.getIsbn() );
}

book&  book::operator=(const book& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

book::book(const book& other){
    copyFrom(other);
}

book::book(const char* newTitle ,  const char* newAuthor, const char* newLocation , const char* newDescription , double newRating ,const char* newIsbn){

    this->title = new char[ sizeof(newTitle) + 1 ];
    strcpy(this->title , newTitle);

    this->author = new char[ sizeof(newAuthor) + 1 ];
    strcpy(this->author , newAuthor);

    this->location = new char[ sizeof(newLocation) + 1 ];
    strcpy(this->location , newLocation);

    
    this->description = new char[ strlen(newDescription) + 1 ];
    strcpy(this->description , newDescription);
    

    setRating( newRating );

    
    if( validIsbn(newIsbn) == true ){
        this->isbn = new char[ sizeof(newIsbn) + 1 ];
        strcpy(this->isbn , newIsbn);
    }else{
        //std::cout<<"Invalid Isbn";
        this->isbn = nullptr;
    }
    createBookInfoFile();


}
book::book(){
   this->title = nullptr;
   this->author = nullptr;
   this->location = nullptr;
   this->description = nullptr;
   this->rating = 1;
   this->isbn = nullptr;
}
book::~book(){
    free();
}

void book::setTitle(const char* newTitle){
    if(strlen(newTitle) > MAX_SYMBOLS_IN_PARAM ){
        delete []this->title;
        this->title = nullptr;
        return;
    }
    delete []this->title;
    this->title = new char [ sizeof(newTitle) + 1 ];
    strcpy(this->title , newTitle);
}
const char* book::getTitle()const {
    return this->title;
}

void book::setAuthor(const char* newAuthor){
    if(strlen(newAuthor) > MAX_SYMBOLS_IN_PARAM ){
        delete []this->author;
        this->author = nullptr;
        return;
    }
    delete []this->author;
    this->author = new char [ sizeof(newAuthor) + 1 ];
    strcpy(this->author , newAuthor);
}
const char* book::getAuthor()const {
    return this->author;
}

void book::setLocation(const char* newLocation){
    if(strlen(location) > MAX_SYMBOLS_IN_PARAM ){
        delete []this->location;
        this->location = nullptr;
        return;
    }
    delete []this->location;
    this->location = new char [ sizeof(newLocation) + 1 ];
    strcpy(this->location , newLocation);
}
const char* book::getLocation()const {
    return this->location;
}

void book::setDescription(const char* newDescription){
    if(strlen(newDescription) > MAX_SYMBOLS_IN_PARAM ){
        delete []this->description;
        this->description = nullptr;
        return;
    }
    delete []this->description;
    this->description = new char [ sizeof(newDescription) + 1 ];
    strcpy(this->description , newDescription);
}
const char* book::getDescription()const {
    return this->description;
}
void book::setRating(const double newRating){
    this->rating = validRatingConverter(newRating);
}
const double book::getRating()const{
    return this->rating;
}

void book::setIsbn(const char* newIsbn){
    if(strlen(newIsbn) > MAX_SYMBOLS_IN_PARAM ){
        delete []this->isbn;
        this->isbn = nullptr;
        return;
    }
    if( validIsbn(newIsbn) == true ){
        delete []this->isbn;
        this->isbn = new char [ sizeof(newIsbn) + 1 ];
        strcpy(this->isbn, newIsbn);
    }else{
        //std::cout<<"Invalid ISBN";
        this->isbn = nullptr;
    }
}
const char* book::getIsbn()const{
    return this->isbn;
}

void book::newPageSpacer()const{
    //std::cout<<"\n newPage \n";
    for(int space = 0; space < LINES_BETWEEN_PAGES; space++){
        std::cout<<std::endl;
    }
}
const bool book::isEndSymbol(const char symbol)const{
 
   if( symbol == '.' || symbol == '!' || symbol == '?'){
       return true;
   }else{
       return false;
   }
}

void book::printBook()const{
    std::cout<<getTitle();
    std::cout<<std::endl;
    std::cout<<"by: "<<getAuthor();
    std::cout<<std::endl;
    std::cout<<std::endl;
    size_t sizeOfFile;
    std::ifstream iBook( getLocation() , std::ios::out );
    if(iBook.is_open() != true ){
        std::cout<<"Cannot open file";
    }else{
        sizeOfFile = getFileSize(iBook);
        char* text = new char[sizeOfFile + 1];
        iBook.read(text ,sizeOfFile);
        std::cout<<text;
        delete []text;
        iBook.close();     
    }
     std::cout<<std::endl;
    std::cout<<std::endl;
}


 
void book::printByPage(const unsigned int linesInPage)const{
    std::cout<<getTitle();
    std::cout<<std::endl;
    std::cout<<"by: "<<getAuthor();
    std::cout<<std::endl;
    std::cout<<std::endl;
    size_t sizeOfFile;
    std::ifstream iBook( getLocation() );
    if(iBook.is_open() != true ){
        std::cout<<"Cannot open file";
    }else{
        unsigned counter = 0;
        while(iBook.tellg() < sizeOfFile){
            char* text = new char[ MAX_SYMBOLS_IN_LINE ];
            iBook.getline(text , MAX_SYMBOLS_IN_LINE);
           std::cout<<text;
            delete []text;
            counter++;
            if(counter%linesInPage == 0){
                newPageSpacer();
            }
        }   
        iBook.close();     
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}


void book::printByNcharacters(const unsigned int symbolsInPage)const{
    std::cout<<getTitle();
    std::cout<<std::endl;
    std::cout<<"by: "<<getAuthor();
    std::cout<<std::endl;
    std::cout<<std::endl;
    size_t sizeOfFile;
    std::ifstream iBook( getLocation() , std::ios::out );
    if(iBook.is_open() != true ){
        std::cout<<"Cannot open file";
    }else{
        sizeOfFile = getFileSize(iBook);

        for(int i = 0; i<sizeOfFile; i = i + symbolsInPage ){
            char* text = new char[symbolsInPage + 1];
            iBook.read(text ,symbolsInPage);
            std::cout<<text;
            delete []text;

            newPageSpacer();

        }

        iBook.close();     
    } 
    std::cout<<std::endl;
    std::cout<<std::endl;
}


void book::printBySentence()const{
    std::cout<<getTitle();
    std::cout<<std::endl;
    std::cout<<"by: "<<getAuthor();
    std::cout<<std::endl;
    std::cout<<std::endl;
    size_t sizeOfFile;
    std::ifstream iBook( getLocation() , std::ios::out );
    if(iBook.is_open() != true ){
        std::cout<<"Cannot open file";
    }else{

        sizeOfFile = getFileSize(iBook);
        bool nearEnd = false;
        for(int i = 0; i < sizeOfFile ;i++){
            
            char currentSymbol = iBook.get();

            if(isEndSymbol(currentSymbol)){
                std::cout<<currentSymbol; 
                nearEnd = true;

            }else{
                if(nearEnd == true){
                    newPageSpacer();
                    nearEnd = false;
                }
                std::cout<<currentSymbol;  
            }
        }
        iBook.close();
    } 
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void book::createBookInfoFile()const{
    char* descLocation = new char [ strlen(getLocation()) + 10];
    strcpy(descLocation, "data/");
    strcat(descLocation,getLocation());
    std::ofstream oBook( descLocation , std::ios::trunc );
    delete []descLocation;
    if(oBook.is_open() != true){
        std::cout<<"Cannot open file! \n";
        return;
    }
    oBook.write(this->title , strlen(title));
    oBook<<std::endl;
    oBook.write(this->author , strlen(author));
    oBook<<std::endl;
    oBook.write(this->location , strlen(location));
    oBook<<std::endl;
    oBook<<rating;
    oBook<<std::endl;
    oBook.write(this->isbn , strlen(isbn));
    oBook<<std::endl;
    oBook.write(this->description , strlen(description));
    oBook<<std::endl;
    oBook.close();
}
