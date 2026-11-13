class DynamicArray {
private : 
    int size ; 
    int capacity_val ; 
    int *data ; 
public:

    DynamicArray(int capacity) {
        capacity_val = capacity ; 
        size = 0 ; 
        data = new int[capacity_val]; 
    }

    int get(int i) {
        return data[i]; 
    }

    void set(int i, int n) {
        data[i]=n ; 
    }

    void pushback(int n) {
        if (capacity_val==size){
            resize();
        }
        data[size]=n ; 
        size++ ;
    }

    int popback() {
        if(size>0){
            size--;
        }
        return data[size];
    }

    void resize() {
        // on va redoubler la capacité 
        capacity_val *= 2   ; 
        int *newdata = new int[capacity_val]; 
        //copier les anciens elements ; 
        for(int i=0  ; i<size; i++){ 
            newdata[i]=data[i]; 
        }
        delete[] data ; // supprime les anciens elements et libère le pointeur 
        data = newdata ; 
    }

    int getSize() {
        return size ; 
    }

    int getCapacity() {
        return capacity_val ; 
    }
};
