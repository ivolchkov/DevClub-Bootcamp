package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class LesserHeal extends Spell {
    public LesserHeal() {
        super("LesserHeal", 30, 40, false);
    }

    public LesserHeal(int actionPoints) {
        super("LesserHeal", 30, actionPoints, false);
    }

    public void action(Unit enemy) throws InvalidCastException {
        throw new InvalidCastException();
    }

    public void heal(Unit unit) throws InvalidCastException {
        unit.addHitPoints(this.actionPoints);
    }
}
