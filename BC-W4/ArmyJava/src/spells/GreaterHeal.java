package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class GreaterHeal extends Spell {
    public GreaterHeal() {
        super("GreaterHeal", 60, 90, false);
    }

    public GreaterHeal(int actionPoints) {
        super("GreaterHeal", 60, actionPoints, false);
    }

    public void heal(Unit unit) throws InvalidCastException {
        unit.addHitPoints(this.actionPoints);
    }
}
