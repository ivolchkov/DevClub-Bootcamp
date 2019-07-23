public class ComplexMain {
    public static void main(String[] args) throws CloneNotSupportedException {
        Complex a = new Complex(2, 7);
        Complex b = new Complex(6, 8);
        Complex c = b.clone();
        Complex d = new Complex();
        
        System.out.println("a:" + a);
        System.out.println("b:" + b);
        System.out.println("c:" + c);
        System.out.println("d:" + d);


        System.out.println("b:" + b);
        System.out.println("c:" + c);

        
        if ( a.equals(b) ) {
            System.out.println(a + " is equal to " + b);
        } else {
            System.out.println(a + " is not equal to " + b);
        }
        
        a.increment(c);
        System.out.println("a incremented c :" + a);
        
        System.out.println("a and b:" + a + b);
        b.decrement(a);
        
        System.out.println("b decremented a:" + b);
        
        
        System.out.println("a multiple c :" + a.multiple(c));
    }
}
