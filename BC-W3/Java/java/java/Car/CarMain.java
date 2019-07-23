public class CarMain {
    public static void main(String[] args) throws CloneNotSupportedException, OutOfFuelException, ToMuchFuelException {
        Point location = new Point(5.0, 5.0);
        Car car = new Car(60, 0.8, location, "Lanos");
        Car car2 = car.clone();
                
        System.out.println("Car:" + car);
        System.out.println("Car2:" + car2);
        
        car.refill(50.0);
        car.drive(new Point(5.0,20.0));
        
        System.out.println("Car:" + car);
        System.out.println("Car location:" + car.getLocation());
    }
}
