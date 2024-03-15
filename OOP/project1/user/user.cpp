const bool user::isValidUsername(const char* name)const{
    size_t sizeOfUsername = sizeof( name );
    if( strstr(name , " " ) == nullptr ){
        return true;

    }else{
        return false;
    }
}

void user::setUsername(const char* newUsername){
    if(strlen(newUsername) > MAX_PARAMATERS_LEN){
        username = nullptr;
    }
    delete []this->username;
    this->username = new char[ sizeof(newUsername) ];
    if( isValidUsername(newUsername) == true ){
        strcpy(username , newUsername);
        
    }else{
        this->username == nullptr;    
    }
}
const char* user::getUsername()const{
    return this->username;
}
void user::setPassword(const char* newPasswrod){
    if(strlen(newPasswrod) > MAX_PARAMATERS_LEN){
        password = nullptr;
    }
    delete []this->password;
    this->password = new char[ sizeof(newPasswrod) ];
    strcpy(this->password , newPasswrod);
}
const char* user::getPassword()const{
    return this->password;
}
const bool user::checkPassword(const char* input)const{
    if( strcmp(this->password , input) == 0 ){
        return true;
    }else{
        return false;
    }
}
const bool user::checkUsername(const char* input)const{
    if( strcmp(this->username , input) == 0 ){
        return true;
    }else{
        return false;
    }
}
void user::setIsAdmin(const bool newIsAdmin){
    this->isAdmin = newIsAdmin;
}
const bool user::getIsAdmin()const{
    return this->isAdmin;
}

void user::copyFrom(const user& other){
    setUsername( other.getUsername() );
    setPassword( other.getPassword() );
    setIsAdmin( other.getIsAdmin() );

}
user& user::operator=(const user& other){
    if(this != &other ){
        free();
        copyFrom(other);
    }
    return *this;
}

void user::free(){
    delete []this->username;
    delete []this->password;
}


user::user(){
    this->username = nullptr;
    this->password = nullptr;
    this->isAdmin = false;
}
user::user(const char* newUsername , const char* newPassword , const bool newIsAdmin){
    this->username = nullptr;
    this->password = nullptr;

    setUsername(newUsername);
    setPassword(newPassword);
    setIsAdmin(newIsAdmin);
}
user::user(const user& other){
    this->username = nullptr;
    this->password = nullptr;
    copyFrom(other);
}
user::~user(){
    free();
}

void user::createUserFile()const{
    char* location = new char[MAX_PARAMATERS_LEN+20];
    strcpy(location, "data/users/");
    strcat(location , getUsername() );
    strcat(location , ".txt" );
    std::ofstream oUser( location , std::ios::trunc );
    delete []location;
    if(oUser.is_open() != true){
        std::cout<<"Cannot open file! \n";
        return;
    }
    oUser.write(this->username , strlen(username));
    oUser<<std::endl;
    oUser.write(this->password , strlen(password));
    oUser<<std::endl;
    oUser<<isAdmin;
    oUser.close();
}
void user::setAll(const char* newUsername, const char* newPassword, const bool newisAdmin){
    setIsAdmin(newisAdmin);
    setUsername(newUsername);
    setPassword(newPassword);
}
void user::importFile(const char* location){
    
    std::ifstream iUser( location);
    if(iUser.is_open() != true){
        std::cout<<"Cannot open file! \n";
        return;
    }
    
    
    char newUsernam[MAX_PARAMATERS_LEN];
    char newPassword[MAX_PARAMATERS_LEN];
    bool newIsAdmin;
    iUser>>newUsernam;
    iUser>>newPassword;
    iUser>>newIsAdmin;
    setAll(newUsernam,newPassword,newIsAdmin);
    
   iUser.close();

}
const char* user::getUserFileLocation()const{
    char location[MAX_PARAMATERS_LEN + 20];
    strcpy(location,"data/users/");
    strcat(location,getUsername());
    strcat(location,".txt");
    return location;
}
const size_t user::getMAX_PARAMETER_LEN()const{
    return MAX_PARAMATERS_LEN;
}
user::user(const char* location){
    importFile(location);
}
