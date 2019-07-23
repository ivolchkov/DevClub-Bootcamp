public class Complex implements Cloneable {
    private double re;
    private double im;
    
    public Complex(double re, double im) {
        this.re = re;
        this.im = im;
    }
    
    public Complex() {
        this(0.0, 0.0);
    }
    
    public double getReal() {
        return re;
    }
    
    public double getImaginary() {
        return im;
    }
    
    public boolean equals(Complex other) {
        return re == other.re && im == other.im;
    }
    
    public boolean notEquals(Complex other) {
        return !this.equals(other);
    }
    
    public Complex increment(Complex other) {
        this.re += other.re;
        this.im += other.im;
        
        return this;
    }
    
    public Complex decrement(Complex other) {
        this.re -= other.re;
        this.im -= other.im;

        return this;
    }
    
    public Complex multiple(Complex other) {
        Complex temp = new Complex();
        
        temp.re = re * other.re - im * other.im;
        temp.im = im * other.re + re * other.im;
        
        return temp;
    }
    
    public String toString() {
        if ( this.im >= 0 ) {
            return re + "+" + im + "i";
        } else {
            return re + "" +  im + "i";
        }
    }
    
    public Complex clone() throws CloneNotSupportedException {
        return (Complex) super.clone();
    }
}