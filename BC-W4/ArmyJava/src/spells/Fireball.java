package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class Fireball extends Spell {
    public Fireball() {
        super("Fireball", 40, 60, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

    public void heal(Unit unit) throws InvalidCastException {
        throw new InvalidCastException();
    }
}

