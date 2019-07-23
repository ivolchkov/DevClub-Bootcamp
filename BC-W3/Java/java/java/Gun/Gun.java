public class Gun implements Cloneable {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;
    
    public Gun(String model, int capacity) {
        this.model = model;
        this.capacity = capacity;
        this.amount = 0;
        this.isReady = false;
        this.totalShots = 0;
    }
    
    public Gun() {
        this("Beretta", 8);
    }
    
    public int getAmount() {
        return amount;
    }
    
    public int getCapacity() {
        return capacity;
    }
    
    public boolean ready() {
        return isReady;
    }
    
    public String getModel() {
        return model;
    }
    
    public int getTotalShots() {
        return totalShots;
    }
    
    public void prepare() {
        isReady = !isReady;
    }
    
    public void reload() {
        amount = capacity;
    }
    
    public void shoot() throws NotReadyException, OutOfRoundsException {
        if ( !isReady ) {
            throw new NotReadyException();
        }
        if ( amount == 0 ) {
            throw new OutOfRoundsException();
        }
        
        amount -= 1;
        totalShots += 1;
        isReady = !isReady;
    }
    
    public String toString() {
        return model + " has capacity of " + capacity + " , amount of rounds - " + amount + " and total shoots - " + totalShots;
    }
    
    public Gun clone() throws CloneNotSupportedException {
        return (Gun) super.clone();
    }
}