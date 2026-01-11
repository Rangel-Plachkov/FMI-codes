#include"Interface.h"

void Interface::help()const{
    std::cout<<"The following commands are supported:"<<std::endl;
    std::cout<<"open <file>                 -> Open file with selected name"<<std::endl;
    std::cout<<"close                       -> Closes currently opened file"<<std::endl;
    std::cout<<"save                        -> Saves the currently open file"<<std::endl;
    std::cout<<"saveAs <file>               -> Saves the currently open file in <file>"<<std::endl;
    std::cout<<"help                        -> Prints this information"<<std::endl;
    std::cout<<"exit                        -> Exits program"<<std::endl;
    std::cout<<"print                       -> Print loaded XML file"<<std::endl;
    std::cout<<"select <id> <key>           -> Get atribute value"<<std::endl;
    std::cout<<"set <id> <key> <value>      -> Set atribute value"<<std::endl;
    std::cout<<"delete <id> <key>           -> Delete atribute"<<std::endl;
    std::cout<<"children <id>               -> Get children of <id>"<<std::endl;
    std::cout<<"child <id> <n>              -> Get index <n> child of <id>"<<std::endl;
    std::cout<<"newChild <id>               -> Add empty child to <id>"<<std::endl;
    std::cout<<"text <id>                   -> Get text of <id>"<<std::endl;
    std::cout<<"xpath <id> <XPath>          -> XPath"<<std::endl;
}
void Interface::open(const myString& fileName){
    std::cout<<"Successfully opened "<<fileName.get();
    std::cout<<std::endl;
    m_parser.incertFile(fileName.get());
    m_file = fileName;
}
void Interface::text(const myString& elementId)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    std::cout<<m_parser.getElementByIndex(indexOfElement)->getText();
    std::cout<<std::endl;
}
void Interface::print()const{
    m_parser.print();
}
void Interface::select(const myString& elementId , const myString& nameOfAtribute)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    
    if(m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->withoutValue()){
        std::cout<<"Atribute has no value!"<<std::endl;
        return;
    }else{  
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->getName();
        std::cout<<" = ";
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->getValue();
        std::cout<<std::endl;
    }
}
void Interface::set(const myString& elementId , const myString& nameOfAtribute, const myString& newValue){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute)->setValue(newValue.get());
    std::cout<<"New value set!"<<std::endl;
}
void Interface::children(const myString& elementId)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    for(size_t i=0; i < m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren(); i++){
        std::cout<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex(i).get()<<" ";
    }
    std::cout<<std::endl;
}
void Interface::child(const myString& elementId, const myString& key)const{
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( key.getNumber() == -1 ){
        std::cout<<"Invalid key!"<<std::endl;
        return;
    }
    const size_t convert  = static_cast<size_t>(key.getNumber() );//Това го правя за да премахна warning
    if( convert >= m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren()){
        std::cout<<"Invalid key! (Index to big)"<<std::endl;
        return;
    }
    std::cout<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex(convert).get();
    std::cout<<std::endl;
}
void Interface::newChild(const myString& elementId){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    XMLelement t_newChild;
    m_parser.getElementByIndex(indexOfElement)->addChild(t_newChild.getId());
    std::cout<<"Added new child with ID: "<<m_parser.getElementByIndex(indexOfElement)->getChildByIndex( m_parser.getElementByIndex(indexOfElement)->getNumberOfChildren()-1 ).get();
    std::cout<<std::endl;
}
void Interface::deleteAtr(const myString& elementId, const myString& nameOfAtribute){
    const size_t indexOfElement = m_parser.findIndexById(elementId);
    if( !m_parser.getElementByIndex(indexOfElement)->getAtributeByName(nameOfAtribute) ){
        std::cout<<"Atribute doesnt exist!"<<std::endl;
        return;
    }
    m_parser.getElementByIndex(indexOfElement)->deleteAtribute(nameOfAtribute);
    std::cout<<"Deleted!"<<std::endl;
}
void Interface::save()const{
    m_parser.exportToFile(m_file.get());
    std::cout<<"Successfully saved "<<m_file.get();
    std::cout<<std::endl;
}
void Interface::saveAs(const myString& newFile){
    m_file = newFile;
    m_parser.exportToFile(m_file.get());
    std::cout<<"Successfully saved "<<m_file.get();
    std::cout<<std::endl;
    
}
void Interface::close(){
    if(m_file != '\0'){
        m_file = '\0';
        m_parser.cleanUp();
    }
    std::cout<<"Successfully closed "<<m_file.get();
    std::cout<<std::endl;
}
void Interface::xpath(const myString& elementId , const myString& newXpath){
    m_parser.xPath(elementId,newXpath);
}
void Interface::menu(){
    char input[MAX_INPUT_SIZE];
    std::cout<<">";
    std::cin.getline(input, MAX_INPUT_SIZE);
    const size_t sizeOfInput = strlen(input) +1;
    myString* words = new myString[MAX_INPUT_SIZE];
    size_t numberOfWords = 0;
    for(size_t i=0; i<sizeOfInput; i++){
        if(input[i] == ' '){
            words[i] += '\0';
            if(input[i-1] !=' '){
                
                numberOfWords++;
            }
        }else{
            words[numberOfWords] += input[i];  
        }
    }
    numberOfWords++;
    bool exitOpt = false;
    if(words[0] == "open"){open(words[1]);
    }else if(words[0] == "close"){close();m_unsavedChanges = false;
    }else if(words[0] == "save"){save();m_unsavedChanges = false;
    }else if(words[0] == "saveAs"){saveAs(words[1]);m_unsavedChanges = false;
    }else if(words[0] == "help"){help();
    }else if(words[0] == "exit"){  exitOpt = true;
    }else if(words[0] == "print"){print();
    }else if(words[0] == "select"){select(words[1] , words[2]);
    }else if(words[0] == "set"){set(words[1] , words[2] , words[3]);m_unsavedChanges = true;
    }else if(words[0] == "children"){children(words[1]);
    }else if(words[0] == "child"){child(words[1] , words[2]);
    }else if(words[0] == "text"){text(words[1]);
    }else if(words[0] == "delete"){deleteAtr(words[1] , words[2]);m_unsavedChanges = true;
    }else if(words[0] == "newChild"){newChild(words[1]);m_unsavedChanges = true;
    }else if(words[0] == "xpath"){xpath(words[1] , words[2]);
    }

    delete []words;
    if( !( exitOpt && exit() ) ){
        menu();
    }
}
bool Interface::exit(){
    if(m_unsavedChanges == true){
        std::cout<<"You have an open file with unsaved changes, please select close or save first."<<std::endl;
        std::cout<<"close / save / saveAs <name of file> "<<std::endl;
        std::cout<<"anything else to return to main menu"<<std::endl;
        std::cout<<">";
        char input[MAX_INPUT_SIZE];
        std::cin.getline(input, MAX_INPUT_SIZE);
        const size_t sizeOfInput = strlen(input) +1;
        myString* words = new myString[MAX_INPUT_SIZE];
        size_t numberOfWords = 0;
        for(size_t i=0; i<sizeOfInput; i++){
            if(input[i] == ' '){
                words[i] += '\0';
                if(input[i-1] !=' '){    
                    numberOfWords++;
                }
            }else{
                words[numberOfWords] += input[i];  
            }
        }
        if(words[0] == "save"){
            save();
            m_unsavedChanges = false;
            delete []words;
            std::cout<<"Exiting program...";
            return true;
        }
        if(words[0] == "saveAs"){
            saveAs(words[1]);
            m_unsavedChanges = false;
            std::cout<<"Exiting program...";
            delete []words;
            return true;
        }
        if(words[0] == "close"){
            close();
            delete []words;
            m_unsavedChanges = false;
            std::cout<<"Exiting program...";
            return true;
        }
        delete []words;
        return false;
    }else{
        std::cout<<"Exiting program...";
        return true;
    }
}
Interface::Interface(){
    m_unsavedChanges = false;
}
Interface::Interface(bool shouldStart){
    m_unsavedChanges = false;
    if(shouldStart){
        menu();
    }
}