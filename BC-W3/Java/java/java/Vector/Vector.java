public class Vector implements Cloneable {
    private double x;
    private double y;
    
    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Vector() {
        this(0.0, 0.0);
    }
    
    public double getX() {
        return x;
    }
    
    public double getY() {
        return y;
    }
    
    public void setX(double value) {
        x = value;
    }
    
    public void setY(double value) {
        y = value;
    }
    
    public double len() {
        return Math.hypot(x, y);
    }
    
    public boolean equals(Vector other) {
        return x == other.x && y == other.y;
    }
    
    public boolean notEquals(Vector other) {
        return x != other.x && y != other.y;
    }
    
    public Vector increment(Vector other) {
        this.x += other.x;
        this.y += other.y;
        
        return this; 
    }
    
    public Vector decrement(Vector other) {
        this.x -= other.x;
        this.y -= other.y;
        
        return this; 
    }
    
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    
    public Vector clone() throws CloneNotSupportedException {
        return (Vector) super.clone();
    }
}