package states;

import exceptions.OutOfManaException;
import exceptions.UnitIsDead;

public class State {
    protected int hitPoints;
    protected int hitPointsLimit;
    protected double magicResist;
    protected int damage;
    protected String name;
    protected String title;
    protected String type;
    protected int manaPoints = 0;
    protected int manaPointsLimit = 0;

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

    public void ensureIsAlive() throws UnitIsDead  {
        if ( this.hitPoints == 0 ) {
            throw new UnitIsDead();
        }
    }

    protected void _takeDamage(int dmg) throws UnitIsDead {
        this.ensureIsAlive();

        this.hitPoints -= dmg;

        if ( this.hitPoints < 0 ) {
            this.hitPoints = 0;
        }
    }

    public void takeDamage(int dmg) throws UnitIsDead  {
        this._takeDamage(dmg);
    }

    public void takeMagicDamage(int dmg) throws UnitIsDead {
        double reducedDamage = (1 - this.magicResist) * dmg;

        this._takeDamage((int)reducedDamage);
    }

    public void addHitPoints(int hp) throws UnitIsDead {
        this.ensureIsAlive();

        this.hitPoints += hp;

        if ( this.hitPoints > this.hitPointsLimit ) {
            this.hitPoints = this.hitPointsLimit;
        }
    }

    public int getManaPoints() throws OutOfManaException {
        throw new OutOfManaException();
    }

    public void spendMana(int mp) throws OutOfManaException {
        throw new OutOfManaException();
    }

    public String toString() {
        return this.name + "\n" + "(" + this.title + ", " + this.type + ")" + "\n"
                + "Hit points: " + this.hitPoints + "/" + this.hitPointsLimit + "\n"
                + "Damage: " + this.damage + "\n"
                + "Magic Resist: " + this.magicResist + "\n";
    }
}
