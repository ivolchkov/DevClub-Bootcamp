package states;

public class State {
    protected int hitPoints;
    protected int hitPointsLimit;
    protected double magicResist;
    protected int damage;
    protected String name;
    protected String title;
    protected String type;

    public State(String name, int hp, int dmg, double magicResist, String title, String type) {
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.magicResist = magicResist;
        this.damage = dmg;
        this.name = name;
        this.title = title;
        this.type = type;
    }

    public int getHitPoints() {
        return this.hitPoints;
    }

    public int getHitPointsLimit() {
        return this.hitPointsLimit;
    }

    public double getMagicResist() {
        return this.magicResist;
    }

    public int getDamage() {
        return this.damage;
    }

    public String getName() {
        return this.name;
    }

    public String getTitle() {
        return this.title;
    }

    public String getType() {
        return this.type;
    }

    public void setHitPointsLimit(int hp) {
        this.hitPointsLimit = hp;
    }

    public void ensureIsAlive() {
        if ( this.hitPoints == 0 ) {
            System.out.println("Unit is dead!");
        }
    }

    protected void _takeDamage(int dmg) {
        this.ensureIsAlive();

        this.hitPoints -= dmg;

        if ( this.hitPoints < 0 ) {
            this.hitPoints = 0;
        }
    }

    public void takeDamage(int dmg) {
        this._takeDamage(dmg);
    }

    public void takeMagicDamage(int dmg) {
        double reducedDamage = (1 - this.magicResist) * dmg;

        this._takeDamage((int)reducedDamage);
    }

    public void addHitPoints(int hp) {
        this.ensureIsAlive();

        this.hitPoints += hp;

        if ( this.hitPoints > this.hitPointsLimit ) {
            this.hitPoints = this.hitPointsLimit;
        }
    }

    public String toString() {
        return this.name + "\n" + "(" + this.title + ", " + this.type + ")" + "\n"
                + "Hit points: " + this.hitPoints + "/" + this.hitPointsLimit + "\n"
                + "Damage: " + this.damage + "\n"
                + "Magic Resist: " + this.magicResist + "\n";
    }
}
