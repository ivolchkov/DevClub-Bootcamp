package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class GreaterHeal extends Spell {
    public GreaterHeal() {
        super("GreaterHeal", 60, 90, false);
    }

    public void action(Unit enemy) throws InvalidCastException {
        throw new InvalidCastException();
    }

    public void heal(Unit unit) throws InvalidCastException {
        unit.addHitPoints(this.actionPoints);
    }
}
