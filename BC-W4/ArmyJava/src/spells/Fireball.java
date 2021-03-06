package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class Fireball extends Spell {
    public Fireball() {
        super("Fireball", 40, 60, true);
    }

    public Fireball(int actionPoints) {
        super("Fireball", 40, actionPoints, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

}

