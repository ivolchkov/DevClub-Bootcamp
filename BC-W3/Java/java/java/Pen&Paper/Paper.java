public class Paper {
    private StringBuffer content;
    private int maxSymbols;
    private int symbols;
    
    public Paper(int maxSymbols) {
        this.symbols = 0;
        this.maxSymbols = maxSymbols;
        content = new StringBuffer();
    }

    public Paper() {
        this(4096); 
    }

    public int getMaxSymbols() {
        return maxSymbols;
    }
    
    public int getSymbols() {
        return symbols;
    }
    
    public void addContent(String message) throws OutOfSpaceException {
        if ( symbols == maxSymbols ) {
            throw new OutOfSpaceException();
        }
        
        this.symbols += message.length();
        
        if ( this.symbols > this.maxSymbols ) {
            int temp = message.length() - (this.symbols - this.maxSymbols);
            
            this.symbols = this.maxSymbols;
            content.append(message.substring(0, temp));
        } else {
            content.append(message);
        }
    }
    public void show() {
        System.out.println(content);
    }
}
