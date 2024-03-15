
template <typename t>
class bag{
    private:
        t* items;
        
        size_t id;
        size_t numberOfItems;
        size_t sizeOfBag;
        static const size_t DEFAULT_STARTING_ARR_SIZE = 16;

        void resize();
    public:
        static size_t counter;
        bag();
        void add(const t& newItem);
        const t& get();
        size_t getId()const;
        //void operator+(const );
};

template <typename t>
bag<t>::bag(){
    items = new t[DEFAULT_STARTING_ARR_SIZE];
    sizeOfBag = DEFAULT_STARTING_ARR_SIZE;
    numberOfItems = 0;
    id = counter;
    counter++;
}

template <typename t>
void bag<t>::add(const t& newItem){
    if(numberOfItems+1 >= sizeOfBag){
        resize();
    }
    items[numberOfItems] = newItem;
    numberOfItems++;
}

template <typename t>
void bag<t>::resize(){
    sizeOfBag = sizeOfBag*2;
    t* buff = new t [sizeOfBag];
    for(int i=0;i<numberOfItems;i++){
        buff[i] = items[i];
    }
    delete []items;
    items = buff;
    buff = nullptr;
}
template <typename t>
const t& bag<t>::get(){
    numberOfItems--;
    return items[numberOfItems];
}
template <typename t>
size_t bag<t>::getId()const{
    return id;
}
