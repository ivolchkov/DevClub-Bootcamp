package states;

import exceptions.*;

public class MagicState extends State {

    public MagicState(String name, int hp, int mp, int dmg, double magicResist, String title, String type) {
        super(name, hp, dmg, magicResist, title, type);
        this.manaPoints = mp;
        this.manaPointsLimit = this.manaPoints;
    }

    public int getManaPoints() throws OutOfManaException {
        return this.manaPoints;
    }

    public void spendMana(int mp) throws OutOfManaException {
        if ( this.manaPoints >= mp ) {
            this.manaPoints -= mp;
        } else {
            throw new OutOfManaException();
        }
    }

    public String toString() {
        return this.name + "\n" + "(" + this.title + ", " + this.type + ")" + "\n"
                + "Hit points: " + this.hitPoints + "/" + this.hitPointsLimit + "\n"
                + "Mana points: " + this.manaPoints + "/" + this.manaPointsLimit + "\n"
                + "Damage: " + this.damage + "\n"
                + "Magic Resist: " + this.magicResist + "\n";
    }
}
