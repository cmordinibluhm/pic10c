#include <iostream>

// Forward declaration of RingQueue class
template <typename ItemType, int MAX_SIZE>
class RingQueue;

//------------------------------------------------------------------------------------//
//                                 RingQueue class                                    //
//------------------------------------------------------------------------------------//

/**
 templated RingQueue class interface
 
 @tparam ItemType the type of object to be stored in the RingQueue
 @tparam MAX_SIZE the capacity of the RingQueue
 */
template <typename ItemType, int MAX_SIZE>
class RingQueue{
    
    // Nested Forward declaration of RingQueue<ItemType,MAX_SIZE>::iterator
    // This is needed if one plans to turn this home-made iterator into
    // one of the special categories of iterators (e.g., input, output,
    // forward, etc.).
public:
    class iterator;

    // Aliases. 
    typedef ItemType* pointer;
    typedef ItemType& reference;

    
        //--------------------------------------------------------------------------------//
        //                             nested iterator class                              //
        //--------------------------------------------------------------------------------//
    
    /**
     Definition of public nested class RingQueue<ItemType,MAX_SIZE>::iterator
     
    */
    class iterator{
        private:
                // A link to the parent container 
            RingQueue* parent;
        
            // The position within the RingQueue is determined
            // by how far ahead we are from the beginning of the
            // queue.
            int offset;

            /**
             private constructor is only accessible through the RingQueue class
                 
             @param _parent pointer to the parent RingQueue that the iterator belongs to
             @param _offset tracks how far through the RingQueue the iterator has gone (defaulted to 0)
            */
            iterator(RingQueue* _parent, int _offset = 0 ) : parent(_parent), offset(_offset) { }
                
            // It is quite common for Containers and their iterators
            // to be friends. After all, they should work closely together.
            friend class RingQueue<ItemType,MAX_SIZE>;


        public:
            reference operator*() {
                  
                return parent->buffer[(parent->begin_index + offset) % MAX_SIZE];
            }

            iterator& operator++(){ //prefix increment operator
                ++offset;
                return *this;
            }

            
            iterator operator++( int unused ){ //postfix increment operator
                    
                iterator copy = *this;
                    
                ++offset;
                    
                return copy;
            }
        
            bool operator==( const iterator& rhs ) const {
                    
                if (parent == rhs.parent && offset == rhs.offset) {
                    return true;
                } else {
                    return false;
                }
                  
            }

            bool operator!=( const iterator& rhs ) const {
                
                return !(*this == rhs);
            }

    }; //---------------------- end nested iterator class ------------------------------


    //--------------------------------------------------------------------------------//
    //                          nested const iterator class                           //
    //--------------------------------------------------------------------------------//
        /**
         
         */
        class const_iterator{
            private:
                RingQueue* parent;
                int offset;

            private:
                // Only RingQueue objects can create const_iterators...
                const_iterator() ;

            public:
                // ... however, const_iterators can be 'copied'.
                const_iterator( const const_iterator& ) ;

            friend class RingQueue<ItemType,MAX_SIZE>;
         
        }; //------------------------ end nested const iterator class -------------------
         
    

    // Friendship goes both ways here.
    friend class iterator;
    // friend class const_iterator;  // not implemented... yet.

    private:
        // A fixed-size static array with constant capacity that represents 
        // the RingQueue
        ItemType buffer[MAX_SIZE];

        // The starting index. It changes according to a very 
        // specific set of rules (below).
        int begin_index;

        // The actual size of the RingQueue. Not to be confused with
        // its capacity. 
        int ring_size;

        // A helper function that computes the index of 'the end'
        // of the RingQueue
        int end_index() const {
            
            return (begin_index + ring_size) % MAX_SIZE;
        }

    public: 
        /**
         RingQueue constructor initializes begin_index and ring_size to zero
         
         */
        RingQueue() : begin_index(0), ring_size(0) { }

        // Accessors. Note: 'back()' is not considered part of the array.
    
        /**
         front() function returns the first value in the ring queue
         
         */
        ItemType front() const { 
            if ( ring_size == 0 ) { std::cerr<< "Warning: Empty ring!\n" ; } // Feel free to throw instead...
            
            else if (ring_size > 0) {
                return buffer[begin_index];
            }
            
        }
    
        /**
         back() function returns the last value in the ring queue
         
         */
        ItemType back() const {  
            if ( ring_size == 0 ) { std::cerr<< "Warning: Empty ring!\n" ; } // Feel free to throw instead...
            
            else if (ring_size > 0) {
                return buffer[end_index() - 1];
            }
        }

        // Mutators
    
        /**
         push_back function adds the value to the end of the RingQueue
         
         @param value the value to be added to the RingQueue
         */
        void push_back( const ItemType& value ){
            
            if (ring_size == 0) { //if the ring is empty
                
                buffer[0] = value;
                ++ ring_size;
                
            } else if (ring_size < MAX_SIZE) {
        
                 buffer[end_index()] = value;
                 ++ring_size;
                
             } else if (ring_size == MAX_SIZE) {
                 buffer[begin_index] = value;
                 
                 if (begin_index == MAX_SIZE - 1) {
                     begin_index = 0;
                     
                 } else {
                     ++begin_index;
                 }
             }
                                                        //
            return;
        }
    
        /**
         pop_front function removes the first value in the RingQueue
     
         */
        void pop_front() {
            
            if (ring_size > 0) {
                
                ++begin_index;
                --ring_size;
            }
            
            return;
        }

        // Functions that return iterators
        iterator begin() { 
            // Replace the line(s) below with your code.
            return iterator(this,0);
        }
        iterator end() {
            // Replace the line(s) below with your code.
            return iterator(this,ring_size);
        }

        // Miscellaneous functions
    
        /**
         returns a copy of the size of the RingQueue
         
         */
        size_t size() const {
            return ring_size;
        }

        // Debugging functions
        void dump_queue() const {
            std::cout << "Raw queue...\n";
            for ( size_t i = 0 ; i < MAX_SIZE ; ++i )
                std::cout << "Val: " << buffer[i] << ", at: " << buffer+i << '\n';
            std::cout << '\n';
            return;
        }

}; //----------------------------- end RingQueue class --------------------------------



int main(){
    RingQueue<int,7> rq;
    rq.dump_queue();

    for ( int i = 0 ; i < 8 ; ++i )
        rq.push_back(i+1);

    rq.dump_queue();
    rq.pop_front();

    std::cout << "Queue via size: \n";

    // RingQueue<int,7>::iterator it = rq.begin() ; 
    auto it = rq.begin() ; 
    for ( size_t i = 0 ; i < rq.size() ; ++i ) {
        std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
        ++it;
    }
    std::cout << '\n';

    // Uncomment the block below only when you have a working 
    // implementation of RingQueue<ItemType,int>::end(). 
    // If the implementation is not correct, it might result in 
    // an infinite loop.
    
    std::cout << "Queue via iterators: \n";
    for ( auto it = rq.begin() ; it != rq.end() ; ++it ) {
        std::cout << "Value: " << *it << ", address: " << &(*it) << '\n';
    }
    std::cout << '\n';
    
    rq.dump_queue();

    return 0;
}


/** 
    +++++++++++++++++++++++++++++++++++++++++++++++
    The output of your program [once the missing 
    code is added] should look more or less like
    the output below.
    
    Note:
        It is dependent on the device where 
        this driver is executed. However, it
        should be clear that the difference 
        between consecutive memory addresses
        is equal to the number reported by
        'size_of( int )'.
    +++++++++++++++++++++++++++++++++++++++++++++++

        Raw queue...
        Val: 2, at: 0x7ffcdeeaab40
        Val: 0, at: 0x7ffcdeeaab44
        Val: 4198285, at: 0x7ffcdeeaab48
        Val: 0, at: 0x7ffcdeeaab4c
        Val: 0, at: 0x7ffcdeeaab50
        Val: 0, at: 0x7ffcdeeaab54
        Val: 0, at: 0x7ffcdeeaab58

        Raw queue...
        Val: 8, at: 0x7ffcdeeaab40
        Val: 2, at: 0x7ffcdeeaab44
        Val: 3, at: 0x7ffcdeeaab48
        Val: 4, at: 0x7ffcdeeaab4c
        Val: 5, at: 0x7ffcdeeaab50
        Val: 6, at: 0x7ffcdeeaab54
        Val: 7, at: 0x7ffcdeeaab58

        Queue via size: 
        Value: 3, address: 0x7ffcdeeaab48
        Value: 4, address: 0x7ffcdeeaab4c
        Value: 5, address: 0x7ffcdeeaab50
        Value: 6, address: 0x7ffcdeeaab54
        Value: 7, address: 0x7ffcdeeaab58
        Value: 8, address: 0x7ffcdeeaab40

        Queue via iterators: 
        Value: 3, address: 0x7ffcdeeaab48
        Value: 4, address: 0x7ffcdeeaab4c
        Value: 5, address: 0x7ffcdeeaab50
        Value: 6, address: 0x7ffcdeeaab54
        Value: 7, address: 0x7ffcdeeaab58
        Value: 8, address: 0x7ffcdeeaab40

        Raw queue...
        Val: 8, at: 0x7ffcdeeaab40
        Val: 2, at: 0x7ffcdeeaab44
        Val: 3, at: 0x7ffcdeeaab48
        Val: 4, at: 0x7ffcdeeaab4c
        Val: 5, at: 0x7ffcdeeaab50
        Val: 6, at: 0x7ffcdeeaab54
        Val: 7, at: 0x7ffcdeeaab58
 */
