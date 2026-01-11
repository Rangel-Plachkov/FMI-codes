#include"Parser.h"

#include<exception>

Parser::Parser(){
    setDefaultValues();
    m_XMLelements = new XMLelement[DEFAULT_ELEMENTS_ARR_SIZE];
}
void Parser::free(){
    delete []m_XMLelements;
}
Parser::~Parser(){
    free();
}
void Parser::copyFrom(const Parser& other){
    m_numberOfElements = other.m_numberOfElements;
    m_sizeOfElementsArr = other.m_sizeOfElementsArr;
    m_XMLelements = new XMLelement[m_sizeOfElementsArr];
    for(size_t i=0; i<m_sizeOfElementsArr; i++){
        m_XMLelements[i] = other.m_XMLelements[i];
    }
}
Parser::Parser(const Parser& other){
    copyFrom(other);
}
Parser& Parser::operator=(const Parser& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
void Parser::addElement(const XMLelement& newElement){
    while(m_numberOfElements + 1 >= m_sizeOfElementsArr){
        resizeXMLelementArr();
    }
    
    m_XMLelements[m_numberOfElements] = newElement;
    if(m_XMLelements[m_numberOfElements].getId()[0] =='\0'){
        
        m_XMLelements[m_numberOfElements].setId("_");

    }else{
        for(size_t i=0 ; i<m_numberOfElements ; i++){
            
            if(   strstr( m_XMLelements[m_numberOfElements].getId() , m_XMLelements[i].getId() )  ){

                m_XMLelements[m_numberOfElements].setId("_");
            }
        }
    }
    
    //m_XMLelements[m_numberOfElements].setParent(m_edit);
    m_numberOfElements++;
}
void Parser::resizeXMLelementArr(){
    m_sizeOfElementsArr = m_sizeOfElementsArr*2;
    XMLelement* temp = new XMLelement[m_sizeOfElementsArr];
    for(size_t i=0; i<m_sizeOfElementsArr;i++){
        temp[i] = m_XMLelements[i];
    }
    delete []m_XMLelements;
    m_XMLelements = temp;
    temp = nullptr;
}
XMLelement* Parser::getElementByIndex(const size_t index)const{
    return &m_XMLelements[index];
}



void Parser::incertFile(const char* file){
    myString edit(BASE_ID);
    std::ifstream iFile(file  , std::ios::binary);
    if( !iFile.is_open() ){
        //throw std::logic_error("Cannot open file");
        return;
    }
    
    while( !iFile.eof() ){
        myString input( fileInput(iFile) );
        if( input.getSize() ){
            if(input.get()[0] == '<'){
                if( input.get()[1] == '/'){
                    
                    if( !findParent(edit).isEmpty() ){
                        edit = findParent(edit);
                    }else{
                        edit = BASE_ID;
                    }
                }else{

                    size_t sizeOfInput = input.getSize();
                    myString* words = new myString [sizeOfInput];
                    size_t numberOfWords = 0;
                    myString currentWord;
                    for(size_t i=1; i<sizeOfInput-1 && input.get()[i] != '>' ; i++){
                        if(input.get()[i] == ' '){
                            if(input.get()[i-1] !=' '){
                                numberOfWords++;
                            }
                        }else{
                            words[numberOfWords] += input.get()[i];  
                        }
                    }
                    numberOfWords++;
                    
                    XMLelement temp;
                    temp.setParent(edit);

                    for(size_t i=0 ; i<numberOfWords; i++){
                        if(words[i].get()[0] == 'i' && words[i].get()[1] == 'd' && words[i].get()[2] == '='){
                            
                            words[i].removeFirstNsymbols(3);
                            if(words[i].get()[0] == '"'  && words[i].get()[ words[i].getSize()-1 ] == '"' ){
                                words[i].removeFirstNsymbols(1);
                                words[i].removeLastNsymbols(1);
                            }
                            temp.setId( words[i].get() );
                        }else{
                            Atribute tempAtribute;
                            if(words[i].strstr('=') == words[i].getSize()+1){
                                tempAtribute.setName( words[i].get() );
                            }else{
                                const size_t posOfEq = words[i].strstr('=');
                                myString storage(words[i]);
                                storage.removeLastNsymbols( words[i].getSize() - posOfEq );
                                tempAtribute.setName( storage.get() );
                                storage = words[i];
                                storage.removeFirstNsymbols( posOfEq + 1 );
                                if(storage.get()[0] == '"' && storage.get()[ storage.getSize()-1] == '"'){
                                    storage.removeFirstNsymbols(1);
                                    storage.removeLastNsymbols(1);
                                }
                                tempAtribute.setValue( storage.get() );

                            }
                            
                            temp.addAtribute(tempAtribute);
                            
                        }
                    }
                    delete []words; 
                    
                    size_t curIndex = findIndexById(edit);   
                    addElement(temp);
                     m_XMLelements[m_numberOfElements].setParent(edit);
                    if(curIndex != m_numberOfElements-1){
                        m_XMLelements[curIndex].addChild( m_XMLelements[m_numberOfElements-1].getId() );
                    }                     
                    m_XMLelements[m_numberOfElements-1].setParent(edit);
                    edit = m_XMLelements[m_numberOfElements-1].getId();
                    
                }
            }else{
                
                const size_t curIndex = findIndexById(edit);    
                if(curIndex != m_numberOfElements){
                    m_XMLelements[curIndex].setText( input.get() );
                }  
                
                 
            }
        }
    }
    iFile.close(); 

}


const myString Parser::fileInput(std::ifstream& iFile)const{
    myString inputLine;
    while( !iFile.eof() ){
        char nextSym = iFile.get();  
        switch (nextSym){
        case '\n':
            return inputLine;
            break;
        case '\t':
            nextSym = '\0';
            break;
        case '<':
            if( !inputLine.isEmpty() ){
                iFile.clear();
                iFile.seekg( -1, std::ios::cur );
                return inputLine;
            }
                inputLine += '<';
            
            break;
        case '>':
            inputLine += '>';
            return inputLine;
            break;
        default:
            inputLine += nextSym;
            break;
        }
    }
    return inputLine;
}

void Parser::print()const{
    for(size_t i=0 ;i<m_numberOfElements;i++){
        std::cout<<"id: "<<m_XMLelements[i].getId()<<std::endl;
        if( m_XMLelements[i].getParent().isEmpty() ){
            std::cout<<"parent: NaN"<<std::endl;
        }else{
            std::cout<<"parent: "<< m_XMLelements[i].getParent().get() <<std::endl;
        }
        std::cout<<"children("<<m_XMLelements[i].getNumberOfChildren()<<"): ";
        for(size_t j=0; j<m_XMLelements[i].getNumberOfChildren(); j++){
            std::cout<< m_XMLelements[i].getChildByIndex(j).get() <<" ";
        }
        std::cout<<std::endl<<"text: ";
        std::cout<<m_XMLelements[i].getText();
        std::cout<<std::endl;
        std::cout<<"atributes("<<m_XMLelements[i].getNumberOfAtributes()<<"): ";
        for(size_t j=0; j<m_XMLelements[i].getNumberOfAtributes(); j++ ){
            std::cout<<"<";
            std::cout<<m_XMLelements[i].getAtributeByIndex(j)->getName();
            if( !m_XMLelements[i].getAtributeByIndex(j)->withoutValue() ){
                std::cout<<"=";
                std::cout<<m_XMLelements[i].getAtributeByIndex(j)->getValue();
            }
            std::cout<<"> ";
        }
        
        std::cout<<"\n\n";
    }
}

size_t Parser::findIndexById(const myString& searchedId)const{
    for(size_t i = 0; i<m_numberOfElements ; i++){
        if( searchedId == m_XMLelements[i].getId() ){
            return i;
        }
    }
    return m_numberOfElements;
}
const myString Parser::findParent(const myString& childId)const{
    myString result;
    const size_t childIndex = findIndexById(childId);
    for(size_t i = 0; i<m_numberOfElements; i++){
        if(m_XMLelements[childIndex].getParent() == m_XMLelements[i].getId() ){
            result =  m_XMLelements[i].getId();
        }
    } 
    return result;

}
const myString* Parser::getChildren(const myString& parentId)const{
    const size_t parentIndex = findIndexById(parentId);
    return m_XMLelements[parentIndex].getChildren();
}   

void Parser::exportToFile(const char* fileName)const{
    std::ofstream oFile(fileName , std::ios::out | std::ios::trunc);
    for(size_t i=0; i<m_numberOfElements; i++){ 
        if(m_XMLelements[i].getParent() == BASE_ID ){
            writeElement(oFile , m_XMLelements[i].getId() ,0);
            oFile<<'\n';
        }   
    }
    oFile.close();
}
void Parser::writeElement(std::ofstream& oFile ,const myString& elementId , const size_t subCount)const{
    const size_t index = findIndexById(elementId);
    tabInNtimes(oFile,subCount);
    oFile<<"<";
    oFile<<m_XMLelements[index].getAtributeByIndex(0)->getName();
    oFile<<" id="<<'"';
    oFile<<m_XMLelements[index].getId();
    oFile<<'"';
    for(size_t i=1; i<m_XMLelements[index].getNumberOfAtributes(); i++){
        oFile<<" ";
        oFile<<m_XMLelements[index].getAtributeByIndex(i)->getName();
        if( !m_XMLelements[index].getAtributeByIndex(i)->withoutValue() ){
            oFile<<'='<<'"';
            oFile<<m_XMLelements[index].getAtributeByIndex(i)->getValue();
            oFile<<'"';
        }
        if(i != m_XMLelements[index].getNumberOfAtributes()-1){
            oFile<<" ";
        }
    }
    oFile<<">";
    oFile<<m_XMLelements[index].getText();
    for(size_t i = 0 ; i < m_XMLelements[index].getNumberOfChildren() ; ++i){
        if(i != 0 ){
            oFile<<'\n';
        }
        writeElement(oFile , m_XMLelements[index].getChildByIndex(i), subCount+1 );
    }
    if(m_XMLelements[index].getNumberOfChildren() != 0){
        oFile<<'\n';
        tabInNtimes(oFile, subCount);
    }
    oFile<<"</";
    oFile<<m_XMLelements[index].getAtributeByIndex(0)->getName();
    oFile<<">";
}
void Parser::tabInNtimes(std::ofstream& oFile , const size_t N)const{
    for(size_t i=0; i<N ; i++){
        oFile<<'\t';
    }
}
void Parser::cleanUp(){
    free();
    setDefaultValues();
}
void Parser::setDefaultValues(){
    m_XMLelements = nullptr;
    m_numberOfElements = 0;
    m_sizeOfElementsArr =DEFAULT_ELEMENTS_ARR_SIZE;
}
XMLelement* Parser::xPath(const myString& elementId ,const myString& command){
    size_t currentIndex = findIndexById(elementId);
    if(currentIndex == m_numberOfElements){
        return nullptr;
    }

    myString* words = new myString[ command.getSize() ];
    size_t numberOfWords = 0;

    for(size_t i=0; i< command.getSize(); i++){
        if(command.get()[i] == '/' || command.get()[i] == '@'){   
            numberOfWords++;
        }
        words[numberOfWords] += command.get()[i];
    }
    myString* remainingElelemts = new myString[m_numberOfElements];
    const size_t numberOfChildren =  m_XMLelements[currentIndex].getNumberOfChildren();
    size_t remainingCount = numberOfChildren;
    for(size_t i=0; i<remainingCount;i++){
        remainingElelemts[i] =  m_XMLelements[currentIndex].getChildByIndex(i);
    }
    for(size_t i=0; i<numberOfWords; i++){
        char lastSym = words[i].get()[ words[i].getSize()-1 ];
        if(lastSym == '/'){
            /*
            words[i].removeLastNsymbols(1);
            for(size_t j=0; j<numberOfChildren; j++){
                size_t tempIndex = findIndexById(remainingElelemts[j]);
                for(size_t s = 0; s<m_XMLelements[tempIndex].getNumberOfAtributes(); s++){
                    if(m_XMLelements[tempIndex].getAtributeByIndex(s)->getName() == words[i]){
                        break;
                    }
                    if(s == m_XMLelements[tempIndex].getNumberOfAtributes()-1 ){
                        remainingElelemts[j] = '\0';
                        remainingCount--;
                    }
                }

            }
            */
        }else if(lastSym == '@'){
            words[i].removeLastNsymbols(1);
            
        }else{
            
        }
    }
    for(int i=0; i<numberOfChildren; i++){
            if(!remainingElelemts[i].isEmpty()){
                std::cout<<remainingElelemts[i].get()<<" ";
            }
        }
    delete []remainingElelemts;
    delete []words;
    return nullptr;
}