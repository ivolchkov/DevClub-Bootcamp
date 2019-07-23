import java.util.ArrayList;

public class List {
    private int capacity;
    private int current;
    private ArrayList<Integer> list;
    
    public List(int capacity) throws ZeroLenException {
        this.capacity = capacity;
        this.current = 0;
        this.list = new ArrayList<>(this.capacity);
        
        if ( this.capacity < 0 ) {
            throw new ZeroLenException();
        }
        
    }
    
    public List() throws ZeroLenException {
        this(100);
    }
    
    public int size() {
        return current;
    }
    
    public int max_size() {
        return capacity;
    }
    
    public void erase(int index) throws IndexOutOfBoundsException {
        if ( index < 0 || index >= this.current ) {
            throw new IndexOutOfBoundsException();
        }
        for ( int i = index; i < this.current - 1; i++ ) {
            this.list.set(i, this.list.get(i+1));
        }
        
        this.current -= 1;
    }
    
    public void insert(int value, int index) throws IndexOutOfBoundsException {
        if ( index < 0 || index >= this.current ) {
            throw new IndexOutOfBoundsException();
        }
        
        this.list.add(index, value);
        this.current += 1;
    }
    
    public int find(int value) {
        for ( int index = 0; index < this.current; index++) {
            if ( list.get(index) == value ) {
                return index;
            }
        }
        return -1;
    }
    
    public void push_back(int value) {
        this.list.add(current, value);
        this.current += 1;
    }
    
    public int pop_back() throws ZeroLenException {
        if ( this.current == 0 ) {
            throw new ZeroLenException();
        }
        
        this.current -= 1;
        
        return this.list.get(current);
    }
    
    public void sort() {
        for ( int i = 1; i < this.current; i++ ) {
            int temp = this.list.get(i);
            int j = i;
            
            for ( int prev = j - 1; j > 0 && this.list.get(prev) > temp; j--, prev-- ) {
                this.list.set(j, this.list.get(prev));
            }
            this.list.set(j, temp);
        }
    }
    
    public int get(int index) throws IndexOutOfBoundsException {
        if ( index < 0 || index >= this.current ) {
            throw new IndexOutOfBoundsException();
        }
        return this.list.get(index);
    }
    
    public boolean equals(List other) throws IndexOutOfBoundsException {
        int i = 0;
        
        for ( ; i < this.current && i < other.current; i++ ) {
            if ( this.get(i) != other.get(i) ) {
                return false;
            }
        }
        if ( i == this.current && i == other.current ) {
            return true;
        }
        return false;
    }
    
    public String toString() {
        int last = this.size() - 1;
        String out = "";
        
        for( int i = 0; i < last; i++ ) {
            out += this.list.get(i) + " ";
        }
        out += this.list.get(last);
        
        return out;
    }
}