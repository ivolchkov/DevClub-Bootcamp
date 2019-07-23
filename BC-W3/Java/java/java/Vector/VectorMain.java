public class VectorMain {
    public static void main(String[] args) throws CloneNotSupportedException {
        Vector a = new Vector(2, 7);
        Vector b = new Vector(6, 8);
        Vector c = b.clone();
        Vector d = new Vector();

        System.out.println("b:" + b);
        System.out.println("c:" + c);
        System.out.println("d:" + d);

        c.setX(42);

        System.out.println("b:" + b);
        System.out.println("c:" + c);
        System.out.println("Not equals:" + a.increment(b));
    }
}
