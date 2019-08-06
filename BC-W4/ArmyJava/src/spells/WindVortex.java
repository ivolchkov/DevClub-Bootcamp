package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class WindVortex extends Spell {
    public WindVortex() {
        super("WindVortex", 30, 40, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

    public void heal(Unit unit) throws InvalidCastException {
        throw new InvalidCastException();
    }
}
