public class Unit implements Cloneable {
    private int damage;
    private int hitPoints;
    private int hitPointsLimit;
    private String name;
    
    private void ensureIsAlive() throws UnitIsDeadException {
        if ( hitPoints == 0 ) {
            throw new UnitIsDeadException();
        }
    }
    
    public Unit(String name, int hp, int dmg) {
        this.name = name;
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.damage = dmg;
    }
    
    public int getDamage() {
        return damage;
    }
    
    public int getHitPoints() {
        return hitPoints;
    }
    
    public int getHitPointsLimit() {
        return hitPointsLimit;
    }
    
    public String getName() {
        return name;
    }
    
    public void addHitPoints(int hp) throws UnitIsDeadException {
        ensureIsAlive();
        
        this.hitPoints += hp;
        
        if ( hitPoints > hitPointsLimit ) {
            this.hitPoints = this.hitPointsLimit;
        }
    }
    
    public void takeDamage(int dmg) throws UnitIsDeadException {
        ensureIsAlive();
        
        this.hitPoints -= dmg;
        
        if ( hitPoints < 0 ) {
            this.hitPoints = 0;
        } 
    }
    
    public void attack(Unit enemy) throws UnitIsDeadException {
        enemy.takeDamage(this.damage);
        enemy.ensureIsAlive();
        enemy.counterAttack(this);
    }
    
    public void counterAttack(Unit enemy) throws UnitIsDeadException {
        enemy.takeDamage(this.damage / 2);
    }
    
    public String toString() {
        return name + " has " + hitPoints + "/" + hitPointsLimit + " hp, and " + damage + " damage.";
    }
    
    public Unit clone() throws CloneNotSupportedException {
        return (Unit) super.clone();
    }
}