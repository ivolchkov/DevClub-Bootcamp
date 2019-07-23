public class UnitMain {
    public static void main(String[] args) throws CloneNotSupportedException, UnitIsDeadException {
        Unit knight = new Unit("Knight", 40, 20);
        Unit knightJohn = knight.clone();
        Unit barbarian = new Unit("Barbarian", 43, 25);
                
        System.out.println("Unit:" + knight);
        System.out.println("Unit John:" + knightJohn);
        System.out.println("Unit:" + barbarian);
        
        barbarian.attack(knight);
        
        System.out.println("Unit:" + knight);
        System.out.println("Unit:" + barbarian);
        
        knight.addHitPoints(25);
        
        System.out.println("Unit:" + knight);
        
        System.out.println("Atributes:" + knight.getName() + " " + knight.getHitPoints() + " " + knight.getHitPointsLimit() + " " + knight.getDamage());
    }
}
