public class Car implements Cloneable {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point location;
    private String model;
    
    public Car(double capacity, double consumption, Point location, String model) {
        this.fuelAmount = 0.0;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
    }
    
    public Car() {
        this.fuelAmount = 0.0;
        this.fuelCapacity = 60.0;
        this.fuelConsumption = 0.6;
        this.location = new Point(0.0, 0.0);
        this.model = "Mercedes";
    }
    
    public double getFuelAmount() {
        return fuelAmount;
    }
    
    public double getFuelCapacity() {
        return fuelCapacity;
    }
    
    public double getFuelConsumption() {
        return fuelConsumption;
    }
    
    public Point getLocation() {
        return location;
    }
    
    public String getModel() {
        return model;
    }
    
    public void drive(Point destination) throws OutOfFuelException {
        double distance = this.location.distance(destination);
        
        this.fuelAmount -= this.fuelConsumption * distance;
        
        if ( this.fuelAmount < 0 ) {
            throw new OutOfFuelException();
        }
        
        this.location = destination;
    }
    
    public void drive(double x, double y) throws OutOfFuelException {
        Point destination = new Point(x, y);
        double distance = this.location.distance(destination);
        
        this.fuelAmount -= this.fuelConsumption * distance;
        
        if ( this.fuelAmount < 0 ) {
            throw new OutOfFuelException();
        }
        
        this.location = destination;
    }
    
    public void refill(double fuel) throws ToMuchFuelException {
        this.fuelAmount += fuel;
        
        if ( this.fuelAmount > this.fuelCapacity ) {
            throw new ToMuchFuelException();
        }
    }
    
    public String toString() {
        return model + " has location - " + location + " with fuel amount - " + fuelAmount + ", capacity - " + fuelCapacity + " and consumption - " + fuelConsumption;
    }
    
    public Car clone() throws CloneNotSupportedException {
        return (Car) super.clone();
    }

}
