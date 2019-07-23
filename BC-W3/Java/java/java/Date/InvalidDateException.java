public class InvalidDateException extends Exception {
    public String text;
    
    public InvalidDateException(String text) {
        this.text = text;
    }
}
