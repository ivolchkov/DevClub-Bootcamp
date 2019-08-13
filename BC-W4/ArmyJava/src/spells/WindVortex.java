package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class WindVortex extends Spell {
    public WindVortex() {
        super("WindVortex", 30, 40, true);
    }

    public WindVortex(int actionPoints) {
        super("WindVortex", 30, actionPoints, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

}
